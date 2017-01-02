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
 * $Revision:: 779      $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2010-11-18 2#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */
#ifndef MML_H_
#define MML_H_

#include "io.h"

#ifndef __MML__
#	define __MML__ 1
#endif

/** @defgroup LONDA Londa
 * @{
 */

/** @defgroup MML_MEM Londa Memories
 * @{
 */


#define MML_MEM_ROM_BASE		0x00000000			//!< Londa ROM based address
#define MML_MEM_ROM_SIZE		0x80000				//!< Londa ROM size
#define ROM_BASE				MML_MEM_ROM_BASE	//!< ROM based address
#define ROM_SIZE				MML_MEM_ROM_SIZE	//!< ROM size
#define MML_MEM_RAM_BASE		0xFFFE1000			//!< Londa RAM based address
#define MML_MEM_RAM_SIZE		0x10000				//!< Londa RAM size
#define RAM_BASE				MML_MEM_RAM_BASE	//!< RAM based address
#define RAM_SIZE				MML_MEM_RAM_SIZE	//!< RAM size
#define MML_MEM_FLASH_BASE	0x10000000			//!< Londa FLASH based address
#define MML_MEM_FLASH_SIZE	0x20000				//!< Londa FLASH size
#define MML_MEM_OTP_BASE		0x10100000			//!< Londa OPT based address
#define MML_MEM_OTP_SIZE		0x2000				//!< Londa OPT size
#define MML_MEM_OTP_USER_BASE	0x10102000			//!< Londa OPT Customer based address
#define MML_MEM_OTP_USER_SIZE	0x2000				//!< Londa OPT Customer size
#define MML_MEM_TDC_BASE		0x30000000			//!< Londa TDC RAM based address
#define MML_MEM_TDC_SIZE		0x28000				//!< Londa TDC RAM size
#define MML_MEM_SEC_BASE		0x40000000			//!< Londa SEC RAM based address
#define MML_MEM_SEC_SIZE		0x400				//!< Londa SEC RAM size
#define MML_MEM_NVSRAM_BASE	0xFFFF1000			//!< Londa NVSRAM based address
#define MML_MEM_NVSRAM_SIZE	0x4000				//!< Londa NVSRAM size
#define MML_MEM_SNVSRAM_BASE	0x80100000			//!< Londa SNVSRAM based address
#define MML_MEM_SNVSRAM_SIZE	0x2000				//!< Londa SNVSRAM size

/** @} */
/* ========================================================================== */
/** @defgroup MML_IO Londa IOs
 * @{
 */

#ifndef __ASSEMBLY__
/** Convert PA to VA. */
#  define IO_ADDRESS(x) (unsigned char *)(x)
#else
/** Convert PA to VA. */
#  define IO_ADDRESS(x) (x)
#endif /* __ASSEMBLY__ */


#define MML_IOBASE			0x80000000 							//!< AHB IO Physical Base Address
#define MML_IOBASE_ADDR		IO_ADDRESS(MML_IOBASE)			//!< AHB IO Virtual Base Address

#define MML_AHB_IOBASE		0x70000000							//!< APB IO Physical Base Address
#define MML_AHB_IOBASE_ADDR	IO_APB_ADDRESS(MML_AHB_IOBASE)	//!< APB IO Virtual Base Address

/* -------------------------------------------------------------------------- */
/** @defgroup MML_PORT Londa IOs Ports
 *
 * Offsets.
 * @{
 */
#define MML_GCR_PORT		0x00000 //! Global Control Register
#define MML_SKBD_PORT		0x01000 //! SKBD
#define MML_SPI0_PORT		0x02000 //! SPI 0
#define MML_SPI1_PORT		0x03000 //! SPI 1
#define MML_I2C_PORT		0x04000 //! I2C
#define MML_UART0_PORT	0x05000 //! UART 0
#define MML_UART1_PORT	0x06000 //! UART 1
#define MML_UART2_PORT	0x07000 //! UART 2
#define MML_GPIO0_PORT	0x08000 //! GPIO 0
#define MML_GPIO1_PORT	0x09000 //! GPIO 1
#define MML_GPIO2_PORT	0x0A000 //! GPIO 2
#define MML_GPIO3_PORT	0x0B000 //! GPIO 3
#define MML_SC0_PORT		0x0C000 //! Smart Card 0
#define MML_SC1_PORT		0x0D000 //! Smart Card 1
#define MML_DMA_PORT		0x0E000 //! DMA
#define MML_TMR0_PORT		0x0F000 //! PWM Timers 0
#define MML_TMR1_PORT		0x10000 //! PWM Timers 1
#define MML_TMR2_PORT		0x11000 //! PWM Timers 2
#define MML_TMR3_PORT		0x12000 //! PWM Timers 3
#define MML_WDG_PORT		0x13000 //! Watchdog
#define MML_TDC_PORT		0x14000 //! TDC
#define MML_INTC_PORT		0x15000 //! Interrupt Controller
#define MML_RTC_PORT		0x16000 //! RTC
#define MML_SMON_PORT		0x17000 //! Security Monitor

