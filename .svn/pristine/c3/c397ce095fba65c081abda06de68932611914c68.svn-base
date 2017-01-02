/*============================================================================
 *
 *      mml_sc_get_ioctl.c
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
/** Global includes */
#include <errors.h>
/** Other includes */
#include <mml_sc.h>
/** Local includes */
#include <mml_sc_dev.h>
#include <mml_scs_counter.h>
#include <mml_scs_private.h>


extern const unsigned short mml_sc_ftab[];
extern const unsigned char mml_sc_dtab[];
/**
 * The function performs Smart Card Interface specific control functions.
 * 
 * @param[in]     cmd   Requested control function. Possible values are:
 *                          \li N_SCS_IOCTL_RESET
 *                          \li N_SCS_IOCTL_POWER_UP
 *                          \li N_SCS_IOCTL_POWER_DOWN
 *                          \li N_SCS_IOCTL_SELECT
 *                          \li N_SCS_IOCTL_UNSELECT
 *                          \li N_SCS_IOCTL_CHECK_VOLT_OK
 *                          \li N_SCS_IOCTL_CONFIG_POWER
 *                          \li N_SCS_IOCTL_CHECK_CARD_PRESENCE
 *                          \li N_SCS_IOCTL_CARD_RESET
 *                          \li N_SCS_IOCTL_WHICHSELECTED
 *                          \li N_SCS_IOCTL_SET_CARDIO
 *                          \li N_SCS_IOCTL_SET_CARDRESET
 *                          \li N_SCS_IOCTL_SET_CARDCLK
 *                          \li N_SCS_IOCTL_SET_SPEED
 *                          \li N_SCS_IOCTL_SET_GUARD_TIME
 *                          \li N_SCS_IOCTL_SET_WAITING_TIME
 *                          \li N_SCS_IOCTL_SET_CWT
 *                          \li N_SCS_IOCTL_SET_BWT
 *                          \li N_SCS_IOCTL_GET_CWT
 *                          \li N_SCS_IOCTL_GET_BWT
 *                          \li N_SCS_IOCTL_CARD_WITHDRAWN
 *                          \li N_SCS_IOCTL_SET_MODE_AUTO
 *                          \li N_SCS_IOCTL_SET_CARDC4
 *                          \li N_SCS_IOCTL_SET_CARDC8
 *                          \li N_SCS_IOCTL_SET_CARDVCC
 *                          \li N_SCS_IOCTL_GET_CARDIO
 *                          \li N_SCS_IOCTL_GET_CARDRESET
 *                          \li N_SCS_IOCTL_GET_CARDCLK
 *                          \li N_SCS_IOCTL_GET_CARDC4
 *                          \li N_SCS_IOCTL_GET_CARDC8
 *                          \li N_SCS_IOCTL_GET_CARDVCC
 *                          \li N_SCS_IOCTL_SECURITY_LOOP
 * Not implemented in mml_sc_ioctl() neither in <chipset>_ioctl()
 *                          \li N_SCS_IOCTL_ATTACH_CARD_MOVED
 * 
 * @param[in,out] data  Points to a buffer that contains any data required for 
 *                      the given control function or receives data from 
 *                      that function.
 *
 * @retval NO_ERROR			No error
 * @retval COMMON_ERR_INVAL       Invalid parameter.
 * @retval Other            See \link Error_Codes Error Codes \endlink
 * 
 */
