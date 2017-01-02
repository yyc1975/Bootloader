/*
 * mml_ebc_regs.h --
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
 * Author: Gregory Rom� <gregory.rome@maximintegrated.com>
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 1156     $:  Revision of last commit
 * $Author:: james.cott#$:  Author of last commit
 * $Date:: 2011-02-15 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#ifndef MML_EBC_REGS_H_
#define MML_EBC_REGS_H_

/** @file mml_ebc_regs.h External Bus Controller Registers Header */

/** @defgroup MML_EBC Ext Bus Controller Driver
 * @ingroup MML_DRIVER
 */

/** @defgroup MML_EBC_REGS Ext Bus Controller Registers
 *
 * @note Jibe specification 0.0.1
 *
 * @ingroup MML_EBC
 * @{
 */

/** @defgroup MML_EBC_SMEM_CFG Register
 *
 * @li BF1 [1:0] - R/W: Bits Data Bus Width
 * @li BF2 [2] - R/W: Bits Byte Control Style
 * @li BF3 [5] - R/W: Bits Page Mode Enabled
 * @li BF3 [6] - R/W: Bits Primary / Secondary
 * @li BF1 [10:8] - R/W: Bits Page Boundary
 *
 * @{
 */

#define MML_EBC_SMEM_CFG_OFST				0x0	//!< SMEM_CFG Register offset
#define MML_EBC_SMEM_CFG_DFLT				0x00000005	//!< SMEM_CFG Register default value

/* Bits Fields */

#define MML_EBC_SMEM_CFG_WIDTH_OFST				0
#define MML_EBC_SMEM_CFG_WIDTH_MASK_NOOFST			0x3
#define MML_EBC_SMEM_CFG_WIDTH_MASK				(MML_EBC_SMEM_CFG_WIDTH_MASK_NOOFST << MML_EBC_SMEM_CFG_WIDTH_OFST)
#define MML_EBC_SMEM_CFG_WIDTH_8BITS				0x0
#define MML_EBC_SMEM_CFG_WIDTH_16BITS				0x1
#define MML_EBC_SMEM_CFG_WIDTH_32BITS				0x2

#define MML_EBC_SMEM_CFG_BSTYLE_OFST				2
#define MML_EBC_SMEM_CFG_BSTYLE_MASK_NOOFST		0x1
#define MML_EBC_SMEM_CFG_BSTYLE_MASK				(MML_EBC_SMEM_CFG_BSTYLE_MASK_NOOFST << MML_EBC_SMEM_CFG_BSTYLE_OFST)
#define MML_EBC_SMEM_CFG_BSTYLE_NOBE				0x0
#define MML_EBC_SMEM_CFG_BSTYLE_BE					0x1

#define MML_EBC_SMEM_CFG_PAGE_EN_OFST				5
#define MML_EBC_SMEM_CFG_PAGE_EN_MASK_NOOFST		0x1
#define MML_EBC_SMEM_CFG_PAGE_EN_MASK				(MML_EBC_SMEM_CFG_PAGE_EN_MASK_NOOFST << MML_EBC_SMEM_CFG_PAGE_EN_OFST)
#define MML_EBC_SMEM_CFG_PAGE_EN_DISABLED			0x0
#define MML_EBC_SMEM_CFG_PAGE_EN_ENABLED			0x1

#define MML_EBC_SMEM_CFG_PRISEC_OFST				6
#define MML_EBC_SMEM_CFG_PRISEC_MASK_NOOFST		0x1
#define MML_EBC_SMEM_CFG_PRISEC_MASK				(MML_EBC_SMEM_CFG_PRISEC_MASK_NOOFST << MML_EBC_SMEM_CFG_PRISEC_OFST)
#define MML_EBC_SMEM_CFG_PRISEC_PRIMARY			0x0
#define MML_EBC_SMEM_CFG_PRISEC_SECONDARY			0x1

