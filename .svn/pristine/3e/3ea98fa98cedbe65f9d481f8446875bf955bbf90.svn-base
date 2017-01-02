/*
 * mml.h --
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
 * Created on: Jun 9, 2010
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision: 2299 $:  Revision of last commit
 * $Author: jeremy.brodt $:  Author of last commit
 * $Date: 2011-12-03 02:42:15 +0530 (Sat, 03 Dec 2011) $:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */
#ifndef MML_H_
#define MML_H_

/** Global includes */
#include <io.h>
/** Other includes */
/** Local includes */

/** @defgroup JIBE Jibe
 * @{
 */

/** @defgroup MML_MEM Jibe Memories
 * @{
 */


#define MML_MEM_ROM_BASE		0x00000000			//!< Jibe ROM base address
#define MML_MEM_ROM_SIZE		0x20000				//!< Jibe ROM size
#define ROM_BASE				MML_MEM_ROM_BASE	//!< ROM base address
#define ROM_SIZE				MML_MEM_ROM_SIZE	//!< ROM size
#define MML_MEM_RAM_BASE		0x00900000			//!< Jibe RAM base address
#define MML_MEM_RAM_SIZE		0x60000				//!< Jibe RAM size (384 kB)
#define RAM_BASE				MML_MEM_RAM_BASE	//!< RAM base address
#define RAM_SIZE				MML_MEM_RAM_SIZE	//!< RAM size
#define MML_MEM_ITCM_BASE		0x00600000			//!< I-TCM base addresss
#define MML_MEM_ITCM_SIZE		0x1000				//!< I-TCM size
#define MML_MEM_DTCM_BASE		0x00700000			//!< I-TCM base addresss
#define MML_MEM_DTCM_SIZE		0x1000				//!< I-TCM size
#define MML_MEM_NVSRAM_BASE	0x00A00000			//!< Jibe NVSRAM base address
#define MML_MEM_NVSRAM_SIZE	0x4000				//!< Jibe NVSRAM size
#define MML_MEM_HASH_BASE		0xFFF60000			//!< Jibe Hash memory base address
#define MML_MEM_HASH_SIZE		0x400				//!< Jibe Hash memory size


#define MML_MEM_OTP_BASE		0xFFF00000			//!< Jibe OTP base address
#define MML_MEM_OTP_MXIM_BASE	MML_MEM_OTP_BASE	//!< Jibe OTP MAXIM based address
#define MML_MEM_OTP_MXIM_SIZE	0x400				//!< mml OTP AXIM size
#define MML_MEM_OTP_USER_BASE	(MML_MEM_OTP_MXIM_BASE + MML_MEM_OTP_MXIM_SIZE)			//!< Jibe OTP Customer based address
#define MML_MEM_OTP_USER_SIZE	0xc00				//!< mml OTP Customer size
#define MML_MEM_OTP_SIZE		(MML_MEM_OTP_MXIM_SIZE +\
								MML_MEM_OTP_USER_SIZE)		//!< Jibe OTP size
#define MML_MEM_SNVSRAM_BASE	0xFFF10000			//!< Jibe SNVSRAM base address
#define MML_MEM_SNVSRAM_SIZE	0x1800				//!< Jibe SNVSRAM size

#define	MML_MEM_NAND_BASE		0x10000000			//!< Jibe NAND base address
#define	MML_MEM_NAND_SIZE		0x20000000			//!< Jibe NAND size

#define	MML_MEM_SMEM0_BASE		0x30000000			//!< Jibe SMEM0 base address
#define	MML_MEM_SMEM0_SIZE		0x4000000			//!< Jibe SMEM0 size
#define	MML_MEM_SMEM1_BASE		0x34000000			//!< Jibe SMEM1 base address
#define	MML_MEM_SMEM1_SIZE		0x4000000			//!< Jibe SMEM1 size
#define	MML_MEM_SMEM2_BASE		0x38000000			//!< Jibe SMEM2 base address
#define	MML_MEM_SMEM2_SIZE		0x4000000			//!< Jibe SMEM2 size
#define	MML_MEM_SMEM3_BASE		0x3c000000			//!< Jibe SMEM3 base address
#define	MML_MEM_SMEM3_SIZE		0x4000000			//!< Jibe SMEM3 size
#define	MML_MEM_SMEM4_BASE		0x40000000			//!< Jibe SMEM4 base address
#define	MML_MEM_SMEM4_SIZE		0x4000000			//!< Jibe SMEM4 size
#define	MML_MEM_SMEM5_BASE		0x44000000			//!< Jibe SMEM5 base address
#define	MML_MEM_SMEM5_SIZE		0x4000000			//!< Jibe SMEM5 size
#define	MML_MEM_SMEM6_BASE		0x48000000			//!< Jibe SMEM6 base address
#define	MML_MEM_SMEM6_SIZE		0x4000000			//!< Jibe SMEM6 size
#define	MML_MEM_SMEM7_BASE		0x4c000000			//!< Jibe SMEM7 base address
#define	MML_MEM_SMEM7_SIZE		0x4000000			//!< Jibe SMEM7 size