int mml_sc_ioctl( int cmd, void *param)
{
    int											result = COMMON_ERR_NO_DEV;
    register unsigned int						tmp;
    register unsigned int						i;



    //while(mml_sc_dev_get_card_activ(dev)==0);
    /* Check device identifier */
    if ( !dev  )
    {
        goto mml_sc_ioctl_out;
    }
    /**  */
    switch( cmd )
    {
    	case N_SCS_IOCTL_RESET:
    		break;
    	case N_SCS_IOCTL_POWER_UP:
    		mml_sc_dev_set_power((int)param);
    		/**  */
    		i = 0;
    		do
    		{
    		        mml_sc_dev_set_start();
    		        while( mml_sc_dev_get_card_activ() == 0 );
    		        i++;

    		} while ( ( mml_sc_dev_get_start() == 0 ) || ( i < 1500 ) );
    		/** Fix from Frank L. */
    		mml_sc_dev_clear_prc_error();
    		if ( 15 == i )
    		{
    		    result = COMMON_ERR_BAD_STATE;
    		    goto mml_sc_ioctl_out;
    		}
    		break;
    	case  N_SCS_IOCTL_POWER_DOWN:
    		mml_sc_dev_clear_start();
    		while(mml_sc_dev_get_card_activ()==0);
    		break;
    	case  N_SCS_IOCTL_SELECT:
    		break;
    	case  N_SCS_IOCTL_UNSELECT:
    		break;
    	case  N_SCS_IOCTL_CHECK_VOLT_OK:
    		if( mml_sc_dev_get_start() == MML_SC_CR_START_MASK )
    		{
    			*((int *)(param))= MML_SCSTATUS_CARD_POWERED;
    	    }
    		else
    		{
    	    	*((int *)(param))=MML_SCSTATUS_CARD_NOT_POWERED;
    	    }
    		break;
    	case  N_SCS_IOCTL_CONFIG_POWER:
    		break;
    	case  N_SCS_IOCTL_CHECK_CARD_PRESENCE:
    		if( mml_sc_dev_get_card_pres() == MML_SC_SR_PRES_MASK )
    		{
    			*((int *)(param))= MML_SCSTATUS_CARD_INSERTED;
    		}
    		else
    		{
    			*((int *)(param))=MML_SCSTATUS_CARD_NOT_INSERTED;
    		}
    		break;
    	case  N_SCS_IOCTL_CARD_RESET:
    	  if ( param )
    	  {
    		  delay_micro(1);
    	      mml_sc_icc_set_rst();
    	      delay_micro(2);
    	  }
    	  else
    	  {
    		  delay_micro(1);
    	      mml_sc_icc_clear_rst();
    	      delay_micro(2);
    	  }
    	  break;
    	case  N_SCS_IOCTL_WHICHSELECTED:
    	   	break;
        case N_SCS_IOCTL_SET_CARDIO :
            if ( param )
            {
                mml_sc_icc_set_io();
                delay_micro(1);
            }
            else
            {
                mml_sc_icc_clear_io();
                delay_micro(1);
            }
            break;
        case N_SCS_IOCTL_SET_CARDRESET :
            if ( param )
            {
                delay_micro(1);
            	mml_sc_icc_set_rst();
                delay_micro(2);
            }
            else
            {
                delay_micro(1);
                mml_sc_icc_clear_rst();
                delay_micro(2);
            }
            break;            
        case N_SCS_IOCTL_SET_SPEED :    
            /* speed communication parameter TA1 of ISO 7816-3 */
            dev->FIDI = (unsigned int) param;
            break;
        case N_SCS_IOCTL_SET_GUARD_TIME :    
            /* Extra Guard time : parameter N of ISO 7816-3 */
            dev->EGT = (unsigned int) param;
            break;
        case N_SCS_IOCTL_SET_WAITING_TIME :    
            /* Waiting Time : parameter WI of ISO 7816-3 */
            dev->WI = (unsigned int) param;
            break;
        case N_SCS_IOCTL_SET_CWT :    
            /* Character Waiting Time */
            dev->cwt = (unsigned int) param;
			dev->ucEraseCWT = FALSE;
            break;
        case N_SCS_IOCTL_SET_BWT :    
            /* Block Waiting Time */
            dev->bwt = (unsigned int) param;
			dev->ucEraseBWT = FALSE;
            break; 
        case N_SCS_IOCTL_GET_CWT :    
            /* Character Waiting Time */
            *((unsigned int *) param) = dev->cwt;
            break;
        case N_SCS_IOCTL_GET_BWT :    
            /* Block Waiting Time */
            *((unsigned int *) param) = dev->bwt;
            break; 
        case N_SCS_IOCTL_CARD_WITHDRAWN :   
            dev->last_err = N_SCS_ERR_CARD_ABSENT; 
            result = mml_sc_dev_cancel_transfer();
            goto mml_sc_ioctl_out;
        /* --------------------------------------------------------------------
         * PATCH 
         * 
         * The following section is added to manage synchronous card
         *  
         * -------------------------------------------------------------------*/    
            
        case N_SCS_IOCTL_SET_MODE_AUTO :
            if ( param )
            {
                mml_sc_dev_clear_card_clk_sel();
                mml_sc_dev_enable_uart();
                delay_micro(1);
            }
            else
            {
                mml_sc_dev_disable_uart();
                mml_sc_dev_clear_card_clk_sel();
                delay_micro(1);
            }
            break;
        case N_SCS_IOCTL_SET_CARDCLK :
            if ( param )
            {
                mml_sc_icc_set_clk();
                delay_micro(1);
            }
            else
            {
                mml_sc_icc_clear_clk();
            }
            break;
        case N_SCS_IOCTL_SET_CARDC4 :
            if ( param )
            {
                mml_sc_icc_set_c4();
            }
            else
            {
                mml_sc_icc_clear_c4();
            }
            break;
        case N_SCS_IOCTL_SET_CARDC8 :
            if ( param )
            {
                mml_sc_icc_set_c8();
            }
            else
            {
                mml_sc_icc_clear_c8();
            }
            break;
        case N_SCS_IOCTL_SET_CARDVCC :
        case N_SCS_IOCTL_GET_CARDVCC :
            break;    
        case N_SCS_IOCTL_GET_CARDCLK :
            if ( param )
            {
            	*(int *)param = (int) mml_sc_icc_get_clk();
            }
            break;  
        case N_SCS_IOCTL_GET_CARDRESET :
            if ( param )
            {
            	*(int *)param = (int) mml_sc_icc_get_rst();
            }
            break;      
        case N_SCS_IOCTL_GET_CARDIO :
            if ( param )
            {
            	*(int *)param = (int) mml_sc_icc_get_io();
            }
            break;
        case N_SCS_IOCTL_GET_CARDC4 :
            if ( param )
            {
            	*(int *)param = (int) mml_sc_icc_get_c4();
            }
            break;
        case N_SCS_IOCTL_GET_CARDC8 :
            if ( param )
            {
            	*(int *)param = (int) mml_sc_icc_get_c8();
            }
            break;
        case N_SCS_IOCTL_SECURITY_LOOP:
        	if ( param )
        	{
        		dev->uiSecurityLoop = (unsigned int) param;
        	}
        	else
        	{
        		dev->uiSecurityLoop = MML_SCDEFAULT_SEC_LOOP_VALUE;
        	}
        	break;
        case N_SCS_IOCTL_LAUNCH_CLK_COUNTER:
        	/** Check input parameter */
        	if ( !param )
        	{
        		result = COMMON_ERR_INVAL;
        		goto mml_sc_ioctl_out;
        	}
        	/** Verify that handler is attached to event */
        	if ( !dev->handlers[MML_SC_EVENT_CLOCK_COUNTER] )
        	{
        		result = N_SCS_ERR_NO_SYS;
        		goto mml_sc_ioctl_out;
        	}
        	/** Compute clock value from ETU value */
        	tmp = ((unsigned int)param) * mml_sc_ftab[(dev->FIDI >> 4) & 0x0f];
			/** Check is value is not too large */

			if ( MML_SC_CCR_CCYC_MASK_NOOFST < (tmp / mml_sc_dtab[dev->FIDI & 0x0f]) )
			{
				result = COMMON_ERR_INVAL;
				goto mml_sc_ioctl_out;
			}
        	/** Then launch manually clock counter */
			mml_sc_counter_clk_start_man((tmp / mml_sc_dtab[dev->FIDI & 0x0f]));
        	break;
        case N_SCS_IOCTL_HALT_CLK_COUNTER:
        	/** Halt clock counter */
        	mml_sc_counter_clk_halt_man();
        	break;
        default:
            result = COMMON_ERR_INVAL;
            goto mml_sc_ioctl_out;
    }
    result = NO_ERROR;
    /** We're done */
mml_sc_ioctl_out:
    return result;
}
