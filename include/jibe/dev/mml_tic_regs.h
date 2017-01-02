/*
 * mml_tic_regs.h --
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
 * Created on: June 8, 2010
 * Author: Gregory Romé <gregory.rome@maximintegrated.com>
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 778      $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2010-11-18 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#ifndef MML_TIC_REGS_H_
#define MML_TIC_REGS_H_

/** @file mml_wdt_regs.h WDT Registers Header */

/** @defgroup MML_WDT WDT Driver
 * @ingroup MML_DRIVER
 */

/** @defgroup MML_WDT_REGS WDT Registers
 *
 * @note WDT IP or Specification version number
 *
 * @ingroup MML_WDT
 * @{
 */

/** @defgroup MML_WDT_REGS_AR WDT A Register
 *
 * @li BF1 [2:0] - R/W: Bits field 1
 * @li BF2 [5] - R/W: Bits field 2
 * @li BF3 [6] - R/W: Bits field 3
 *
 * @{
 */

#define MML_TIC_TM_OFST	0x0	//!< A Register offset
#define MML_TIC_TM_DFLT	0x0	//!< A Register default value

/* Bits Fields */

#define MML_TIC_TM_BF1_OFST	0	//!< BF1 offset
#define MML_TIC_TM_BF2_OFST	5	//!< BF2 offset
#define MML_TIC_TM_BF3_OFST	6	//!< BF3 offset

#define MML_TIC_TM_BF1_MASK	0x7	//!< BF1 mask
#define MML_TIC_TM_BF2_MASK	0x1	//!< BF2 mask
#define MML_TIC_TM_BF3_MASK	0x1	//!< BF3 mask

/* Enumeration of the different value for a bits field . We recommend to use
 * human readable value. */

#define MML_TIC_TM_BF1_OPTION1		0x0	//!< BF1 value 1
#define MML_TIC_TM_BF1_OPTION2		0x3	//!< BF1 value 2
#define MML_TIC_TM_BF1_OPTION3		0x7	//!< BF1 value 3

/* We use the term enabled/disabled for bits field of size 1 */
#define MML_TIC_TM_BF2_ENABLED	0x1	//!< BF2 enabled == 1

#define MML_TIC_TM_BF3_DISABLED	0x1	//!< BF3 enabled == 0

/** @} */ /* @defgroup MML_WDT_REGS_AR */



#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */
/** WDT Registers.
 *
 */
typedef volatile struct _mml_tic_regs_{
	volatile unsigned tm;	  // 0x00 - System Test Mode Register
	volatile unsigned trcn;	  // 0x04 - Trim control register
	volatile unsigned tclk;   // 0x08 - Test clock control register
	volatile unsigned tmr0;	  // 0x0C - Security test mode register
	volatile unsigned tmr1;	  // 0x10 - Clock test mode register
	volatile unsigned tmr2;	  // 0x14 - Peripheral test mode register 0
	volatile unsigned tmr3;	  // 0x18 - Peripheral test mode register 1
	volatile unsigned resv0;  // 0x1C - reserved
	volatile unsigned mbcn;   // 0x20 - BIST control register
	volatile unsigned mbstat; // 0x24 - BIST status register
	volatile unsigned mbdsel; // 0x28 - BIST diag select
	volatile unsigned mbdiag; // 0x2C - BIST diag register
} mml_tic_regs_t;

#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_WDT_REGS */

#endif /* MML_WDT_REGS_H_ */
