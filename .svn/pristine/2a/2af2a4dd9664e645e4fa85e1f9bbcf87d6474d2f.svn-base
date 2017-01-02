/*
 * memories.inc -- JIBE Memory Layout
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
 * $Revision:: 2166     $:  Revision of last commit
 * $Author:: yann.gaude $:  Author of last commit
 * $Date:: 2011-09-29 2#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

MEMORY
{
  /* Some JTAG probes need work memory let 4KB in the ROM for that */ 
  irom (rx)         : ORIGIN = 0x00000000, LENGTH = 128K
  itcm (rx)         : ORIGIN = 0x00600000, LENGTH = 4K
  dtcm (rw)         : ORIGIN = 0x00700000, LENGTH = 4K
  iram (rwx)        : ORIGIN = 0x00900000, LENGTH = 384K
  iram_novect (rwx) : ORIGIN = 0x00901000, LENGTH = 380K
  iram1 (rwx)       : ORIGIN = 0x00900000, LENGTH = 64K
  iram2 (rwx)       : ORIGIN = 0x00910000, LENGTH = 320K
  nvsram (rwx)      : ORIGIN = 0x00A00000, LENGTH = 64K
  iram_a (rwx)      : ORIGIN = 0xFFFF0000, LENGTH = 64K
  iram_avect (rwx)  : ORIGIN = 0xFFFF0000, LENGTH = 4K
  nand (rw)         : ORIGIN = 0x10000000, LENGTH = 512M
  sram (rwx)        : ORIGIN = 0x30000000, LENGTH = 64M
  nor (rw)			: ORIGIN = 0x40000000, LENGTH = 32M
  sdram0 (rwx)      : ORIGIN = 0x70000000, LENGTH = 512M
  sdram1 (rwx)      : ORIGIN = 0x90000000, LENGTH = 512M
}

EXTERN(__reset __reset_jibe)
PROVIDE(__reset = __reset_jibe);
