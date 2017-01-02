/*============================================================================
 *
 *      mml_sc_clock.c
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
#include <mml_gcr_regs.h>
#include <mml.h>
#include <mml_sc.h>
#include <mml_sc_dev.h>
#include <mml_scs_clock.h>

mml_gcr_regs_t				*gcr_reg = (mml_gcr_regs_t*)MML_GCR_IOBASE;

#define SCCK_DIVIDER_SHIFT 6
#define SCCK_DIVIDER_MASK 0x3F


int mml_sc_set_clock(int clock)
{
    unsigned int mask, data;
    //unsigned int shift_fact = (dev->ucSCIB==N_MML_SC_DEV0)?0:1;
    unsigned int shift_fact = 0;
	if ( !clock )
	{
		return COMMON_ERR_INVAL;
	}

    data = gcr_reg->scck;
    mask = (SCCK_DIVIDER_MASK)<<(shift_fact * SCCK_DIVIDER_SHIFT);
    data &= ~mask;

    mask = clock << (shift_fact * SCCK_DIVIDER_SHIFT);
     /* Update GCR */
   gcr_reg->scck = (data | mask);

    /** We're done */
	return NO_ERROR;
}
/******************************************************************************/
/* EOF */
