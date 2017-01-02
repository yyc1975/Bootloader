/*============================================================================
 *
 *      mml_sc_shutdown.c
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
#include <mml.h>
#include <mml_io.h>
#include <mml_intc_regs.h>

#include <mml_sc.h>

#include <mml_sc_dev.h>
#include <mml_scs_counter.h>                    

/**
 * The function shutdowns a Smart Card Interface.
 *  
 * @retval NO_ERROR				No error
 * @retval Other            	See \link Error_Codes Error Codes \endlink
 *							or mml_sc_power_down()'s ones.
 * 
 */
int mml_sc_shutdown( )
{
    int						result;

    /* Deactivate the ICC */
    result = mml_sc_power_down();
    if ( result )
    {
        goto mml_sc_shutdown_out;
    }
    /* Disable interrupts */
    //FIXME: SPFM....
   // mml_intc_enable_irq(SPFM(ios)->intc, dev->vnum);
   // mml_intc_dettach_irq(SPFM(ios)->intc, dev->vnum);
    /* Reset the context */
	mml_sc_memset((unsigned char*)dev, 0x00, sizeof(mml_sc_dev_t));
	result = NO_ERROR;

mml_sc_shutdown_out:
    return result;
}
