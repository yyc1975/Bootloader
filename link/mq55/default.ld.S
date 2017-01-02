/*
 * ----------------------------------------------------------------------------
 * Copyright (c) 2013, Maxim Integrated Products
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
 * THIS SOFTWARE IS PROVIDED BY MAXIM INTEGRATED PRODUCTS ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL MAXIM INTEGRATED PRODUCTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <config.h>

OUTPUT_FORMAT ("elf32-littlearm")
ENTRY(__reset)
SEARCH_DIR(.)

INCLUDE memories.inc
INCLUDE layout.inc

/** HEAP_SIZE */
__heap_size = HEAP_SIZE;
/** STACK_SIZE */
__stack_size = STACK_SIZE;

SECTIONS
{
  /* ------------------------------------------------------------------------ */
  /* Init Code */
  .text.init : ALIGN(0x20)
  {
    KEEP(*(.reset))
    KEEP(*(.text.init))
  } > boot

  /* NVIC */
  .nvic_section : ALIGN(0x100)
  {
    __section_nvic_start = .;
    KEEP(*(.nvic_section))
    __section_nvic_end = .;
  } > nvic_rw AT>nvic_ro

  __section_nvic_size = SIZEOF(.nvic_section);
  __section_load_nvic = LOADADDR(.nvic_section);
  __section_load_nvic_end = __section_load_nvic + __section_nvic_size;

  /** NMI code section ********************************************************/
  .nmi_code __section_nvic_end : ALIGN(0x100)
  {
  	__section_nmi_code_start = .;
    *(.nmi_code)
    __section_nmi_code_end = .;
  } > ram

  __section_nmi_code_size = SIZEOF(.nmi_code);
  __section_nmi_code_load_start = LOADADDR(.nmi_code);
  __section_nmi_code_load_end = __section_nmi_code_load_start + __section_nmi_code_size;
  /****************************************************************************/

  /* Code */
  .text : ALIGN (4)
  {
    __section_start_text = .;
    *(.text.startup)
    *(.text .text.*)
    *(.gnu.warning)
    *(.ARM.extab*)
    __section_end_text = .;
  } > rom
  __section_size_text = __section_end_text - __section_start_text;

  /* ------------------------------------------------------------------------ */
  /* RO Data */
  __section_start_rodata = .;

  /* .ARM.exidx is sorted, so has to go in its own output section.  */
  PROVIDE_HIDDEN (__exidx_start = .);
  .ARM.exidx :
  {
    *(.ARM.exidx*)
  } > rom
  PROVIDE_HIDDEN (__exidx_end = .);

  .rodata : ALIGN (4)
  {
    KEEP(*(.rodata .rodata.*))
  } > rom

  __section_end_rodata = .;
  __section_size_rodata = __section_end_rodata - __section_start_rodata;

  /* ======================================================================== */
  /** RAM **/

  /* ------------------------------------------------------------------------ */
  /* DATA */
  .data : ALIGN (4)
  {
   __section_start_data = .;
    KEEP(*(.data .data.*))
    __section_end_data = .;
  } > ram AT>rom
  __section_size_data = __section_end_data - __section_start_data;
  __section_load_data = LOADADDR(.data);

  /* ------------------------------------------------------------------------ */
  /* BSS */
  .bss (NOLOAD) : ALIGN (4)
  {
    __section_start_bss = .;
    *(.bss .bss.*)
    *(COMMON)
    __section_end_bss = .;
  } > ram
  __section_bss_size = __section_end_bss - __section_start_bss;

  /* ------------------------------------------------------------------------ */
  /* Stack and Heap */
  .stack (ORIGIN(stack) + LENGTH(stack) - __stack_size) (NOLOAD) :
  {
    __section_start_stack = .;
    . += __stack_size;
    __section_end_stack = .;
    __stack = .;
  }

  .heap (NOLOAD) : ALIGN(0x100)
  {
    __section_start_heap = .;
    . += __heap_size;
    __section_end_heap = .;
  } > stack

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
  .debug_info     0 : { *(.debug_info) }
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

  /DISCARD/ :
  {
    *(.note.GNU-stack)
    *(.comment)
  }
}