#define	MML_MEM_DDRRAM0_BASE	0x70000000			//!< Jibe SD/DDR RAM0 base address
#define	MML_MEM_DDRRAM0_SIZE	0x20000000			//!< Jibe SD/DDR RAM0 size
#define	MML_MEM_DDRRAM1_BASE	0x90000000			//!< Jibe SD/DDR RAM1 base address
#define	MML_MEM_DDRRAM1_SIZE	0x20000000			//!< Jibe SD/DDR RAM1 size

/** @} */
/* ========================================================================== */
/** @defgroup MML_IO Jibe IOs
 * @{
 */

#ifndef __ASSEMBLY__
/** Convert PA to VA. */
#  define IO_ADDRESS(x) (unsigned char *)(x)
#else
/** Convert PA to VA. */
#  define IO_ADDRESS(x) (x)
#endif /* __ASSEMBLY__ */


#define MML_IOBASE			0xFFE00000 				//!< AHB IO Physical Base Address
#define MML_IOBASE_ADDR	IO_ADDRESS(MML_IOBASE)	//!< AHB IO Virtual Base Address

#define MML_AHB_IOBASE			0xFFF50000						//!< APB IO Physical Base Address
#define MML_AHB_IOBASE_ADDR	IO_APB_ADDRESS(MML_AHB_IOBASE)	//!< APB IO Virtual Base Address

/* -------------------------------------------------------------------------- */
/** @defgroup MML_PORT Jibe IOs Ports
 *
 * Offsets.
 * @{
 */

#define MML_SIR_PORT		0x00000 //! SIR
#define MML_GCR_PORT		0x01000 //! GCR
#define MML_SMON_PORT		0x02000 //! Security Monitor
#define MML_INTC_PORT		0x03000 //! Interrupt Controller
#define MML_WDT_PORT		0x04000 //! Watchdog Timer
#define MML_DMA_PORT		0x05000 //! DMA
#define MML_RFU1_PORT		0x06000 //! Reserved
#define MML_TIC_PORT		0x07000 //! TIC
#define MML_GPIO0_PORT		0x08000 //! GPIO 0
#define MML_GPIO1_PORT		0x09000 //! GPIO 1
#define MML_GPIO2_PORT		0x0A000 //! GPIO 2
#define MML_GPIO3_PORT		0x0B000 //! GPIO 3
#define MML_GPIO4_PORT		0x0C000 //! GPIO 4
#define MML_TMR0_PORT		0x18000 //! PWM Timers 0
#define MML_TMR1_PORT		0x19000 //! PWM Timers 1
#define MML_TMR2_PORT		0x1A000 //! PWM Timers 2
#define MML_UART0_PORT		0x28000 //! UART 0
#define MML_UART1_PORT		0x29000 //! UART 1
#define MML_UART2_PORT		0x2A000 //! UART 2
#define MML_SPI0_PORT		0x30000 //! SPI 0
#define MML_SPI1_PORT		0x31000 //! SPI 1
#define MML_SPI2_PORT		0x32000 //! SPI 2
#define MML_SPI3_PORT		0x33000 //! SPI 3
#define MML_SPI4_PORT		0x34000 //! SPI 4
#define MML_I2C_PORT		0x40000 //! I2C
#define MML_OTPC_PORT		0x4F000 //! OTP Controller
/* #define MML_EBC_PORT		0x50000 //! External Bus Control */
#define MML_RTC_PORT		0x52000 //! RTC
#define MML_SHA_PORT		0x54000 //! SHA
#define MML_DES_PORT		0x55000 //! DES
#define MML_AES_PORT		0x56000 //! AES
#define MML_MCR_PORT		0x56000 //! MCR
#define MML_CRYPTO_PORT	0x57000 //! Crypto
#define MML_SC0_PORT		0x60000 //! Smart Card 0
#define MML_SC1_PORT		0x61000 //! Smart Card 1
#define MML_SKBD_PORT		0x68000 //! SKBD
#define MML_TPR_PORT		0x69000 //! Thermal Printer
#define MML_LCD_PORT		0x6C000 //! Mono LCD
#define MML_TDC_PORT		0x6D000 //! Color LCD // TRusted CLCD
#define MML_ETH_PORT		0x70000 //! Ethernet
#define MML_ACR_PORT		0xC0000 //! Analog Control Registers
#define MML_SNVRF_PORT		0x120000//! Secure NVSRF


