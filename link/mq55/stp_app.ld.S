/*
 * STP Application -- Code in "RAM" and Data in "RAM"
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2014, Maxim Integrated Products
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
SEARCH_DIR(.)

INCLUDE link/mq55/memories.inc
INCLUDE layout.inc
INCLUDE import.inc

EXTERN(main __stack __heap_end)

SECTIONS
{
  /* ------------------------------------------------------------------------ */
  __section_nvic_end = __section_protocol_start;

  /* Stack */
  .stp_stack __section_protocol_start : ALIGN(0x20)
  {
    __fwk_stack_end = .;
    . += __STACK_FWK_SIZE;
    __fwk_stack_start = .;
  }

  .text __fwk_stack_start : ALIGN(0x20)
  {
    __text_stpa_start = .;
    *(.text.startup)
    *(.text .text.* .gnu.linkonce.t.*)
    *(.plt)
    *(.gnu.warning)
    *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    *(.gcc_except_table)
  }
  __text_stpa_end = .;

  /* ------------------------------------------------------------------------ */
  /* RO Data */

  .eh_frame_hdr : ALIGN (0x10)
  {
    __frame_hdr_start = .;
    KEEP (*(.eh_frame_hdr))
  }
  __frame_hdr_end = .;

  .eh_frame __frame_hdr_end : ALIGN (0x10)
  {
    __frame_start = .;
    KEEP (*(.eh_frame))
  }
  __frame_end = .;

  /* .ARM.exidx is sorted, so has to go in its own output section.  */
  PROVIDE_HIDDEN (__exidx_start = .);
  .ARM.exidx  __exidx_start :
  {
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
  }

  PROVIDE_HIDDEN (__exidx_end = .);

  __beacon_start = LOADADDR(.ARM.exidx) + SIZEOF(.ARM.exidx);

  .rodata __beacon_start : ALIGN(0x10)
  {
    __rodata_start = .;
    KEEP(*(.rodata .rodata.* .gnu.linkonce.r.*))
  }
  __rodata_end = ALIGN(0x10);

  /* ------------------------------------------------------------------------ */
  /* DATA */

  .data __rodata_end :
  {
   __section_start_data = .;
    KEEP(*(.jcr))
    *(.got.plt) *(.got)
    *(.shdata)
    KEEP(*(.data .data.* .gnu.linkonce.d.*))
    . = ALIGN(0x20);
  }
  __section_end_data = .;

  /* ------------------------------------------------------------------------ */
  /* BSS */
  .bss  __section_end_data : ALIGN(0x20)
  {
    __section_start_bss = .;
    *(.shbss)
    KEEP(*(.bss .bss.* .gnu.linkonce.b.*))
    *(COMMON)
    __section_end_bss = .;
  }

  /* ------------------------------------------------------------------------ */
  /* OTHERS */
  /* ------------------------------------------------------------------------ */
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

  .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) }
  .ARM.attributes 0 : { KEEP (*(.ARM.attributes)) }

  /DISCARD/ :
  {
    *(.note.GNU-stack)
    *(.comment)
    *(.reset)
    *(.text.init)
    *(.nvic_section)
   }
}
/* EOF */
