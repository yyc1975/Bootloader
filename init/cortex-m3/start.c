/*
 * start.c -- Startup code
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2013, Maxim Integrated
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
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF subSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* [INTERNAL] ------------------------------------------------------------------
 * Created on: Sep 16, 2013
 * Author:
 *
 * ---- subversion keywords (need to set the keyword property)
 * $Revision:: $: Revision of last commit
 * $Author:: $: Author of last commit
 * $Date:: $: Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

/** Global includes */
#include <config.h>
/** Other includes */
#include <arch/cortex-m3/bitband.h>
#include <mml.h>
#include <mml_nvic_regs.h>
#include <mml_intc.h>
/** Local includes */



extern unsigned int __section_load_data;
extern unsigned int __section_start_data;
extern unsigned int __section_end_data;
extern unsigned int __section_start_bss;
extern unsigned int __section_end_bss;
extern unsigned int __section_nvic_start;
extern unsigned int __section_nvic_end;
extern unsigned int __section_load_nvic;


extern int main(void);
extern void __start_c(void);

__attribute__((section(".text.init"))) void _start(void)
{
    volatile unsigned int						*pSrc;
    volatile unsigned int						*pDst;
    volatile nvic_regs_t						*reg_nvic = (volatile nvic_regs_t*)SCS_BASE;

    /** Copy the data segment initializers from ROM to SRAM. */
    pSrc = (volatile unsigned int*)&__section_load_data;
    for ( pDst = &__section_start_data; pDst < &__section_end_data; )
    {
        *pDst++ = *pSrc++;
    }
    /** Zero fill the bss segment. */
    __asm__ __volatile__
    (
        "ldr     r0, =__section_start_bss\n"
        "ldr     r1, =__section_end_bss\n"
        "mov     r2, #0\n"
        ".thumb_func\n"
        "zero_loop:\n"
        "cmp     r0, r1\n"
        "it      lt\n"
        "strlt   r2, [r0], #4\n"
        "blt     zero_loop"
    );
    /** Copy the reset vectors from ROM to SRAM. */
    pSrc = (volatile unsigned int*)&__section_load_nvic;
    for ( pDst = &__section_nvic_start; pDst < &__section_nvic_end; )
    {
        *pDst++ = *pSrc++;
    }
    /** Set the vector table offset to point to the new vector table in RAM */
    reg_nvic->vtor = (volatile unsigned int)&__section_nvic_start;
    /** Call specific initialization if any */
    __start_c();
    /** Enable Global Interrupts */
#ifndef _NO_GLOBAL_INTERRUPT_ENABLE_ON_STARTUP
    cpsie();
#endif /** _NO_GLOBAL_INTERRUPT_ENABLE_ON_STARTUP */
    /** Call the application's entry point. */
    main();
    /** We're done */
    return;
}

/******************************************************************************/
/* EOF */
