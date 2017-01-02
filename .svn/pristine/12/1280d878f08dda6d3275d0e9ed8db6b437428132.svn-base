/*
 * Second Level Application
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
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <config.h>

OUTPUT_FORMAT ("elf32-littlearm")
ENTRY(main)
SEARCH_DIR(.)

INCLUDE memories.inc
INCLUDE layout.inc
INCLUDE import.inc

SECTIONS
{
  /* ------------------------------------------------------------------------ */
  /* SLA Start */
  __start_sla = __EXECUTION_START;
  __sla_load_addr = __STORAGE_START;

  __sla_header_load_addr_start = __sla_load_addr;
  /* SLA Header */
  .sla_header __sla_load_addr : ALIGN(0x20)
  {
    . += 0x38;
  } >s_mem

  __sla_header_size = SIZEOF(.sla_header);
  __sla_header_load_addr_end = __sla_header_load_addr_start + __sla_header_size;

  /* SLA Arguments */
  .sla_args __sla_header_load_addr_end :
  {
    . += 0x00;
  } >s_mem

  __sla_args_load_addr_start = LOADADDR(.sla_args);
  __sla_args_size = SIZEOF(.sla_args);
  __sla_args_load_addr_end = __sla_args_load_addr_start + __sla_args_size;

  /*__sla_core = __start_sla + __sla_header_size + __sla_args_size;*/
  /* ------------------------------------------------------------------------ */
  /* Code */
  .text __start_sla : AT(__sla_args_load_addr_end) ALIGN(0x20)
  {
    __text_sla_start = .;
#ifndef _EMPTY_APPLICATION_
	*(.text.startup)
    *(.text)
    *(.text.init)
    *(.gnu.linkonce.t.*)
    *(.plt)
    *(.gnu.warning)
    *(.nvic_section)
    *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    *(.gcc_except_table)
    *(.reset)
#endif /* _EMPTY_APPLICATION_ */
  } >e_mem
  __text_sla_end = .;

  __sla_text_load_addr_start = LOADADDR(.text);
  __sla_text_size = SIZEOF(.text);
  __sla_text_load_addr_end = __sla_text_load_addr_start + __sla_text_size;

  /* ------------------------------------------------------------------------ */
  /* RODATA */
  .rodata __text_sla_end : AT(__sla_text_load_addr_end) ALIGN(0x10)
  {
  	__rodata_start = .;
#ifndef _EMPTY_APPLICATION_
    *(.rodata .rodata.* .gnu.linkonce.r.*)
#endif /* _EMPTY_APPLICATION_ */
  } >e_mem
  __rodata_end = ALIGN(4);

  __sla_rodata_load_addr_start = LOADADDR(.rodata);
  __sla_rodata_size = SIZEOF(.rodata);
  __sla_rodata_load_addr_end = __sla_rodata_load_addr_start + __sla_rodata_size;

  __section_size_rodata = __rodata_end - __rodata_start;
  __section_load_rodata = LOADADDR(.rodata);

  /* ------------------------------------------------------------------------ */
  /* DATA */
  .data __rodata_end : AT(__sla_rodata_load_addr_end) ALIGN(0x10)
  {
   __section_start_data = .;
#ifndef _EMPTY_APPLICATION_
    KEEP(*(.jcr))
    *(.got.plt) *(.got)
    *(.shdata)
    *(.data .data.* .gnu.linkonce.d.*)
    . = ALIGN(32);
#endif /* _EMPTY_APPLICATION_ */
   __section_end_data = .;
  } >e_mem

  __sla_data_load_addr_start = LOADADDR(.data);
  __sla_data_size = SIZEOF(.data);
  __sla_data_load_addr_end = __sla_data_load_addr_start + __sla_data_size;

  __section_size_data = __section_end_data - __section_start_data;
  __section_load_data = LOADADDR(.data);

  /* ------------------------------------------------------------------------ */
  /* BSS */
  .bss __section_end_data : ALIGN(0x10)
  {
    __section_start_bss = .;
#ifndef _EMPTY_APPLICATION_
    *(.shbss)
    *(.bss .bss.* .gnu.linkonce.b.*)
    *(COMMON)
#endif /* _EMPTY_APPLICATION_ */
    __section_end_bss = .;
  } >e_mem

  __section_size_bss = __section_end_bss - __section_start_bss;
  __section_load_bss = LOADADDR(.bss);

  /* ------------------------------------------------------------------------ */
  /* .ARM.exidx is sorted, so has to go in its own output section.  */
  PROVIDE_HIDDEN (__exidx_start = .);
  .ARM.exidx  __exidx_start :
  {
#ifndef _EMPTY_APPLICATION_
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
#endif /* _EMPTY_APPLICATION_ */
  } >e_mem

  PROVIDE_HIDDEN (__exidx_end = .);

  /* ------------------------------------------------------------------------ */
  .eh_frame_hdr : ALIGN (4)
  {
#ifndef _EMPTY_APPLICATION_
  	__frame_hdr_start = .;
    KEEP (*(.eh_frame_hdr))
#endif /* _EMPTY_APPLICATION_ */
  } >e_mem
  __frame_hdr_end = .;

  .eh_frame __frame_hdr_end : ALIGN (4)
  {
  	__frame_start = .;
#ifndef _EMPTY_APPLICATION_
    KEEP (*(.eh_frame))
#endif /* _EMPTY_APPLICATION_ */
  } >e_mem
  __frame_end = .;

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
    *(.rvect)
    *(.vect)
    *(.text.init0)
#ifdef _EMPTY_APPLICATION_
    *(EXCLUDE_FILE(*main* *exit*).text)
    *(.v4_bx)
    *(.gnu.linkonce.t.*)
    *(.plt)
    *(.gnu.warning)
    *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    *(.gcc_except_table)
    *(.eh_frame_hdr)
    *(.eh_frame)
	*(.ARM.exidx* .gnu.linkonce.armexidx.*)
	*(.rodata .rodata.* .gnu.linkonce.r.*)
    *(.jcr)
    *(.got.plt) *(.got)
    *(.shdata)
    *(.data .data.* .gnu.linkonce.d.*)
    *(.shbss)
    *(.bss .bss.* .gnu.linkonce.b.*)
    *(COMMON)
#endif /* _EMPTY_APPLICATION_ */
   }
}

/* EOF */
