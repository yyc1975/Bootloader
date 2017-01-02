/*============================================================================
 *
 *      mml_sc_cancel.c
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
#include <mml_scs_handler.h>
#include <mml_scs_private.h>

/******************************************************************************/
/**
 * The function is used to cancel the current smart card transaction.
 *
 * 
 * @retval NO_ERROR			No error
 * @retval N_SCS_ERR_NXIO	Device not configured. Use mml_sc_init() first.
 * @retval Other            See \link Error_Codes Error Codes \endlink
 * 
 */
int mml_sc_cancel(void) {

	int result;

	/* Check if the device is initialized */
	if (!(dev->status & MML_SCSTATUS_INITIALIZED))
		return N_SCS_ERR_NXIO;

	/* Cancel operation */
	if ((result = mml_sc_dev_cancel_transfer()) == NO_ERROR) {
		dev->last_err = N_SCS_ERR_CMD_ABORTED;
		mml_sc_dev_call_handler(MML_SC_EVENT_ERROR);
	}

	return result;
}
/******************************************************************************/
/* EOF */