#define MML_EBC_SMEM_CFG_PAGE_BDY_OFST				8
#define MML_EBC_SMEM_CFG_PAGE_BDY_MASK_NOOFST		0x3
#define MML_EBC_SMEM_CFG_PAGE_BDY_MASK				(MML_EBC_SMEM_CFG_PAGE_BDY_MASK_NOOFST << MML_EBC_SMEM_CFG_PAGE_BDY_OFST)
#define MML_EBC_SMEM_CFG_PAGE_BDY_A2				0x0
#define MML_EBC_SMEM_CFG_PAGE_BDY_A3				0x1
#define MML_EBC_SMEM_CFG_PAGE_BDY_A4				0x2
#define MML_EBC_SMEM_CFG_PAGE_BDY_A5				0x3
#define MML_EBC_SMEM_CFG_PAGE_BDY_A6				0x4
#define MML_EBC_SMEM_CFG_PAGE_BDY_A7				0x5
/** @} */ /* @defgroup MML_EBC_REGS_AR */

/** @defgroup MML_EBC_SMEM_RTIM Register
 *
 * @li BF1 [6:0] - R/W: Bits Read Cycle Setup Time
 * @li BF1 [15:8] - R/W: Bits Read Access Time
 * @li BF1 [22:16] - R/W: Bits Read Cycle Hold Time
 * @li BF1 [31:24] - R/W: Bits Page Burst Read Access Time
 *
 * @{
 */


/** @} */ /* @defgroup MML_EBC_REGS_BR */

/** @defgroup MML_EBC_SMEM_WTIM Register
 *
 * @li BF1 [6:0] - R/W: Bits Write Cycle Setup Time
 * @li BF1 [15:8] - R/W: Bits Write Access Time
 * @li BF1 [22:16] - R/W: Bits Write Cycle Hold Time
 * @li BF1 [30:24] - R/W: Bits Read Recovery Time
 *
 * @{
 */


/** @} */ /* @defgroup MML_EBC_SMEM_WTIM */

/** @defgroup MML_EBC_SDR_CMD Register : Primary/Secondary SDRAM Command Register
 *
 * @li SDCMD 		[3:0] 	  	- R/W: SDRAM Command
 * @li CMDEXE  		[4] 	 	- R/W: Execute Command
 * @li 				[7:5]		    R: Reserved
 * @li SDDIS		[8]			- R/W: SDRAM Controller Disable.
 * @li SDEN			[9]			- R/W: SDRAM Controller Enable.
 * @li SDSTAT 		[10]		- R/W: SDRAM Status
 * @li				[31:11]		  - R: Reserved
 * @li BF1 [22:16] - R/W: Bits Read Cycle Hold Time
 * @li BF1 [31:24] - R/W: Bits Page Burst Read Access Time
 *
 * @{
 */
#define	MML_EBC_SDR_CMD_SDCMD_OFST			0
#define	MML_EBC_SDR_CMD_SDCMD_MASK_NOOFST	0xf
#define	MML_EBC_SDR_CMD_SDCMD_MASK			( MML_EBC_SDR_CMD_SDCMD_MASK_NOOFST << MML_EBC_SDR_CMD_SDCMD_OFST )

#define	MML_EBC_SDR_CMD_CMDEXE_OFST		4
#define	MML_EBC_SDR_CMD_CMDEXE_MASK_NOOFST	0x1
#define	MML_EBC_SDR_CMD_CMDEXE_MASK		( MML_EBC_SDR_CMD_CMDEXE_MASK_NOOFST << MML_EBC_SDR_CMD_CMDEXE_OFST )

#define	MML_EBC_SDR_CMD_SDDIS_OFST			8
#define	MML_EBC_SDR_CMD_SDDIS_MASK_NOOFST	0x1
#define	MML_EBC_SDR_CMD_SDDIS_MASK			( MML_EBC_SDR_CMD_SDDIS_MASK_NOOFST << MML_EBC_SDR_CMD_SDDIS_OFST )

#define	MML_EBC_SDR_CMD_SDEN_OFST			9
#define	MML_EBC_SDR_CMD_SDEN_MASK_NOOFST	0x1
#define	MML_EBC_SDR_CMD_SDEN_MASK			( MML_EBC_SDR_CMD_SDEN_MASK_NOOFST << MML_EBC_SDR_CMD_SDEN_OFST )

