/*============================================================================
 *
 *      mml_sc_power_up.c
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
#include <mml_sc_dev.h>
#include <mml_scs_private.h>
#include <mml_io.h>

void mml_sc_vsr_power_up(int event );

/**
 * The function powers up and resets an asynchronous card. During the card 
 * Answer To Reset (ATR), the function performs a check for the T0 and TDi 
 * bytes to compute the number of bytes that must be received.
 * 
 * @param[out] atr      Valid pointer to the card Answer To Reset (ATR).
 * 
 * @param[out] length   Valid pointer to the length of the Answer To Reset.
 * 
 * @retval NO_ERROR			No error
 * @retval N_SCS_ERR_NXIO        Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * @retval COMMON_ERR_ALREADY     Operation already pending
 * @retval N_SCS_ERR_CARD_ABSENT Card absent
 * @retval ERR_SCS_BAD_ATR     Bad Answer To Reset
 * @retval Other            See \link Error_Codes Error Codes \endlink
 * 
 * @note The function is synchronous since a call to #mml_sc_attach() makes 
 * the function asynchronous by returning immediatly without waiting the end 
 * of the operation.
 * 
 */
int mml_sc_power_up( unsigned char *atr, unsigned int *length )
{
    int							result;

    /* Check if the device is initialized */  
    if ( !( dev->status & MML_SCSTATUS_INITIALIZED ) )
    {
        return N_SCS_ERR_NXIO;
    }

    /* Check if an operation is already pending */  
    if ( dev->status & MML_SCSTATUS_OPERATION_PENDING )
    {
      return COMMON_ERR_ALREADY;
    }
    /* Check parameters */
    if ( ( !atr ) ||
    	( !length ) )
    {
       return COMMON_ERR_INVAL;
    }
    /* Check the card presence */
    result = mml_sc_analog_check();
    if ( result )
    {
    	return result;
    }
    else if ( dev->status & MML_SCSTATUS_CARD_NOT_INSERTED )
    {
    	dev->last_err = N_SCS_ERR_CARD_ABSENT;
    	return dev->last_err;
    }
    /* Initialize to default communication parameters */
    dev->FIDI = 0x11;
	/* Default Gard Time 12 etu */
    dev->EGT = 0x00;
    dev->WI = 10;
    mml_sc_dev_wt_load(dev->bwt);

    /* Maximum clock cycles for ATR to begin */
    if ( dev->ucEraseBWT == TRUE )
    {
        mml_sc_calculate_wt( K_SCS_WT_START_ATR);
    }
    /**  */
    if ( dev->ucEraseCWT == TRUE )
    {
        mml_sc_calculate_wt(K_SCS_WT_INITIAL_WT);
    }
    /**  */
    dev->ucEraseCWT = TRUE;
    dev->ucEraseBWT = TRUE;
    dev->WTX = 1;
    dev->EDC = 1;
	dev->CWI = 13;
	dev->BWI = 4;
    dev->status &= ~MML_SCSTATUS_CONV_INVERSE;
    /* Register services */
    mml_sc_dev_register_service(mml_sc_vsr_power_up);
    /* Prepare buffer */
	mml_sc_memset((unsigned char*)atr, 0x00, *length);
    dev->rx_buf = atr;
    dev->rx_size = length;
    dev->rx_alloc = *length;
    *dev->rx_size = 0;
    /* Configure the digital part  */
    mml_sc_counter_etu_set();
    delay_micro(1);
    mml_sc_dev_set_conv();
    delay_micro(1);
    mml_sc_intr_mask_all();
    delay_micro(1);
/* _DBG_YG_ */
    scib_clear_all_status();
    delay_micro(1);
    /* inutile */
    /*mml_sc_intr_mask_parity_error(dev);*/
/*  */
    mml_sc_dev_disable_char_rep();
    delay_micro(1);
    dev->last_err = NO_ERROR;
    /* Cold reset */
    if ( dev->status & MML_SCSTATUS_CARD_NOT_POWERED )
    {
        mml_sc_dev_disable_uart();
        delay_micro(1);
        mml_sc_icc_set_io();
        delay_micro(1);
        mml_sc_dev_set_card_clk_sel();
        delay_micro(1);
        /*  */

        dev->last_err = mml_sc_analog_power_up((int)dev->power);
		if ( dev->last_err )
		{
			return dev->last_err;
		}

        /* Poll until the voltage is OK */
        do
        {
        	result = mml_sc_analog_check();
        	if ( result )
        	{
				mml_sc_analog_power_down();
		    	dev->last_err = result;
        		return result;
        	}
        	else if ( dev->status & MML_SCSTATUS_CARD_NOT_INSERTED )
		    {
				mml_sc_analog_power_down();
		    	dev->last_err = N_SCS_ERR_CARD_ABSENT;
		    	return dev->last_err;
		    }
			else
			{
				/* Decrease Security counter */
				dev->uiSecurityLoop--;
			}
        }
        while( ( dev->status & MML_SCSTATUS_CARD_NOT_POWERED ) && (dev->uiSecurityLoop) );
		/* Check Security counter */
		if ( !(dev->uiSecurityLoop) )
		{
			mml_sc_analog_power_down();
	    	dev->last_err = N_SCS_ERR_CARD_ABSENT;
	    	return dev->last_err;
		}

        /* Wait 40 000 cycles */
        dev->state = STATE_WAIT_40000_CYCLES;

        mml_sc_dev_enable_uart();
        delay_micro(1);
        /* 1 ETU is set in the Waiting Time counter because it
		 * corresponds roughly to 400 clock cycles */
        /*mml_sc_counter_start(dev, 1);*/

        mml_sc_counter_clk_start_man( 400);
/*  */
    }
    else /* Warm reset */
    {
        mml_sc_dev_disable_uart();
        delay_micro(1);
    	mml_sc_icc_set_io();
        delay_micro(1);
        dev->state = STATE_WAIT_BGT;
        /** Launch safety guard time */
        mml_sc_counter_start_bgt();
    } 

    dev->status |= MML_SCSTATUS_OPERATION_PENDING;

    /* Blocking function if no interrupt handler */
    if ( !dev->handlers[MML_SC_EVENT_ATR_RECEIVED] )
    {
         while ( dev->status & MML_SCSTATUS_OPERATION_PENDING );
    }       

    return dev->last_err;
}