#define MML_USB_PORT		0x00000 //! USB
#define MML_USBH_PORT		0x00000 //! USBH
#define MML_USBP_PORT		0x01000 //! USBP
#define MML_UCI0_PORT		0x0A000 //! UCI0
#define MML_NFC_PORT		0x0A800 //! NFC
#define MML_EBC_PORT		0x0AC00 //! EBC
#define MML_DMC_PORT		MML_EBC_PORT //! Dual Memory Controller
#define MML_SDR_PORT		MML_DMC_PORT + 0x80 //! SDRAM Controller
#define MML_SMEM_PORT		MML_DMC_PORT + 0x100 //! Static RAM Controller
#define MML_UCI1_PORT		0x0B000 //! UCI1
#define MML_SDMC_PORT		0x0C000 //! SD/SDHC/SDIO
#define MML_TRNG_PORT		0x11000 //! TRNG


/** @} */
/* -------------------------------------------------------------------------- */
/** @defgroup MML_IOBASE Jibe IOs Physical Addresses
 * @{
 */

#define MML_SIR_IOBASE		(MML_IOBASE + MML_SIR_PORT)		//! SIR Physical Address
#define MML_GCR_IOBASE		(MML_IOBASE + MML_GCR_PORT)		//! GCR Physical Address
#define MML_SMON_IOBASE	(MML_IOBASE + MML_SMON_PORT)		//! Security Monitor Physical Address
#define MML_INTC_IOBASE	(MML_IOBASE + MML_INTC_PORT)		//! Interrupt Controller Physical Address
#define MML_WDT_IOBASE		(MML_IOBASE + MML_WDT_PORT)		//! Watchdog Timer Physical Address
#define MML_DMA_IOBASE		(MML_IOBASE + MML_DMA_PORT)		//! DMA Physical Address
#define MML_TIC_IOBASE		(MML_IOBASE + MML_TIC_PORT)		//! TIC Physical Address
#define MML_GPIO0_IOBASE	(MML_IOBASE + MML_GPIO0_PORT)		//! GPIO 0 Physical Address
#define MML_GPIO1_IOBASE	(MML_IOBASE + MML_GPIO1_PORT)		//! GPIO 1 Physical Address
#define MML_GPIO2_IOBASE	(MML_IOBASE + MML_GPIO2_PORT)		//! GPIO 2 Physical Address
#define MML_GPIO3_IOBASE	(MML_IOBASE + MML_GPIO3_PORT)		//! GPIO 3 Physical Address
#define MML_GPIO4_IOBASE	(MML_IOBASE + MML_GPIO4_PORT)		//! GPIO 4 Physical Address
#define MML_TMR0_IOBASE	(MML_IOBASE + MML_TMR0_PORT)		//! PWM Timers 0 Physical Address
#define MML_TMR1_IOBASE	(MML_IOBASE + MML_TMR1_PORT)		//! PWM Timers 1 Physical Address
#define MML_TMR2_IOBASE	(MML_IOBASE + MML_TMR2_PORT)		//! PWM Timers 2 Physical Address
#define MML_UART0_IOBASE	(MML_IOBASE + MML_UART0_PORT)		//! UART 0 Physical Address
#define MML_UART1_IOBASE	(MML_IOBASE + MML_UART1_PORT)		//! UART 1 Physical Address
#define MML_UART2_IOBASE	(MML_IOBASE + MML_UART2_PORT)		//! UART 2 Physical Address
#define MML_SPI0_IOBASE	(MML_IOBASE + MML_SPI0_PORT)		//! SPI 0 Physical Address
#define MML_SPI1_IOBASE	(MML_IOBASE + MML_SPI1_PORT)		//! SPI 1 Physical Address
#define MML_SPI2_IOBASE	(MML_IOBASE + MML_SPI2_PORT)		//! SPI 2 Physical Address
#define MML_SPI3_IOBASE	(MML_IOBASE + MML_SPI3_PORT)		//! SPI 3 Physical Address
#define MML_SPI4_IOBASE	(MML_IOBASE + MML_SPI4_PORT)		//! SPI 4 Physical Address
#define MML_I2C_IOBASE		(MML_IOBASE + MML_I2C_PORT)		//! I2C Physical Address
#define MML_OTPC_IOBASE	(MML_IOBASE + MML_OTPC_PORT)		//! OPT Controller Physical Address
//#define MML_EBC_IOBASE		(MML_IOBASE + MML_EBC_PORT)		//! External Bus Control Physical Address
#define MML_RTC_IOBASE		(MML_IOBASE + MML_RTC_PORT)		//! RTC Physical Address
#define MML_CRYPTO_IOBASE	(MML_IOBASE + MML_CRYPTO_PORT)	//! Crypto Physical Address
#define MML_DES_IOBASE		(MML_IOBASE + MML_DES_PORT)		//! DES Physical Address
#define MML_AES_IOBASE		(MML_IOBASE + MML_AES_PORT)		//! AES Physical Address
#define MML_SHA_IOBASE		(MML_IOBASE + MML_SHA_PORT)		//! SHA Physical Address

