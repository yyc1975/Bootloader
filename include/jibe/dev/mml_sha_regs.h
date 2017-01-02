/*
 * mml_sha_regs.h --
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
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* [INTERNAL] ------------------------------------------------------------------
 * Created on: June 8, 2010
 * Author: Gregory Romé <gregory.rome@maximintegrated.com>
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 1215     $:  Revision of last commit
 * $Author:: james.cott#$:  Author of last commit
 * $Date:: 2011-02-24 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */
#ifndef MML_SHA_REGS_H_
#define MML_SHA_REGS_H_

#ifndef __ASSEMBLER__
/* ------------------------------------------------------------------------
---- */
/** SHA Registers.
*
*/
typedef volatile struct _mml_sha_regs_{
	unsigned shac;	//< control register
	// NO_SHAP_CHANGE unsigned shap;	//< Address register
	unsigned sha_mesg_size_0;	//< Message Size
	unsigned sha_mesg_size_1;	//< Message Size
	unsigned sha_mesg_size_2;	//< Message Size
	unsigned sha_mesg_size_3;	//< Message Size
	unsigned sha_digest_0;	//< Hash Digest register
	unsigned sha_digest_1;	//< Hash Digest register
	unsigned sha_digest_2;	//< Hash Digest register
	unsigned sha_digest_3;	//< Hash Digest register
	unsigned sha_digest_4;	//< Hash Digest register
	unsigned sha_digest_5;	//< Hash Digest register
	unsigned sha_digest_6;	//< Hash Digest register
	unsigned sha_digest_7;	//< Hash Digest register
	unsigned sha_digest_8;	//< Hash Digest register
	unsigned sha_digest_9;	//< Hash Digest register
	unsigned sha_digest_10;	//< Hash Digest register
	unsigned sha_digest_11;	//< Hash Digest register
	unsigned sha_digest_12;	//< Hash Digest register
	unsigned sha_digest_13;	//< Hash Digest register
	unsigned sha_digest_14;	//< Hash Digest register
	unsigned sha_digest_15;	//< Hash Digest register

} mml_sha_regs_t;

#endif /* __ASSEMBLER__ */

#endif /* MML_SHA_REGS_H_ */
