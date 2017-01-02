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
#include <arch/arm/link.h>

OUTPUT_FORMAT ("elf32-littlearm")
ENTRY(__reset)
SEARCH_DIR(.)

INCLUDE link/mq55/memories.inc
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
  /* Init Code */
   /* SLA Start */
  __start_sla = 0x10000000;
  __sla_load_addr = 0x10000000;
  /* SLA Header */
  .sla_header __start_sla : ALIGN(0x20)
  {
    . += 0x20;
  } > iflash

  /* SLA Arguments */
  .sla_args : ALIGN(0x20)
  {
    . += 0x00;
  } > iflash

  __sla_start = .;
  
  .text.init : ALIGN(0x20)
  {
    KEEP(*(.reset))
    KEEP(*(.text.init))
  } > boot

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

  /* Maxim HW */
  maxim_gcr 0x10020000 : ALIGN(0x4)
  {
    ./build/mq55-default_bin-default_bin-debug/objs/mml_gcr.o(.text)
  }

  maxim_gpio 0x10021000 : ALIGN(0x4)
  {
    ./build/mq55-default_bin-default_bin-debug/objs/mml_gpio.o(.text)
  }

  maxim_intc 0x10022000 : ALIGN(0x4)
  {
    ./build/mq55-default_bin-default_bin-debug/objs/mml_intc.o(.text)
  }

  maxim_uart 0x10023000 : ALIGN(0x4)
  {
    ./build/mq55-default_bin-default_bin-debug/objs/mml_uart.o(.text)
  }

  maxim_tmr 0x10024000 : ALIGN(0x4)
  {
    ./build/mq55-default_bin-default_bin-debug/objs/mml_tmr.o(.text)
  }

  maxim_printf 0x10025000 : ALIGN(0x4)
  {
    ./build/mq55-default_bin-default_bin-debug/objs/printf_lite.o(.text)
    ./build/mq55-default_bin-default_bin-debug/objs/printf_lite.o(.rodata)
  }

  maxim_ucl 0x10028000 : ALIGN(0x4)
  {
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ecdsa_generic_api.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ecdsa_generic_api.c.o(.rodata*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha224.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha224.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha384.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha384.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha512.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha512.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha256.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha256.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:sha512_stone.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:sha512_stone.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sia256.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sia256.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha1.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sha1.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:sha1_stone.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:sha1_stone.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sys.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sys.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_rng.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_rng.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:data_conv.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:data_conv.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_stack.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_stack.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:bignum.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:bignum.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:sha256_stone.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:sha256_stone.c.o(.rodata.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sm3.c.o(.text.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sm3.c.o(.rodata.*)
  }

  /* Code */
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
  } > rom
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
  } > rom

  __section_size_rodata = __section_end_rodata - __section_start_rodata;
  __section_wsize_rodata = __section_size_rodata / 4;
  __section_load_rodata = LOADADDR(.eh_frame_hdr);

  /* ======================================================================== */
  /** RAM **/

  /* ------------------------------------------------------------------------ */
  /* DATA */
  .data : ALIGN(0x10)
  {
    __section_start_data = .;
    KEEP(*(.share))
    /* ucl library bss */
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ecdsa_generic_api.c.o(.bss.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sia256.c.o(.bss.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sys.c.o(.bss.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_stack.c.o(.bss.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:bignum.c.o(.bss.*)
    . = ALIGN(0x10);
    __section_end_share = .;
    /* ucl library data */
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:ucl_sia256.c.o(.data.*)
    ./lib/libucl/cortex-m3/libucl-2.4.7_max32550.a:bignum.c.o(.data.*)
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
  .stack (ORIGIN(stack) + LENGTH(stack) - __stack_size) (NOLOAD) :
  {
    __section_start_stack = .;
    . += __stack_size;
    __section_end_stack = .;
    __stack = .;
  }
  __stack_va = __stack;

  .heap (NOLOAD) : ALIGN(0x100)
  {
    __section_start_heap = .;
    . = . + __heap_size;
    __section_end_heap = .;
    __region_end_ram = .;
  } > stack

  __section_start_heap_va = __section_start_heap;
  __section_end_heap_va = __section_start_heap_va + __heap_size;

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