#define MML_USB_PORT		0x00000 //! USB
#define MML_SEC_PORT		0x01000 //! Security Island
#define MML_TRNG_PORT		0x02000 //! True Random Generator

/** @} */
/* -------------------------------------------------------------------------- */
/** @defgroup MML_IOBASE Londa IOs Physical Addresses
 * @{
 */

#define MML_GCR_IOBASE	(MML_IOBASE + MML_GCR_PORT)
#define MML_SKBD_IOBASE	(MML_IOBASE + MML_SKBD_PORT)
#define MML_SPI0_IOBASE	(MML_IOBASE + MML_SPI0_PORT)
#define MML_SPI1_IOBASE	(MML_IOBASE + MML_SPI1_PORT)
#define MML_I2C_IOBASE	(MML_IOBASE + MML_I2C_PORT)
#define MML_UART0_IOBASE	(MML_IOBASE + MML_UART0_PORT)
#define MML_UART1_IOBASE	(MML_IOBASE + MML_UART1_PORT)
#define MML_UART2_IOBASE	(MML_IOBASE + MML_UART2_PORT)
#define MML_GPIO0_IOBASE	(MML_IOBASE + MML_GPIO0_PORT)
#define MML_GPIO1_IOBASE	(MML_IOBASE + MML_GPIO1_PORT)
#define MML_GPIO2_IOBASE	(MML_IOBASE + MML_GPIO2_PORT)
#define MML_GPIO3_IOBASE	(MML_IOBASE + MML_GPIO3_PORT)
#define MML_SC0_IOBASE	(MML_IOBASE + MML_SC0_PORT)
#define MML_SC1_IOBASE	(MML_IOBASE + MML_SC1_PORT)
#define MML_DMA_IOBASE	(MML_IOBASE + MML_DMA_PORT)
#define MML_TMR0_IOBASE	(MML_IOBASE + MML_TMR0_PORT)
#define MML_TMR1_IOBASE	(MML_IOBASE + MML_TMR1_PORT)
#define MML_TMR2_IOBASE	(MML_IOBASE + MML_TMR2_PORT)
#define MML_TMR3_IOBASE	(MML_IOBASE + MML_TMR3_PORT)
#define MML_WDG_IOBASE	(MML_IOBASE + MML_WDG_PORT)
#define MML_INTC_IOBASE	(MML_IOBASE + MML_INTC_PORT)
#define MML_TDC_IOBASE	(MML_IOBASE + MML_TDC_PORT)
#define MML_RTC_IOBASE	(MML_IOBASE + MML_RTC_PORT)
#define MML_SMON_IOBASE	(MML_IOBASE + MML_SMON_PORT)

#define MML_USB_IOBASE	(MML_AHB_IOBASE + MML_USB_PORT)
#define MML_SEC_IOBASE	(MML_AHB_IOBASE + MML_SEC_PORT)
#define MML_TRNG_IOBASE	(MML_AHB_IOBASE + MML_TRNG_PORT)
#define MML_FCTRL_IOBASE	0xDEAD0000 //! Flash Controller

/** @} */
/* -------------------------------------------------------------------------- */
/** @defgroup MML_IOMEM Londa IOs Virtual Addresses
 * @{
 */