#define MML_MCR_IOBASE		(MML_IOBASE + MML_MCR_PORT)		//! MCR Physical Address
#define MML_SC0_IOBASE		(MML_IOBASE + MML_SC0_PORT)		//! Smart Card 0 Physical Address
#define MML_SC1_IOBASE		(MML_IOBASE + MML_SC1_PORT)		//! Smart Card 1 Physical Address
#define MML_SKBD_IOBASE	(MML_IOBASE + MML_SKBD_PORT)		//! SKBD Physical Address
#define MML_TPR_IOBASE		(MML_IOBASE + MML_TPR_PORT)		//! Thermal printer Physical Address
#define MML_LCD_IOBASE		(MML_IOBASE + MML_LCD_PORT)		//! Mono LCD Physical Address
#define MML_TDC_IOBASE		(MML_IOBASE + MML_TDC_PORT)		//! Color TFT/LCD Physical Address
#define MML_ETH_IOBASE		(MML_IOBASE + MML_ETH_PORT)		//! Ethernet
#define MML_ACR_IOBASE		(MML_IOBASE + MML_ACR_PORT)		//! Analog Control Registers  Physical Address
#define MML_SNVRF_IOBASE	(MML_IOBASE + MML_SNVRF_PORT)		//! Secure NVSRF  Physical Address

#define MML_USB_IOBASE		(MML_AHB_IOBASE + MML_USB_PORT)	//! USB
#define MML_USBH_IOBASE	(MML_AHB_IOBASE + MML_USBH_PORT)	//! USBH
#define MML_USBP_IOBASE	(MML_AHB_IOBASE + MML_USBP_PORT)	//! USBP
#define MML_SDMC_IOBASE	(MML_AHB_IOBASE + MML_SDMC_PORT)	//! SD/MC
#define MML_UCI0_IOBASE	(MML_AHB_IOBASE + MML_UCI0_PORT)	//! UCI0
#define MML_NFC_IOBASE		(MML_AHB_IOBASE + MML_NFC_PORT)	//! NFC
#define MML_EBC_IOBASE		(MML_AHB_IOBASE + MML_EBC_PORT)	//! External Bus Control Physical Address
#define MML_DMC_IOBASE		(MML_AHB_IOBASE + MML_DMC_PORT)		//! Dual Memory Control Physical Address
#define MML_SDR_IOBASE		(MML_AHB_IOBASE + MML_SDR_PORT)		//! SDRAM Memory Control Physical Address
#define MML_SMEM_IOBASE	(MML_AHB_IOBASE + MML_SMEM_PORT)		//! Static Memory Control Physical Address
#define MML_UCI1_IOBASE	(MML_AHB_IOBASE + MML_UCI1_PORT)	//! UCI1
#define MML_TRNG_IOBASE	(MML_AHB_IOBASE + MML_TRNG_PORT)	//! TRNG Physical Address

