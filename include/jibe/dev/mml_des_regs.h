/*
 * mml_des_regs.h --
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

#ifndef MML_DES_REGS_H_
#define MML_DES_REGS_H_

/** @file mml_des_regs.h DES Registers Header */

/** @defgroup MML_DES DES Driver
 * @ingroup MML_DRIVER
 */

/** @defgroup MML_DES_REGS DES Registers
 *
 * @note DES IP or Specification version number
 *
 * @ingroup MML_DES
 * @{
 */

/** @defgroup MML_DES_REGS_AR DES A Register
 *
 * @li BF1 [2:0] - R/W: Bits field 1
 * @li BF2 [5] - R/W: Bits field 2
 * @li BF3 [6] - R/W: Bits field 3
 *
 * @{
 */

#define MML_DES_UDESC_COS_OFST	        0	//!< UDESC COS offset
#define MML_DES_UDESC_COS_MASK	        3	//!< UDESC COS mask
#define MML_DES_UDESC_ROS_OFST	        2	//!< UDESC ROS offset
#define MML_DES_UDESC_ROS_MASK	        7	//!< UDESC ROS mask
#define MML_DES_UDESC_DESDIF_OFST	14	//!< UDESC ROS offset
#define MML_DES_UDESC_DESDIF_MASK	1	//!< UDESC ROS mask
#define MML_DES_UDESC_DESDIE_OFST	15	//!< UDESC ROS offset
#define MML_DES_UDESC_DESDIE_MASK	1	//!< UDESC ROS mask



#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */
/** SEC Registers.
 *
 */
//typedef volatile struct _mml_des_regs_{
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
//} mml_des_regs_t;

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
typedef volatile struct _mml_des_regs_{
    unsigned int udesd;
    unsigned int udesc;
} mml_des_regs_t;

#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_SEC_REGS */

#endif /* MML_DES_REGS_H_ */