#define MML_GCR_IOMEM		IO_ADDRESS(MML_GCR_IOBASE)
#define MML_SKBD_IOMEM	IO_ADDRESS(MML_SKBD_IOBASE)
#define MML_SPI0_IOMEM	IO_ADDRESS(MML_SPI0_IOBASE)
#define MML_SPI1_IOMEM	IO_ADDRESS(MML_SPI1_IOBASE)
#define MML_I2C_IOMEM		IO_ADDRESS(MML_I2C_IOBASE)
#define MML_UART0_IOMEM	IO_ADDRESS(MML_UART0_IOBASE)
#define MML_UART1_IOMEM	IO_ADDRESS(MML_UART1_IOBASE)
#define MML_UART2_IOMEM	IO_ADDRESS(MML_UART2_IOBASE)
#define MML_GPIO0_IOMEM	IO_ADDRESS(MML_GPIO0_IOBASE)
#define MML_GPIO1_IOMEM	IO_ADDRESS(MML_GPIO1_IOBASE)
#define MML_GPIO2_IOMEM	IO_ADDRESS(MML_GPIO2_IOBASE)
#define MML_GPIO3_IOMEM	IO_ADDRESS(MML_GPIO3_IOBASE)
#define MML_SC0_IOMEM		IO_ADDRESS(MML_SC0_IOBASE)
#define MML_SC1_IOMEM		IO_ADDRESS(MML_SC1_IOBASE)
#define MML_DMA_IOMEM		IO_ADDRESS(MML_DMA_IOBASE)
#define MML_TMR0_IOMEM	IO_ADDRESS(MML_TMR0_IOBASE)
#define MML_TMR1_IOMEM	IO_ADDRESS(MML_TMR1_IOBASE)
#define MML_TMR2_IOMEM	IO_ADDRESS(MML_TMR2_IOBASE)
#define MML_TMR3_IOMEM	IO_ADDRESS(MML_TMR3_IOBASE)
#define MML_WDG_IOMEM		IO_ADDRESS(MML_WDG_IOBASE)
#define MML_INTC_IOMEM	IO_ADDRESS(MML_INTC_IOBASE)
#define MML_TDC_IOMEM		IO_ADDRESS(MML_TDC_IOBASE)
#define MML_RTC_IOMEM		IO_ADDRESS(MML_RTC_IOBASE)
#define MML_SMON_IOMEM	IO_ADDRESS(MML_SMON_IOBASE)

#define MML_USB_IOMEM		IO_ADDRESS(MML_USB_IOBASE)
#define MML_SEC_IOMEM		IO_ADDRESS(MML_SEC_IOBASE)
#define MML_TRNG_IOMEM	IO_ADDRESS(MML_TRNG_IOBASE)
#define MML_FCTRL_IOMEM	IO_ADDRESS(MML_FCTRL_IOBASE)
/** @} */

/** @} */ /* @defgroup MML_IO */

/* -------------------------------------------------------------------------- */
/** @defgroup MML_GPIO_STATUS Londa GPIO Status
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
/** @defgroup MML_INT_SRC Londa Interruption Sources
 *
 * @{
 */

/*
 * Interrupt Channel Numbers
 */

#define MML_INTNUM_WDG	 0
#define MML_INTNUM_UART0	 1
#define MML_INTNUM_USB 	 2
#define MML_INTNUM_SHA	 3
#define MML_INTNUM_AES	 4
#define MML_INTNUM_TMR0	 5
#define MML_INTNUM_TMR1	 6
#define MML_INTNUM_TMR2	 7
#define MML_INTNUM_TMR3	 8
#define MML_INTNUM_RTC	 9
#define MML_INTNUM_EXT_IT	10
#define MML_INTNUM_TRNG	11
#define MML_INTNUM_SC0	12
#define MML_INTNUM_SC1	13
#define MML_INTNUM_SPI0	14
#define MML_INTNUM_SPI1	15
#define MML_INTNUM_I2C	16
#define MML_INTNUM_TDC	17
#define MML_INTNUM_SKBD	18
#define MML_INTNUM_DMA	19
#define MML_INTNUM_UART1	20
#define MML_INTNUM_UART2	21
#define MML_INTNUM_GPIO0	22
#define MML_INTNUM_GPIO1	23
#define MML_INTNUM_GPIO2	24
#define MML_INTNUM_GPIO3	25
#define MML_INTNUM_GPIO4	26
#define MML_INTNUM_FTS	27

/** @} */ /* @defgroup MML_INT_SRC */

/** @} */ /* @defgroup LONDA */

#endif /* MML_H_ */
