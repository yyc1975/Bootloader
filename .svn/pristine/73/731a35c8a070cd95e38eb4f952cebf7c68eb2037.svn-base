/*============================================================================
 *
 *      mml_sc_vsr_power_up.c
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

#include <mml_sc.h>

#include <mml_sc_dev.h>
#include <mml_scs_analog.h>
#include <mml_scs_counter.h>
#include <mml_scs_handler.h>
#include <mml_scs_private.h>


int mml_sc_atr_check_TDx( unsigned char TDx );
int mml_sc_atr_get_interface_byte_num();
unsigned char mml_sc_atr_get_TCK();

#define WAIT_EXTRA_BYTE 25

void mml_sc_vsr_power_up(int event )
{
    unsigned char   k;
    unsigned char   expected;
    unsigned char   err; 
    unsigned char   data;
    unsigned char   TDx, TCK;

    switch( event )
    {
        case MML_SC_EVENT_PARITY:
			mml_sc_handler_parity();
			mml_sc_dev_disable_uart();
			delay_micro(1);
			dev->state = ATR_STATE_DONE;
			break;
        case MML_SC_EVENT_RX:
			/* Retrieve the received data */
			data = dev->reg_sc->sc_rxr;
			mml_sc_counter_start(dev->cwt); //start wt to manage cwt
			switch( dev->state )
			{
				/* Start Final State Machine */
				case ATR_STATE_CHECK_TS_BYTE:
					mml_sc_counter_clk_halt_man();
					/* Check parity error to determine the convention */
					err = mml_sc_dev_get_parity_error();
					if ( data == 0x03 )
					{
						/* if no error parity then bad atr */
						if ( !err )
						{
							dev->last_err = N_SCS_ERR_INVALID_ATR;
							goto done;
						}
						/* Change convension */
						dev->status |= MML_SCSTATUS_CONV_INVERSE;
						mml_sc_dev_set_conv();
						delay_micro(1);
						mml_sc_dev_clear_parity_error();
						delay_micro(1);
						data = 0x3F;
					}
					else if ( ( data != 0x3B ) || err )
					{
						dev->last_err = N_SCS_ERR_INVALID_ATR;
						goto done;
					}
					mml_sc_intr_unmask_parity_error();
					delay_micro(1);
					/* Call if registered the user handler */
					mml_sc_dev_call_handler(MML_SC_EVENT_ATR_TS_RECEIVED);
					/* Update state machine */
					dev->state = ATR_STATE_CHECK_T0_BYTE;
					break;
				case ATR_STATE_CHECK_T0_BYTE:
					/* Check the presence of Interface Characters */
					if ( data & 0xF0 )
					{
						dev->state = ATR_STATE_CHECK_INTERFACE_BYTES;
					}
					/* Check the presence of historical bytes */
					else if ( data & 0x0F )
					{
						/* Retrieve the historical bytes */
						mml_sc_dev_receive_data(data & 0x0F);
						dev->state = ATR_STATE_CHECK_HIST_BYTES;
					}
					else
					{
						dev->state = ATR_STATE_CHECK_EXTRA_BYTES;
						mml_sc_counter_start(WAIT_EXTRA_BYTE);
						delay_micro(1);
					}
					break;
				case ATR_STATE_CHECK_INTERFACE_BYTES:
					/* Get the number of Interface Characters */
					TCK = 0;
					{
						expected = 1;

						while ( expected <= (*(dev->rx_size) + 1) )
						{
							if ( expected < *(dev->rx_size) )
								TDx = dev->rx_buf[expected];
							else
								TDx = data;

							if ( ( expected > 1 ) &&
								( TDx & 0x0F ) )
								TCK++;

							expected += mml_sc_atr_check_TDx(TDx);

							if ( ( TDx & 0x80 ) == 0 )
								break;
					   }
					   expected--;
					}

					if ( (*dev->rx_size - 1) == expected )
					{
						/* Get the number of historical bytes */
						k = (dev->rx_buf[1] & 0x0F);
						if ( k )
						{
							mml_sc_dev_receive_data(k);
							dev->state = ATR_STATE_CHECK_HIST_BYTES;
						}
						else if ( TCK )
							dev->state = ATR_STATE_CHECK_TCK_BYTE;
						else
						{
							dev->state = ATR_STATE_CHECK_EXTRA_BYTES;
							mml_sc_counter_start(WAIT_EXTRA_BYTE);
							delay_micro(1);
						}
					}
					break;
				case ATR_STATE_CHECK_HIST_BYTES:
					if ( --dev->rx_expected == 0 )
					{
						if ( mml_sc_atr_get_TCK(dev) )
						{
							dev->state = ATR_STATE_CHECK_TCK_BYTE;
							break;
						}
						else
						{
							dev->state = ATR_STATE_CHECK_EXTRA_BYTES;
							mml_sc_counter_start(WAIT_EXTRA_BYTE);
							delay_micro(1);
						}
					}
					break;
				case ATR_STATE_CHECK_TCK_BYTE:
					dev->state = ATR_STATE_CHECK_EXTRA_BYTES;
					mml_sc_counter_start(WAIT_EXTRA_BYTE);
					delay_micro(1);
					break;
				case ATR_STATE_CHECK_EXTRA_BYTES:
					return;
			}

			if ( dev->last_err == NO_ERROR )
			{
				/* Append received byte in the received data buffer */
				if( *(dev->rx_size) < dev->rx_alloc )
				{
					dev->rx_buf[*dev->rx_size] = data;
					(*dev->rx_size)++;
				}
				else
					/* buffer overflow */
					dev->last_err = N_SCS_ERR_NO_BUFS;
			}
            break; 
        case MML_SC_EVENT_TIMEOUT:
                switch( dev->state )
                {
                    case STATE_WAIT_BGT:
  					    mml_sc_counter_halt();
                    	/** RESET to low */
                    	mml_sc_analog_card_reset(0);
                    	delay_micro(1);
				        mml_sc_dev_enable_uart();
					    delay_micro(1);
                        /** Clock counter */
					    // FIXME
						mml_sc_counter_clk_start_man(35000);
                        dev->state = STATE_WAIT_40000_CYCLES_BIS;
                        break;
                    case ATR_STATE_CHECK_EXTRA_BYTES:
                        mml_sc_counter_halt_bgt();
                        dev->state = ATR_STATE_DONE; 
                        break;
                    case ATR_STATE_CHECK_TS_BYTE:
                    	mml_sc_intr_mask_rx();
                    	delay_micro(1);
						dev->state = ATR_STATE_DONE;
						break;
                    default:
                        mml_sc_intr_mask_rx();
                        delay_micro(1);
                        dev->last_err = N_SCS_ERR_CARD_MUTE;
                        break;
                }           
            break;
        case MML_SC_EVENT_COUNTER:
        	switch( dev->state )
			{
				case STATE_WAIT_40000_CYCLES:
					mml_sc_dev_counter_clk_stop();
					mml_sc_counter_clk_start_man(40000);
					dev->state = STATE_WAIT_40000_CYCLES_BIS;
					break;
				case STATE_WAIT_40000_CYCLES_BIS:
					/** Stop clock counter */
					mml_sc_counter_clk_halt_man();
					mml_sc_intr_unmask_rx();
                    delay_micro(1);

                    /* Set RESET signal */
					mml_sc_analog_card_reset(1);

					mml_sc_counter_clk_start(dev->bwt);

					/* Prepare for the next character to be received */
					dev->state = ATR_STATE_CHECK_TS_BYTE;
					break;
				case ATR_STATE_CHECK_TS_BYTE:
				case ATR_STATE_CHECK_T0_BYTE:
				case ATR_STATE_CHECK_INTERFACE_BYTES:
				case ATR_STATE_CHECK_HIST_BYTES:
				case ATR_STATE_CHECK_TCK_BYTE:
				case ATR_STATE_CHECK_EXTRA_BYTES:
					mml_sc_dev_call_handler(MML_SC_EVENT_CLOCK_COUNTER);
				default:
					// FIXME : probleme tempo
					mml_sc_intr_mask_rx();
					dev->last_err = N_SCS_ERR_CARD_MUTE;
					break;
			}
        	break;
        default:
            dev->last_err = N_SCS_ERR_UNKNOW;
            break;
    }
    