/** @} */
/* -------------------------------------------------------------------------- */
/** @defgroup MML_IOMEM Jibe IOs Virtual Addresses
 * @{
 */

#define MML_SIR_IOMEM		IO_ADDRESS(MML_SIR_IOBASE)		//! SIR Virtual Address
#define MML_GCR_IOMEM		IO_ADDRESS(MML_GCR_IOBASE)		//! GCR Virtual Address
#define MML_SMON_IOMEM		IO_ADDRESS(MML_SMON_IOBASE)	//! Security Monitor Virtual Address
#define MML_INTC_IOMEM		IO_ADDRESS(MML_INTC_IOBASE)	//! Interrupt Controller Virtual Address
#define MML_WDT_IOMEM		IO_ADDRESS(MML_WDT_IOBASE)		//! Watchdog Timer Virtual Address
#define MML_DMA_IOMEM		IO_ADDRESS(MML_DMA_IOBASE)		//! DMA Virtual Address
#define MML_TIC_IOMEM		IO_ADDRESS(MML_TIC_IOBASE)		//! TIC Virtual Address
#define MML_GPIO0_IOMEM	IO_ADDRESS(MML_GPIO0_IOBASE)	//! GPIO 0 Virtual Address
#define MML_GPIO1_IOMEM	IO_ADDRESS(MML_GPIO1_IOBASE)	//! GPIO 1 Virtual Address
#define MML_GPIO2_IOMEM	IO_ADDRESS(MML_GPIO2_IOBASE)	//! GPIO 2 Virtual Address
#define MML_GPIO3_IOMEM	IO_ADDRESS(MML_GPIO3_IOBASE)	//! GPIO 3 Virtual Address
#define MML_GPIO4_IOMEM	IO_ADDRESS(MML_GPIO4_IOBASE)	//! GPIO 4 Virtual Address
#define MML_TMR0_IOMEM		IO_ADDRESS(MML_TMR0_IOBASE)	//! PWM Timers 0 Virtual Address
#define MML_TMR1_IOMEM		IO_ADDRESS(MML_TMR1_IOBASE)	//! PWM Timers 1 Virtual Address
#define MML_TMR2_IOMEM		IO_ADDRESS(MML_TMR2_IOBASE)	//! PWM Timers 2 Virtual Address
#define MML_UART0_IOMEM	IO_ADDRESS(MML_UART0_IOBASE)	//! UART 0 Virtual Address
#define MML_UART1_IOMEM	IO_ADDRESS(MML_UART1_IOBASE)	//! UART 1 Virtual Address
#define MML_UART2_IOMEM	IO_ADDRESS(MML_UART2_IOBASE)	//! UART 2 Virtual Address
#define MML_SPI0_IOMEM		IO_ADDRESS(MML_SPI0_IOBASE)	//! SPI 0 Virtual Address
#define MML_SPI1_IOMEM		IO_ADDRESS(MML_SPI1_IOBASE)	//! SPI 1 Virtual Address
#define MML_SPI2_IOMEM		IO_ADDRESS(MML_SPI2_IOBASE)	//! SPI 2 Virtual Address
#define MML_SPI3_IOMEM		IO_ADDRESS(MML_SPI3_IOBASE)	//! SPI 3 Virtual Address
#define MML_SPI4_IOMEM		IO_ADDRESS(MML_SPI4_IOBASE)	//! SPI 4 Virtual Address
#define MML_I2C_IOMEM		IO_ADDRESS(MML_I2C_IOBASE)		//! I2C Virtual Address
#define MML_OTPC_IOMEM		IO_ADDRESS(MML_OTPC_IOBASE)	//! OPT Controller Virtual Address
#define MML_EBC_IOMEM		IO_ADDRESS(MML_EBC_IOBASE)		//! External Bus Control Virtual Address
#define MML_RTC_IOMEM		IO_ADDRESS(MML_RTC_IOBASE)		//! RTC Virtual Address
#define MML_CRYPTO_IOMEM	IO_ADDRESS(MML_CRYPTO_IOBASE)	//! Crypto Virtual Address
#define MML_DES_IOMEM		IO_ADDRESS(MML_DES_IOBASE)		//! DES Virtual Address
#define MML_AES_IOMEM		IO_ADDRESS(MML_AES_IOBASE)		//! AES Virtual Address
#define MML_SHA_IOMEM		IO_ADDRESS(MML_SHA_IOBASE)		//! SHA Virtual Address
#define MML_MCR_IOMEM		IO_ADDRESS(MML_MCR_IOBASE)		//! MCR Virtual Address
#define MML_SC0_IOMEM		IO_ADDRESS(MML_SC0_IOBASE)		//! Smart Card 0 Virtual Address
#define MML_SC1_IOMEM		IO_ADDRESS(MML_SC1_IOBASE)		//! Smart Card 1 Virtual Address
#define MML_SKBD_IOMEM		IO_ADDRESS(MML_SKBD_IOBASE)	//! SKBD Virtual Address
#define MML_TPR_IOMEM		IO_ADDRESS(MML_TPR_IOBASE)		//! Thermal printer Virtual Address
#define MML_LCD_IOMEM		IO_ADDRESS(MML_LCD_IOBASE)		//! Mono LCD Virtual Address
#define MML_TDC_IOMEM		IO_ADDRESS(MML_TDC_IOBASE)		//! Color TFT/LCD Virtual Address
#define MML_ETH_IOMEM		IO_ADDRESS(MML_ETH_IOBASE)		//! Ethernet MAC Virtual Address
#define MML_ACR_IOMEM		IO_ADDRESS(MML_ACR_IOBASE)		//! Analog Control Registers
#define MML_SNVRF_IOMEM	IO_ADDRESS(MML_SNVRF_IOBASE)	//! Secure NVSRF Registers

