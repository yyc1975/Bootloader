/*============================================================================
 *
 *      mml_sc_vsr_t0_out.c
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

void mml_sc_vsr_t0_out(int event) {
	switch (event) {
	case MML_SC_EVENT_PARITY:
		mml_sc_handler_parity();
		break;
	case MML_SC_EVENT_TX:
		if (!mml_sc_handler_tx()) {
			/* Call user handler if registered */
			mml_sc_dev_call_handler(MML_SC_EVENT_DATA_SENT);
		}
		break;
	case MML_SC_EVENT_EMPTY:
		mml_sc_handler_empty();
		break;
	case MML_SC_EVENT_RX: {
		unsigned char data;

		data = mml_sc_dev_inb();
		/* wait end header tx for start rx */
		switch (dev->state) {
		case STATE_T0_OUT_CHECK_PROC_BYTE:
			/* Check SW1 byte */
			if (((data & 0xF0) == 0x60) || ((data & 0xF0) == 0x90)) {
				/* if byte NULL 0x60 */
				if (data == 0x60) {
					/* Call user handler if registered */
					mml_sc_dev_call_handler(
							MML_SC_EVENT_WAITING_TIME_EXTENSION);
					return;
				} else
					dev->state = STATE_T0_OUT_CHECK_SW2;
			}
			/* if byte == INS */
			else if (data == dev->tx_buf[OFFSET_INS]) {
				/* if no all data received */
				if (dev->rx_expected)
					dev->state = STATE_T0_OUT_CHECK_REMAINING_DATA;
				return;
			}
			/* if byte XOR INS */
			else if ((unsigned char) data
					== (unsigned char) (~((unsigned char) dev->tx_buf[OFFSET_INS]))) {
				/* if no all data received */
				if (dev->rx_expected)
					dev->state = STATE_T0_OUT_CHECK_ONE_DATA;
				return;
			}
			/* received other byte */
			else {
				dev->last_err = N_SCS_ERR_PROC_BYTE;
				goto done;
			}
			break;
		case STATE_T0_OUT_CHECK_ONE_DATA:
			dev->rx_expected--;
			dev->state = STATE_T0_OUT_CHECK_PROC_BYTE;
			break;
		case STATE_T0_OUT_CHECK_REMAINING_DATA:
			dev->rx_expected--;
			if (!dev->rx_expected)
				dev->state = STATE_T0_OUT_CHECK_PROC_BYTE;
			break;
		case STATE_T0_OUT_CHECK_SW1:
			dev->state = STATE_T0_OUT_CHECK_SW2;
			break;
		case STATE_T0_OUT_CHECK_SW2:
			dev->state = STATE_T0_OUT_CHECK_BGT2;
			mml_sc_counter_start_bgt();
			/* prevent from receiving character durint Guard Time */
			mml_sc_intr_mask_rx();
			break;
		}
		/* Store received data */
		if (*(dev->rx_size) < dev->rx_alloc) {
			dev->rx_buf[*dev->rx_size] = data;
			(*dev->rx_size)++;
		}
	}
		break;
	case MML_SC_EVENT_TIMEOUT: {
		switch (dev->state) {
		case STATE_T0_OUT_CHECK_BGT2:
			/* Stop Block Guard Time autoreload */
			mml_sc_counter_halt_bgt();
			dev->state = STATE_T0_OUT_DONE;
			break;
		default:
			mml_sc_intr_mask_rx();
			dev->last_err = N_SCS_ERR_CARD_MUTE;
			break;
		}
	}
		break;
	}

	done:
	/* Handle error */
	if (dev->last_err)
		dev->state = STATE_T0_OUT_DONE;

	if (dev->state == STATE_T0_OUT_DONE) {
		if (mml_sc_dev_cancel_transfer())
			mml_sc_dev_call_handler(MML_SC_EVENT_ERROR);
		else
			mml_sc_dev_call_handler(MML_SC_EVENT_DATA_RECEIVED);
	}
	return;
}