#define	MML_EBC_SDR_CMD_SDSTAT_OFST		10
#define	MML_EBC_SDR_CMD_SDSTAT_MASK_NOOFST	0x1
#define	MML_EBC_SDR_CMD_SDSTAT_MASK		( MML_EBC_SDR_CMD_SDSTAT_MASK_NOOFST << MML_EBC_SDR_CMD_SDSTAT_OFST )

/** SDRAM Commands */
#define MML_EBC_XCMD_DRAM_CMD_NORMAL 								0
#define MML_EBC_XCMD_DRAM_CMD_NOP			 						1
#define MML_EBC_XCMD_DRAM_CMD_PRECHARGE_ALL						2
#define MML_EBC_XCMD_DRAM_CMD_LOAD_MODE_REGISTER					3			/** BA[1-0]=00b */
#define MML_EBC_XCMD_DRAM_CMD_SELF_REFRESH							4
#define MML_EBC_XCMD_DRAM_CMD_POWER_DOWN		 					5
#define MML_EBC_XCMD_DRAM_CMD_AUTO_REFRESH							6
#define MML_EBC_XCMD_DRAM_CMD_ZEROIZATION							7
#define MML_EBC_XCMD_DRAM_CMD_LOAD_EXTENDED_MODE_REGISTER  		8	/** BA[1-0]=01b */
#define MML_EBC_XCMD_DRAM_CMD_LOAD_MODE_REGISTER_DDR 				9 		/** with DDR bit cleared (only for DDR) */
#define MML_EBC_XCMD_DRAM_CMD_LOAD_EXTENDED_MODE_REGISTER_LPDDR  	10	/** LPDDR */

/** @} */ /* @defgroup MML_EBC_SDR_CMD */

/** @defgroup MML_DMC_GCFG Dual Memory Controller Global Configuration Register (DMC_GCFG)
 * From SDRAM/LPDDR Design Specification Rev 0.3
 * @li BUS_ZERO 		[0]			- R/W: Drive Memory Bus to zero when Memory Controller is Idle
 * @li	            	[3:1]	   	  - R: Reserved
 * @li  PRI_RCV_OVR		[4]	  		- R/W: Primary Input Receiver Override.
 * @li	SEC_RCV_OVR     [5]			- R/W: Secondary Input Receiver Override.
 * @li				    [7:6] 			R: Reserved
 * @li	PRI_DRV			[10:8]		- R/W: Primary Drive Control
 *										   -These bits control the drive slew rate in V/ns.
 * @li	PRI_CLK_DLY		[13:11]		- R/W: Primary Clock Delay
 *										   -These bits select the clock delay in V/ns.
 * @li	PRI_CLK_SEL		[14] 		- R/W: Primary Clock Select
 * @li	PRI_CLK_DIS		[15]		- R/W: Primary Clock Disable
 * @li	SEC_DRV 		[18:16] 	- R/W: Secondary Drive Control
 *										   -These bits control the drive slew rate in V/ns.
 * @li	SEC_CLK_DLY		[21:19]		- R/W: Secondary Clock Delay
 *										   -These bits select the clock delay in V/ns.
 * @li	SEC_CLK_SEL		[22] 		- R/W: Secondary Clock Select
 * @li	SEC_CLK_DIS		[23] 		- R/W: Secondary Clock Disable
 * @li	PRI_ADDR_PD 	[24] 		- R/W: Primary Address/Control Pull Down Enable
 * @li	PRI_ADDR_PU 	[25]		- R/W: Primary Address/Control Pull Up Enable
 * @li	PRI_DATA_PD 	[26]		- R/W: Primary Data Pull Down Enable
 * @li	PRI_DATA_PU 	[27] 		- R/W: Primary Data Pull Up Enable
 * @li	SEC_ADDR_PD 	[28]		- R/W: Secondary Address/Control Pull Down Enable
 * @li	SEC_ADDR_PU 	[29]		- R/W: Secondary Address/Control Pull Up Enable
 * @li	SEC_DATA_PD 	[30]		- R/W: Secondary Data Pull Down Enable
 * @li	SEC_DATA_PU 	[31]		- R/W: Secondary Data Pull Up Enable
 *
 * @{
 */
