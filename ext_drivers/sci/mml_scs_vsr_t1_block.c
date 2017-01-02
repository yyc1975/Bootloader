/*============================================================================
 *
 *      mml_sc_vsr_t1_block.c
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

volatile unsigned char	mml_sc_BGTCounterReception;

void mml_sc_vsr_t1_block(int event )
{
    switch(event)
    {         
		case MML_SC_EVENT_EMPTY:
			mml_sc_handler_empty();
			return;
        case MML_SC_EVENT_TX:
			if ( !dev->tx_expected_tx )
			{
				/* BGT = 22 etus for the next - and last - character to send */
				mml_sc_dev_gt_load(22);
				/* Load WT counter to check CWT */
				mml_sc_dev_wt_load(dev->cwt);
			}
            mml_sc_handler_tx();
			return;
        case MML_SC_EVENT_PARITY:
            mml_sc_handler_parity();
        case MML_SC_EVENT_RX:
            {
                unsigned char data;
                
                if ( ( dev->last_err == N_SCS_ERR_PARITY ) ||
                	( dev->state == STATE_T1_PRE_BGT ) )
                    data = 0;
                else    
                    data = mml_sc_dev_inb();

                switch( dev->state )
                {
                    case STATE_T1_PROLOGUE:
                        if ( --dev->rx_expected == 0 )
                        {
                            /* Ready to receive the information and epilogue */
                            mml_sc_dev_receive_data(data + dev->EDC);
                            dev->state = STATE_T1_REMAINING_DATA;
                        }
                        break;                   
                    case STATE_T1_REMAINING_DATA: 
                        if ( --dev->rx_expected == 0 )
                        {
							dev->state = STATE_T1_DONE;
                            mml_sc_intr_mask_rx();
                        }
                        break;
					case STATE_T1_PRE_BGT:
						/* Relaunch BGT */
						/* the 255th character received calls Error Handler */
						if ( mml_sc_BGTCounterReception == 0xfe )
						{
							mml_sc_counter_halt_bgt();
							mml_sc_intr_mask_rx();
							dev->state = STATE_T1_DONE;
							dev->status &= ~MML_SCSTATUS_OPERATION_PENDING;

							mml_sc_dev_call_handler( MML_SC_EVENT_ERROR);
						}
						else
						{
							mml_sc_intr_mask_timeout();
							mml_sc_dev_wt_stop();
							mml_sc_dev_wt_load(22);
							delay_micro(1);
							mml_sc_intr_unmask_timeout();
							mml_sc_dev_wt_run();
							mml_sc_BGTCounterReception++;
						}
                    case STATE_T1_CHECK_BGT2:
                    default:
                    	/* Here, the received data are not saved */
                    	return;
                } 
                /* Store received data */  
                if( *(dev->rx_size) < dev->rx_alloc )
                {
                    dev->rx_buf[*dev->rx_size] = data;
                    (*dev->rx_size)++;
                }
            }
            break;
        case MML_SC_EVENT_TIMEOUT:
			switch( dev->state )
			{
				case STATE_T1_CHECK_BGT2:
					break;
				case STATE_T1_PRE_BGT:
					/* Ok, everything's fine let's go for the transmission */
					dev->state = STATE_T1_PROLOGUE;
					mml_sc_dev_flush_tx();
					mml_sc_dev_flush_rx();
					/* Prepare to send the frame */
					mml_sc_dev_send_data_T1();
					/* Ready to receive the frame header { NAD+PCB+LEN }*/
					mml_sc_dev_receive_data_T1();
					break;
				default:
					dev->last_err = N_SCS_ERR_CARD_MUTE;
					mml_sc_intr_unmask_parity_error();
					break;
			}
            break;
    }

    if ( dev->last_err )
    {
        dev->state = STATE_T1_DONE;
    }
    if ( STATE_T1_DONE == dev->state )
    {
        if ( dev->status & MML_SCSTATUS_PARITY_ERROR )
        {
            dev->last_err = N_SCS_ERR_PARITY;
            dev->status &= ~MML_SCSTATUS_PARITY_ERROR; 
        }

        if ( mml_sc_dev_cancel_transfer() )
        {
            mml_sc_dev_call_handler(MML_SC_EVENT_ERROR);
        }
        else
        {
            mml_sc_dev_call_handler(MML_SC_EVENT_DATA_RECEIVED);
        }
    }     
	return;
}
