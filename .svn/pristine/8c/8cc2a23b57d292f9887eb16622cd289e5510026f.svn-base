/*
 * asm_handlers.S --
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
 * $Revision:: 1626     $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2011-04-11 2#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

/** Global includes */
#include <config.h>
/** Other includes */
#include <mml_intc_regs.h>
/** Local includes */

#define INTC_IRQ_END	( MML_INTC_IOBASE | MML_INTC_IRQ_END_OFST )
#define INTC_IRQ_VEC	( MML_INTC_IOBASE | MML_INTC_IRQ_VEC_OFST )
#define INTC_FIQ_END	( MML_INTC_IOBASE | MML_INTC_FIQ_END_OFST )
#define INTC_FIQ_VEC	( MML_INTC_IOBASE | MML_INTC_FIQ_VEC_OFST )

	.section .handlers

/* -------------------------------------------------------------------------- */

	.globl __handler_undefined_
	.type	__handler_undefined_, %function

__handler_undefined_:
	sub		lr, lr, #4
	stmfd	sp!, {r0-r12, lr}
	sub		r0,	lr, #4
	ldr		r5, =_handler_undefined_
	mov		lr, pc
	bx		r5
	/* We don't want to continue if this exception occurs */
	ldr		r5, =__exit
	bx		r5
	#ldmfd	sp!, {r0-r12, pc}^

/* -------------------------------------------------------------------------- */

	.globl __handler_swi_
	.type	__handler_swi_, %function

__handler_swi_:
	sub		lr, lr, #4
	stmfd	sp!, {r0-r12, lr}
	ldr		r5, =_handler_swi_
	mov		lr, pc
	bx		r5
	ldmfd	sp!, {r0-r12, pc}^

/* -------------------------------------------------------------------------- */

	.globl __handler_abort_
	.type	__handler_abort_, %function

__handler_abort_:
	sub		lr, lr, #4
	stmfd	sp!, {r0-r12, lr}
 	/* Fault Status Register */
	mrc p15, 0, r0, c5, c0, 0
	/* Fault Address */
	mrc p15, 0, r1, c6, c0, 0
	sub		r2,	lr, #4
	ldr		r5, =_handler_abort_
	mov		lr, pc
	bx		r5
#if !defined(CONTINUE_AFTER_XCPT)
	ldr		r5, =__exit
	bx		r5
#else
	ldmfd	sp!, {r0-r12, pc}^
#endif

/* -------------------------------------------------------------------------- */

	.globl __handler_prefetch_
	.type	__handler_prefetch_, %function

__handler_prefetch_:
	sub		lr, lr, #4
	stmfd	sp!, {r0-r12, lr}
	/* Fault Status Register */
	mrc p15, 0, r0, c5, c0, 1
	/* Fault Address */
	mrc p15, 0, r1, c6, c0, 0
	sub		r2,	lr, #4
	ldr		r5, =_handler_prefetch_
	mov		lr, pc
	bx		r5
	/* We don't want to continue if this exception occurs */
	ldr		r5, =__exit
	bx		r5
	/* ldmfd	sp!, {r0-r12, pc}^ */

/* -------------------------------------------------------------------------- */

	.globl __handler_irq_
	.type	__handler_irq_, %function

__handler_irq_:
	sub		lr, lr, #4
	stmfd	sp!, {r0-r12, lr}
	ldr		r6, =INTC_IRQ_VEC
	ldr		r5, [r6]
	mov		lr, pc
	bx		r5
	ldr		r0, =INTC_IRQ_END
	str		r0, [r0, #0]
	ldmfd	sp!, {r0-r12, pc}^

/* -------------------------------------------------------------------------- */

	.globl __handler_fiq_
	.type	__handler_fiq_, %function

__handler_fiq_:
	sub		lr, lr, #4
	stmfd	sp!, {r0-r12, lr}
	ldr		r6, =INTC_FIQ_VEC
	ldr		r5, [r6]
	mov		lr, pc
	bx		r5
	ldr		r5, =INTC_FIQ_END
	str		r5, [r5, #0]
	ldmfd	sp!, {r0-r12, pc}^

/* -------------------------------------------------------------------------- */

	.globl __handler_nested_irq
	.type	__handler_nested_irq, %function

__handler_nested_irq:
	sub		lr, lr, #4			/* construct the return address */
	stmfd	sp!, {lr}			/* and push the adjusted lr_IRQ */
	mrs		r14, SPSR			/* copy spsr_IRQ to r14 */
	stmfd	sp!, {r12, r14}		/* save work regs and spsr_IRQ */
	/* ---------------------------------------------------------------------- */
	/* Add instructions to clear the interrupt here */

	/* ---------------------------- */
	ldr		r12, =INTC_IRQ_END
	str		r12, [r12, #0]
	/* ---------------------------------------------------------------------- */
	/* then re-enable interrupts */
	msr		CPSR_c, #0x1F		/* switch to SYS mode, FIQ and IRQ */
								/* enabled. USR mode registers */
								/* are now current. */
	stmfd	sp!, {r0-r3, lr}	/* save lr_USR and non-callee */
								/* saved registers */
	//bl		C_irq_handler		/* branch to C IRQ handler. */
	ldmfd	sp!, {r0-r3, lr}	/* restore registers */
	msr		CPSR_c, #0x92		/* switch to IRQ mode and disable */
								/* IRQs. FIQ is still enabled. */
	ldmfd	sp!, {r12, r14}		/* restore work regs and spsr_IRQ */
	msr		SPSR_cf, r14
	ldmfd	sp!, {pc}^			/* return from IRQ. */
