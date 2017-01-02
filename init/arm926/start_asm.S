/*
 * start_asm.S -- ASM startup code
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
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF subSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* [INTERNAL] ------------------------------------------------------------------
 * Created on: May 6, 2010
 * Author:
 *
 * ---- subversion keywords (need to set the keyword property)
 * $Revision:: 1587     $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2011-04-05 2#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

/** Global includes */
#include <config.h>
/** Other includes */
#include <arch/arm/arm.h>
/** Local includes */


#define ABT_Stack_Len	0x400
#define FIQ_Stack_Len	0x400
#define IRQ_Stack_Len	0x400

	.section .text.init
	.globl __start_asm
	.type	__start_asm, %function

__start_asm:

/* The simulation environment requires that all gprs are initialized before
 * any usage.
 */
#if SIMULATION == 1
	mov		r0, #0
	mov		r1, #0
	mov		r2, #0
	mov		r3, #0
	mov		r4, #0
	mov		r5, #0
	mov		r6, #0
	mov		r7, #0
	mov		r8, #0
	mov		r9, #0
	mov		r10, #0
	mov		r11, #0
	mov		r12, #0
#endif /* #if SIMULATION == 1 */

	/* Temporary stack */
	ldr 	sp, =__stack

#if USE_HIGH_VECTORS == 1
	/* Copy the exceptions vectors to ram alias */
	ldr		r0, =__section_load_vectors
	ldr		r1, =__section_start_vectors
	ldr		r2, =__section_wsize_vectors
	cmp		r0, r1
	blne	__wordcopy
#endif /* USE_HIGH_VECTORS == 1 */
	nop /* For breakpoints */
#if ARM_HAS_DTCM == 1
	/* Set the DTCM base address */
	ldr 	r0, =__region_start_dtcm
	mrc 	p15,0,r1,c9,c1,0	/* Read the DTCM region register value */
	ldr		r2, =0xFFFFF000		/* */
	bic		r1, r2				/* Clean the base address */
	orr		r3, r0, r1			/* Create the new DTCM region register value */
	orr		r3, r0, #0x1		/* Enable the DTCM */
	mcr 	p15,0,r3,c9,c1,0	/* Write it */

	/* Clear the DTCM zero segment */
	ldr		r0, =__section_start_bss_dtcm
	ldr		r1, =__section_end_bss_dtcm
	mov		r2, #0
1:
	cmp		r0, r1
	strcc	r2, [r0], #4
	bcc		1b

	ldr		r0, =__section_load_data_dtcm
	ldr		r1, =__section_start_data_dtcm
	ldr		r2, =__section_wsize_data_dtcm
	cmp		r0, r1
	blne	__wordcopy

#endif /* #if HAS_DTCM == 1 */
#if ARM_HAS_ITCM == 1
	/* Set the ITCM base address */
	ldr 	r0, =__region_start_itcm
	mrc 	p15,0,r1,c9,c1,1	/* Read the ITCM region register value */
	ldr		r2, =0xFFFFF000		/* */
	bic		r1, r2				/* Clean the base address */
	orr		r3, r0, r1			/* Create the new ITCM region register value */
	orr		r3, r0, #0x1		/* Enable the ITCM */
	mcr 	p15,0,r3,c9,c1,1	/* Write it */

	ldr		r0, =__section_load_itcm
	ldr		r1, =__section_start_itcm
	ldr		r2, =__section_wsize_itcm
	cmp		r0, r1
	blne	__wordcopy

#endif /* #if HAS_ITCM == 1 */

	/* ---------------------------------------------------------------------- */
	/* Set MMU and Cache configuration (I/D) */

#if ENABLE_MMU == 1
#if ENABLE_DCACHE == 1
	/* ttb_init(CACHE_ENABLED_WRITEBACK); */
	mov		r0, #0x3
	ldr		r5, =ttb_init
	mov		lr, pc
	bx		r5
#else
	/* ttb_init(CACHE_DISABLED_NOTBUFFERABLE); */
	mov		r0, #0x0
	ldr		r5, =ttb_init
	mov		lr, pc
	bx		r5
#endif /* #if ENABLE_DCACHE == 1 */
#endif /* #if ENABLE_MMU == 1 */

