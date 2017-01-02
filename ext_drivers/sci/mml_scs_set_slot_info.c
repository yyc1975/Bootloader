/*============================================================================
 *
 *      mml_sc_set_slot_info.c
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


void mml_sc_counter_set_cwt();

/**
 * The function is used to set the working communication parameters.
 * 
 * @param[in] slot_info     Valid pointer to an initialized #mml_sc_slot_info_t 
 *                          structure.
 * 
 * @retval NO_ERROR			No error
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * 
 */
int mml_sc_set_slot_info(mml_sc_slot_info_t *slot_info )
{
        
    if (slot_info == 0)
        return COMMON_ERR_INVAL;
    /* set power */
    dev->power = slot_info->power;
    /** Smart card protocol */
    dev->protocol = slot_info->protocol;
    /** speed communication parameter TA1 of ISO 7816-3 */
    if ( !slot_info->FIDI )
    	/* Default value is 0x11 */
    	dev->FIDI = 0x11;
    else
		dev->FIDI = slot_info->FIDI;
	/*Guard time :parameter N of ISO 7816-3*/
	/* Default value is 0 */
    dev->EGT = slot_info->EGT;

	if ( !slot_info->WI )
		dev->WI = 0x4d;
	else
		dev->WI = slot_info->WI;

	if ( dev->protocol == MML_SCPROTOCOL_T1 )
	{
		/* filtrage de CWI et BWI */
		dev->BWI = (dev->WI >> 4) & 0x0f;
		dev->CWI = 0x0f & dev->WI;
		if ( slot_info->WTX )
			dev->WTX = slot_info->WTX;
		else
			dev->WTX = 1;
	}
    return NO_ERROR;
}
