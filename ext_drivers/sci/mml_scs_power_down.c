/*============================================================================
 *
 *      mml_sc_power_down.c
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

/**
 * The function powers down a card.
 * 
 * 
 * @retval NO_ERROR				No error
 * @retval N_SCS_ERR_NXIO       Device not configured. Use mml_sc_init() first.
 * @retval Other            	See \link Error_Codes Error Codes \endlink.
 * 
 */        
int mml_sc_power_down()
{
    int							result;

    /* Check if the device is initialized */  
    if ( !( dev->status & MML_SCSTATUS_INITIALIZED ) )
    {
        return N_SCS_ERR_NXIO;
    }

    /* Power off SCIB */
    mml_sc_analog_card_reset( 0);

	mml_sc_dev_disable_uart();

	/** Flush both FIFOs */
	mml_sc_dev_flush_all();
	/** Disable IO line */
	mml_sc_icc_clear_io();

    result = mml_sc_analog_power_down();
    if ( result == NO_ERROR )
    {
		dev->status |= MML_SCSTATUS_CARD_NOT_POWERED;
		dev->status &= ~(MML_SCSTATUS_POWER_5V |
						MML_SCSTATUS_POWER_3V |
						MML_SCSTATUS_POWER_1_8V);
        mml_sc_intr_mask_all();
    }

    return result;     
}


int mml_sc_prepare_warmreset()
{
    int							result=NO_ERROR;

    /* Check if the device is initialized */
    if ( !( dev->status & MML_SCSTATUS_INITIALIZED ) )
    {
        return N_SCS_ERR_NXIO;
    }

    /* Power off SCIB */
    mml_sc_analog_card_reset( 0);
	mml_sc_dev_disable_uart();

	/** Flush both FIFOs */
	mml_sc_dev_flush_all();
	/** Disable IO line */
	mml_sc_icc_clear_io();

    mml_sc_intr_mask_all();

    return result;
}
