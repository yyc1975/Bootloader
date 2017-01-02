/*
 * flora -- Code in "ROM" and Data in "RAM"
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011, Maxim Integrated Products
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

INCLUDE memories.inc
INCLUDE layout.inc

EXTERN(__start_asm _start)
/* Bring in the interrupt routines & vector */
INCLUDE arm-names.inc
EXTERN(__start_c main __stack __heap_end)

__heap_size = HEAP_SIZE;
__stack_size = STACK_SIZE;

SECTIONS
{
  /* ------------------------------------------------------------------------ */
  /* Exception Vectors */
#if HAVE_ROM_BOOTSTRAP == 1
  .bootstrap :
  {
    *(.rvect)
    *(.reset)
  } > irom
#endif /* #if HAVE_ROM_BOOTSTRAP == 1 */

#if USE_HIGH_VECTORS == 1
  .higvects :
  {
    /* High Interrupt Vectors */
    __region_start_vectors = .;
    __section_start_vectors = .;
    *(.vect)
    /* The low level handlers must be in a 4K range */
    *(.handlers)
    . = ALIGN(32);
    __section_end_vectors = .;
  } > highvects AT> rom
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
  } > rom

  .text : ALIGN(32)
  {
  	__section_start_text = .;
    *(.text .text.* .gnu.linkonce.t.*)
    *(.plt)
    *(.gnu.warning)
    *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    *(.gcc_except_table)
    . = ALIGN(32);
    __section_end_text = .;
  } >rom
  __section_size_text = __section_end_text - __section_start_text;
  __section_wsize_text = __section_size_text / 4;
  __section_load_text = LOADADDR(.text);

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
  } >itcm AT>rom
  __section_size_itcm = __section_end_itcm - __section_start_itcm;
  __section_wsize_itcm = __section_size_itcm / 4;
  __section_load_itcm = LOADADDR(.itcm);
#endif /* #if ARM_HAS_ITCM == 1 */

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
    *(.rodata .rodata.* .gnu.linkonce.r.*)
    . = ALIGN(32);
    __section_end_rodata = .;
  } > rom
  __section_size_rodata = __section_end_rodata - __section_start_rodata;
  __section_wsize_rodata = __section_size_rodata / 4;
  __section_load_rodata = LOADADDR(.eh_frame_hdr);

  /* Section where ROM coded constants are stored */
  .flora_rom_params : ALIGN(4)
  {
	*(.flora_rom_params)
  } >rom

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

  } >dtcm AT>rom

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
  .bss (NOLOAD) : __mmu_align__
  {
    __section_start_bss = .;
    *(.shbss)
    *(.bss .bss.* .gnu.linkonce.b.*)
    *(COMMON)
    __section_end_bss = .;
  } >ram
  /* ------------------------------------------------------------------------ */
  /* Stack and Heap */
  .stack (NOLOAD) : __mmu_align__
  {
    __section_start_stack = .;
    . += __stack_size;
    __stack = .;
    __section_end_stack = .;
  } > ram
/** _DBG_YG_ */
/*  __stack_va = 0xFFF00000 + __stack_size;*/
  __stack_va = __stack;
/*  */
  .heap (NOLOAD) : __mmu_align__
  {
    __section_start_heap = .;
    . = . + __heap_size;
    __section_end_heap = .;
#if ENABLE_MMU == 0
	__region_end_ram = .;
#endif /* #if ENABLE_MMU == 0 */
  } > ram
/** _DBG_YG_ */
/*  __section_start_heap_va = 0xFFF02000;*/
  __section_start_heap_va = __section_start_heap;
  __section_end_heap_va = __section_start_heap_va + __heap_size;
  __virtual_start_flora = __section_end_heap;
/*  */
/**/

  /* ------------------------------------------------------------------------ */
  /* TTB
   */
#if ENABLE_MMU == 1
  .ttb  (NOLOAD) : __mmu_align__
  {
    __section_start_ttb = .;
    *(.ttb.prim)
    . = ALIGN (4K);
    *(.ttb.sec)
    . = ALIGN (16K);
    __ttb = .;
    *(.ttb)
    __section_end_ttb = .;
    . = ALIGN (4);
    __region_end_ram = .;

  } > ram
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

  /* ======================================================================== */

  /** Cryptography work buffer */
  .flora_work.sh __region_end_ram : ALIGN(0x10)
  {
  	*(.flora_work.sh)
#ifdef flora_work
  } > flora_work=0
