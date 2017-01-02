/*============================================================================
 *
 *      mml_sc_pps_exchange.c
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
#include <mml_scs_counter.h>
#include <mml_scs_handler.h>
#include <mml_scs_analog.h>
#include <mml_scs_private.h>



void mml_sc_vsr_pps_exchange( int event );
void mml_sc_vsr_t1_block( int event );

/**
 * The functions sends a Protocol Parameter Selection (PPS) to a card, 
 * and retreives the response card . 
 * 
 * @param[in]   pps_request    Valid pointer to the send buffer
 * 
 * @param[out]  pps_response       Valid pointer to the card response
 * 
 * @param[in]   size_request size buffer in
 * 
 * @param[in,out] size_response in   : Valid pointer to the size buffer dataOut,
 *                          out : Valid pointer to the length of the response.
 * 
 * @retval NO_ERROR				No error
 * @retval N_SCS_ERR_NXIO       Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL     Invalid parameter.
 * @retval Other            	See \link Error_Codes Error Codes \endlink
 * 							or those from treatment PPS negotiation.
 *
 * @note The function is synchronous since a call to #mml_sc_attach() makes a 
 * the function asynchronous by returning immediatly without waiting the end 
 * of the operation.
 *  
 */
int mml_sc_pps_exchange( unsigned char *pps_request,
                          int size_request, 
                          unsigned char *pps_response,                          
                          unsigned int *size_response )
{
	int result;
  
    if ( !pps_request || !pps_response || !size_response )
    {
        return COMMON_ERR_INVAL;
    }
    /* Check if the device is initialized */  
    if ( !( dev->status & MML_SCSTATUS_INITIALIZED ) )
    {
        return N_SCS_ERR_NXIO;
    }

	result = mml_sc_analog_check();
	if ( result )
	{
			return result;
	}
	/* In cancel_transfer, there is the deselection */
	if ( dev->status & MML_SCSTATUS_CARD_NOT_INSERTED )
		dev->last_err = N_SCS_ERR_CARD_ABSENT;
	else if ( dev->status & MML_SCSTATUS_CARD_NOT_POWERED )
		dev->last_err = N_SCS_ERR_POWER_UP;
	else
		dev->last_err = NO_ERROR;

    if ( dev->last_err )
        return mml_sc_dev_cancel_transfer();

    mml_sc_counter_etu_set();
    mml_sc_dev_set_conv();
    mml_sc_dev_disable_char_rep();
    mml_sc_intr_unmask_parity_error();
    /* Set Guard Time */
    mml_sc_counter_set_gt();
    /* Initialize buffers */   
    dev->rx_buf = pps_response;
    dev->rx_alloc = *size_response;
    dev->rx_size = (unsigned int*)size_response;
    *dev->rx_size = 0;
    dev->tx_buf = pps_request;
    dev->tx_size = 0;
    /* Register services */
    mml_sc_dev_register_service(mml_sc_vsr_pps_exchange);
    dev->status &= ~MML_SCSTATUS_PARITY_ERROR;
    dev->status |= MML_SCSTATUS_OPERATION_PENDING;
    dev->state = STATE_PPS_RESPONSE_TS;

    if ( dev->ucEraseBWT == TRUE )
    	mml_sc_calculate_wt(K_SCS_WT_WORK_WT);

    if ( dev->ucEraseCWT == TRUE )
    	mml_sc_calculate_wt(K_SCS_WT_WORK_WT);
    /* Prepare to send the frame */
    mml_sc_dev_send_data(size_request);
    /* Ready to receive the frame header */
    mml_sc_dev_receive_data(3); /* PTSS + PTS0 + PCK default */
    /* Blocking function if no interrupt handler */

    if ( dev->handlers[MML_SC_EVENT_ATR_RECEIVED] == 0 ) 
    {
        while(dev->status & MML_SCSTATUS_OPERATION_PENDING);
    }     
        
    return dev->last_err;
}