/* Bits Fields */
#define	MML_EBC_DMC_GCFG_BUSZERO_OFST		0
#define	MML_EBC_DMC_GCFG_BUSZERO_MASK		(0x01 << MML_EBC_DMC_GCFG_BUSZERO_OFST)
#define	MML_EBC_DMC_GCFG_PRIRCVOVR_OFST	4
#define	MML_EBC_DMC_GCFG_PRIRCVOVR_MASK	(0x01 << MML_EBC_DMC_GCFG_PRIRCVOVR_OFST)
#define	MML_EBC_DMC_GCFG_SECRCVOVR_OFST	5
#define	MML_EBC_DMC_GCFG_SECRCVOVR_MASK	(0x01 << MML_EBC_DMC_GCFG_SECRCVOVR_OFST)
#define	MML_EBC_DMC_GCFG_PRIDRV_OFST		8
#define	MML_EBC_DMC_GCFG_PRIDRV_MASK		(0x07 << MML_EBC_DMC_GCFG_PRIDRV_OFST)
#define	MML_EBC_DMC_GCFG_PRICLKDLY_OFST	11
#define MML_EBC_DMC_GCFG_PRICLKDLY_MASK	(0x07 << MML_EBC_DMC_GCFG_PRICLKDLY_OFST)
#define MML_EBC_DMC_GCFG_PRICLKSEL_OFST	14
#define MML_EBC_DMC_GCFG_PRICLKSEL_MASK	(0x01 << MML_EBC_DMC_GCFG_PRICLKSEL_OFST)
#define MML_EBC_DMC_GCFG_PRICLKDIS_OFST	15
#define MML_EBC_DMC_GCFG_PRICLKDIS_MASK	(0x01 << MML_EBC_DMC_GCFG_PRICLKDIS_OFST)
#define MML_EBC_DMC_GCFG_SECDRV_OFST		16
#define MML_EBC_DMC_GCFG_SECDRV_MASK		(0x07 << MML_EBC_DMC_GCFG_SECDRV_OFST)
#define MML_EBC_DMC_GCFG_SECCLKDLY_OFST	19
#define MML_EBC_DMC_GCFG_SECCLKDLY_MASK	(0x07 << MML_EBC_DMC_GCFG_SECCLKDLY_OFST)
#define MML_EBC_DMC_GCFG_SECCLKSEL_OFST	22
#define MML_EBC_DMC_GCFG_SECCLKSEL_MASK	(0x01 << MML_EBC_DMC_GCFG_SECCLKSEL_OFST)
#define MML_EBC_DMC_GCFG_SECCLKDIS_OFST	23
#define MML_EBC_DMC_GCFG_SECCLKDIS_MASK	(0x01 << MML_EBC_DMC_GCFG_SECCLKDIS_OFST)
#define MML_EBC_DMC_GCFG_PRIADDRPD_OFST	24
#define MML_EBC_DMC_GCFG_PRIADDRPD_MASK	(0x01 << MML_EBC_DMC_GCFG_PRIADDRPD_OFST)
#define MML_EBC_DMC_GCFG_PRIADDRPU_OFST	25
#define MML_EBC_DMC_GCFG_PRIADDRPU_MASK	(0x01 << MML_EBC_DMC_GCFG_PRIADDRPU_OFST)
#define MML_EBC_DMC_GCFG_PRIDATAPD_OFST	26
#define MML_EBC_DMC_GCFG_PRIDATAPD_MASK	(0x01 << MML_EBC_DMC_GCFG_PRIDATAPD_OFST)
#define MML_EBC_DMC_GCFG_PRIDATAPU_OFST	27
#define MML_EBC_DMC_GCFG_PRIDATAPU_MASK	(0x01 << MML_EBC_DMC_GCFG_PRIDATAPU_OFST)
#define MML_EBC_DMC_GCFG_SECADDRPD_OFST	28
#define MML_EBC_DMC_GCFG_SECADDRPD_MASK	(0x01 << MML_EBC_DMC_GCFG_SECADDRPD_OFST)
#define MML_EBC_DMC_GCFG_SECADDRPU_OFST	29
#define MML_EBC_DMC_GCFG_SECADDRPU_MASK	(0x01 << MML_EBC_DMC_GCFG_SECADDRPU_OFST)
#define MML_EBC_DMC_GCFG_SECDATAPD_OFST	30
#define MML_EBC_DMC_GCFG_SECDATAPD_MASK	(0x01 << MML_EBC_DMC_GCFG_SECDATAPD_OFST)
#define MML_EBC_DMC_GCFG_SECDATAPU_OFST	31
#define MML_EBC_DMC_GCFG_SECDATAPU_MASK	(0x01 << MML_EBC_DMC_GCFG_SECDATAPU_OFST)

