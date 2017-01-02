/*
 * start_c.c -- C startup code
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
 * Created on: May 19, 2010
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 2405     $:  Revision of last commit
 * $Author:: seeniraj.n#$:  Author of last commit
 * $Date:: 2012-01-19 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

/** Global includes */
#include <config.h>
/** Other includes */
#include <mml_io.h>
#include <arch/arm/ttb.h>
#include <mml_gcr_regs.h>
#ifdef _WITH_WDT_RESET_
#include <mml_intc.h>
#include <mml_wdt_regs.h>
#include <mml_intc_regs.h>
#endif /* _WITH_WDT_RESET_ */
/** Local includes */


#define	K_COBRA_RESET_WDT_WAIT_LOOP_MAX		500

void __start_c(void) __attribute__ ((section (".text.init")));

#if ENABLE_UART == 1
extern mml_uart_regs_t *_uart_stdin;
extern mml_uart_regs_t *_uart_stdout;
extern mml_uart_regs_t *_uart_stderr;
#endif /* ENABLE_UART */

#if ENABLE_GPIO == 1
volatile mml_gpio_regs_t *status_gpios = 0;
#endif /* ENABLE_GPIO */

void __main(void);

void __start_c(void)
{
	register unsigned int					loop;
#ifdef _WITH_WDT_RESET_
	unsigned int							tmp_wdt = 0;
	volatile mml_wdt_regs_t					*reg_wdt = (volatile mml_wdt_regs_t*)MML_WDT_IOBASE;
	volatile mml_intc_regs_t				*reg_intc = (volatile mml_intc_regs_t*)MML_INTC_IOBASE;
#endif /* _WITH_WDT_RESET_ */
	volatile mml_gcr_regs_t					*reg_gcr = (volatile mml_gcr_regs_t*)MML_GCR_IOBASE;

#if ENABLE_UART == 1
	volatile mml_gpio_regs_t				*reg_gpio0 = (volatile mml_gpio_regs_t*)MML_GPIO0_IOBASE;
 	unsigned int							config;
	unsigned int							uart0_pads[3] = MML_GPIO_MODE_UART0;
#endif /* ENABLE_UART */


#ifdef _WITH_WDT_RESET_
	/** Acknowledge interruption if any */
	reg_intc->irq_end = 0x1;
	/** Remove interruption parameters related to WDT */
	reg_intc->enable0_clr |= ( 0x1 << MML_INTC_WDT );
	reg_intc->vector[MML_INTC_WDT] = (unsigned int)_handler_irq_;
	/** Save RST_FLAG value ... */
	tmp_wdt = ( reg_wdt->control & MML_WDT_CTRL_WDRSTF_MASK );
	/** ... reset WDT asap ... */
	reg_gcr->rstr |= MML_GCR_RSTR_WDT_MASK;
	/** Set default value */
	loop = K_COBRA_RESET_WDT_WAIT_LOOP_MAX;
	/** ... wait for reset to be done ... */
	while( ( reg_gcr->rstr & MML_GCR_RSTR_WDT_MASK ) && loop-- );
	/** ... re-introduce RST_FLAG value */
	reg_wdt->control |= tmp_wdt;
#endif /* _WITH_WDT_RESET_ */

	/** Reset all but CPU ... */
	reg_gcr->rstr |= MML_GCR_RSTR_SRST_MASK;
	/** Set default value */
	loop = K_COBRA_RESET_WDT_WAIT_LOOP_MAX;
	/** ... wait for reset to be done ... */
	while( ( reg_gcr->rstr & MML_GCR_RSTR_SRST_MASK ) && loop-- );

#if ENABLE_UART == 1
	cobra_uart_brr_t							baud = MML_BR_57600;
	/** Enable the UART0 clock */
	reg_gcr->perckcn &= ~( 0x01 <<  MML_GCR_DEV_UART0 );
	reg_gpio0->en &= ~( MML_UART_PAD_CFG_MASK << MML_UART0_PAD_CFG_OFFSET );
	reg_gpio0->en1 &= ~( MML_UART_PAD_CFG_MASK << MML_UART0_PAD_CFG_OFFSET );
	/** UART CONFIGURATION */
	config = (UARTB_CR_SIZE_8BIT);
	cobra_uart_init((cobra_uart_t*)reg_uart0, config, baud);
	_uart_stdin = (mml_uart_regs_t*)reg_uart0;
	_uart_stdout = (mml_uart_regs_t*)reg_uart0;
	_uart_stderr = (mml_uart_regs_t*)reg_uart0;
#else
#endif /* ENABLE_UART */

#if ENABLE_GPIO == 1
 #if STATUS_USES_GPIOS_SC0 == 1
	status_gpios = reg_gpio1;
	reg_gpio1->out_en = MML_GPIO1_SC0;
	reg_gpio1->out = 0x0;
 #else
	status_gpios = reg_gpio0;
	reg_gpio0->out_en = MML_GPIO0_SC1;
	reg_gpio0->out = 0x0;
 #endif /* USE_GPIOS_SC0 */
#endif /* ENABLE_GPIO */
	/** We're done */
	return;
}

/******************************************************************************/
/* EOF */
