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
 * $Revision:: 915      $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2010-12-20 0#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#ifndef MML_SNVRF_REGS_H_
#define MML_SNVRF_REGS_H_

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



/** @} */ /* @defgroup MML_SIR_REGS_BR */


#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */

/** SIR Registers.
 *
 */
typedef volatile struct _mml_snvrf_regs_{
	unsigned int	key0_tm;		//!< test Register
	unsigned int	key1_tm;		//!< test Register
	unsigned int	key2_tm;		//!< test Register
	unsigned int	key3_tm;		//!< test Register
	unsigned int	key4_tm;		//!< test Register
	unsigned int	key5_tm;		//!< test Register
	unsigned int	key6_tm;		//!< test Register
	unsigned int	key7_tm;		//!< test Register
} mml_snvrf_regs_t;


#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_SIR_REGS */

#endif /* MML_SIR_REGS_H_ */
