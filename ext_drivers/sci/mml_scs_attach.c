/*============================================================================
 *
 *      mml_sc_attach.c
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

/******************************************************************************/
/**
 * The function registers an interrupt handler for a type of event.
 *
 * @param[in] event     Event type. Possible values are the following: 
 *                          \li #MML_SC_EVENT_ATR_RECEIVED
 *                          \li #MML_SC_EVENT_DATA_RECEIVED
 *                          \li #MML_SC_EVENT_DATA_SENT
 *                          \li #MML_SC_EVENT_ERROR
 * 
 * @param[in] handler   Pointer to the interrupt handler function.
 * 
 * @retval NO_ERROR			No error
 * @retval N_SCS_ERR_NXIO       Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * @retval Other         Valid pointer of the previous handler for chosen event.
 * 
 */
int mml_sc_attach(int event, void (*handler)(int)) {
	int result = NO_ERROR;

	/* Check if the device is initialized */
	if (!(dev->status & MML_SCSTATUS_INITIALIZED))
		return N_SCS_ERR_NXIO;
	/* Check parameters */
	if ((event > (MML_SC_EVENT_COUNT - 1)) || !handler)
		return COMMON_ERR_INVAL;

	if (dev->handlers[event])
		result = (int) dev->handlers[event];

	dev->handlers[event] = handler;
	return result;
}
/******************************************************************************/
/* EOF */