#else
  } >ram=0
#endif /* flora_work */
  __flora_work_sh_start = LOADADDR(.flora_work.sh);
  __flora_work_sh_end = LOADADDR(.flora_work.sh) + SIZEOF(.flora_work.sh);
  __flora_work_sh_size = SIZEOF(.flora_work.sh);

  /** Configuration Management work buffer */
  .flora_work.cm : ALIGN(0x10)
  {
  	*(.flora_work.cm)
#ifdef flora_work
  } > flora_work=0
#else
  } >ram=0
#endif /* flora_work */
  __flora_work_cm_start = LOADADDR(.flora_work.cm);
  __flora_work_cm_end = LOADADDR(.flora_work.cm) + SIZEOF(.flora_work.cm);
  __flora_work_cm_size = SIZEOF(.flora_work.cm);

  /** Trace Log work buffer */
  .flora_work.tl : ALIGN(0x10)
  {
  	*(.flora_work.tl)

#ifdef flora_work
  } > flora_work=0
#else
  } >ram=0
#endif /* flora_work */
  __flora_work_tl_start = LOADADDR(.flora_work.tl);
  __flora_work_tl_end = LOADADDR(.flora_work.tl) + SIZEOF(.flora_work.tl);
  __flora_work_tl_size = SIZEOF(.flora_work.tl);

  /** RCE Signature check work buffer */
  .flora_work.rce : ALIGN(0x10)
  {
	*(.flora_work.rce)

#ifdef flora_work
  } > flora_work=0
#else
  } >ram=0
#endif /* flora_work */
	__flora_work_rce_start = LOADADDR(.flora_work.rce);
	__flora_work_rce_end = LOADADDR(.flora_work.rce) + SIZEOF(.flora_work.rce);
	__flora_work_rce_size = SIZEOF(.flora_work.rce);

  /* ======================================================================== */

  /** STP Application, SCP Applet memory areas */
  /** RAM for STP and SCP **/
  __section_protocol_ram_end = (ORIGIN(ram) + LENGTH(ram));

  .protocol_ram.stack __flora_work_rce_end : ALIGN(0x10)
  {
    __section_protocol_start = .;
  	/** Stack dedicated to STP application matter if needed */
   	__section_start_stp_stack = .;
	/*. += __stack_size_stp;*/
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
    *stp_*(.data .data.* .gnu.linkonce.d.*)
    *stp_*(.protocol_ram)

  } >ram
  __section_protocol_end = ALIGN(0x10);

  /** Lasting free internal SRAM space */
  .flora_scp_applet __section_protocol_end : ALIGN(0x10)
  {
    __scp_applet_start = .;
    . += __section_protocol_ram_end - __section_protocol_end;
    __scp_applet_end = .;

  } >ram

  __section_scp_start = __section_protocol_start;
  __section_scp_stop = LOADADDR(.flora_scp_applet) + SIZEOF(.flora_scp_applet);

  __section_bss_size_stp = __section_end_bss_stp - __section_start_bss_stp;
  __section_stp_size = SIZEOF(.protocol_ram.stack) + SIZEOF(.protocol_ram.bss) + SIZEOF(.protocol_ram);

  /* ======================================================================== */
  /* Code in AHB instruction memory 0xFFFF0000 */
  __section_iram_avect_end = (ORIGIN(iram_avect) + LENGTH(iram_avect));
  .iram_avect : ALIGN (4)
  {
    __region_start_iram_avect = .;
    __section_start_iram_avect = .;
    *(.iram_avect)
    . = ALIGN(32);
    __section_end_iram_avect = .;
  } >iram_avect
  __section_size_iram_avect = __section_end_iram_avect - __section_start_iram_avect;
  __section_wsize_iram_avect = __section_size_iram_avect / 4;
  __section_load_iram_avect = LOADADDR(.iram_avect);


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
