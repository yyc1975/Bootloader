/*============================================================================
 *
 *      mml_sc_get_slot_info.c
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


/**
 * The function is used to retreive the working communication parameters.
 * 
 * @param[out] slot_info    Valid pointer to an initialized #mml_sc_slot_info_t 
 *                          structure. 
 * 
 * @retval NO_ERROR			No error
 * @retval N_SCS_ERR_NXIO        Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * 
 */
int mml_sc_get_slot_info( mml_sc_slot_info_t *slot_info )
{
	
    if ( !slot_info )
        return COMMON_ERR_INVAL;
    /* get power */
    slot_info->power = dev->power;
    /** Smart card protocol */
    slot_info->protocol = dev->protocol;
    /** speed communication parameter TA1 of ISO 7816-3*/
    slot_info->FIDI = dev->FIDI;
    /* Extra Guard time :parameter N of ISO 7816-3 */
    slot_info->EGT = dev->EGT;
    slot_info->WI = dev->WI;
    slot_info->WTX = dev->WTX;
    return NO_ERROR;
}
