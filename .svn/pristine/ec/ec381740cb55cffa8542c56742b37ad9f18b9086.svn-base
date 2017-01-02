/*
 * exit.c --
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
 * Created on: May 25, 2010
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 2369     $:  Revision of last commit
 * $Author:: bryan.arms#$:  Author of last commit
 * $Date:: 2011-12-22 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#include "config.h"
#include <stdio.h>

#if ENABLE_GPIO
extern SPFM(gpio_regs_t) *status_gpios;
#endif

#if SIMULATION == 1
#  define __sim_unused__ __attribute__ ((unused))
#else
#  define __sim_unused__
#endif

void
_exit(int status __sim_unused__) __attribute__ ((noreturn));

void
__exit() __attribute__ ((noreturn));

void
_exit(int status __sim_unused__)
{
#if SIMULATION == 0
#ifdef __DEBUG__
	printf("** EXIT **\n");
	printf("Status: %d\n", status);
#endif
#endif /* #if SIMULATION == 0 */
	__exit();
}


void __exit()
{
	do {
#if ENABLE_GPIO
		cobra_gpio_flip(status_gpios, STATUS_GPIO_EXIT);
#endif
	} while (1);
}
