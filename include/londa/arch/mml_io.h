/*
 * mml_io.h --
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
 * Created on: Jun 23, 2010
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 753      $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2010-11-10 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */
#ifndef MML_IO_H_
#define MML_IO_H_

#include "io.h"

#include "dev/mml_dma_regs.h"
#include "dev/mml_fctrl_regs.h"
#include "dev/mml_gcr_regs.h"
#include "dev/mml_gpio_regs.h"
#include "dev/mml_i2c_regs.h"
#include "dev/mml_intc_regs.h"
#include "dev/mml_rtc_regs.h"
#include "dev/mml_sc_regs.h"
#include "dev/mml_sec_regs.h"
#include "dev/mml_skbd_regs.h"
#include "dev/mml_smon_regs.h"
#include "dev/mml_spi_regs.h"
#include "dev/mml_tdc_regs.h"
#include "dev/mml_tmr_regs.h"
#include "dev/mml_trng_regs.h"
#include "dev/mml_uart_regs.h"
#include "dev/mml_usb_regs.h"
#include "dev/mml_wdg_regs.h"

#ifndef __ASSEMBLER__

#include "dev/cobra_gpio.h"
#include "dev/cobra_gcr.h"
#include "dev/cobra_intc.h"
#include "dev/cobra_tmr.h"
#include "dev/cobra_uart.h"

/** Londa IOs Structure.
 *
 */
typedef struct _mml_ios_s_ {
	mml_dma_regs_t	*dma;	//!< DMA
	mml_fctrl_regs_t	*fctrl;	//!< Flash Controller
	mml_gcr_regs_t	*gcr;	//!< Global Control Registers
	mml_gpio_regs_t	*gpio0;	//!< GPIO0
	mml_gpio_regs_t	*gpio1;	//!< GPIO1
	mml_gpio_regs_t	*gpio2;	//!< GPIO2
	mml_gpio_regs_t	*gpio3;	//!< GPIO3
	mml_i2c_regs_t	*i2c;	//!< I2C
	mml_intc_regs_t	*intc;	//!< Interrupt Controller
	mml_rtc_regs_t	*rtc;	//!< RTC
	mml_sc_regs_t		*sc0;	//!< Smart Card 0
	mml_sc_regs_t		*sc1;	//!< Smart Card 1
	mml_sec_regs_t	*sec;	//!< Security island
	mml_skbd_regs_t	*skbd;	//!< Secure Keyboard
	mml_smon_regs_t	*smon;	//!< Security Monitor
	mml_spi_regs_t	*spi0;	//!< SPI 0
	mml_spi_regs_t	*spi1;	//!< SPI 1
	mml_tdc_regs_t	*tdc;	//!< Trusted Display Controller
	mml_tmr_regs_t	*tmr0;	//!< Timer 0
	mml_tmr_regs_t	*tmr1;	//!< Timer 1
	mml_tmr_regs_t	*tmr2;	//!< Timer 2
	mml_tmr_regs_t	*tmr3;	//!< Timer 3
	mml_trng_regs_t	*trng;	//!< TRNG
	mml_uart_regs_t	*uart0;	//!< UART 0
	mml_uart_regs_t	*uart1;	//!< UART 1
	mml_uart_regs_t	*uart2;	//!< UART 2
	mml_usb_regs_t	*usb;	//!< USB device
	mml_wdg_regs_t	*wdg;	//!< Watchdog
} mml_ios_t;

/** Londa IOs.
 *
 */
extern mml_ios_t *mml_ios;

/* ------------------------------------------------------------------------- */

/** PADS Configuration
 *
 * {GPIO, Offset, Mask}
 *
 * */

#define MML_GPIO_MODE_UART0	{MML_GPIO1_IOBASE, 24, 0xF}
#define MML_GPIO_MODE_UART1	{MML_GPIO1_IOBASE, 16, 0xF}
#define MML_GPIO_MODE_UART2	{MML_GPIO1_IOBASE, 20, 0xF}

#endif /* #ifndef __ASSEMBLER__ */

#endif /* MML_IO_H_ */
