/*
 * mml_sec_regs.h --
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
 * $Revision:: 1623     $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2011-04-11 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#ifndef MML_SEC_REGS_H_
#define MML_SEC_REGS_H_

/** @file mml_sec_regs.h SEC Registers Header */

/** @defgroup MML_SEC SEC Driver
 * @ingroup MML_DRIVER
 */

/** @defgroup MML_SEC_REGS SEC Registers
 *
 * @note SEC IP or Specification version number
 *
 * @ingroup MML_SEC
 * @{
 */

/** @defgroup MML_SEC_REGS_AR SEC A Register
 *
 * @li BF1 [2:0] - R/W: Bits field 1
 * @li BF2 [5] - R/W: Bits field 2
 * @li BF3 [6] - R/W: Bits field 3
 *
 * @{
 */

#define MML_SEC_AR_OFST	0x0	//!< A Register offset
#define MML_SEC_AR_DFLT	0x0	//!< A Register default value

/* Bits Fields */

#define MML_SEC_AR_BF1_OFST	0	//!< BF1 offset
#define MML_SEC_AR_BF2_OFST	5	//!< BF2 offset
#define MML_SEC_AR_BF3_OFST	6	//!< BF3 offset

#define MML_SEC_AR_BF1_MASK	0x7	//!< BF1 mask
#define MML_SEC_AR_BF2_MASK	0x1	//!< BF2 mask
#define MML_SEC_AR_BF3_MASK	0x1	//!< BF3 mask

/* Enumeration of the different value for a bits field . We recommend to use
 * human readable value. */

#define MML_SEC_AR_BF1_OPTION1		0x0	//!< BF1 value 1
#define MML_SEC_AR_BF1_OPTION2		0x3	//!< BF1 value 2
#define MML_SEC_AR_BF1_OPTION3		0x7	//!< BF1 value 3

/* We use the term enabled/disabled for bits field of size 1 */
#define MML_SEC_AR_BF2_ENABLED	0x1	//!< BF2 enabled == 1

#define MML_SEC_AR_BF3_DISABLED	0x1	//!< BF3 enabled == 0

/** @} */ /* @defgroup MML_SEC_REGS_AR */

/** @defgroup MML_SEC_REGS_BR SEC B Register
 * @{
 */

#define MML_SEC_BR_OFST	0x0	//!< B Register offset
#define MML_SEC_BR_DFLT	0x0	//!< A Register default value

/* Bits Fields */



/** @} */ /* @defgroup MML_SEC_REGS_BR */


#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */
/** SEC Registers.
 *
 */
typedef volatile struct _mml_sec_regs_{
  //volatile unsigned ar; //< A register
  //volatile unsigned br; //< B register
unsigned int udesd;
unsigned int udesc;

unsigned int aesc;
unsigned int aesdin0;
unsigned int aesdin1;
unsigned int aesdin2;
unsigned int aesdin3;
unsigned int aesdout0;
unsigned int aesdout1;
unsigned int aesdout2;
unsigned int aesdout3;

unsigned int shap;
unsigned int shac;
} mml_sec_regs_t;

#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_SEC_REGS */

#endif /* MML_SEC_REGS_H_ */
