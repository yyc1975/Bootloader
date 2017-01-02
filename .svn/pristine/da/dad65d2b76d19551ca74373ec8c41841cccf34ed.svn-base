/*
 * ext_mem.inc -- Code in external memories, Interrupt Vectors in SRAM
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
 * Created on: Jun 21, 2011
 * Author: Yann G.
 *
 * ---- subversion keywords (need to set the keyword property)
 * $Revision:: 1588     $:  Revision of last commit
 * $Author:: gregory.ro#$:  Author of last commit
 * $Date:: 2011-04-05 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */
REGION_ALIAS("rom", irom);
REGION_ALIAS("ram", iram);
REGION_ALIAS("highvects", iram_avect);

/** List of available external memories
* - INT_RAM = 0
* - EXT_NAND = 1
* - EXT_SRAM0 = 2
* - EXT_SRAM1 = 3
* - EXT_SRAM2 = 4
* - EXT_SRAM3 = 5
* - EXT_SRAM4 = 6
* - EXT_SRAM5 = 7
* - EXT_SRAM6 = 8
* - EXT_SRAM7 = 9
* - EXT_SDRAM0 = 10
* - EXT_SDRAM1 = 11
*/
/** Storage memory region definition */
#if __MEM_STORAGE == 0
REGION_ALIAS("s_mem", iram);
#elif __MEM_STORAGE == 1
REGION_ALIAS("s_mem", nand);
#elif __MEM_STORAGE == 2
REGION_ALIAS("s_mem", sram);
#elif __MEM_STORAGE == 3
REGION_ALIAS("s_mem", sram);
#elif __MEM_STORAGE == 4
REGION_ALIAS("s_mem", sram);
#elif __MEM_STORAGE == 5
REGION_ALIAS("s_mem", nor);
#elif __MEM_STORAGE == 6
REGION_ALIAS("s_mem", sram);
#elif __MEM_STORAGE == 7
REGION_ALIAS("s_mem", sram);
#elif __MEM_STORAGE == 8
REGION_ALIAS("s_mem", sram);
#elif __MEM_STORAGE == 9
REGION_ALIAS("s_mem", sram);
#elif __MEM_STORAGE == 10
REGION_ALIAS("s_mem", sdram0);
#elif __MEM_STORAGE == 11
REGION_ALIAS("s_mem", sdram1);
#endif /* __MEM_STORAGE */

/** Execution memory region definition */
#if __MEM_EXEC == 0
REGION_ALIAS("e_mem", iram);
#elif __MEM_EXEC == 1
REGION_ALIAS("e_mem", nand);
#elif __MEM_EXEC == 2
REGION_ALIAS("e_mem", sram);
#elif __MEM_EXEC == 3
REGION_ALIAS("e_mem", sram);
#elif __MEM_EXEC == 4
REGION_ALIAS("e_mem", sram);
#elif __MEM_EXEC == 5
REGION_ALIAS("e_mem", nor);
#elif __MEM_EXEC == 6
REGION_ALIAS("e_mem", sram);
#elif __MEM_EXEC == 7
REGION_ALIAS("e_mem", sram);
#elif __MEM_EXEC == 8
REGION_ALIAS("e_mem", sram);
#elif __MEM_EXEC == 9
REGION_ALIAS("e_mem", sram);
#elif __MEM_EXEC == 10
REGION_ALIAS("e_mem", sdram0);
#elif __MEM_EXEC == 11
REGION_ALIAS("e_mem", sdram1);
#endif /* __MEM_EXEC */

/* EOF */
