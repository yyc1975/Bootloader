/*============================================================================
 *
 *      mml_sc_handler.c
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



int mml_sc_handler_parity()
{
    if ( dev->protocol == MML_SCPROTOCOL_T0 )
    {
	    mml_sc_analog_card_reset(0);
		mml_sc_analog_power_down();
		dev->status |= MML_SCSTATUS_CARD_NOT_POWERED;
		dev->status &= ~(MML_SCSTATUS_POWER_5V |
						MML_SCSTATUS_POWER_3V |
						MML_SCSTATUS_POWER_1_8V);
        dev->last_err = N_SCS_ERR_PARITY;
    } 
    else
    {
        dev->status |= MML_SCSTATUS_PARITY_ERROR;
    }
   // lite_printf("ERR 62: %d",dev->last_err);
    return dev->last_err;
}

/*************************************************************************
 * Cet handler d'IT correspond � la fin de transimission du caract�re
 * vers la carte
 * Elle doit claquer en deuxi�me.
 * This IT handler indicates end of character transmission to the card.
 * It must raised in 2nd position
 * 
 ************************************************************************/
int mml_sc_handler_tx()
{


	/* Bug fixes #1138, #1139 */
	if ( !( dev->tx_expected_tx - 1 ) &&
		( dev->protocol == MML_SCPROTOCOL_T1 ) )
	{
		/* Load WT counter to check BWT */
		mml_sc_dev_wt_load(((dev->WTX * dev->bwt) + BWT_OFFSET_ERROR));
	}
	/*  */
	if ( dev->tx_expected_tx )
	{
		dev->tx_expected_tx--;
	}
	else
	{
	    mml_sc_intr_mask_tx();
	}
    return dev->tx_expected_tx;
}

/*************************************************************************
 * Cet handler d'IT correspond au vidage par le GemCore du registre
 * d'emission vers son module interne de s�rialisation
 * Elle doit claquer en premier.
 * This IT handler indicates that Gemcore transfered from its emitting register to
 * its internal serialisation module.
 * It must raised 1st ...
 ************************************************************************/
int mml_sc_handler_empty()
{

	if ( dev->tx_expected_txempty )
	{

dev->tx_expected_txempty--;
		mml_sc_dev_outb(dev->tx_buf[dev->tx_size++]);

	}
	else
	{
		/* Set mask for tx_empty in order to lighten normal tx */
		mml_sc_intr_mask_empty_buf();
		mml_sc_intr_unmask_timeout();
	}

    return dev->tx_expected_txempty;
}
