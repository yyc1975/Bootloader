/*
 * reset.S -- Reset code for JIBE
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

#include "config.h"

#if defined(__thumb2__) || defined(__ARM_ARCH_6M__)
#define THUMB 1
	.thumb
	.thumb_func
#else
	.arm
#endif
	.section .reset,"ax",%progbits
	.globl __reset_jibe
	.type	__reset_jibe, %function
__reset_jibe:

#if __emulator_ig1__ == 1
#	if __jibe_rc9__ == 1
	/* Initialize CE0 timing (SRAM) */
	ldr	r0, =0xffe50000
	mov	r3, #5
	str	r3, [r0, #0x100]	/* Configuration */
	ldr	r3, =0x03030303
	str	r3, [r0, #0x104]	/* Read          */
	ldr	r3, =0x03030303
	str	r3, [r0, #0x108]	/* Write         */
#	endif /* #if __jibe_rc9__ == 1 */
#endif /* #if __emulator_ig1__ == 1 */

	/* jump to common start code */
#if THUMB
	ldr	r0,=__start_asm
	bx	r0
#else
	b	__start_asm
#endif
	.pool
	.size	__reset_jibe,.-__reset_jibe
