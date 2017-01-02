/*============================================================================
 *
 *      mml_sc_counter.c
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
#include <mml_scs_counter.h>

const unsigned short mml_sc_ftab[16] = { 372, 372, 558, 744, 1116, 1488, 1860,
		0, 0, 512, 768, 1024, 1536, 2048, 0, 0 };

const unsigned char mml_sc_dtab[16] = { 0, 1, 2, 4, 8, 16, 32, 64, 12, 20, 0,
		0, 0, 0, 0, 0 };

/******************************************************************************/
int mml_sc_calculate_wt(unsigned int timer) {

	unsigned int ucD_tmp = 0;
	unsigned int uiF_tmp = 0;
	unsigned int etu;

	ucD_tmp = mml_sc_dtab[(dev->FIDI & 0x0F)];
	uiF_tmp = mml_sc_ftab[((dev->FIDI >> 4) & 0x0F)];
	/* WT value has to be set from ISO */
	switch (timer) {
	case K_SCS_WT_WORK_WT:
		/* ISO -> WWT = 960 * D * WI */
		etu = 960 * ucD_tmp * dev->WI;
		dev->cwt = dev->bwt = etu;
		break;
	case K_SCS_WT_CHARACTER_WT:
		/* ISO -> CWT = 11 + 2^CWI */
		etu = 11;
		etu += ((unsigned int) 1 << dev->CWI);
		dev->cwt = etu;
		break;
	case K_SCS_WT_BLOCK_WT:
		/* ISO -> BWT = 11 + 960 * 372 * 2^BWI * DI / FI */
		etu = 357120 * ucD_tmp;
		etu /= uiF_tmp;
		etu *= ((unsigned int) 1 << dev->BWI);
		etu += 11;
		dev->bwt = etu;
		break;
	case K_SCS_WT_INITIAL_WT:
		/* ISO -> 9600 etus - CWT for ATR */
		dev->cwt = 9600;
		break;
	case K_SCS_WT_START_ATR:
		/* ISO -> 40000 clock cycles for ATR to begin */
		dev->bwt = ISO_40000_CYCLE;
		break;
	case K_SCS_WT_UNKNOWN_WT:
	default:
		/* Default value */
		return COMMON_ERR_INVAL;
	}
	return NO_ERROR;
}
/******************************************************************************/

/******************************************************************************/
/** _DBG_YG_ */
void mml_sc_counter_clk_start_man(unsigned int count) {
	/** Mask clock counter interrupt */
	mml_sc_intr_mask_clk_counter();
	/** Stop previous clock count */
	mml_sc_dev_counter_clk_stop();
	delay_micro(1);
	/** Load new clock count value */
	mml_sc_dev_counter_clk_load_man(count);
	delay_micro(2);
	/** Unmask clock counter interrupt */
	mml_sc_intr_unmask_clk_counter();
	/** Launch clock count */
	mml_sc_dev_counter_clk_run();
	delay_micro(1);
	/** We're done */
	return;
}

/******************************************************************************/
void mml_sc_counter_clk_start(unsigned int count) {
	/** Mask clock counter interrupt */
	mml_sc_intr_mask_clk_counter();
	/** Stop previous clock count */
	mml_sc_dev_counter_clk_stop();
	delay_micro(1);
	/** Load new clock count value */
	mml_sc_dev_counter_clk_load(count);
	/** Wait few card clock cycles */
	delay_micro(2);
	/** Unmask clock counter interrupt */
	mml_sc_intr_unmask_clk_counter();
	/** Launch clock count */
	mml_sc_dev_counter_clk_run();
	delay_micro(1);
	/** We're done */
	return;
}
/*  */

/******************************************************************************/
void mml_sc_counter_start(unsigned int etu) {
	/** Mask timeout */
	mml_sc_intr_mask_timeout();
	/** Stop previous timeout */
	mml_sc_dev_wt_stop();
	delay_micro(1);
	/** Load new timeout */
	mml_sc_dev_wt_load(etu);
	delay_micro(2);
	/** Unmask timeout */
	mml_sc_intr_unmask_timeout();
	/** Launch timeout */
	mml_sc_dev_wt_run();
	delay_micro(1);
	/** We're done */
	return;
}

/******************************************************************************/
void mml_sc_counter_start_bgt() {
	unsigned int etu = mml_sc_counter_get_bgt();

	mml_sc_counter_start(etu);
	delay_micro(1);
	/** We're done */
	return;
}

/******************************************************************************/
/** this function stop clock counter */
void mml_sc_counter_clk_halt_man() {
	/** Mask clock counter */
	mml_sc_intr_mask_clk_counter();
	mml_sc_dev_counter_clk_clr_man();
	delay_micro(1);
	/** Disable CCR bit in CR */
	mml_sc_dev_counter_clk_stop();
	delay_micro(1);
	/** We're done */
	return;
}

/******************************************************************************/
void mml_sc_counter_clk_halt() {
	/** Mask clock counter */
	mml_sc_intr_mask_clk_counter();
	delay_micro(1);
	/** Disable CCR bit in CR */
	mml_sc_dev_counter_clk_stop();
	delay_micro(1);
	return;
}

/******************************************************************************/
/** this function stop timer etu */
void mml_sc_counter_halt() {
	mml_sc_intr_mask_timeout();
	delay_micro(1);
	mml_sc_dev_wt_stop();
	delay_micro(1);
	return;
}

/******************************************************************************/
void mml_sc_counter_set_gt() {

	unsigned short gt = 12;

	if ((dev->protocol == MML_SCPROTOCOL_T1) && (dev->EGT == 0xFF)) {
		gt--;
	} else if (dev->EGT != 0xFF) {
		gt += (unsigned short) dev->EGT;
	}
	/* set block guard time for the next transmission */
	mml_sc_dev_gt_load(gt);
	delay_micro(1);
	return;
}

/******************************************************************************/
unsigned int mml_sc_counter_get_bgt() {

	unsigned int bgt = 12;

	if (dev->protocol == MML_SCPROTOCOL_T1) {
		bgt += 10;
	} else if (dev->EGT != 0xFF) {
		bgt += dev->EGT;
	}

	return bgt;
}

/******************************************************************************/
void mml_sc_counter_etu_set() {

	unsigned char di;
	unsigned short fi;
	unsigned int etu;
	unsigned char fidi = dev->FIDI;

	di = mml_sc_dtab[fidi & 0x0F];
	fi = mml_sc_ftab[fidi >> 4];
	etu = fi / di;
	mml_sc_dev_etu_load(etu);
	mml_sc_dev_clear_etu_comp();

	if ((fi % di) > (di / 2)) {
		mml_sc_dev_set_etu_comp();
	}
	return;
}
