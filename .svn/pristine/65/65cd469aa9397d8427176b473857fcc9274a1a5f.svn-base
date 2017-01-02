/*
 * mml_uci_regs.h --
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

#ifndef MML_UCI_REGS_H_
#define MML_UCI_REGS_H_

/** @file mml_uci_regs.h UCI Registers Header */

/** @defgroup MML_UCI UCI Driver
 * @ingroup MML_DRIVER
 */

/** @defgroup MML_UCI_REGS UCI Registers
 *
 * @note UCI IP or Specification version number
 *
 * @ingroup MML_UCI
 * @{
 */

/** @defgroup MML_UCI_REGS_AR UCI A Register
 *
 * @li BF1 [2:0] - R/W: Bits field 1
 * @li BF2 [5] - R/W: Bits field 2
 * @li BF3 [6] - R/W: Bits field 3
 *
 * @{
 */

/* Bits Fields */

#define MML_UCI_UCICR_KACT_OFST			0 //!< KACT offset
#define MML_UCI_UCICR_KSRC_OFST			3 //!< KACT offset
#define MML_UCI_UCICR_KXTR_OFST			5 //!< KXTR offset
#define MML_UCI_UCICR_KID_OFST				8 //!< KID
#define MML_UCI_UCICR_CLKDIV_OFST			12
#define	MML_UCI_UCICR_IFLUSH_OFST			16
#define	MML_UCI_UCICR_SCREN_OFST			17
#define	MML_UCI_UCICR_KLOCK0_OFST			28
#define	MML_UCI_UCICR_KLOCK1_OFST			29
#define	MML_UCI_UCICR_KLOCK2_OFST			30
#define	MML_UCI_UCICR_KLOCK3_OFST			31

#define MML_UCI_UCICR_KACT_MASK_NOOFST		0x7
#define MML_UCI_UCICR_KSRC_MASK_NOOFST		0x3
#define MML_UCI_UCICR_KXTR_MASK_NOOFST		0x3
#define	MML_UCI_UCICR_KID_MASK_NOOFST		0x3
#define	MML_UCI_UCICR_CLKDIV_MASK_NOOFST	0x1
#define	MML_UCI_UCICR_IFLUSH_MASK_NOOFST	0x1
#define	MML_UCI_UCICR_SCREN_MASK_NOOFST	0x1
#define	MML_UCI_UCICR_KLOCK0_MASK_NOOFST	0x1
#define	MML_UCI_UCICR_KLOCK1_MASK_NOOFST	0x1
#define	MML_UCI_UCICR_KLOCK2_MASK_NOOFST	0x1
#define	MML_UCI_UCICR_KLOCK3_MASK_NOOFST	0x1

#define MML_UCI_UCICR_KACT_MASK			( MML_UCI_UCICR_KACT_MASK_NOOFST << MML_UCI_UCICR_KACT_OFST ) //!< KACT mask
#define MML_UCI_UCICR_KSRC_MASK			( MML_UCI_UCICR_KSRC_MASK_NOOFST << MML_UCI_UCICR_KSRC_OFST ) //!< KACT mask
#define MML_UCI_UCICR_KXTR_MASK			( MML_UCI_UCICR_KXTR_MASK_NOOFST << MML_UCI_UCICR_KXTR_OFST ) //!< KXTR mask
#define	MML_UCI_UCICR_KID_MASK				( MML_UCI_UCICR_KID_MASK_NOOFST << MML_UCI_UCICR_KID_OFST ) //(0x3 << MML_UCI_UCICR_KID_OFST)
#define	MML_UCI_UCICR_CLKDIV_MASK			( MML_UCI_UCICR_CLKDIV_MASK_NOOFST << MML_UCI_UCICR_CLKDIV_OFST )
#define	MML_UCI_UCICR_IFLUSH_MASK			( MML_UCI_UCICR_IFLUSH_MASK_NOOFST << MML_UCI_UCICR_IFLUSH_OFST )
#define	MML_UCI_UCICR_SCREN_MASK			( MML_UCI_UCICR_SCREN_MASK_NOOFST << MML_UCI_UCICR_SCREN_OFST )
#define	MML_UCI_UCICR_KLOCK0_MASK			( MML_UCI_UCICR_KLOCK0_MASK_NOOFST << MML_UCI_UCICR_KLOCK0_OFST )
#define	MML_UCI_UCICR_KLOCK1_MASK			( MML_UCI_UCICR_KLOCK1_MASK_NOOFST << MML_UCI_UCICR_KLOCK1_OFST )
#define	MML_UCI_UCICR_KLOCK2_MASK			( MML_UCI_UCICR_KLOCK2_MASK_NOOFST << MML_UCI_UCICR_KLOCK2_OFST )
#define	MML_UCI_UCICR_KLOCK3_MASK			( MML_UCI_UCICR_KLOCK3_MASK_NOOFST << MML_UCI_UCICR_KLOCK3_OFST )

