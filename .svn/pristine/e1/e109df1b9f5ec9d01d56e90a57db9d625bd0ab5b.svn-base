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
 * $Revision:: 785      $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2010-11-19 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#include "config.h"

#include "arch/arm/ttb.h"

#include "dev/cobra_gpio.h"
#include "dev/cobra_gcr.h"

void __start_c(void) __attribute__ ((section (".text.init")));

extern londa_uart_regs_t *_uart_stdin;
extern londa_uart_regs_t *_uart_stdout;
extern londa_uart_regs_t *_uart_stderr;

static const londa_ios_t __londa_ios = {
	(londa_dma_regs_t *) LONDA_DMA_IOMEM,
	(londa_fctrl_regs_t *) LONDA_FCTRL_IOMEM,
	(londa_gcr_regs_t *) LONDA_GCR_IOMEM,
	(londa_gpio_regs_t *) LONDA_GPIO0_IOMEM,
	(londa_gpio_regs_t *) LONDA_GPIO1_IOMEM,
	(londa_gpio_regs_t *) LONDA_GPIO2_IOMEM,
	(londa_gpio_regs_t *) LONDA_GPIO3_IOMEM,
	(londa_i2c_regs_t *) LONDA_I2C_IOMEM,
	(londa_intc_regs_t *) LONDA_INTC_IOMEM,
	(londa_rtc_regs_t *) LONDA_RTC_IOMEM,
	(londa_sc_regs_t *) LONDA_SC0_IOMEM,
	(londa_sc_regs_t *) LONDA_SC1_IOMEM,
	(londa_sec_regs_t *) LONDA_SEC_IOMEM,
	(londa_skbd_regs_t *) LONDA_SKBD_IOMEM,
	(londa_smon_regs_t *) LONDA_SMON_IOMEM,
	(londa_spi_regs_t *) LONDA_SPI0_IOMEM,
	(londa_spi_regs_t *) LONDA_SPI1_IOMEM,
	(londa_tdc_regs_t *) LONDA_TDC_IOMEM,
	(londa_tmr_regs_t *) LONDA_TMR0_IOMEM,
	(londa_tmr_regs_t *) LONDA_TMR1_IOMEM,
	(londa_tmr_regs_t *) LONDA_TMR2_IOMEM,
	(londa_tmr_regs_t *) LONDA_TMR3_IOMEM,
	(londa_trng_regs_t *) LONDA_TRNG_IOMEM,
	(londa_uart_regs_t *) LONDA_UART0_IOMEM,
	(londa_uart_regs_t *) LONDA_UART1_IOMEM,
	(londa_uart_regs_t *) LONDA_UART2_IOMEM,
	(londa_usb_regs_t *) LONDA_USB_IOMEM,
	(londa_wdg_regs_t *) LONDA_WDG_IOMEM
};

londa_ios_t *londa_ios = (londa_ios_t *)&__londa_ios;
londa_gpio_regs_t *status_gpios = 0;

void __main(void);

void __start_c(void) {
#if ENABLE_UART == 1
	unsigned config;
	unsigned int uart0_pads[3] = LONDA_GPIO_MODE_UART0;
#endif
	/** Power on the RTC */
	cobra_gcr_dev_setpower1(londa_ios->gcr, PFM(GCR_DEV_RTC));


#if ENABLE_UART == 1
	cobra_uart_brr_t baud = UARTB_BR_57600;

	/* Power on the UART0 */
	cobra_gcr_dev_setpower1(londa_ios->gcr, LONDA_GCR_DEV_UART0);

	/* Enable the UART0 */
	cobra_gpio_set_padsmode(uart0_pads, COBRA_PADSMODE_DEV);

	/* UART CONFIGURATION */
	config = (UARTB_CR_SIZE_8BIT | UARTB_CR_RXTHD_DEPTH8);

	cobra_uart_init((cobra_uart_t *) londa_ios->uart0, config, baud);

	_uart_stdin = (londa_uart_regs_t *) londa_ios->uart0;
	_uart_stdout = (londa_uart_regs_t *) londa_ios->uart0;
	_uart_stderr = (londa_uart_regs_t *) londa_ios->uart0;
#else

#endif /* #if ENABLE_UART == 1 */

#if ENABLE_GPIO == 1
#  if STATUS_USES_GPIOS_SC0 == 1

	/* Power on the GPIO1 */
	cobra_gcr_dev_setpower1(londa_ios->gcr, LONDA_GCR_DEV_GPIO1);

	status_gpios = londa_ios->gpio1;
	londa_ios->gpio1->out_en = LONDA_GPIO1_SC0;
	londa_ios->gpio1->out = 0x0;
#  else

	/* Power on the GPIO0 */
	cobra_gcr_dev_setpower1(londa_ios->gcr, LONDA_GCR_DEV_GPIO0);

	status_gpios = londa_ios->gpio0;
	londa_ios->gpio0->out_en = LONDA_GPIO0_SC1;
	londa_ios->gpio0->out = 0x0;
#  endif /* USE_GPIOS_SC0 */
#endif /* #if ENABLE_GPIO == 1 */

	return;
}