#define MML_USB_IOMEM		IO_ADDRESS(MML_USB_IOBASE)		//! USB Virtual Address
#define MML_USBH_IOMEM		IO_ADDRESS(MML_USBH_IOBASE)	//! USBH Virtual Address
#define MML_USBP_IOMEM		IO_ADDRESS(MML_USBP_IOBASE)	//! USBP Virtual Address
#define MML_SDMC_IOMEM		IO_ADDRESS(MML_SDMC_IOBASE)	//! SD/MC IO Virtual Address
#define MML_UCI0_IOMEM		IO_ADDRESS(MML_UCI0_IOBASE)	//! UCI0 Virtual Address
#define MML_UCI1_IOMEM		IO_ADDRESS(MML_UCI1_IOBASE)	//! UCI1 Virtual Address
#define MML_TRNG_IOMEM		IO_ADDRESS(MML_TRNG_IOBASE)	//! TRNG Virtual Address

/** _MML_SPEC_0_0_7_ */
#define MML_NFC_IOMEM		IO_ADDRESS(MML_NFC_IOBASE)		//! NAND Flash Controller Virtual Address
#define MML_DMC_IOMEM		IO_ADDRESS(MML_DMC_IOBASE)		//! Dual Memory Controller Virtual Address
#define MML_SDR_IOMEM		IO_ADDRESS(MML_SDR_IOBASE)		//! SDRAM Memory Controller Virtual Address
#define MML_SMEM_IOMEM		IO_ADDRESS(MML_SMEM_IOBASE)	//! Static Memory Controller Virtual Address
/*  */
/** @} */

/** @} */ /* @defgroup MML_IO */

/* -------------------------------------------------------------------------- */
/** @defgroup MML_GPIO_STATUS Jibe GPIO Status
 * @{
 */

#define MML_GPIO0_SC1 0x0FF00000
#define MML_GPIO1_SC0 0x00FF0000

