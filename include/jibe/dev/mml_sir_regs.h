/*
 * mml_sir_regs.h --
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2010, Maxim Integrated
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
 * THIS SOFTWARE IS PROVIDED BY MAXIM INTEGRATED ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* [INTERNAL] ------------------------------------------------------------------
 * Created on: December 20, 2010
 * Author: Gregory Romé <gregory.rome@maximintegrated.com>
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 2380     $:  Revision of last commit
 * $Author:: bryan.arms#$:  Author of last commit
 * $Date:: 2012-01-09 2#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#ifndef MML_SIR_REGS_H_
#define MML_SIR_REGS_H_

/** @file mml_sir_regs.h System Intialization Registers (SIR) Header */

/** @defgroup MML_SIR SIR Driver
 * @ingroup MML_DRIVER
 */

/** @defgroup MML_SIR_REGS System Intialization Registers
 *
 * @note Jibe Specification 0.0.1
 *
 * @ingroup MML_SIR
 * @{
 */

/** @defgroup MML_SIR_REGS_AR SIR A Register
 *
 * @li BF1 [2:0] - R/W: Bits field 1
 * @li BF2 [5] - R/W: Bits field 2
 * @li BF3 [6] - R/W: Bits field 3
 *
 * @{
 */

#define MML_SIR_AR_OFST	0x0	//!< A Register offset
#define MML_SIR_AR_DFLT	0x0	//!< A Register default value

/* Bits Fields */

#define MML_SIR_CONF_BF1_OFST		0	//!< BF1 offset
#define MML_SIR_CONF_BF2_OFST		5	//!< BF2 offset
#define MML_SIR_CONF_TRNGEN_OFST	6	//!< BF3 offset

#define MML_SIR_AR_BF1_MASK		0x7	//!< BF1 mask
#define MML_SIR_AR_BF2_MASK		0x1	//!< BF2 mask
#define MML_SIR_CONF_TRNGEN_MASK	(0x1 << MML_SIR_CONF_TRNGEN_OFST)	//!< TRNGEN mask

// SICFG.ROMSEL selects the ROM mode of Jibe
// 0 - Mudbug
// 1 - Flora
#define MML_SIR_CONF_ROMSEL_OFST 11
#define MML_SIR_CONF_ROMSEL_MASK_NOOFST 1
#define MML_SIR_CONF_ROMSEL_MASK (MML_SIR_CONF_ROMSEL_MASK_NOOFST << MML_SIR_CONF_ROMSEL_OFST)

// SICFG.CHIPMODE (SICFG[31:28]) selects hardware mode for Jibe
// 0000 - Jibe
// 0001 - Jibonda
#define MML_SIR_CONF_CHIPMODE_OFST 28
#define MML_SIR_CONF_CHIPMODE_MASK_NOOFST 0xf
#define MML_SIR_CONF_CHIPMODE_MASK (MML_SIR_CONF_CHIPMODE_MASK_NOOFST << MML_SIR_CONF_CHIPMODE_OFST)
#define MML_SIR_CONF_CHIPMODE_MML_NOOFST    0x0
#define MML_SIR_CONF_CHIPMODE_JIBE (MML_SIR_CONF_CHIPMODE_MML_NOOFST << MML_SIR_CONF_CHIPMODE_OFST)
#define MML_SIR_CONF_CHIPMODE_JIBONDA_NOOFST 0x1
#define MML_SIR_CONF_CHIPMODE_JIBONDA (MML_SIR_CONF_CHIPMODE_JIBONDA_NOOFST << MML_SIR_CONF_CHIPMODE_OFST)

/* Enumeration of the different value for a bits field . We recommend to use
 * human readable value. */

#define MML_SIR_AR_BF1_OPTION1		0x0	//!< BF1 value 1
#define MML_SIR_AR_BF1_OPTION2		0x3	//!< BF1 value 2
#define MML_SIR_AR_BF1_OPTION3		0x7	//!< BF1 value 3

/* We use the term enabled/disabled for bits field of size 1 */
#define MML_SIR_AR_BF2_ENABLED	0x1	//!< BF2 enabled == 1

#define MML_SIR_AR_BF3_DISABLED	0x1	//!< BF3 enabled == 0

/** @} */ /* @defgroup MML_SIR_REGS_AR */

/** @defgroup MML_SIR_REGS_BR SIR B Register
 * @{
 */

#define MML_SIR_BR_OFST	0x0	//!< B Register offset
#define MML_SIR_BR_DFLT	0x0	//!< A Register default value

/* Bits Fields */



/** @} */ /* @defgroup MML_SIR_REGS_BR */


#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */

/** SIR Registers.
 *
 */
typedef volatile struct _mml_sir_regs_{
	unsigned int	conf;		//!< Configuration Register
	unsigned int	status;		//!< Status Register
	unsigned int	error;		//!< Error Address Register
	unsigned int	rfu0[61];	//!< For alignment

	unsigned int	bbconf0;	//!< Battery Backed Shadow Register 0
	unsigned int	bbconf1;	//!< Battery Backed Shadow Register 0
	unsigned int	bbshr2;		//!< Battery Backed Shadow Register 2
	unsigned int	bbshr3;		//!< Battery Backed Shadow Register 3
	unsigned int	bbshr4;		//!< Battery Backed Shadow Register 4
	unsigned int	bbshr5;		//!< Battery Backed Shadow Register 5
	unsigned int	bbshr6;		//!< Battery Backed Shadow Register 6
	unsigned int	bbshr7;		//!< Battery Backed Shadow Register 7
	unsigned int	bbshr8;		//!< Battery Backed Shadow Register 7
	unsigned int	bbshr9;		//!< Battery Backed Shadow Register 7
	unsigned int	bbshr10;	//!< Battery Backed Shadow Register 7
	unsigned int	bbshr11;	//!< Battery Backed Shadow Register 7
	unsigned int	rfu1[52];	//!< For alignment
	unsigned int	shr0;		//!< Shadow Register 0
	unsigned int	shr1;		//!< Shadow Register 1
	unsigned int	shr2;		//!< Shadow Register 2
	unsigned int	shr3;		//!< Shadow Register 3
	unsigned int	shr4;		//!< Shadow Register 4
	unsigned int	shr5;		//!< Shadow Register 5
	unsigned int	shr6;		//!< Shadow Register 6
	unsigned int	shr7;		//!< Shadow Register 7
	unsigned int	shr8;		//!< Shadow Register 8
	unsigned int	shr9;		//!< Shadow Register 9
	unsigned int	shr10;		//!< Shadow Register 10 
	unsigned int	shr11;		//!< Shadow Register 11 
	unsigned int	shr12;		//!< Shadow Register 12 
	unsigned int	shr13;		//!< Shadow Register 13 
	unsigned int	shr14;		//!< Shadow Register 14 
	unsigned int	shr15;		//!< Shadow Register 15 
	unsigned int	shr16;		//!< Shadow Register 16 
	unsigned int	shr17;		//!< Shadow Register 17 
	unsigned int	shr18;		//!< Shadow Register 18 
	unsigned int	shr19;		//!< Shadow Register 19 
} mml_sir_regs_t;


#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_SIR_REGS */

#endif /* MML_SIR_REGS_H_ */
