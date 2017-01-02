/*============================================================================
 *
 *      mml_sc_vsr_t0_in.c
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

#include <mml_sc_dev.h>
#include <mml_scs_analog.h>
#include <mml_scs_counter.h>
#include <mml_scs_handler.h>
#include <mml_scs_private.h>

void mml_sc_vsr_t0_in(int event) {
	switch (event) {
	case MML_SC_EVENT_PARITY:
		mml_sc_handler_parity();
		break;
	case MML_SC_EVENT_TX:
		mml_sc_handler_tx();
		break;
	case MML_SC_EVENT_EMPTY:
		mml_sc_handler_empty();
		break;
	case MML_SC_EVENT_RX: {
		unsigned char data;

		data = mml_sc_dev_inb();
		/* wait end header tx for start rx */
		switch (dev->state) {
		case STATE_T0_IN_CHECK_PROC_BYTE:
		case STATE_T0_IN_CHECK_SW1:
			/* Check SW1 byte */
			if (((data & 0xF0) == 0x60) || ((data & 0xF0) == 0x90)) {
				/* if byte NULL 0x60 */
				if (data == 0x60) {
					/* Call user handler if registered */
					mml_sc_dev_call_handler(
							MML_SC_EVENT_WAITING_TIME_EXTENSION);
					return;
				} else {
					dev->state = STATE_T0_IN_CHECK_SW2;
				}
			}
			/* if byte == INS */
			else if (data == dev->tx_buf[OFFSET_INS]) {
				/* if no all data send */
				if ((dev->tx_size - 5) != dev->tx_buf[OFFSET_Lc]) {
					mml_sc_counter_start_bgt();
					dev->state = STATE_T0_IN_SEND_REMAINING_DATA;
				}
				return;
			}
			/* if byte XOR INS */
			else if ((unsigned char) data
					== (unsigned char) (~((unsigned char) dev->tx_buf[OFFSET_INS]))) {
				/* if buffer tx not empty */
				if ((dev->tx_size - 5) != dev->tx_buf[OFFSET_Lc]) {
					mml_sc_counter_start_bgt();
					dev->state = STATE_T0_IN_SEND_ONE_DATA;
				}
				return;
			}
			/* received other byte */
			else {
				dev->last_err = N_SCS_ERR_PROC_BYTE;
				goto done;
			}
			break;
		case STATE_T0_IN_CHECK_SW2:
			dev->state = STATE_T0_IN_CHECK_BGT2;
			mml_sc_counter_start_bgt();
			/* prevent from receiving character durint Guard Time */
			mml_sc_intr_mask_rx();
			break;
		default:
			dev->last_err = N_SCS_ERR_UNKNOW;
			goto done;
		}
		/* Store the received data byte */
		if (*(dev->rx_size) < dev->rx_alloc) {
			dev->rx_buf[*dev->rx_size] = data;
			(*dev->rx_size)++;
		}
	}
		break;
	case MML_SC_EVENT_TIMEOUT: {
		switch (dev->state) {
		case STATE_T0_IN_SEND_ONE_DATA:
			/* Stop the Character Guard Time autoreload */
			mml_sc_counter_halt();
			/* Send only one data byte */
			mml_sc_dev_send_data(1);
			/* Call user handler if registered */
			if (dev->tx_size == (unsigned int) (dev->tx_buf[OFFSET_Lc] + 5)) {
				mml_sc_dev_call_handler(MML_SC_EVENT_DATA_SENT);
			}
			/* Ready to receive a procedure byte
			 * or the status words */
			dev->state = STATE_T0_IN_CHECK_PROC_BYTE;
			break;
		case STATE_T0_IN_SEND_REMAINING_DATA:
			/* Stop the Character Guard Time autoreload */
			mml_sc_counter_halt();
			/* Send all remaining data */
			mml_sc_dev_send_data(dev->tx_buf[OFFSET_Lc] - (dev->tx_size - 5));
			/* Call user handler if registered */
			mml_sc_dev_call_handler(MML_SC_EVENT_DATA_SENT);
			/* Ready to receive the status words */
			dev->state = STATE_T0_IN_CHECK_SW1;
			break;
		case STATE_T0_IN_CHECK_BGT2:
			/* Stop Block Guard Time autoreload */
			mml_sc_counter_halt_bgt();
			dev->state = STATE_T0_IN_DONE;
			break;
		default:
			dev->last_err = N_SCS_ERR_CARD_MUTE;
			break;
		}
	}
		break;
	default:
		return;
	}

	done:
	/* Catch error */
	if (dev->last_err) {
		dev->state = STATE_T0_IN_DONE;
	}
	if (dev->state == STATE_T0_IN_DONE) {
		if (mml_sc_dev_cancel_transfer()) {
			mml_sc_dev_call_handler(MML_SC_EVENT_ERROR);
		} else {
			mml_sc_dev_call_handler(MML_SC_EVENT_DATA_RECEIVED);
		}
	}
	return;
}

