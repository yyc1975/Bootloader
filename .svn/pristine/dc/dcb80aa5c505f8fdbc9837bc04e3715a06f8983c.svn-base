/*
 * mml_smon.c --
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2013, Maxim Integrated Products
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MAXIM INTEGRATED PRODUCTS ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL MAXIM INTEGRATED PRODUCTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* [INTERNAL] ------------------------------------------------------------------
 * Created on: Oct 11, 2013
 * Author: Yann G. <yann.gaude@maximintegrated.com>
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: $: Revision of last commit
 * $Author:: $: Author of last commit
 * $Date:: $: Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

/** @file mml_smon.c SMON core driver */
/** Global includes */
#include <config.h>
#include <errors.h>
/** Other includes */
#include <mml_io.h>
#include <mml.h>
/** Local includes */
#include <mml_smon.h>
#include <mml_smon_regs.h>





#ifdef _STAND_ALONE_DRIVER_SMON_
/* This compilation flag is activated only in driver development context
* without any application using it.
* DO NOT define it in application/test context then. */
/******************************************************************************/
int main(void)
{
	/** We're done */
	return NO_ERROR;
}
#endif /* _STAND_ALONE_DRIVER_SMON_ */
/******************************************************************************/
/** Set value to SECALM register
 *
 * @param reg	Value to set in SECALM register
 *
 */
inline void mml_smon_setsecalm(unsigned int reg)
{
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	reg_smon->secalm |= reg;
	/** We're done */
	return;
}

/******************************************************************************/
/** Write value to SECALM register
 *
 * @param reg	Value of SECALM register to be written
 *
 */
inline void mml_smon_writesecalm(unsigned int reg)
{
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	reg_smon->secalm = reg;
	/** We're done */
	return;
}

/******************************************************************************/
/** Read value from SECALM register
 *
 * @param *reg	Pointer on read SECALM register value
 *
 */
inline void mml_smon_readsecalm(unsigned int *reg)
{
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	/** Check input pointer */
	if ( reg )
	{
		*reg = reg_smon->secalm;
	}
	/** We're done */
	return;
}

/******************************************************************************/
/** Set value to SECALM register
 *
 * @param reg	Value to remove from SECALM register
 *
 */
inline void mml_smon_clearsecalm(unsigned int reg)
{
	unsigned int								tmp;
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	tmp = reg_smon->secalm;
	tmp &= ~reg;
	reg_smon->secalm &= tmp;
	/** We're done */
	return;
}

/******************************************************************************/
/** Read value from SECDIAG register
 *
 * @param *reg	Pointer on read SECDIAG register value
 *
 */
inline void mml_smon_readsecdiag(unsigned int *reg)
{
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	/** Check input pointer */
	if ( reg )
	{
		*reg = reg_smon->secdiag;
	}
	/** We're done */
	return;
}

/******************************************************************************/
/** Read value from DLRTC register
 *
 * @param *reg	Pointer on read DLRTC register value
 *
 */
inline void mml_smon_readdlrtc(unsigned int *reg)
{
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	/** Check input pointer */
	if ( reg )
	{
		*reg = reg_smon->dlrtc;
	}
	/** We're done */
	return;
}

/******************************************************************************/
/** Read value from EXTSCN register
 *
 * @param *reg	Pointer on read EXTSCN register value
 *
 */
inline void mml_smon_readextscn(unsigned int *reg)
{
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	/** Check input pointer */
	if ( reg )
	{
		*reg = reg_smon->extscn;
	}
	/** We're done */
	return;
}

/******************************************************************************/
/** Read value from INTSCN register
 *
 * @param *reg	Pointer on read INTSCN register value
 *
 */
inline void mml_smon_readintscn(unsigned int *reg)
{
	volatile mml_smon_regs_t					*reg_smon = (volatile mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	/** Check input pointer */
	if ( reg )
	{
		*reg = reg_smon->intscn;
	}
	/** We're done */
	return;
}

/******************************************************************************/
void mml_External_Sensor_Config(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;
	//wait for SecMon busy bit clear
	while(SecMon_Reg->extscn & MML_SMON_EXTSCN_BUSY_MASK);

	// Unlock External Sensor Control Register
	// SecMon_Reg->extscn &= (~MML_SMON_EXTSCN_LOCK_MASK);

	//wait for SecMon busy bit clear
	// while(SecMon_Reg->extscn & MML_SMON_EXTSCN_BUSY_MASK);
    
    

	//DIVCLK = 1,EXTFRQ = 2,EXTCNT = 1
	SecMon_Reg->extscn |= ((1 << MML_SMON_EXTSCN_DIVCLK_OFST) \
			| (2 << MML_SMON_EXTSCN_EXTFRQ_OFST) | (1 << MML_SMON_EXTSCN_EXTCNT_OFST));

	// check if there is alarm flag raised, if so, clear them
	if(SecMon_Reg->secalm & MML_SMON_SECALM_EXSTAT_MASK)
	{
		SecMon_Reg->secalm &=  ~(MML_SMON_SECALM_EXSTAT_MASK | 
                                 MML_SMON_SECALM_EXTF_MASK);
	}

	// check if there is alarm warning flag raised, if so, clear them
	if(SecMon_Reg->secalm & MML_SMON_SECALM_EXTSWARN_MASK)
	{
		SecMon_Reg->secalm &=  (~MML_SMON_SECALM_EXTSWARN_MASK);
	}

	//wait for SecMon busy bit clear
	while(SecMon_Reg->extscn & MML_SMON_EXTSCN_BUSY_MASK);
    
    //wait for SecMon alarm warning bit0 to clear
    while(SecMon_Reg->secalm & MML_SMON_SECALM_EXTSWARN_MASK);

	//ENABLE Sensor 0
	SecMon_Reg->extscn |= 0x003F;

	//wait for SecMon busy bit clear
	while(SecMon_Reg->extscn & MML_SMON_EXTSCN_BUSY_MASK);

	//lock External Sensor Control Register
	SecMon_Reg->extscn |= MML_SMON_EXTSCN_LOCK_MASK;
}

void mml_Enable_Shield_sensor(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;
    //ENABLE Sensor 0
	SecMon_Reg->intscn |= MML_SMON_INTSCN_SHIELD_EN_MASK;
}
void mml_Enable_Temp_sensor(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;
    //ENABLE Sensor 0
	SecMon_Reg->intscn |= MML_SMON_INTSCN_TEMP_EN_MASK;
}
void mml_Enable_Vbat_sensor(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;
    //ENABLE Sensor 0
	SecMon_Reg->intscn |= MML_SMON_INTSCN_VBAT_EN_MASK;
}
void mml_Enable_Vdd_low_detect(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;
    //ENABLE Sensor 0
	SecMon_Reg->intscn |= MML_SMON_INTSCN_VIOLOEN_MASK;
}
void mml_Enable_Vdd_high_detect(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;
    //ENABLE Sensor 0
	SecMon_Reg->intscn |= MML_SMON_INTSCN_VIOHIEN_MASK;
}
void mml_lock_internel_sensor_control(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;

	SecMon_Reg->intscn |= MML_SMON_INTSCN_LOCK_MASK;
}
/******************************************************************************/
void mml_clear_all_alarm(void)
{
    mml_smon_regs_t *SecMon_Reg = (mml_smon_regs_t*)MML_SEC_MON_IOBASE;
    
    SecMon_Reg->secalm = 0;
}

/******************************************************************************/
/* EOF */