done:
    if ( dev->state == ATR_STATE_DONE )
    {    
    	mml_sc_dev_wt_stop();  //stop looking for cwt
    	delay_micro(1);

        if ( mml_sc_dev_cancel_transfer() )
        {
            mml_sc_dev_call_handler(MML_SC_EVENT_ERROR);
        }
        else
        {
            mml_sc_dev_call_handler(MML_SC_EVENT_ATR_RECEIVED);
        }
    }     
    /* Handle error */
	else if ( dev->last_err == N_SCS_ERR_INVALID_ATR )
	{
		dev->state = ATR_STATE_DONE;
		goto done;
	}
    else if ( dev->last_err )
	{
        dev->state = ATR_STATE_CHECK_EXTRA_BYTES;
        mml_sc_counter_start_bgt();
    }
    return;
}

unsigned char mml_sc_atr_get_TCK(mml_sc_dev_t* dev)
{
    unsigned int			i = 1;
    unsigned char			TDx;
    unsigned char			TCK = 0;
    
    while( i <= *(dev->rx_size) )
    {            
        TDx = dev->rx_buf[i];
          
        if ( ( i > 1 ) &&
        	( TDx & 0x0F ) )
            TCK++;

        if ( ( TDx & 0x80 ) == 0 )
            break;

        i += mml_sc_atr_check_TDx(TDx);                                                                
    }
    return TCK;
}
    
/**
 * the function computes the number of byte annonced in the TDx
 */
int mml_sc_atr_check_TDx(unsigned char TDx)
{
    register unsigned int			i;
    unsigned int					count = 0;
    unsigned char					mask = 0x10;
    
    for ( i = 4;i > 0; )
    {
    	i--;
        if ( TDx & mask )
            count++;

        mask <<=1;
    }
    return count;
}

/**
 * the function gets the number of interface bytes
 */
int mml_sc_atr_get_interface_byte_num()
{
	unsigned int				i;
	unsigned int				count;
    unsigned char				TDx;
    unsigned char*				atr = dev->rx_buf;
    
    count = 0;
    i = 1;
    while( i <= (*(dev->rx_size) + 1) )
    {
        TDx = atr[i];
        count = mml_sc_atr_check_TDx(TDx);
        i += count;

        if ( ( TDx & 0x80 ) == 0 )
            break;
    }
    return (i - 1);
}
