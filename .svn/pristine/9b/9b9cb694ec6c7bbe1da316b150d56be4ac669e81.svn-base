/*============================================================================
 *
 *      mml_sc_dev.c
 *
 *      
 *
 *==========================================================================*/
/*============================================================================
 * 
 * Copyright (c) 2002-2010 Maxim Integrated Products.
 * All Rights Reserved.
 *
 * This software is the confidential and proprietary information of
 * Maxim Integrated Products ("Confidential Information"). You shall not
 * disclose such Confidential Information and shall use it only in
 * accordance with the terms of the license agreement you entered
 * into with Maxim Integrated Products.
 *
 * Maxim Integrated Products makes no representations or warranties about the suitability of 
 * the software, either express or implied, including but not limited to 
 * the implied warranties of merchantability, fitness for a particular purpose, 
 * or non-infrigement. Maxim Integrated Products shall not be liable for any damages suffered 
 * by licensee as the result of using, modifying or distributing this software 
 * or its derivatives.
 * 
 *==========================================================================*/
/*============================================================================
 * 
 * Author(s): Maxim Integrated Products
 * Contributors:
 * Date:          
 * Purpose:       
 * Description:
 * 
 *==========================================================================*/
#include <errors.h>
#include <mml.h>
#include <mml_io.h>
#include <mml_intc_regs.h>
#include <mml_intc.h>

#include <mml_sc.h>

#include <mml_sc_dev.h>
#include <mml_scs_counter.h>
#include <mml_scs_analog.h>
#include <mml_scs_private.h>

mml_sc_dev_t mml_sc_dev[N_MML_SC_DEV_COUNT] __attribute__ ((aligned(4)));

/******************************************************************************/
int mml_sc_dev_send_data(unsigned int length) {
	dev->tx_expected_txempty = length;
	dev->tx_expected_tx = length;
	return mml_sc_dev_send_data_T1();
}

/******************************************************************************/
int mml_sc_dev_send_data_T1() {
	unsigned int bwt = dev->bwt;

	if ((dev->WTX) && (dev->protocol == MML_SCPROTOCOL_T1))
	/* Bug fix 1139 */
	{
		bwt *= dev->WTX;
		bwt += BWT_OFFSET_ERROR;
	}
	/*  */
	/* Load the BWT */
	mml_sc_intr_mask_timeout();
	mml_sc_dev_wt_stop();
	mml_sc_dev_disable_uart();
	mml_sc_dev_wt_load(bwt);
	delay_micro(1);
	mml_sc_dev_wt_run();
	mml_sc_dev_enable_uart();
	/* decrease both Tx's counters */
	dev->tx_expected_txempty--;
	dev->tx_expected_tx--;
	/* Send the first data byte */
	mml_sc_dev_outb(dev->tx_buf[dev->tx_size++]);

	/* unmask TxTransmitted's IT */
	mml_sc_intr_unmask_tx();
	/* unmask TxEmptyBuffer's IT */
	mml_sc_intr_unmask_empty_buf();
	return dev->last_err;
}

/******************************************************************************/
int mml_sc_dev_receive_data(int length) {
	/* Check parameter */
	dev->rx_expected = length;
	return mml_sc_dev_receive_data_T1();
}

/******************************************************************************/
int mml_sc_dev_receive_data_T1() {
	mml_sc_intr_unmask_rx();
	return dev->last_err;
}

/******************************************************************************/
int mml_sc_dev_cancel_transfer() {

	switch (dev->last_err) {
	case N_SCS_ERR_CARD_MUTE:
		/* Check if the card is really mute or absent */
		if (mml_sc_analog_card_presence()) {
			dev->last_err = N_SCS_ERR_CARD_ABSENT;
		}
		if (dev->protocol == MML_SCPROTOCOL_T1) {
			goto endseq;
		}
	case N_SCS_ERR_POWER_UP:
	case N_SCS_ERR_CARD_ABSENT:
	case N_SCS_ERR_PROC_BYTE:
	case N_SCS_ERR_INVALID_ATR:
	case N_SCS_ERR_PROTOCOL:
		mml_sc_power_down();
	case N_SCS_ERR_PARITY:
		break;
	default:
		break;
	}

	mml_sc_intr_mask_all();
	endseq: mml_sc_counter_clk_halt();
	mml_sc_counter_halt();
	dev->status &= ~MML_SCSTATUS_OPERATION_PENDING;

	return dev->last_err;
}

/******************************************************************************/
void mml_sc_dev_etu_load(unsigned int etu) {
//	mml_sc_dev_write_reg(dev, SCIB_ETUR, etu);
	dev->reg_sc->sc_etur = etu;
	delay_micro(1);
	return;
}

/******************************************************************************/
void mml_sc_dev_wt_load(unsigned long long etu) {

	dev->reg_sc->sc_wt0r = (unsigned int) (MML_SC_WT0R_WT_MASK_NOOFST & etu);
	dev->reg_sc->sc_wt1r = (unsigned int) (MML_SC_WT1R_WT_MASK_NOOFST
			& (etu >> 32));
	return;
}

/******************************************************************************/
void mml_sc_dev_gt_load(unsigned int etu) {

	dev->reg_sc->sc_gtr = (MML_SC_GTR_GT_MASK_NOOFST & etu);
	return;
}

/******************************************************************************/
void mml_sc_dev_set_conv() {
	if (dev->status & MML_SCSTATUS_CONV_INVERSE) {
		dev->reg_sc->sc_cr |= MML_SC_CR_CONV_MASK;
	} else {
		dev->reg_sc->sc_cr &= ~MML_SC_CR_CONV_MASK;
	}
	return;
}

inline void mml_sc_dev_call_service(int event) {
	if (dev->vsr) {
		dev->vsr(event);
	}
}

/******************************************************************************/
inline void mml_sc_dev_call_handler(int event) {
	if (dev->handlers[event]) {
		dev->handlers[event](event);
	}
}

/******************************************************************************/
inline int mml_sc_dev_selected_device() {
	return mml_sc_ioctl(N_SCS_IOCTL_WHICHSELECTED, (void *) 0);
}

/******************************************************************************/
inline int mml_sc_dev_selection(int cmd) {

	return mml_sc_ioctl(cmd, (void *) 0);

}

#define SLOW_XTAL
#ifdef SLOW_XTAL
#define US_DELAY_FACT 108
#else
#define US_DELAY_FACT 470
#endif

__attribute__((optimize("-O0"))) void delay_micro(int us_to_delay) {
	// just guessing at delay time
	int i, j;
	cpsid();
	for (i = 0; i < us_to_delay; i++) {
		for (j = 0; j < US_DELAY_FACT; j++) {
			asm ("mov r0, r0");
		}
	}
	cpsie();
}