#define	MML_UCI_UCI0SR_ACDN_OFST			0
#define	MML_UCI_UCI0SR_ACDN_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_ACDN_MASK			( MML_UCI_UCI0SR_ACDN_MASK_NOOFST << MML_UCI_UCI0SR_ACDN_OFST )

#define	MML_UCI_UCI0SR_KLD0_OFST			8
#define	MML_UCI_UCI0SR_KLD0_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_KLD0_MASK			( MML_UCI_UCI0SR_KLD0_MASK_NOOFST << MML_UCI_UCI0SR_KLD0_OFST )

#define	MML_UCI_UCI0SR_KLD1_OFST			9
#define	MML_UCI_UCI0SR_KLD1_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_KLD1_MASK			( MML_UCI_UCI0SR_KLD1_MASK_NOOFST << MML_UCI_UCI0SR_KLD1_OFST )

#define	MML_UCI_UCI0SR_KLD2_OFST			10
#define	MML_UCI_UCI0SR_KLD2_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_KLD2_MASK			( MML_UCI_UCI0SR_KLD2_MASK_NOOFST << MML_UCI_UCI0SR_KLD2_OFST )

#define	MML_UCI_UCI0SR_KLD3_OFST			11
#define	MML_UCI_UCI0SR_KLD3_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_KLD3_MASK			( MML_UCI_UCI0SR_KLD3_MASK_NOOFST << MML_UCI_UCI0SR_KLD3_OFST )

#define	MML_UCI_UCI0SR_TFAILA_OFST			16
#define	MML_UCI_UCI0SR_TFAILA_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_TFAILA_MASK			( MML_UCI_UCI0SR_TFAILA_MASK_NOOFST << MML_UCI_UCI0SR_TFAILA_OFST )

#define	MML_UCI_UCI0SR_TFAILB_OFST			17
#define	MML_UCI_UCI0SR_TFAILB_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_TFAILB_MASK			( MML_UCI_UCI0SR_TFAILB_MASK_NOOFST << MML_UCI_UCI0SR_TFAILB_OFST )

#define	MML_UCI_UCI0SR_TFAILC_OFST			18
#define	MML_UCI_UCI0SR_TFAILC_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_TFAILC_MASK			( MML_UCI_UCI0SR_TFAILC_MASK_NOOFST << MML_UCI_UCI0SR_TFAILC_OFST )

#define	MML_UCI_UCI0SR_FSMAB_OFST			20
#define	MML_UCI_UCI0SR_FSMAB_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_FSMAB_MASK			( MML_UCI_UCI0SR_FSMAB_MASK_NOOFST << MML_UCI_UCI0SR_FSMAB_OFST )

#define	MML_UCI_UCI0SR_FSMBB_OFST			21
#define	MML_UCI_UCI0SR_FSMBB_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_FSMBB_MASK			( MML_UCI_UCI0SR_FSMBB_MASK_NOOFST << MML_UCI_UCI0SR_FSMBB_OFST )

#define	MML_UCI_UCI0SR_FSMCB_OFST			22
#define	MML_UCI_UCI0SR_FSMCB_MASK_NOOFST	0x1
#define	MML_UCI_UCI0SR_FSMCB_MASK			( MML_UCI_UCI0SR_FSMCB_MASK_NOOFST << MML_UCI_UCI0SR_FSMCB_OFST )

/* Enumeration of the different value for a bits field . We recommend to use
 * human readable value. */