#if STATUS_USES_GPIOS_SC0 == 1
#define STATUS_GPIO_START		(1<<16)
#define STATUS_GPIO_ERROR		(1<<17)
#define STATUS_GPIO_EXIT 		(1<<18)
#define STATUS_GPIO_UNDEFINED	(1<<19)
#define STATUS_GPIO_SWI 		(1<<20)
#define STATUS_GPIO_ABORT 		(1<<21)
#define STATUS_GPIO_PREFETCH 	(1<<22)
#define STATUS_GPIO_IRQ 		(1<<23)
#define STATUS_GPIO_FIRQ 		(1<<24)
#else /* #if STATUS_USES_GPIOS_SC0 == 1 */
#define STATUS_GPIO_START		(1<<20)
#define STATUS_GPIO_ERROR		(1<<21)
#define STATUS_GPIO_EXIT 		(1<<22)
#define STATUS_GPIO_UNDEFINED	(1<<23)
#define STATUS_GPIO_SWI 		(1<<24)
#define STATUS_GPIO_ABORT 		(1<<25)
#define STATUS_GPIO_PREFETCH 	(1<<26)
#define STATUS_GPIO_IRQ 		(1<<27)
#define STATUS_GPIO_FIRQ 		(1<<28)
#endif /* #if STATUS_USES_GPIOS_SC0 == 1 */

/** @} */
/* -------------------------------------------------------------------------- */
/** @defgroup MML_INT_SRC Jibe Interruption Sources
 *
 * @{
 */

/*
 * Interrupt Channel Numbers
 */

#define MML_INTNUM_PWRF	 0
#define MML_INTNUM_WDT	 	 1
#define MML_INTNUM_USBH 	 2
#define MML_INTNUM_USBP 	 3
#define MML_INTNUM_SHA	 	 4
#define MML_INTNUM_AES		 5
#define MML_INTNUM_RTC		 6
#define MML_INTNUM_TRNG	 7
#define MML_INTNUM_TMR0	 8
#define MML_INTNUM_TMR1	 9
#define MML_INTNUM_TMR2 	10
#define MML_INTNUM_SC0		11
#define MML_INTNUM_SC1		12
#define MML_INTNUM_LCD		13
#define MML_INTNUM_I2C		14
#define MML_INTNUM_TDC		15
#define MML_INTNUM_UART0	16
#define MML_INTNUM_UART1	17
#define MML_INTNUM_UART2	18
#define MML_INTNUM_SPI0	19
#define MML_INTNUM_SPI1	20
#define MML_INTNUM_SPI2	21
#define MML_INTNUM_SPI3	22
#define MML_INTNUM_SPI4	23
#define MML_INTNUM_SKB		24
#define MML_INTNUM_TPR		25
#define MML_INTNUM_SDC		26
#define MML_INTNUM_EMAC	27

#define MML_INTNUM_ADC	        28
#define MML_INTNUM_UCI0        29
#define MML_INTNUM_UCI1        30

#define MML_INTNUM_GPIO0	32
#define MML_INTNUM_GPIO1	33
#define MML_INTNUM_GPIO2	34
#define MML_INTNUM_GPIO3	35
#define MML_INTNUM_GPIO4	36
#define MML_INTNUM_CRYPTO	37
#define MML_INTNUM_DES	    38
#define MML_INTNUM_DMC	        39

#define MML_INTNUM_DMA0	48
#define MML_INTNUM_DMA1	49
#define MML_INTNUM_DMA2	50
#define MML_INTNUM_DMA3	51
#define MML_INTNUM_DMA4	52
#define MML_INTNUM_DMA5	53
#define MML_INTNUM_DMA6	54
#define MML_INTNUM_DMA7	55
#define MML_INTNUM_DMA8	56
#define MML_INTNUM_DMA9	57
#define MML_INTNUM_DMA10	58
#define MML_INTNUM_DMA11	59
#define MML_INTNUM_DMA12	60
#define MML_INTNUM_DMA13	61
#define MML_INTNUM_DMA14	62
#define MML_INTNUM_DMA15	63

/*DMA interrupt number with idex to select one of the channel */
#define MML_INTNUM_DMA(x)	48+x

/** @} */ /* @defgroup MML_INT_SRC */

/* System Frequency */
#ifdef _FPGA_WORKAROUND_
#define MML_PLLO_FREQ      40000000 // JIBE emulator
#else
#define MML_PLLO_FREQ      192000000 // JIBE real silicon
#endif /* _FPGA_WORKAROUND_ */

#define MML_SYS_FREQ       MML_PLLO_FREQ
#define MML_APB_FREQ       ( MML_SYS_FREQ / 2 )

/** @} */ /* @defgroup JIBE */

#endif /* MML_H_ */
