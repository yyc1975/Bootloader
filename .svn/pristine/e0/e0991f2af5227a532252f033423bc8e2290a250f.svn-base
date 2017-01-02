/*============================================================================
 *
 *      mml_sc_t0_out.c
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


void mml_sc_vsr_t0_out(int event );

/**
 * The function sends a T=0 outgoing command to a card, 
 * and retreives the response card, plus the status word SW1 SW2.
 * 
 * @param[in]    c_apdu   Valid pointer to a command APDU buffer 
 *                          {CLA,INS,P1,P2,Le}.
 * 
 * @param[out]   r_apdu   Valid pointer to the card response
 * 
 * @param[in,out] r_length    Valid pointer to the size of response buffer, 
 *                          updated with the number of bytes available 
 *                          in the response buffer.
 * 
 * @retval NO_ERROR				No error
 * @retval N_SCS_ERR_NXIO       Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL     Invalid parameter.
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
int mml_sc_t0_out( unsigned char *c_apdu,
                    unsigned char *r_apdu, unsigned int *r_length )
{
    int result;

    /* Check if the device is initialized */  
    if ( !( dev->status & MML_SCSTATUS_INITIALIZED ) )
        return N_SCS_ERR_NXIO;

    /* Check parameters */
    if ( ( c_apdu == 0 ) ||
    	( r_apdu == 0 ) ||
    	( r_length == 0 ) )
    {
        return COMMON_ERR_INVAL;
    }
    /* Check anomaly */
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
    /* Set timers */
    mml_sc_counter_etu_set();
    mml_sc_counter_set_gt();
    /* Set convention */
    mml_sc_dev_set_conv();
    mml_sc_dev_enable_char_rep();
    mml_sc_intr_unmask_parity_error();
    /* Initialize buffers */   
    dev->rx_buf = r_apdu;
    dev->rx_alloc = *r_length;
    dev->rx_size = (unsigned int*)r_length;
    *dev->rx_size = 0;
    dev->rx_expected = c_apdu[4];

    if ( !dev->rx_expected )
        dev->rx_expected = 256;
      
    dev->tx_buf = c_apdu;       
    dev->tx_size = 0;
    dev->status |= MML_SCSTATUS_OPERATION_PENDING;
    dev->state = STATE_T0_OUT_CHECK_PROC_BYTE;
    /**  */
    if ( dev->ucEraseBWT == TRUE )
    {
    	mml_sc_calculate_wt(K_SCS_WT_WORK_WT);
    }
    /**  */
    if ( dev->ucEraseCWT == TRUE )
    {
    	mml_sc_calculate_wt(K_SCS_WT_WORK_WT);
    }
    /* Register services */
    mml_sc_dev_register_service(mml_sc_vsr_t0_out);
    /* Prepare to send CLA INS P1 P2 Li */
    mml_sc_dev_send_data( 5);
    mml_sc_intr_unmask_rx();

    /* Blocking function if no interrupt handler */
    if ( !dev->handlers[MML_SC_EVENT_DATA_RECEIVED] )
    {
        while(dev->status & MML_SCSTATUS_OPERATION_PENDING);
        /* Unselect dev if an error occured */
    }
               
    return dev->last_err; 
}