#define MML_UCI_UCICR_KACT_NOLOCK			0x03 //!< Erase not-locked encryption and decryption keys
#define MML_UCI_UCICR_KACT_LOADKEY			0x06 //!< Load the key and compute decryption key
#define MML_UCI_UCICR_KACT_CLEAR			0x00 //!< operation complete

#define	MML_UCI_UCIDDRR_BASE_OFST			0
#define	MML_UCI_UCIDDRR_BASE_MASK_NOOFST	0xffff
#define	MML_UCI_UCIDDRR_BASE_MASK			( MML_UCI_UCIDDRR_BASE_MASK_NOOFST << MML_UCI_UCIDDRR_BASE_OFST )

#define	MML_UCI_UCIDDRR_SIZE_OFST			16
#define	MML_UCI_UCIDDRR_SIZE_MASK_NOOFST	0x7ff
#define	MML_UCI_UCIDDRR_SIZE_MASK			( MML_UCI_UCIDDRR_SIZE_MASK_NOOFST << MML_UCI_UCIDDRR_SIZE_OFST )

#define MML_UCI_UCIDDRR_UTS_OFST			29
#define MML_UCI_UCIDDRR_UTS_MASK_NOOFST	0x7
#define MML_UCI_UCIDDRR_UTS_MASK			( MML_UCI_UCIDDRR_UTS_MASK_NOOFST << MML_UCI_UCIDDRR_UTS_OFST )

#define MML_UCI_UCIDDRR_UTS_REGION_P		( 0x1 << MML_UCI_UCIDDRR_UTS_OFST )
#define MML_UCI_UCIDDRR_UTS_REGION_E		( 0x2 << MML_UCI_UCIDDRR_UTS_OFST )
#define MML_UCI_UCIDDRR_UTS_REGION_I		( 0x4 << MML_UCI_UCIDDRR_UTS_OFST )
#define MML_UCI_UCIDDRR_UTS_REGION_EI		( 0x7 << MML_UCI_UCIDDRR_UTS_OFST )

#define MML_UCI_UCICR_KSRC_DIRECTREG		0
#define	MML_UCI_UCICR_KSRC_TRNG			1
#define	MML_UCI_UCICR_KSRC_OTP				2
#define	MML_UCI_UCICR_KSRC_NVSRAM			3

#define MML_UCI_UCISR_ACDN_OFST			0 //!< ACDN offset
#define MML_UCI_UCISR_ACDN_MASK			( 0x01 << MML_UCI_UCISR_ACDN_OFST ) //!< KACT offset

/* We use the term enabled/disabled for bits field of size 1 */
#define MML_UCI_AR_BF2_ENABLED				0x1 //!< BF2 enabled == 1
#define MML_UCI_AR_BF3_DISABLED			0x1 //!< BF3 enabled == 0

/** @} */ /* @defgroup MML_UCI_REGS_AR */

#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */
/** UCI Registers.
 *
 */
