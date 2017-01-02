/*
 * mml_otpc_regs.h --
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
 * $Revision:: 1623     $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2011-04-11 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#ifndef MML_OTPC_REGS_H_
#define MML_OTPC_REGS_H_

/** @file mml_otpc_regs.h OTP Controller Registers Header */

/** @defgroup MML_OTPC OTP Controller Driver
 * @ingroup MML_DRIVER
 */

/** @defgroup MML_OTPC_REGS OTP Controller Registers
 *
 * @note Jibe specification 0.0.1
 *
 * @ingroup MML_OTPC
 * @{
 */

/** @defgroup MML_OTPC_REGS_OTPC OTP Control Register
 *
 * @li OC [2:0] - R/W: OTP command.
 * @li OBUSY [7] - R/W: OTP Busy.
 *
 * @{
 */
#define MML_OTPC_OCNTL_OFST				0x0	//!< OCNTL Register offset
#define MML_OTPC_OCNTL_DFLT				0x0	//!< OCNTL Register default value
/* Bits Fields */
#define MML_OTPC_OCNTL_OC0_OFST			0	//!< OC0 offset
#define MML_OTPC_OCNTL_OC0_MASK_NOOFST		0x1
#define MML_OTPC_OCNTL_OC0_MASK			(MML_OTPC_OCNTL_OC0_MASK_NOOFST << MML_OTPC_OCNTL_OC0_OFST)

#define MML_OTPC_OCNTL_OC1_OFST			1	//!< OC1 offset
#define MML_OTPC_OCNTL_OC1_MASK_NOOFST		0x1
#define MML_OTPC_OCNTL_OC1_MASK			(MML_OTPC_OCNTL_OC1_MASK_NOOFST << MML_OTPC_OCNTL_OC1_OFST)

#define MML_OTPC_OCNTL_OC2_OFST			2	//!< OC2 offset
#define MML_OTPC_OCNTL_OC2_MASK_NOOFST		0x1
#define MML_OTPC_OCNTL_OC2_MASK			(MML_OTPC_OCNTL_OC2_MASK_NOOFST << MML_OTPC_OCNTL_OC2_OFST)

#define MML_OTPC_OCNTL_OC_MASK_NOOFST		(MML_OTPC_OCNTL_OC0_MASK |\
												MML_OTPC_OCNTL_OC1_MASK |\
												MML_OTPC_OCNTL_OC2_MASK)	//!< OC mask
/** OTP Command */
/** Read Mode */
#define	MML_OTPC_OCNTL_OC_READ				0x0
/** Program Array */
#define	MML_OTPC_OCNTL_OC_PGM				0x1

#define MML_OTPC_OCNTL_OBUSY_OFST			7	//!< OBUSY offset
#define MML_OTPC_OCNTL_OBUSY_MASK_NOOFST	0x1
#define MML_OTPC_OCNTL_OBUSY_MASK			(MML_OTPC_OCNTL_OBUSY_MASK_NOOFST << MML_OTPC_OCNTL_OBUSY_OFST)
/** @} */ /* @defgroup MML_OTPC_REGS_OCNTL */

/** @defgroup MML_OTPC_REGS_OSTATUS OTP Status Register
 * @{
 */
#define MML_OTPC_OSTATUS_OFST				0xc	//!< OSTATUS Register offset
#define MML_OTPC_OSTATUS_DFLT				0x0	//!< OSTATUS Register default value
/* Bits Fields */
#define MML_OTPC_OSTATUS_PGMSTAT_OFST		0	//!< PGMSTAT offset
#define MML_OTPC_OSTATUS_PGMSTAT_MASK_NOOFST		0x1
#define MML_OTPC_OSTATUS_PGMSTAT_MASK		(MML_OTPC_OSTATUS_PGMSTAT_MASK_NOOFST << MML_OTPC_OSTATUS_PGMSTAT_OFST)

#define MML_OTPC_OSTATUS_XTAL_OFST			1	//!< XTAL offset
#define MML_OTPC_OSTATUS_XTAL_MASK_NOOFST	0x1
#define MML_OTPC_OSTATUS_XTAL_MASK			(MML_OTPC_OSTATUS_XTAL_MASK_NOOFST << MML_OTPC_OSTATUS_XTAL_OFST)

/** @} */ /* @defgroup MML_OTPC_REGS_STATUS */

/** @defgroup MML_OTPC_REGS_DATA OTP Data Register
 * @{
 */
#define MML_OTPC_ODATA_OFST				0x4	//!< ODATA Register offset
#define MML_OTPC_ODATA_DFLT				0x0	//!< ODATA Register default value
/** @} */ /* @defgroup MML_OTPC_REGS_ODATA */

/** @defgroup MML_OTPC_REGS_OLOCK OTP Lock Register
 * @{
 */
#define	MML_OTPC_OLOCK_MAGIC_WORD1			0x3a7f5ca3
#define	MML_OTPC_OLOCK_MAGIC_WORD2			0xa1e34f20
#define	MML_OTPC_OLOCK_MAGIC_WORD3			0x9608b2c1

#define MML_OTPC_OLOCK_OFST				0x8	//!< OLOCK Register offset
#define MML_OTPC_OLOCK_DFLT				0x0	//!< OLOCK Register default value
/** @} */ /* @defgroup MML_OTPC_REGS_OLOCK */


#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */
/** OTPC Registers.
 *
 */
typedef volatile struct _mml_otpc_regs_{
	unsigned int	ctrl;	//!< Control Register
	unsigned int	data;	//!< Data Register
	unsigned int	lock;	//!< Lock Register
	unsigned int	status;	//!< Status Register
} mml_otpc_regs_t;



#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_OTPC_REGS */

#endif /* MML_OTPC_REGS_H_ */
