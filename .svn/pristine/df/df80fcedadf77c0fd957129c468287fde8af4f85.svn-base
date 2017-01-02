/*============================================================================
 *
 *      mml_sc_get_status.c
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
 * The function provides the current state of a Smart Card Interface. 
 * It returns information indicating :
 *  \li The power supply value
 *  \li Card presence
 *  \li The card power status 
 *  \li The communication protocol (T=0 or T=1)
 * 
 * @param[out] status   Receives the current state of the Smart Card Interface. 
 *                      Upon success, it receives a combinaison of the following 
 *                      state indicators: 
 *                          \li #MML_SCSTATUS_POWER_5V 
 *                          \li #MML_SCSTATUS_POWER_3V             
 *                          \li #MML_SCSTATUS_CARD_NOT_POWERED     
 *                          \li #MML_SCSTATUS_CARD_POWERED         
 *                          \li #MML_SCSTATUS_CARD_NOT_INSERTED    
 *                          \li #MML_SCSTATUS_CARD_INSERTED        
 *                          \li #MML_SCSTATUS_PROTOCOL_T0         
 *                          \li #MML_SCSTATUS_PROTOCOL_T1 
 *  
 * @retval NO_ERROR			No error 
 * @retval N_SCS_ERR_NXIO       Device not configured. Use mml_sc_init() first.
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * @retval Other            See \link Error_Codes Error Codes \endlink
 * 
 */
int mml_sc_get_status(int *status) {
	int tmp;
	int result;

	/* Check if the device is initialized */
	if (!(dev->status & MML_SCSTATUS_INITIALIZED))
		return N_SCS_ERR_NXIO;
	/* Check parameter */
	if (!status)
		return COMMON_ERR_INVAL;

	/* Get card presence status */
	*status = 0;
	tmp = 0;
	result = mml_sc_ioctl(N_SCS_IOCTL_CHECK_CARD_PRESENCE, &tmp);
	if (result)
		return result;

	if (tmp & MML_SCSTATUS_CARD_NOT_INSERTED)
		dev->status |= MML_SCSTATUS_CARD_NOT_INSERTED;
	else
		dev->status &= ~MML_SCSTATUS_CARD_NOT_INSERTED;

	*status = tmp;
	/* Get card power status */
	result = mml_sc_ioctl(N_SCS_IOCTL_CHECK_VOLT_OK, &tmp);
	if (result)
		return result;

	if (tmp & MML_SCSTATUS_CARD_NOT_POWERED)
		dev->status |= MML_SCSTATUS_CARD_NOT_POWERED;
	else
		dev->status &= ~MML_SCSTATUS_CARD_NOT_POWERED;

	*status |= tmp;
	/* Get power supply value */
	*status |= dev->power;
	/* Get protocol value */
	*status |= dev->protocol;
	return result;
}
