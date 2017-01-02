/*============================================================================
 *
 *      mml_sc_t1_block.c
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



void mml_sc_vsr_t1_block( int event );
extern volatile unsigned char	mml_sc_BGTCounterReception;

/**
 * This function may be used when for T=1 protocol exchanges when the 
 * application layer provides the complete T=1 frame including prologue, 
 * information and epilogue fields. The frame is passed to this function from 
 * address frame_in and is assumed to be \c len length. The function will send 
 * this frame to the smart card without any verification and will return 
 * the length of the received frame from the card.
 *
 * @param[in]   frame_in    Valid pointer to the send buffer
 * 
 * @param[out]  frame_out   Valid pointer to the card response
 * 
 * @param[in,out] length    in   : Valid pointer to the size buffer frame_in,
 *                          out  : Valid pointer to the length of the frame_out.
 * 
 * @retval NO_ERROR			No error
 * @retval N_SCS_ERR_NXIO        Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * @retval N_SCS_ERR_CARD_ABSENT	No card present.
 * @retval N_SCS_ERR_POWER_UP	Card not powered up.
 * @retval Other            See \link Error_Codes Error Codes \endlink
 * 							or those from communication.
 * 
 * @note The function is synchronous since a call to #mml_sc_attach() makes a 
 * the function asynchronous by returning immediatly without waiting the end 
 * of the operation.
 * 
 */                        
int mml_sc_t1_block( unsigned char *frame_in,
					  int length_in,
                      unsigned char *frame_out,
                      unsigned int *length_out )
{
    int							result;

    /* Check if the device is initialized */  
    if ( !( dev->status & MML_SCSTATUS_INITIALIZED ) )
    {
        result = N_SCS_ERR_NXIO;
        goto mml_sc_t1_block_out;
    }

    if ( ( frame_in == 0 ) ||
    	( frame_out == 0 ) ||
    	( length_out == 0 ) )
    {
        result = COMMON_ERR_INVAL;
        goto mml_sc_t1_block_out;
    }

 	result = mml_sc_analog_check();
	if ( result )
	{
		goto mml_sc_t1_block_out;
	}

	/* In cancel_transfer, there is the deselection */
	if ( dev->status & MML_SCSTATUS_CARD_NOT_INSERTED )
	{
		dev->last_err = N_SCS_ERR_CARD_ABSENT;
	}
	else if ( dev->status & MML_SCSTATUS_CARD_NOT_POWERED )
	{
		dev->last_err = N_SCS_ERR_POWER_UP;
	}
	else
	{
		dev->last_err = NO_ERROR;
	}

    if ( dev->last_err )
    {
        result = mml_sc_dev_cancel_transfer();
        if ( result )
        {
        	goto mml_sc_t1_block_out;
        }
        else
        {
        	result = dev->last_err;
        	goto mml_sc_t1_block_out;
        }
    }
    /**  */
    mml_sc_counter_etu_set();
    mml_sc_dev_set_conv();
    mml_sc_dev_disable_char_rep();
    mml_sc_intr_unmask_parity_error();
    /* Set Guard Time */
    mml_sc_counter_set_gt();
	/* set Waiting Time */
	if ( TRUE == dev->ucEraseCWT )
	{
		mml_sc_calculate_wt( K_SCS_WT_CHARACTER_WT);
	}
	if ( TRUE == dev->ucEraseBWT )
	{
		mml_sc_calculate_wt(K_SCS_WT_BLOCK_WT);
	}
    /* Initialize buffers */   
    dev->rx_buf = frame_out;
    dev->rx_alloc = *length_out;
    dev->rx_size = (unsigned int*)length_out;
    *dev->rx_size = 0;
    dev->tx_buf = frame_in;       
    dev->tx_size = 0;
    /* Register services */
    mml_sc_dev_register_service( mml_sc_vsr_t1_block);
    dev->status &= ~MML_SCSTATUS_PARITY_ERROR;
    dev->status |= MML_SCSTATUS_OPERATION_PENDING;
    dev->state = STATE_T1_PRE_BGT;
	/* Launch Block Guard Time */   
	/* Load the BGT */
	mml_sc_intr_mask_timeout();
	mml_sc_dev_wt_stop();
	mml_sc_dev_disable_uart();
	mml_sc_dev_wt_load(22);
	delay_micro(1);
	mml_sc_dev_wt_run();
	mml_sc_dev_enable_uart();
	mml_sc_intr_unmask_timeout();
	mml_sc_intr_unmask_rx();
	delay_micro(1);
	mml_sc_BGTCounterReception = 0;
	dev->tx_expected_txempty = length_in;
	dev->tx_expected_tx = length_in;
	dev->rx_expected = 3;
    /* Unselect dev if an error occured */
    if ( dev->last_err )
    {
    	/*result = dev->last_err;
    	goto mml_sc_t1_block_out;*/
    }
    /* Blocking function if no interrupt handler */
    if ( !dev->handlers[MML_SC_EVENT_DATA_RECEIVED] )
    {
         while( dev->status & MML_SCSTATUS_OPERATION_PENDING );
    }
    /**  */
    result = dev->last_err;
    /** We're done */
mml_sc_t1_block_out:
    return result;
}
