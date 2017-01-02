/*
 * vectors.c -- Initial vector table
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
 * Created on: 
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
#include <arch/cortex-m3/nvic.h>
/** Local includes */

//*****************************************************************************
extern void __reset(void);
//extern void _handler_nmi_(void);
//extern void _handler_fault_(void);
//extern void handler_default_inital_(void);
//extern void handler_default_reset_(void);
//extern void handler_default_nmi_(void);
//extern void handler_default_hard_fault_(void);
//extern void handler_default_memory_manage_(void);
//extern void handler_default_bus_fault_(void);
//extern void handler_default_usage_fault_(void);
//extern void handler_default_svcall_(void);
//extern void handler_default_debug_monitor_(void);
//extern void handler_default_pendsv_(void);
//extern void handler_default_systick_(void);
//extern void handler_default_irq_(void);
//extern void handler_default_undefined_(void);

//*****************************************************************************
// The following is a construct created by the linker, indicating where the
// the stack resides in memory.
//*****************************************************************************
extern void __section_end_stack(void);

//*****************************************************************************
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000.
//*****************************************************************************
__attribute__ ((section(".nvic_section")))
void (* const rom_vectors[])(void) =
{
    &__section_end_stack,                   // The initial stack pointer
    __reset,                                // The reset handler
    handler_default_nmi_,                          // The NMI handler
    handler_default_hard_fault_,                        // The hard fault handler
    handler_default_memory_manage_,                    // The MPU fault handler
    handler_default_bus_fault_,                    // The bus fault handler
    handler_default_usage_fault_,                    // The usage fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    handler_default_svcall_,                    // SVCall handler
    handler_default_debug_monitor_,                    // Debug monitor handler
    0,                                      // Reserved
    handler_default_pendsv_,                    // The PendSV handler
    handler_default_systick_,                    // The SysTick handler
    handler_default_undefined_,                    // Interrupt #16
    handler_default_undefined_,                    // Interrupt #17
    handler_default_undefined_,                    // Interrupt #18
    handler_default_undefined_,                    // Interrupt #19
    handler_default_undefined_,                    // Interrupt #20
    handler_default_undefined_,                    // Interrupt #21
    handler_default_undefined_,                    // Interrupt #22
    handler_default_undefined_,                    // Interrupt #23
    handler_default_undefined_,                    // Interrupt #24
    handler_default_undefined_,                    // Interrupt #25
    handler_default_undefined_,                    // Interrupt #26
    handler_default_undefined_,                    // Interrupt #27
    handler_default_undefined_,                    // Interrupt #28
    handler_default_undefined_,                    // Interrupt #29
    handler_default_undefined_,                    // Interrupt #30
    handler_default_undefined_,                    // Interrupt #31
    handler_default_undefined_,                    // Interrupt #32
    handler_default_undefined_,                    // Interrupt #33
    handler_default_undefined_,                    // Interrupt #34
    handler_default_undefined_,                    // Interrupt #35
    handler_default_undefined_,                    // Interrupt #36
    handler_default_undefined_,                    // Interrupt #37
    handler_default_undefined_,                    // Interrupt #38
    handler_default_undefined_,                    // Interrupt #39
    handler_default_undefined_,                    // Interrupt #40
    handler_default_undefined_,                    // Interrupt #41
    handler_default_undefined_,                    // Interrupt #42
    handler_default_undefined_,                    // Interrupt #43
    handler_default_undefined_,                    // Interrupt #44
    handler_default_undefined_,                    // Interrupt #45
    handler_default_undefined_,                    // Interrupt #46
    handler_default_undefined_,                    // Interrupt #47
    handler_default_undefined_,                    // Interrupt #48
    handler_default_undefined_,                    // Interrupt #49
    handler_default_undefined_,                    // Interrupt #50
    handler_default_undefined_,                    // Interrupt #51
    handler_default_undefined_,                    // Interrupt #52
    handler_default_undefined_,                    // Interrupt #53
    handler_default_undefined_,                    // Interrupt #54
    handler_default_undefined_,                    // Interrupt #55
    handler_default_undefined_,                    // Interrupt #56
    handler_default_undefined_,                    // Interrupt #57
    handler_default_undefined_,                    // Interrupt #58
    handler_default_undefined_,                    // Interrupt #59
    handler_default_undefined_,                    // Interrupt #60
    handler_default_undefined_,                    // Interrupt #61
    handler_default_undefined_,                    // Interrupt #62
    handler_default_undefined_,                    // Interrupt #63
};

/******************************************************************************/
/* EOF */
