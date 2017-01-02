/*
 * lhassa -- Code in "ROM" and Data in "RAM"
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
#include <arch/arm/link.h>

OUTPUT_FORMAT ("elf32-littlearm")
ENTRY(__reset)
SEARCH_DIR(.)

INCLUDE link/yumen/memories.inc
INCLUDE layout.inc

EXTERN(__start_asm _start)
/* Bring in the interrupt routines & vector */
INCLUDE arm-names.inc
EXTERN(__start_c main __stack __heap_end)

/** HEAP_SIZE */
__heap_size = HEAP_SIZE;
/** STACK_SIZE */
__stack_size = STACK_SIZE;

SECTIONS
{
  /* ------------------------------------------------------------------------ */
  /* NVIC */
  .nvic_section :
  {
    . = ALIGN(0x100);
    __section_nvic_start = .;
    KEEP(*(.nvic_section))
    __section_nvic_end = .;
  } > nvic_rw AT>nvic_ro

  __section_nvic_size = SIZEOF(.nvic_section);
  __section_load_nvic = LOADADDR(.nvic_section);
  __section_load_nvic_end = __section_load_nvic + __section_nvic_size;

  /* Code */
  .text.init : ALIGN(0x20)
  {
  	KEEP(*(.reset))
	KEEP(*(.text.init))
  } > boot

  .text : ALIGN(0x20)
  {
  	__section_start_text = .;
  	*(.text.startup)
    *(.text .gnu.linkonce.t.*)
    *(.plt)
    *(.gnu.warning)
    *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    *(.gcc_except_table)
    . = ALIGN(32);
    __section_end_text = .;
  } > rom AT>rom
  __section_size_text = __section_end_text - __section_start_text;
  __section_wsize_text = __section_size_text / 4;
  __section_load_text = LOADADDR(.text);

  /* ------------------------------------------------------------------------ */
  /* RO Data */
  .eh_frame_hdr : ALIGN (4)
  {
    __section_start_rodata = .;
    KEEP (*(.eh_frame_hdr))
  } > rom

  .eh_frame : ALIGN (4)
  {
    KEEP (*(.eh_frame))
  } > rom

  /* .ARM.exidx is sorted, so has to go in its own output section.  */
  PROVIDE_HIDDEN (__exidx_start = .);
  .ARM.exidx :
  {
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
  } > rom
  PROVIDE_HIDDEN (__exidx_end = .);

  .rodata : ALIGN (4)
  {
    KEEP(*(.rodata .rodata.* .gnu.linkonce.r.*))
    . = ALIGN(32);
    __section_end_rodata = .;
  } > rom AT>rom

  __section_size_rodata = __section_end_rodata - __section_start_rodata;
  __section_wsize_rodata = __section_size_rodata / 4;
  __section_load_rodata = LOADADDR(.eh_frame_hdr);

  /* Section where ROM coded constants are stored */
  .lhassa_rom_params : ALIGN(4)
  {
	KEEP(*(.lhassa_rom_params))
  } > rom

  /* ======================================================================== */
  /** RAM **/

  /* ------------------------------------------------------------------------ */
  /* DATA */
  .data : ALIGN(0x10)
  {
   __section_start_data = .;
    KEEP(*(.jcr))
    *(.got.plt) *(.got)
    *(.shdata)
    KEEP(*(.data .data.* .gnu.linkonce.d.*))
    . = ALIGN(32);
    __section_end_data = .;
  } >ram AT>rom
  __section_size_data = __section_end_data - __section_start_data;
  __section_wsize_data = __section_size_data / 4;
  __section_load_data = LOADADDR(.data);

  /* ------------------------------------------------------------------------ */
  /* ROM CRC */
  .checksum.rom  : ALIGN(0x10)
  {
	. += 4;
  } >rom

  /* ------------------------------------------------------------------------ */
  /* BSS */
  .bss (NOLOAD) : ALIGN(0x20)
  {
    __section_start_bss = .;
    *(.shbss)
    *(.bss .bss.* .gnu.linkonce.b.*)
    *(COMMON)
    __section_end_bss = .;
  } >ram

  __section_bss_size = __section_end_bss - __section_start_bss;

  /* ------------------------------------------------------------------------ */
  /* Stack and Heap */
  .stack (NOLOAD) : ALIGN(0x80)
  {
  	__section_start_stack = .;
    . += __stack_size;
    __section_end_stack = .;
    __stack = .;
  } > stack
  __stack_va = __stack;

  .heap (NOLOAD) : ALIGN(0x80)
  {
    __section_start_heap = .;
    . = . + __heap_size;
    __section_end_heap = .;
    __region_end_ram = .;
  } > stack

  __section_start_heap_va = __section_start_heap;
  __section_end_heap_va = __section_start_heap_va + __heap_size;
  __virtual_start_lhassa = __section_end_heap;
/*  */

  /* ======================================================================== */

  /** Cryptography work buffer */
  .lhassa_work.sh __region_end_ram : ALIGN(0x10)
  {
  	KEEP(*(.lhassa_work.sh))
  } >ram=0

  __lhassa_work_sh_start = LOADADDR(.lhassa_work.sh);
  __lhassa_work_sh_end = LOADADDR(.lhassa_work.sh) + SIZEOF(.lhassa_work.sh);
  __lhassa_work_sh_size = SIZEOF(.lhassa_work.sh);

  /** Configuration Management work buffer */
  .lhassa_work.cm : ALIGN(0x10)
  {
  	KEEP(*(.lhassa_work.cm))
  } >ram=0

  __lhassa_work_cm_start = LOADADDR(.lhassa_work.cm);
  __lhassa_work_cm_end = LOADADDR(.lhassa_work.cm) + SIZEOF(.lhassa_work.cm);
  __lhassa_work_cm_size = SIZEOF(.lhassa_work.cm);

#ifdef _LHASSA_WITH_TL_
  /** Trace Log work buffer */
  .lhassa_work.tl : ALIGN(0x10)
  {
  	KEEP(*(.lhassa_work.tl))

  } >ram=0

  __lhassa_work_tl_start = LOADADDR(.lhassa_work.tl);
  __lhassa_work_tl_end = LOADADDR(.lhassa_work.tl) + SIZEOF(.lhassa_work.tl);
  __lhassa_work_tl_size = SIZEOF(.lhassa_work.tl);
#endif /* _LHASSA_WITH_TL_ */

  /** RCE Signature check work buffer */
  .lhassa_work.rce : ALIGN(0x10)
  {
	KEEP(*(.lhassa_work.rce))

  } >ram=0

	__lhassa_work_rce_start = LOADADDR(.lhassa_work.rce);
	__lhassa_work_rce_end = LOADADDR(.lhassa_work.rce) + SIZEOF(.lhassa_work.rce);
	__lhassa_work_rce_size = SIZEOF(.lhassa_work.rce);

  /* ======================================================================== */

  /** STP Application, SCP Applet memory areas */
  /** RAM for STP and SCP **/
  __section_protocol_ram_end = (ORIGIN(ram) + LENGTH(ram));

  .protocol_ram.stack __lhassa_work_rce_end : ALIGN(0x10)
  {
    __section_protocol_start = .;
  	/** Stack dedicated to STP application matter if needed */
   	__section_start_stp_stack = .;
	/* . += __stack_size_stp;*/
	__stack_stp = .;

  } >ram
	__section_end_stp_stack = .;

  .protocol_ram.bss __section_end_stp_stack : ALIGN(0x10)
  {
      __section_start_bss_stp = .;
    *stp_*(.bss .bss.* .gnu.linkonce.b.*)

  } >ram
    __section_end_bss_stp = .;

  .protocol_ram __section_end_bss_stp : ALIGN(0x10)
  {
	/** Code part */
    KEEP(*stp_*(.data .data.* .gnu.linkonce.d.*))
    KEEP(*stp_*(.protocol_ram))

  } >ram
  __section_protocol_end = ALIGN(0x10);
  __scp_applet_area_size = __section_protocol_ram_end - __section_protocol_end;
  /** Lasting free internal SRAM space */
  .lhassa_scp_applet __section_protocol_end : ALIGN(0x10)
  {
    __scp_applet_start = .;
    . += __scp_applet_area_size;
    __scp_applet_end = .;

  } >ram

  __section_scp_start = __section_protocol_start;
  __section_scp_stop = LOADADDR(.lhassa_scp_applet) + SIZEOF(.lhassa_scp_applet);

  __section_bss_size_stp = __section_end_bss_stp - __section_start_bss_stp;
  __section_stp_size = SIZEOF(.protocol_ram.stack) + SIZEOF(.protocol_ram.bss) + SIZEOF(.protocol_ram);

  /* ======================================================================== */
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
   }
}