/** @} */ /* @defgroup MML_DMC_GCFG */


#ifndef __ASSEMBLER__
/* -------------------------------------------------------------------------- */
/** EBC Registers.
 *
 */
typedef volatile struct _mml_ebc_regs_
{
	unsigned int	gconfig;	//!< Global Config
	unsigned int	clock;		//!< Clock Control
	unsigned int	status;		//!< Status
	unsigned int	rfu0[29];	//!< reserve

	unsigned int	pconfig;	//!< Primary Config
	unsigned int	pcommand;	//!< Primary Command
	unsigned int	prefresh;	//!< Primary Refresh
	unsigned int	papd;		//!< Primary Automatic Power Down
	unsigned int	sconfig;	//!< Secondary Config
	unsigned int	scommand;	//!< Secondary Command
	unsigned int	srefresh;	//!< Secondary Refresh
	unsigned int	sapd;		//!< Secondary Automatic Power Down
	unsigned int	pext;		//!< Primary Extended Mode Register
	unsigned int	rfu1[3];	//!< reserve
	unsigned int	sext;		//!< Secondary Extended Mode Register
	unsigned int	rfu2[19];	//!< reserve

	unsigned int	config0;	//!< Config0 Register
	unsigned int	rtiming0;	//!< Read Timing0 Register
	unsigned int	wtiming0;	//!< Write Timing0 Register
	unsigned int	rfu3;		//!< reserve

	unsigned int	config1;	//!< Config1 Register
	unsigned int	rtiming1;	//!< Read Timing1 Register
	unsigned int	wtiming1;	//!< Write Timing1 Register
	unsigned int	rfu4;		//!< reserve

	unsigned int	config2;	//!< Config2 Register
	unsigned int	rtiming2;	//!< Read Timing2 Register
	unsigned int	wtiming2;	//!< Write Timing2 Register
	unsigned int	rfu5;		//!< reserve

	unsigned int	config3;	//!< Config3 Register
	unsigned int	rtiming3;	//!< Read Timing3 Register
	unsigned int	wtiming3;	//!< Write Timing3 Register
	unsigned int	rfu6;		//!< reserve

	unsigned int	config4;	//!< Config4 Register
	unsigned int	rtiming4;	//!< Read Timing4 Register
	unsigned int	wtiming4;	//!< Write Timing4 Register
	unsigned int	rfu7;		//!< reserve

	unsigned int	config5;	//!< Config5 Register
	unsigned int	rtiming5;	//!< Read Timing5 Register
	unsigned int	wtiming5;	//!< Write Timing5 Register
	unsigned int	rfu8;		//!< reserve

	unsigned int	config6;	//!< Config6 Register
	unsigned int	rtiming6;	//!< Read Timing6 Register
	unsigned int	wtiming6;	//!< Write Timing6 Register
	unsigned int	rfu9;		//!< reserve

	unsigned int	config7;	//!< Config7 Register
	unsigned int	rtiming7;	//!< Read Timing7 Register
	unsigned int	wtiming7;	//!< Write Timing7 Register

	unsigned int	rfu10[33];	//!< reserve
	unsigned int	key0_0;		//!< Key0 regs
	unsigned int	key0_1;		//!< Key0 regs
	unsigned int	key0_2;		//!< Key0 regs
	unsigned int	key0_3;		//!< Key0 regs
	unsigned int	key1_0;		//!< Key1 regs
	unsigned int	key1_1;		//!< Key1 regs
	unsigned int	key1_2;		//!< Key1 regs
	unsigned int	key1_3;		//!< Key1 regs

} mml_ebc_regs_t;

