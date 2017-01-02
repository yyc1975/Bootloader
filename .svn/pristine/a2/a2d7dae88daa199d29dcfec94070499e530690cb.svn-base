/*
 * mml_aes_regs.h --
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
 * $Revision:: 1021     $:  Revision of last commit
 * $Author:: rajasekhar#$:  Author of last commit
 * $Date:: 2011-01-13 0#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#ifndef MML_AES_REGS_H_
#define MML_AES_REGS_H_

/** @file mml_aes_regs.h SEC Registers Header */

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

#define MML_AES_AESC_AESST_OFST	0	//!< aes start op. offset
#define MML_AES_AESC_AESST_MASK	1	//!< aes start op. mask
#define MML_AES_AESC_AESMD_OFST	1	//!< aes mode offset
#define MML_AES_AESC_AESMD_MASK	1	//!< aes mode mask
#define MML_AES_AESC_KS_OFST		3	//!< aes key size offset
#define MML_AES_AESC_KS_MASK		0x3	//!< aes key size mask
#define MML_AES_AESC_AESIE_OFST	5	//!< aes Interrupt enable  offset
#define MML_AES_AESC_AESIE_MASK	1	//!< aes Interrupt enable  mask
#define MML_AES_AESC_AESIF_OFST	6	//!< aes Interrupt flag  offset
#define MML_AES_AESC_AESIF_MASK	1	//!< aes Interrupt flag  mask
#define MML_AES_AESC_KSEL_OFST	        8	//!< aes Key select  offset
#define MML_AES_AESC_KSEL_MASK	        1	//!< aes Key select  mask



#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */
/** SEC Registers.
 *
 */
//typedef volatile struct _mml_aes_regs_{
//  //volatile unsigned ar; //< A register
//  //volatile unsigned br; //< B register
//unsigned int udesd;
//unsigned int udesc;
//
//unsigned int aesc;
//unsigned int aesdin0;
//unsigned int aesdin1;
//unsigned int aesdin2;
//unsigned int aesdin3;
//unsigned int aesdout0;
//unsigned int aesdout1;
//unsigned int aesdout2;
//unsigned int aesdout3;
//
//unsigned int shap;
//unsigned int shac;
//} mml_aes_regs_t;

//typedef volatile struct _mml_sha_regs_{
//  //volatile unsigned ar; //< A register
//  //volatile unsigned br; //< B register
//
//unsigned int shap;
//unsigned int shac;
//} mml_sha_regs_t;
//
//typedef volatile struct _mml_des_regs_{
//  //volatile unsigned ar; //< A register
//  //volatile unsigned br; //< B register
//unsigned int udesd;
//unsigned int udesc;
//
//} mml_des_regs_t;
//
typedef volatile struct _mml_aes_regs_{
    unsigned int aesc;
    unsigned int aesdin0;
    unsigned int aesdin1;
    unsigned int aesdin2;
    unsigned int aesdin3;
    unsigned int aesdout0;
    unsigned int aesdout1;
    unsigned int aesdout2;
    unsigned int aesdout3;
    unsigned int aeskey0;
    unsigned int aeskey1;
    unsigned int aeskey2;
    unsigned int aeskey3;
    unsigned int aeskey4;
    unsigned int aeskey5;
    unsigned int aeskey6;
    unsigned int aeskey7;

} mml_aes_regs_t;

#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_SEC_REGS */

#endif /* MML_AES_REGS_H_ */
