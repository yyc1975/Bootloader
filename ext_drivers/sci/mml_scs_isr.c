/*============================================================================
 *
 *      mml_sc_isr.c
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
 * or non-infringement. Maxim Integrated Products shall not be liable for any damages suffered
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
#include "config.h"

#include <mml.h>

#include <mml_sc.h>

#include <mml_sc_dev.h>
#include <mml_scs_analog.h>
#include <mml_scs_counter.h>
#include <mml_scs_handler.h>


/** This function is call by interrupt when a event Tx or Rx */
void mml_sc_isr()
{
    register unsigned int IT_rised;

    /** Keep wanted ITs among the ones read */
	IT_rised = dev->reg_sc->sc_ier & dev->reg_sc->sc_isr;

	/** Ack IT with complement to 1 */
	dev->reg_sc->sc_isr = 0;

    /** If timeout */
    if ( IT_rised & BIT_WaitTimeout )
    {
        /** Call the vsr associated to the interrupt */
        mml_sc_dev_call_service(MML_SC_EVENT_TIMEOUT);
    }
    /** If counter */
    if ( IT_rised & BIT_Counter )
    {
    	/** Call the vsr associated to the interrupt */
    	mml_sc_dev_call_service(MML_SC_EVENT_COUNTER);
    }
    /** If it parity */
    if ( IT_rised & BIT_ErrParity )
    {
        /** Call the vsr associated to the interrupt */
        mml_sc_dev_call_service(MML_SC_EVENT_PARITY);
    }
    /** IF received byte */
    else if ( IT_rised & BIT_RxThreshold )
    {
        /** Call the vsr associated to the interrupt */
        mml_sc_dev_call_service(MML_SC_EVENT_RX);
    }

    /** If IT transmit buffer empty */
    if ( IT_rised & BIT_TxEmpty )
    {
        /** Call the vsr associated to the interrupt */
        mml_sc_dev_call_service(MML_SC_EVENT_EMPTY);
    }
    /** If IT transmit byte */
    if ( IT_rised & BIT_Tx )
    {
        /** Call the vsr associated to the interrupt */
        mml_sc_dev_call_service( MML_SC_EVENT_TX);
    }
    /** If IT Presence Card */
    if ( IT_rised & BIT_PresenceCard )
    {
        /** Call the esr associated to the interrupt */
	if (dev->esr)
	    dev->esr(dev->reg_sc->sc_sr & MML_SC_SR_PRES_MASK);
    }
    /** We're done */
    return;
}


