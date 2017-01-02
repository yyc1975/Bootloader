/*
 * mml_sci.c --
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2014, Maxim Integrated Products
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MAXIM INTEGRATED PRODUCTS ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL MAXIM INTEGRATED PRODUCTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* [INTERNAL] ------------------------------------------------------------------
 * Created on:  Oct 30, 2012
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: $: Revision of last commit
 * $Author:: $: Author of last commit
 * $Date:: $: Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

/** Global includes */
#include <config.h>
#include <errors.h>
/** Other includes */
#include <mml_intc.h>
/** Local includes */
#include <mml_sc.h>
#include <mml_sc_dev.h>
#include <mml_sc_regs.h>
#include <mml_scs_clock.h>
#include <mml_scs_handler.h>
#include <mml_scs_private.h>
#include <mml_scs_counter.h>

#ifdef _STAND_ALONE_DRIVER_SCI_
/* This compilation flag is activated only in driver development context
 * without any application using it.
 * DO NOT define it in application/test context then. */
/*****************************************************************************/
int main(void)
{
	/** We're done */
	return NO_ERROR;
}
#endif /* _STAND_ALONE_DRIVER_SCI_ */

mml_sc_dev_t sc_device __attribute__ ((aligned(4)));
mml_sc_dev_t * dev;

/******************************************************************************/
/**
 * The function initializes a Smart Card Interface.
 *
 * @param[in] params   Pointer to an initialized configuration structure.
 *
 * @retval NO_ERROR			No error
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * @retval Other            See \link Error_Codes Error Codes \endlink
 *							or mml_sc_set_config()'s ones.
 *
 */
int mml_sc_init(t_mml_sc_config *params) {
	int result = COMMON_ERR_UNKNOWN;
	mml_sc_regs_t *mml_sc;

	/** Check parameters */
	if (!params) {
		result = COMMON_ERR_INVAL;
		goto mml_sc_init_out;
	}

	dev = &sc_device;

	/** Reset all internal variables */
	mml_sc_memset((unsigned char*) dev, (unsigned char) 0x00,
			sizeof(mml_sc_dev_t));
	/* Activate the device and initialize interrupt handlers */

	dev->reg_sc = (mml_sc_regs_t*) MML_SC_IOBASE;

	result = mml_intc_setup_irq(MML_INTNUM_SC, MML_INTC_PRIO_6, mml_sc_isr);
	if (result) {
		goto mml_sc_init_out;
	}
	mml_sc = (mml_sc_regs_t*) dev->reg_sc;
	/**  */
	dev->status = ( MML_SCSTATUS_INITIALIZED | MML_SCSTATUS_CARD_NOT_POWERED);
	result = mml_sc_set_config(params);
	if (result) {
		dev->status &= ~MML_SCSTATUS_INITIALIZED;
		return result;
	}
	/** Reset hardware */
	mml_sc_dev_disable_uart();
	mml_sc_icc_set_io();
	delay_micro(10);
	mml_sc_dev_set_card_clk_sel();
	/** Vcard OK , CLK GCR */

	/** Set receive and transmit character depth to 1 */
	mml_sc->sc_cr |= (1 << MML_SC_CR_RXTHD_OFST)
			| (1 << MML_SC_CR_TXTHD_OFST);
	mml_sc_dev_enable_uart();
	/** Init Security counter with default value */
	dev->uiSecurityLoop = MML_SCDEFAULT_SEC_LOOP_VALUE;
	/**  */
	dev->ucEraseCWT = TRUE;
	dev->ucEraseBWT = TRUE;

	/** We're done */
	mml_sc_init_out: return result;
}

/******************************************************************************/
/**
 * The function configures a Smart Card Interface and selects the working
 * clock for the interface.
 *
 * @param[in] params    Pointer to an initialized configuration structure.
 *
 * @retval NO_ERROR				No error
 * @retval N_SCS_ERR_NXIO    	Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL   	Invalid parameter.
 * @retval Other        		See \link Error_Codes Error Codes \endlink
 *
 */
int mml_sc_set_config(t_mml_sc_config *params) {
	int result = COMMON_ERR_UNKNOWN;

	/** Check if the device is initialized */
	if (!(dev->status & MML_SCSTATUS_INITIALIZED)) {
		result = N_SCS_ERR_NXIO;
		goto mml_sc_set_config_out;
	}
	/** Check parameters */
	else if (!params) {
		result = COMMON_ERR_INVAL;
		goto mml_sc_set_config_out;
	} else if ((params->power != N_MML_SC_POWER_1_8V)
			&& (params->power != N_MML_SC_POWER_3V)
			&& (params->power != N_MML_SC_POWER_5V)) {
		result = COMMON_ERR_INVAL;
		goto mml_sc_set_config_out;
	} else if (params->clock > ( MML_SCCLOCK_EXTERNAL | MML_SCCLOCK_3MHz)) {
		result = COMMON_ERR_INVAL;
		goto mml_sc_set_config_out;
	} else if (!params->devio) {
		result = COMMON_ERR_INVAL;
		goto mml_sc_set_config_out;
	}
	/** First, set the clock */
	result = mml_sc_set_clock(params->clock);
	if (result) {
		goto mml_sc_set_config_out;
	} else {
		dev->power = params->power;
	}
	/** We're done */
	mml_sc_set_config_out: return result;
}

/******************************************************************************/
/* EOF */
