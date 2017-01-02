/*
 * mml_io.h --
 *
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

/* [INTERNAL] ------------------------------------------------------------------
 * Created on: June 1, 2012
 * Author: Jeremy B. <jeremy.brodt@maximintegrated.com>
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision: 3896 $:  Revision of last commit
 * $Author: yann.gaude $:  Author of last commit
 * $Date: 2014-08-19 11:57:48 +0200 (mar. 19 août 2014) $:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */
#ifndef _MML_IO_H_
#define _MML_IO_H_

/** Global includes */
#include <io.h>
/** Other includes */
/** Local includes */


#ifndef __ASSEMBLER__
// Nominal Frequency (Nf) Calculation
// Per MQ55 Spec: PCF = PSC + 2
// Nf = PCLK * 2^PCF
// PCLK = PLLO / 2^(PSC+1)
// Nf = 2 * PLLO
#define MML_NOM_FREQ							( 2 * MML_PLLO_FREQ )

#define MML_UART_FREQ							MML_NOM_FREQ
#define MML_I2C_FREQ							MML_NOM_FREQ
#define MML_FLC_FREQ							MML_APB_FREQ
#define MML_SPI_FREQ							MML_APB_FREQ
#define MML_TIMER_FREQ							MML_APB_FREQ

#define MML_GPIO_MODE_UART0						{MML_GPIO0_IOBASE,  8, 0x3}
#define MML_GPIO_MODE_UART1						{MML_GPIO0_IOBASE, 12, 0x3}

#endif /* __ASSEMBLER__ */

#endif /* _MML_IO_H_ */

/******************************************************************************/
/* EOF */
