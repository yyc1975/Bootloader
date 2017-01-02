/*============================================================================
 *
 *      mml_sc_presence_card.c
 *
 *      
 *
 *==========================================================================*/
/*============================================================================
 * 
 * Copyright (c) 2002-2014 Maxim Integrated Products.
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
/** Global include */
#include <config.h>
#include <errors.h>
/** Other includes */
#include <mml_io.h>
#include <mml_sc.h>
/** Local includes */
#include <mml_sc_dev.h>
#include <mml_scs_analog.h>
#include <mml_scs_counter.h>
#include <mml_scs_handler.h>
#include <mml_sc_dev.h>
#include <mml_scs_private.h>


/**
 * The function
 */
int mml_sc_init_presence_card(void (*func)(int) )
{
    int											result = COMMON_ERR_UNKNOWN;

    /** Check if the device is initialized */
    if ( !( dev->status & MML_SCSTATUS_INITIALIZED ) )
    {
        result = N_SCS_ERR_NXIO;
    }
    /** Check if an operation is already pending */
    else if ( dev->status & MML_SCSTATUS_OPERATION_PENDING )
    {
      result = COMMON_ERR_ALREADY;
    }
    /** Check parameters */
    else if ( !func )
    {
       result = COMMON_ERR_INVAL;
    }
    else
    {
    	dev->esr = func;
    	/** No error */
    	result = NO_ERROR;
    }
    /** We're done */
    return result;
}
