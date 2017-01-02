/*
 * mml_sc_analog.c --
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

#include <mml_sc.h>

#include <mml_sc_dev.h>
#include <mml_scs_counter.h>
#include <mml_scs_handler.h>
#include <mml_scs_analog.h>

/******************************************************************************/
/**
 * the function check if the card is present and power on
 */
int mml_sc_analog_check() {
	int result;

	/* check card presence */
	result = mml_sc_analog_card_presence();
	if (result)
		return result;
	/* Check power */
	result = mml_sc_analog_check_voltage();
	return result;
}
/******************************************************************************/
int mml_sc_analog_card_presence() {
	int result;
	int status;

	result = mml_sc_ioctl(N_SCS_IOCTL_CHECK_CARD_PRESENCE, &status);
	if (result) {
		return result;
	} else {
		dev->status &= ~(MML_SCSTATUS_CARD_NOT_INSERTED
				| MML_SCSTATUS_CARD_INSERTED);
		dev->status |= status;
	}

	return result;
}
/******************************************************************************/
int mml_sc_analog_check_voltage() {
	int result;
	int status;

	result = mml_sc_ioctl(N_SCS_IOCTL_CHECK_VOLT_OK, &status);
	if (!result) {
		dev->status &= ~(MML_SCSTATUS_CARD_NOT_POWERED
				| MML_SCSTATUS_CARD_POWERED);
		dev->status |= status;
	}

	return result;
}

/******************************************************************************/
inline int mml_sc_analog_power_down() {
	return mml_sc_ioctl(N_SCS_IOCTL_POWER_DOWN, (void *) 0);
}

/******************************************************************************/
inline int mml_sc_analog_power_up(int volt) {

	int voltreg = 0;

	switch (volt) {
	case MML_SCSTATUS_POWER_5V:
		voltreg = 0x200;
		break;

	case MML_SCSTATUS_POWER_3V:
		voltreg = 0x100;
		break;
	case MML_SCSTATUS_POWER_1_8V:
		voltreg = 0x000;
		break;
	}
	return mml_sc_ioctl(N_SCS_IOCTL_POWER_UP, (void *) voltreg);
}

/******************************************************************************/
inline int mml_sc_analog_card_reset(int value) {
	return mml_sc_ioctl(N_SCS_IOCTL_CARD_RESET, (void *) value);
}

/******************************************************************************/
/* EOF */