#if ENABLE_MMU == 1
	/** Set the TTB base address */
	mrc 	p15,0,r1,c1,c0,0
	ldr 	r0,=__ttb
	mcr 	p15,0,r0,c2,c0,0

	/** Set permissions for domains:
	  * 0   : check
	  * 1-14: fault
	  * 15  : no check
	  */
	mov 	r0,#0xC0000001
	mcr 	p15,0,r0,c3,c0,0

	/** Enable ROM protection */
	orr		r1,r1,#0x200
	/** Enable SYSTEM protection */
	//orr		r1,r1,#0x400
	/** Enable the MMU */
	orr		r1,r1,#0x1
#if ENABLE_DCACHE == 1
	orr 	r1,r1,#0x4
#endif /* #if ENABLE_DCACHE == 1 */
#endif /* #if ENABLE_MMU == 1  */

#if ENABLE_ICACHE == 1
	orr 	r1,r1,#0x1000
#endif /* ENABLE_ICACHE == 1 */

#if USE_HIGH_VECTORS == 1
	orr 	r1,r1,#0x2000
#endif /* USE_HIGH_VECTORS == 1 */

#if ENABLE_MMU == 1 || ENABLE_ICACHE == 1 || USE_HIGH_VECTORS == 1
	mcr 	p15,0,r1,c1,c0,0
#endif /* #if ENABLE_MMU == 1 || ENABLE_ICACHE == 1 */

	/* ---------------------------------------------------------------------- */
	/** Set the Mode stacks (virtual address if MMU is set) */

#if ENABLE_MMU == 1
	ldr 	r0, =__stack_va
#else
	ldr 	r0, =__stack
#endif /* #if ENABLE_MMU == 1 */

	msr 	CPSR_c, #Mode_ABT | I_Bit | F_Bit
	mov 	sp, r0
	sub 	r0, #ABT_Stack_Len

#if ENABLE_FIQ == 1
	/* Configure the stack for FIQ */
	msr 	CPSR_c, #Mode_FIQ | I_Bit | F_Bit
	mov 	sp, r0
	sub 	r0, #FIQ_Stack_Len
#endif /* #if FIQ_HAVE_STACK == 1 */

#if ENABLE_IRQ == 1
	/* Configure the stack for IRQ */
	msr 	CPSR_c, #Mode_IRQ | I_Bit | F_Bit
	mov 	sp, r0
	sub 	r0, #IRQ_Stack_Len
#endif /* #if IRQ_HAVE_STACK == 1  */

	/* Return to supervisor mode */
	msr 	CPSR_c, #Mode_SVC | I_Bit | F_Bit

	/* Configure the stack for Supervisor mode */
	mov 	sp, r0

	/* ------------------------------------------------------------------- */
	/* Copy data to writable region */

	ldr		r0, =__section_load_data
	ldr		r1, =__section_start_data
	ldr		r2, =__section_wsize_data
	cmp		r0, r1
	blne	__wordcopy

	/* ------------------------------------------------------------------- */
	/* Clear the BSS segment */
	ldr		r0, =__section_start_bss
	ldr		r1, =__section_end_bss
	mov		r2, #0
1:
	cmp		r0, r1
	strcc	r2, [r0], #4
	bcc		1b

	/* ------------------------------------------------------------------- */
	/* C Initialization */
	ldr		r0, =__start_c
	mov		lr, pc
	bx		r0

	/* ------------------------------------------------------------------- */
#if ENABLE_IRQ == 1 && ENABLE_FIQ == 1
	/* Enable IRQ and FIQ */
	msr 	CPSR_c, #Mode_SVC
#elif  ENABLE_IRQ == 1
	/* Enable IRQ  */
	msr 	CPSR_c, #Mode_SVC | F_Bit
#elif ENABLE_FIQ == 1
	/* Enable FIQ */
	msr 	CPSR_c, #Mode_SVC | I_Bit
#endif /* ENABLE_IRQ == 1 && ENABLE_FIQ == 1 */

	/* ---------------------------------------------------------------------- */
	/* main() */
	ldr		r5, =main
	mov		lr, pc
	bx		r5

	/* ---------------------------------------------------------------------- */
	/* _exit() */
	b		_exit

	.pool
	.size	__start_asm,.-__start_asm
