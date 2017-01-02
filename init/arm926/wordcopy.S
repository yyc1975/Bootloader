/*
 * wordcopy.S -- Copy words block
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
 * $Revision:: 265      $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2010-08-20 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#include "arch/arm/arm.h"
#include "config.h"

	.section .text.init
	.globl	__wordcopy
	.type	__wordcopy, %function

	/** Copy words block
	 * @param r0	Source
	 * @param r1	Destination
	 * @param r2	Word size
	*/
__wordcopy:
	movs	r3,r2, LSR #3
	beq		__wordcopy_copywords
	stmfd	sp!, {r4-r11}
__wordcopy_octcopy:
	ldmia	r0!, {r4-r11}
	stmia	r1!, {r4-r11}
	subs	r3, r3, #1
	bne		__wordcopy_octcopy
	ldmfd	sp!, {r4-r11}
__wordcopy_copywords:
	ands	r2, r2, #7
	beq		__wordcopy_end
__wordcopy_wordcopy:
	ldr		r3, [r0], #4
	str		r3, [r1], #4
	subs	r2, r2, #1
	bne		__wordcopy_wordcopy
__wordcopy_end:
	bx		lr

	.pool
	.size	__wordcopy,.-__wordcopy