/** _MML_SPEC_0_0_7_ */
/** NAND Flash Controller (NFC) Registers.
 *
 */
typedef volatile struct _mml_nfc_regs_
{
	unsigned int	nfconfig;	//!< Nand Flash Config Register
	unsigned int	nfrtiming;	//!< Nand Flash Read Timing Register
	unsigned int	nfwtiming;	//!< Nand Flash Write Timing Register
	unsigned int	ecc_ctrl;	//!< Nand Flash ECC Control Register
	unsigned int	ecc_stat;	//!< Nand Flash ECC Status Register
	unsigned int	ecc_val;	//!< Nand Flash ECC Value Register

} mml_nfc_regs_t;

/** _MML_SPEC_0_0_7_ */
/** Dual Memory Controller (DMC) Registers
 *
 */
typedef volatile struct _mml_dmc_regs_
{
	unsigned int	gconfig;	//!< Global Config
	unsigned int	clock;		//!< Clock Control
	unsigned int	status;		//!< Status

} mml_dmc_regs_t;

/** _MML_SPEC_0_0_7_ */
/** SDRAM Controller (SDR) Registers
 *
 */
typedef volatile struct _mml_sdr_regs_
{
	unsigned int	pconfig;	//!< Primary Config
	unsigned int	pcommand;	//!< Primary Command
	unsigned int	prefresh;	//!< Primary Refresh
	unsigned int	papd;		//!< Primary Automatic Power Down
	unsigned int	sconfig;	//!< Secondary Config
	unsigned int	scommand;	//!< Secondary Command
	unsigned int	srefresh;	//!< Secondary Refresh
	unsigned int	sapd;		//!< Secondary Automatic Power Down
	unsigned int	pext;		//!< Primary Extended Mode Register
	unsigned int	rfu1[3];	//!< reserve
	unsigned int	sext;		//!< Secondary Extended Mode Register
	unsigned int	rfu2[19];	//!< reserve

} mml_sdr_regs_t;

/** _MML_SPEC_0_0_7_ */
/** Static Memory Controller (SMEM) Registers
 *
 */
typedef volatile struct _mml_smem_regs_
{
	unsigned int	config0;	//!< Config0 Register
	unsigned int	rtiming0;	//!< Read Timing0 Register
	unsigned int	wtiming0;	//!< Write Timing0 Register
	unsigned int	rfu0;	//!< reserve

	unsigned int	config1;	//!< Config1 Register
	unsigned int	rtiming1;	//!< Read Timing1 Register
	unsigned int	wtiming1;	//!< Write Timing1 Register
	unsigned int	rfu1;	//!< reserve

	unsigned int	config2;	//!< Config2 Register
	unsigned int	rtiming2;	//!< Read Timing2 Register
	unsigned int	wtiming2;	//!< Write Timing2 Register
	unsigned int	rfu2;	//!< reserve

	unsigned int	config3;	//!< Config3 Register
	unsigned int	rtiming3;	//!< Read Timing3 Register
	unsigned int	wtiming3;	//!< Write Timing3 Register
	unsigned int	rfu3;	//!< reserve

	unsigned int	config4;	//!< Config4 Register
	unsigned int	rtiming4;	//!< Read Timing4 Register
	unsigned int	wtiming4;	//!< Write Timing4 Register
	unsigned int	rfu4;	//!< reserve

	unsigned int	config5;	//!< Config5 Register
	unsigned int	rtiming5;	//!< Read Timing5 Register
	unsigned int	wtiming5;	//!< Write Timing5 Register
	unsigned int	rfu5;	//!< reserve

	unsigned int	config6;	//!< Config6 Register
	unsigned int	rtiming6;	//!< Read Timing6 Register
	unsigned int	wtiming6;	//!< Write Timing6 Register
	unsigned int	rfu6;	//!< reserve

	unsigned int	config7;	//!< Config7 Register
	unsigned int	rtiming7;	//!< Read Timing7 Register
	unsigned int	wtiming7;	//!< Write Timing7 Register

} mml_smem_regs_t;


#endif /* __ASSEMBLER__ */

/** @} */ /* @defgroup MML_EBC_REGS */

#endif /* MML_EBC_REGS_H_ */
