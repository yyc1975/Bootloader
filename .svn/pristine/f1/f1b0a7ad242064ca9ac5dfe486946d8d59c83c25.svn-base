/*============================================================================
 *
 *      mml_sc_vsr_pps_exchange.c
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
#include <mml_sc.h>

#include <errors.h>

#include <mml_sc_dev.h>
#include <mml_scs_analog.h>
#include <mml_scs_counter.h>
#include <mml_scs_handler.h>
#include <mml_scs_private.h>

void mml_sc_vsr_pps_exchange(int event) {

	switch (event) {
	case MML_SC_EVENT_EMPTY:
		mml_sc_handler_empty();
		break;
	case MML_SC_EVENT_TX:
		if (!dev->tx_expected_tx) {
			/* Wait of PPS_RESPONSE */
			dev->state = STATE_PPS_RESPONSE_TS;
		}

		mml_sc_handler_tx();
		break;
	case MML_SC_EVENT_PARITY:
		mml_sc_handler_parity();
	case MML_SC_EVENT_RX: {
		unsigned char data;
		if (dev->last_err == N_SCS_ERR_PARITY) {
			data = 0;
		} else {
			data = mml_sc_dev_inb();
		}

		switch (dev->state) {
		case STATE_PPS_REQUEST:
			if (--dev->rx_expected == 0) {
				/* Ready to receive the information and epilogue */
				dev->state = STATE_PPS_RESPONSE;
			}
			break;
		case STATE_PPS_RESPONSE_TS:
			/* calculation on rx_expected useless here ... */
			dev->state = STATE_PPS_RESPONSE_T0;
			break;
		case STATE_PPS_RESPONSE_T0:
			if (data & 0x80) {
				dev->last_err = N_SCS_ERR_PROTOCOL;
				break;
			}

			if ((data & 0x10) && (dev->tx_buf[1] & 0x10)) {
				dev->rx_expected = 2; /* PCK + PTS_1 */
				dev->state = STATE_PPS_RESPONSE;
			} else if (!(data & 0x10)) {
				dev->rx_expected = 1; /* PCK */
				dev->state = STATE_PPS_RESPONSE;
			} else {
				dev->last_err = N_SCS_ERR_PROTOCOL;
				break;
			}

			if ((data & 0x20) && (dev->tx_buf[1] & 0x20)) {
				dev->rx_expected++; /* PTS_2 */
				dev->state = STATE_PPS_RESPONSE;
			} else if (!(data & 0x20)) {
				dev->state = STATE_PPS_RESPONSE;
			} else {
				dev->last_err = N_SCS_ERR_PROTOCOL;
				break;
			}

			if ((data & 0x40) && (dev->tx_buf[1] & 0x40)) {
				dev->rx_expected++; /* PTS_3 */
				dev->state = STATE_PPS_RESPONSE;
			} else if (!(data & 0x40)) {
				dev->state = STATE_PPS_RESPONSE;
			} else {
				dev->last_err = N_SCS_ERR_PROTOCOL;
				break;
			}
			break;
		case STATE_PPS_RESPONSE:
			dev->rx_expected--;
			if (!dev->rx_expected) {
				dev->state = STATE_PPS_CHECK_BGT;
				mml_sc_counter_start_bgt();
				mml_sc_intr_mask_rx();
			}
			break;
		case STATE_PPS_CHECK_BGT:
		case STATE_PPS_DONE:
		default:
			return;
		}
		/* Store received data */
		if (*(dev->rx_size) < dev->rx_alloc) {
			dev->rx_buf[*dev->rx_size] = data;
			(*dev->rx_size)++;
		}
	}
		break;
	case MML_SC_EVENT_TIMEOUT:
		switch (dev->state) {
		case STATE_PPS_CHECK_BGT:
			/* Stop Block Guard Time autoreload */
			mml_sc_counter_halt_bgt();
			dev->state = STATE_PPS_DONE;
			break;
		default:
			if (dev->last_err != N_SCS_ERR_PARITY) {
				dev->last_err = N_SCS_ERR_CARD_MUTE;
				dev->state = STATE_PPS_DONE;
			} else {
				dev->rx_expected = 0;
			}
			break;
		}
		break;
	}

	/* Handle error */
	if (dev->last_err) {
		dev->state = STATE_PPS_DONE;
	}

	if (dev->state == STATE_PPS_DONE) {
		if (dev->status & MML_SCSTATUS_PARITY_ERROR) {
			dev->last_err = N_SCS_ERR_PARITY;
			dev->status &= ~MML_SCSTATUS_PARITY_ERROR;
		}

		if (mml_sc_dev_cancel_transfer()) {
			mml_sc_dev_call_handler(MML_SC_EVENT_ERROR);
		} else {
			mml_sc_dev_call_handler(MML_SC_EVENT_DATA_RECEIVED);
		}
	}
	return;
}
