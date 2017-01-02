/*
 * sdram0 -- Code in "sdram0" and Data in "sdram0"
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

#include <config.h>
#include <arch/arm/link.h>

OUTPUT_FORMAT ("elf32-littlearm")
ENTRY(__reset)
SEARCH_DIR(.)

INCLUDE memories.inc
INCLUDE layout.inc

EXTERN(__start_asm _start)
/* Bring in the interrupt routines & vector */
INCLUDE arm-names.inc
EXTERN(__start_c main __stack __heap_end)

__heap_size = HEAP_SIZE;
__stack_size = STACK_SIZE;
__section_cpu_context_size = 64; /** ARM CPU Registers from r0 to r15  */

SECTIONS
{
  /* ------------------------------------------------------------------------ */
  /* Exception Vectors */
#if HAVE_ROM_BOOTSTRAP == 1
  .bootstrap :
  {
    *(.rvect)
    *(.reset)
  } > sdram0
#endif /* #if HAVE_ROM_BOOTSTRAP == 1 */

#if USE_HIGH_VECTORS == 1
  .higvects :
  {
    /* High Interrupt Vectors */
    __section_start_vectors = .;
    *(.vect)
    /* The low level handlers must be in a 4K range */
    *(.handlers)
    . = ALIGN(32);
    __section_end_vectors = .;
  } > highvects AT> sdram0
  __section_size_vectors = __section_end_vectors - __section_start_vectors;
  __section_wsize_vectors = __section_size_vectors / 4;
  __section_load_vectors = LOADADDR(.higvects);
#endif /* #if USE_HIGH_VECTORS == 1 */

  /* ------------------------------------------------------------------------ */
  /* Code */
  .text.init : ALIGN(32)
  {
    _start = DEFINED(__start_asm) ? __start_asm : _start;

    __handler_undefined__ = DEFINED(__handler_undefined) ? __handler_undefined : __handler_undefined_;
    __handler_swi__       = DEFINED(__handler_swi) ? __handler_swi : __handler_swi_;
    __handler_prefetch__  = DEFINED(__handler_prefetch) ? __handler_prefetch : __handler_prefetch_;
    __handler_abort__     = DEFINED(__handler_abort) ? __handler_abort : __handler_abort_;
    __handler_irq__       = DEFINED(__handler_irq) ? __handler_irq : __handler_irq_;
    __handler_fiq__      = DEFINED(__handler_fiq) ? __handler_fiq : __handler_fiq_;

    _handler_undefined_ = DEFINED(handler_undefined) ? handler_undefined : handler_undefined_;
    _handler_swi_       = DEFINED(handler_swi) ? handler_swi : handler_swi_;
    _handler_prefetch_  = DEFINED(handler_prefetch) ? handler_prefetch : handler_prefetch_;
    _handler_abort_     = DEFINED(handler_abort) ? handler_abort : handler_abort_;
    _handler_irq_       = DEFINED(handler_irq) ? handler_irq : handler_irq_;
    _handler_fiq_      = DEFINED(handler_fiq) ? handler_firq : handler_fiq_;

	*(.text.init0)
	*(.text.init)
#if USE_HIGH_VECTORS == 0
    *(.handlers)
#endif /* #if USE_HIGH_VECTORS == 0 */
  } > sdram0

  .text : ALIGN(32)
  {
    *(.text .text.* .gnu.linkonce.t.*)
    *(.plt)
    *(.gnu.warning)
    *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    *(.gcc_except_table)
  } >sdram0

  /* ------------------------------------------------------------------------ */
  /* Code in I-TCM */
#if ARM_HAS_ITCM == 1
  .itcm : ALIGN (32)
  {
    __region_start_itcm = .;
    __section_start_itcm = .;
    *(.itcm)
    . = ALIGN(32);
    __section_end_itcm = .;
  } >itcm AT>sdram0
  __section_size_itcm = __section_end_itcm - __section_start_itcm;
  __section_wsize_itcm = __section_size_itcm / 4;
  __section_load_itcm = LOADADDR(.itcm);
#endif /* #if ARM_HAS_ITCM == 1 */

  /* ------------------------------------------------------------------------ */
  /* RO Data */

  .eh_frame_hdr : ALIGN (4)
  {
    KEEP (*(.eh_frame_hdr))
  } >sdram0

  .eh_frame : ALIGN (4)
  {
    KEEP (*(.eh_frame))
  } >sdram0

  /* .ARM.exidx is sorted, so has to go in its own output section.  */
  PROVIDE_HIDDEN (__exidx_start = .);
  .ARM.exidx :
  {
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
  } >sdram0
  PROVIDE_HIDDEN (__exidx_end = .);

  .rodata : ALIGN (4)
  {
    *(.rodata .rodata.* .gnu.linkonce.r.*)
  } >sdram0

  /* ------------------------------------------------------------------------ */
  /* Data in D-TCM */
#if ARM_HAS_DTCM == 1
  .dtcm : ALIGN (32)
  {
    __region_start_dtcm = .;
    __section_start_data_dtcm = .;
    *(.dtcm)
    . = ALIGN(32);
    __section_end_data_dtcm = .;
  } >dtcm  AT>sdram0
  __section_size_data_dtcm = __section_end_data_dtcm - __section_start_data_dtcm;
  __section_wsize_data_dtcm = __section_size_data_dtcm / 4;
  __section_load_data_dtcm = LOADADDR (.dtcm);
#endif /* #if ARM_HAS_DTCM == 1 */
  /* ======================================================================== */
  /** RAM **/

  /* ------------------------------------------------------------------------ */
  /* DATA */
  .data : 
  {
   __section_start_data = .;
    KEEP(*(.jcr))
    *(.got.plt) *(.got)
    *(.shdata)
    *(.data .data.* .gnu.linkonce.d.*)
    . = ALIGN(32);
    __section_end_data = .;
  } >sdram0
  __section_size_data = __section_end_data - __section_start_data;
  __section_wsize_data = __section_size_data / 4;
  __section_load_data = LOADADDR(.data);

  /* ------------------------------------------------------------------------ */
  /* BSS */
  .bss (NOLOAD) : __mmu_align__
  {
    __section_start_bss = .;
    *(.shbss)
    *(.bss .bss.* .gnu.linkonce.b.*)
    *(COMMON)
    __section_end_bss = .;
  } >sdram0

  /** ARM CPU Context info */
  .cpu_context (NOLOAD) : ALIGN (4)
  {
  		__section_cpu_context_start = __section_end_bss;
  		. = . + __section_cpu_context_size;
		__section_cpu_context_end = .;
  } > sdram0

  /* ------------------------------------------------------------------------ */
  /* Stack and Heap */

  .stack (NOLOAD) : __mmu_align__
  {
    __section_start_stack = .;
    . = . + __stack_size;
    __stack = .;
    __section_end_stack = .;
  } > sdram0
  __stack_va = 0xFFF00000 + __stack_size;

  .heap (NOLOAD) : __mmu_align__
  {
    __section_start_heap = .;
    . = . + __heap_size;
    __section_end_heap = .;
#if ENABLE_MMU == 0
	    __region_end_ram = .;
#endif /* #if ENABLE_MMU == 0 */
  } > sdram0
  __section_start_heap_va = 0xFFF02000;
  __section_end_heap_va = __section_start_heap_va + __heap_size;
/**/

  /* ------------------------------------------------------------------------ */
  /* TTB
   */
#if ENABLE_MMU == 1
  .ttb  (NOLOAD) : ALIGN(1K)
  {
    __section_start_ttb = .;
    *(.ttbl2)
    . = ALIGN (16K);
    __ttb = .;
    *(.ttb)
    __section_end_ttb = .;
    . = ALIGN (4);
    __region_end_ram = .;
  } >sdram0
#endif /* #if ENABLE_MMU == 1 */

  /* ======================================================================== */
  /* BSS in D-TCM */
#if ARM_HAS_DTCM == 1
  .dtcm.bss (NOLOAD) :
  {
    __section_start_bss_dtcm = .;
    *(.dtcm.b .bss.dtcm)
    . = ALIGN(4);
    __section_end_bss_dtcm = .;
  } >dtcm
#endif /* #if ARM_HAS_DTCM == 1 */

  /* ------------------------------------------------------------------------ */
  /* OTHERS */
  /* ------------------------------------------------------------------------ */

#if _DEBUG == 1
  .stab 0 (NOLOAD) : { *(.stab) }
  .stabstr 0 (NOLOAD) : { *(.stabstr) }

  /* DWARF debug sections.
   * Symbols in the DWARF debugging sections are relative to
   * the beginning of the section so we begin them at 0.
   */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* DWARF 2.1 */
  .debug_ranges   0 : { *(.debug_ranges) }

#endif /* #if _DEBUG == 1 */

  .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
  .ARM.attributes 0 : { KEEP (*(.ARM.attributes)) }

  /DISCARD/ : {
    *(.note.GNU-stack)
    *(.comment)
#if USE_HIGH_VECTORS == 0
    *(.vect)
#endif
#if ENABLE_MMU == 0
    *(.ttbl2)
    *(.ttb)
#endif
   }
}
