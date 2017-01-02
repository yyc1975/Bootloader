/*
 * memories.inc -- Memory layout for Londa
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011, Maxim Integrated
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
 * $Revision:: 1044     $:  Revision of last commit
 * $Author:: yann.gaude $:  Author of last commit
 * $Date:: 2011-01-21 2#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

MEMORY
{
  irom (rx)     : ORIGIN = 0x00000000, LENGTH = 128K
  iram (rwx)  : ORIGIN = 0xFFFE1000, LENGTH = 64K
  nvsram (rwx)  : ORIGIN = 0xFFFF1000, LENGTH = 16K
  itcm (rwx)    : ORIGIN = 0x50000000, LENGTH = 4K
  dtcm (rw)     : ORIGIN = 0x60000000, LENGTH = 4K
  otp (r)       : ORIGIN = 0x10100000, LENGTH = 2K
  iflash (rx)   : ORIGIN = 0x10000000, LENGTH = 512K
  tftram (rw)  : ORIGIN = 0x30000000, LENGTH = 160K
}

EXTERN(__reset __reset_londa)
PROVIDE(__reset = __reset_londa);