typedef volatile struct _mml_uci_regs_
{
	unsigned cr;		//< 0x00 Control register
	unsigned sr;		//< 0x04 Status register
	unsigned ier;		//< 0x08 Interrupt Enable register
	unsigned isr;		//< 0x0c Interrupt Status register
	unsigned afar;		//< 0x10 Address Fail FSM A register
	unsigned afbr;		//< 0x14 Address Fail FSM B register
	unsigned afcr;		//< 0x18 Address Fail FSM C register
	unsigned atr;		//< 0x1c Autotest Status Register
	unsigned esr;		//< 0x20 Error Status Register
	unsigned rfu1[55];	//< 0x24-0xfc Reserved
	unsigned ac0r[2];	//< 0x100-0x104 Area Config 0 Register
	unsigned ac1r[2];	//< 0x108-0x10c Area Config 1 Register
	unsigned ac2r[2];	//< 0x110-0x114 Area Config 2 Register
	unsigned ac3r[2];	//< 0x118-0x11c Area Config 3 Register
	unsigned ac4r[2];	//< 0x120-0x124 Area Config 4 Register
	unsigned ac5r[2];	//< 0x128-0x12c Area Config 5 Register
	unsigned rfu2[52];	//< 0x130-0x1fc Reserved
	unsigned ky00;		//< 0x200 Key 0 Register 0
	unsigned ky01;		//< 0x204 Key 0 Register 1
	unsigned ky02;		//< 0x208 Key 0 Register 2
	unsigned ky03;		//< 0x20c Key 0 Register 3
	unsigned rfu3[4];	//< 0x210-0x21c Reserved
	unsigned ky10;		//< 0x220 Key 1 Register 0
	unsigned ky11;		//< 0x224 Key 1 Register 1
	unsigned ky12;		//< 0x228 Key 1 Register 2
	unsigned ky13;		//< 0x22c Key 1 Register 3
	unsigned rfu4[4];	//< 0x230-0x23c Reserved
	unsigned ky20;		//< 0x240 Key 2 Register 0
	unsigned ky21;		//< 0x244 Key 2 Register 1
	unsigned ky22;		//< 0x248 Key 2 Register 2
	unsigned ky23;		//< 0x24c Key 2 Register 3
	unsigned rfu5[4];	//< 0x250-0x25c Reserved
	unsigned ky30;		//< 0x260 Key 3 Register 0
	unsigned ky31;		//< 0x264 Key 3 Register 1
	unsigned ky32;		//< 0x268 Key 3 Register 2
	unsigned ky33;		//< 0x26c Key 3 Register 3
	unsigned rfu6[20];	//< 0x270-0x2bc Reserved
	unsigned iky0;		//< 0x2c0 Integrity Key Register 0
	unsigned iky1;		//< 0x2c4 Integrity Key Register 1
	unsigned iky2;		//< 0x2c8 Integrity Key Register 2
	unsigned iky3;		//< 0x2cc Integrity Key Register 3
	unsigned rfu7[12];	//< 0x2d0-0x2fc Reserved
	unsigned smr0;		//< 0x300 Static Memory Region 0 Config Register
	unsigned smr1;		//< 0x304 Static Memory Region 1 Config Register
	unsigned smr2;		//< 0x308 Static Memory Region 2 Config Register
	unsigned smr3;		//< 0x30c Static Memory Region 3 Config Register
	unsigned ddrr0;		//< 0x310 DDR Region 0 Config Register
	unsigned ddrr1;		//< 0x314 DDR Region 1 Config Register
	unsigned ddrr2;		//< 0x318 DDR Region 2 Config Register
	unsigned ddrr3;		//< 0x31c DDR Region 3 Config Register
	unsigned nfr0;		//< 0x320 NAND Flash Region 0 Config Register
	unsigned nfr1;		//< 0x324 NAND Flash Region 1 Config Register
	unsigned nfr2;		//< 0x328 NAND Flash Region 2 Config Register
	unsigned nfr3;		//< 0x32c NAND Flash Region 3 Config Register
    unsigned rfu8[308]; //< 0x330-0x7fc Reserved
	/** Following register mappings are for UCI0 and not applicable for UCI1 */
	unsigned nfc_cfg;	//< 0x800 NAND Flash Configuration Register
	unsigned nfc_rtim;	//< 0x804 NAND Flash Read Timing Register
	unsigned nfc_wtim;	//< 0x808 NAND Flash Write Timing Register
	unsigned ecc_ctrl;	//< 0x80C NAND Flash ECC Control Register
	unsigned ecc_status;	//< 0x810 NAND Flash ECC Status Register
	unsigned ecc_value;		//< 0x814 NAND Flash ECC Value Register
    unsigned rfu9[250];     //< 0x818-0xbfc Reserved

	unsigned dmc_gcfg; 		//< 0xC00 Dual Memory Controller Global Configuration Register
	unsigned dmc_clk;		//< 0xC04 Clock Configuration Register
	unsigned dmc_status;	//< 0xC08 Status Register
    unsigned rfu10[29];     //< 0xc0c-0xc7c

	unsigned sdr_pcfg;		//< 0xC80 Primary SDRAM Configuration Register
	unsigned sdr_pcmd;		//< 0xC84 Primary SDRAM Command Register
	unsigned sdr_prfsh;		//< 0xC88 Primary SDRAM Refresh Register
	unsigned sdr_papd;		//< 0xC8C Primary SDRAM Power Down Register
	unsigned sdr_scfg;		//< 0xC90 Secondary SDRAM Configuration Register
	unsigned sdr_scmd;		//< 0xC94 Secondary SDRAM Command Register
	unsigned sdr_srfsh;		//< 0xC98 Secondary SDRAM Refresh Register
	unsigned sdr_sapd;		//< 0xC9C Secondary SDRAM Power Down Register
	unsigned ldr_ext;		//< 0xca0 Primary LPDDR Extended Mode Register
    unsigned rfu11[3];		//< 0xca4 - 0xcac Reserved
    unsigned sdr_ext;		//< 0xcb0 Secondary LPDDR Extended Mode Register
    unsigned rfu12[19];		//< 0xcb4 - 0xcfc Reserved

	unsigned smem_cfg_0;	//< 0xD00 Static Memory Configuration Register – nCS0
	unsigned smem_rtm_0;	//< 0xD04 0xD04 Static Memory Read Timing Register – nCS0
	unsigned smem_wtim_0;	//< 0xD08 Static Memory Write Timing Register – nCS0
	unsigned rfu13[1];		//< 0xD0C Reserved

	unsigned smem_cfg_1;	//< 0xD10 Static Memory Configuration Register – nCS1
	unsigned smem_rtim_1; 	//< 0xD14h Static Memory Read Timing Register – nCS1
	unsigned smem_wtim_1;	//< 0xD18 Static Memory Write Timing Register – nCS1
	unsigned rfu14[1];		//< 0xD1C Reserved

	unsigned smem_cfg_2; 	//< 0xD20 Static Memory Configuration Register – nCS2
	unsigned smem_rtim_2; 	//< 0xD24 Static Memory Read Timing Register – nCS2
	unsigned smem_wtim_2;	//< 0xD28 Static Memory Write Timing Register – nCS2
	unsigned rfu15[1];		//< 0xD2C Reserved

	unsigned smem_cfg_3; 	//< 0xD30 Static Memory Configuration Register – nCS3
	unsigned smem_rtim_3; 	//< 0xD34 Static Memory Read Timing Register – nCS3
	unsigned smem_wtim_3;	//< 0xD38 Static Memory Write Timing Register – nCS3
	unsigned rfu16[1];		//< 0xD3C Reserved

	unsigned smem_cfg_4; 	//< 0xD40 Static Memory Configuration Register – nCS4
	unsigned smem_rtim_4; 	//< 0xD44 Static Memory Read Timing Register – nCS4
	unsigned smem_wtim_4;	//< 0xD48 Static Memory Write Timing Register – nCS4
	unsigned rfu17[1];		//< 0xD4C Reserved

	unsigned smem_cfg_5; 	//< 0xD50 Static Memory Configuration Register – nCS5
	unsigned smem_rtim_5; 	//< 0xD54 Static Memory Read Timing Register – nCS5
	unsigned smem_wtim_5;	//< 0xD58 Static Memory Write Timing Register – nCS5
	unsigned rfu18[1];		//< 0xD5C Reserved

	unsigned smem_cfg_6; 	//< 0xD60 Static Memory Configuration Register – nCS6
	unsigned smem_rtim_6; 	//< 0xD64 Static Memory Read Timing Register – nCS6
	unsigned smem_wtim_6;	//< 0xD68 Static Memory Write Timing Register – nCS6
	unsigned rfu19[37];		//< 0xd6c - 0xdfc Reserved

	unsigned memc_key0_0;	//< 0xe00 Key0 registers
	unsigned memc_key0_1;	//< 0xe04 Key0 registers
	unsigned memc_key0_2;	//< 0xe08 Key0 registers
	unsigned memc_key0_3;	//< 0xe0c Key0 registers
	unsigned memc_key1_0;	//< 0xe10 Key1 registers
	unsigned memc_key1_1;	//< 0xe14 Key1 registers
	unsigned memc_key1_2;	//< 0xe18 Key1 registers
	unsigned memc_key1_3;	//< 0xe1c Key1 registers

} mml_uci_regs_t;

#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_UCI_REGS */

#endif /* MML_UCI_REGS_H_ */
