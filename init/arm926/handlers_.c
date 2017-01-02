/*
 * handlers.c --
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
 * Created on: Jun 14, 2010
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 2370     $:  Revision of last commit
 * $Author:: bryan.arms#$:  Author of last commit
 * $Date:: 2011-12-22 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if ENABLE_GPIO
extern SPFM(gpio_regs_t) *status_gpios;
#endif

/* -------------------------------------------------------------------------- */

/** Update the vector table.
 *  Updates contents of 'vector' to contain LDR pc,,[pc,#offset].
 *
 *  @note The vectors MUST be in writable region!
 *
 * @return original contents of 'vector'.
 */
unsigned handler_install(unsigned *handler, unsigned *vector)
{
	unsigned vec, oldvec;
	vec = *handler - (unsigned) vector - 0x8;
	if ((vec & 0xFFFFF000) != 0) {
		_exit(1);
	}
	vec = 0xE59FF000 | vec;
	oldvec = *vector;
	*vector = vec;
	return (oldvec);
}

/* -------------------------------------------------------------------------- */

void handler_undefined_(unsigned fault_addr __sim_unused__) {
#if SIMULATION == 0
#ifdef __DEBUG__
	printf("** EXCEPTION; UNDEFINED **\n");
	printf("Fault Address: 0x%08x\n", fault_addr);
#endif
#endif
#if ENABLE_GPIO
	cobra_gpio_flip(status_gpios, STATUS_GPIO_UNDEFINED);
#endif
	return;
}

/* -------------------------------------------------------------------------- */

void handler_swi_(unsigned code __sim_unused__) {
#if SIMULATION == 0
#ifdef __DEBUG__
	printf("** EXCEPTION; SWI **\n");
	printf("Code: %dx\n", code);
#endif
#endif
#if ENABLE_GPIO
	cobra_gpio_flip(status_gpios, STATUS_GPIO_SWI);
#endif
	return;
}

/* -------------------------------------------------------------------------- */

void handler_abort_(unsigned dfault_status __sim_unused__,
		unsigned fault_addr __sim_unused__,
		unsigned fault_inst __sim_unused__) {
#if SIMULATION == 0
#ifdef __DEBUG__
	printf("** EXCEPTION; ABORT **\n");
	printf("Instruction Address: 0x%08x\n", fault_inst);
	printf("Fault Address: 0x%08x\n", fault_addr);
	printf("Data Fault Status: 0x%08x\n", dfault_status);
#endif
#endif
#if ENABLE_GPIO
	cobra_gpio_flip(status_gpios, STATUS_GPIO_ABORT);
#endif
	return;
}

/* -------------------------------------------------------------------------- */

void handler_prefetch_(unsigned ifault_status __sim_unused__,
		unsigned fault_addr __sim_unused__) {
#if SIMULATION == 0
#ifdef __DEBUG__
	printf("** EXCEPTION: PREFETCH **\n");

	printf("Fault Address: 0x%08x\n", fault_addr);
	printf("Instruction Fault Status: 0x%08x\n", ifault_status);
#endif
#endif
#if ENABLE_GPIO
	cobra_gpio_flip(status_gpios, STATUS_GPIO_PREFETCH);
#endif
	return;
}

void handler_irq_() {
#if SIMULATION == 0
#ifdef __DEBUG__
	printf("** EXCEPTION: IRQ **\n");
#endif
#endif
#if ENABLE_GPIO
	cobra_gpio_flip(status_gpios, STATUS_GPIO_IRQ);
#endif
	return;
}

void handler_fiq_() {
#if SIMULATION == 0
#ifdef __DEBUG__
	printf("** EXCEPTION: FIRQ **\n");
#endif
#endif
#if ENABLE_GPIO
	cobra_gpio_flip(status_gpios, STATUS_GPIO_FIRQ);
#endif
	return;
}
