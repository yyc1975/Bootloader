/*
 * max32550_crypto_regs.h --
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2010, Maxim Integrated Products
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
/*
 * max32550_crypto_regs.h
 *
 *  Created on: 24-May-2012
 *      Author: Rajasekhar.Baddala
 */

#ifndef MQ55_CRYPTO_REGS_H_
#define MQ55_CRYPTO_REGS_H_

#ifndef __ASSEMBLER__

/* Crypto Control Register */
#define CRYPTO_CTRL_RST 0x01

#define CRYPTO_CTRL_INT 0x02
/* retaining wrongly typed macro "CRYPTO_CTRL_INIT" (use CRYPTO_CTRL_INT defined above)*/
#define CRYPTO_CTRL_INIT CRYPTO_CTRL_INT

#define CRYPTO_CTRL_SRC 0x04
#define CRYPTO_CTRL_BSO 0x10
#define CRYPTO_CTRL_BSI 0x20
#define CRYPTO_CTRL_WAIT_EN 0x40
#define CRYPTO_CTRL_WAIT_POL 0x80
#define CRYPTO_CTRL_WRSRC_BITS 0x0300
#define CRYPTO_CTRL_WRSRC_NONE 0x0000
#define CRYPTO_CTRL_WRSRC_CIPHER_OUT 0x0100
#define CRYPTO_CTRL_WRSRC_READ_FIFO 0x0200
#define CRYPTO_CTRL_RDSRC_DMA_BITS 0x0C00
#define CRYPTO_CTRL_RDSRC_DMA_DISABLE 0x00
#define CRYPTO_CTRL_RDSRC_DMA_APB 0x0400
#define CRYPTO_CTRL_RDSRC_RNG 0x0800
#define CRYPTO_CTRL_DMA_DONE 0x01000000
#define CRYPTO_CTRL_GLS_DONE 0x02000000
//bit 26
#define CRYPTO_CTRL_HSH_DONE 0x04000000
#define CRYPTO_CTRL_CPH_DONE 0x08000000
#define CRYPTO_CTRL_MAA_DONE 0x10000000
#define CRYPTO_CTRL_ERR_DONE 0x20000000
//bit 30
#define CRYPTO_CTRL_RDY 0x40000000
#define CRYPTO_CTRL_DONE 0x80000000
//#define FLAG_MODE 0x4000


/* Crypto Cipher Control Register */
#define CRYPTO_CIPHER_CTRL_ENC_BIT_POS 0
#define CRYPTO_CIPHER_CTRL_ENC 0x00
#define CRYPTO_CIPHER_CTRL_DEC 0x01

#define CRYPTO_CIPHER_CTRL_KEY 0x02
#define CRYPTO_CIPHER_CTRL_IV 0x04
#define CRYPTO_CIPHER_CTRL_CIPHER_BITS 0x70
#define CRYPTO_CIPHER_CTRL_CIPHER_BITS_POS 4
#define CRYPTO_CIPHER_CTRL_CIPHER_AES_128 0x10
#define CRYPTO_CIPHER_CTRL_CIPHER_AES_192 0x20
#define CRYPTO_CIPHER_CTRL_CIPHER_AES_256 0x30
#define CRYPTO_CIPHER_CTRL_CIPHER_DES 0x40
#define CRYPTO_CIPHER_CTRL_CIPHER_TDES 0x50
#define CRYPTO_CIPHER_CTRL_MODE_BITS 0x0700
#define CRYPTO_CIPHER_CTRL_MODE_BITS_POS 8
#define CRYPTO_CIPHER_CTRL_MODE_ECB 0x0000
#define CRYPTO_CIPHER_CTRL_MODE_CBC 0x0100
#define CRYPTO_CIPHER_CTRL_MODE_CFB 0x0200
#define CRYPTO_CIPHER_CTRL_MODE_OFB 0x0300
#define CRYPTO_CIPHER_CTRL_MODE_CTR 0x0400
#define CRYPTO_CIPHER_CTRL_INS_BITS 0x070000
#define CRYPTO_CIPHER_CTRL_INS_NO_INS 0x000000
#define CRYPTO_CIPHER_CTRL_INS_1OF_16CLKS 0x010000
#define CRYPTO_CIPHER_CTRL_INS_1OF_8CLKS 0x020000
#define CRYPTO_CIPHER_CTRL_INS_1OF_4CLKS 0x030000
#define CRYPTO_CIPHER_CTRL_INS_1OF_2CLKS 0x040000
#define CRYPTO_CIPHER_CTRL_INS_3OF_4CLKS 0x050000
#define CRYPTO_CIPHER_CTRL_INS_7OF_8CLKS 0x060000
#define CRYPTO_CIPHER_CTRL_INS_15OF_16CLKS 0x070000
#define CRYPTO_CIPHER_CTRL_DLY_BITS 0x0x380000
#define CRYPTO_CIPHER_CTRL_DLY_NODELAY 0x000000
#define CRYPTO_CIPHER_CTRL_DLY_HALFCLK_AVG 0x080000
#define CRYPTO_CIPHER_CTRL_DLY_2CLK_AVG 0x100000
#define CRYPTO_CIPHER_CTRL_DLY_4CLK_AVG 0x180000
#define CRYPTO_CIPHER_CTRL_DLY_8CLK_AVG 0x2000000
#define CRYPTO_CIPHER_CTRL_DLY_16CLK_AVG 0x280000
#define CRYPTO_CIPHER_CTRL_DLY_32CLK_AVG 0x300000
#define CRYPTO_CIPHER_CTRL_DLY_64CLK_AVG 0x380000

/* Crypto Hash Control Register */
#define CRYPTO_HASH_CTRL_INIT 0x01
#define CRYPTO_HASH_CTRL_XOR 0x02
#define CRYPTO_HASH_CTRL_HASH_BITS_POS 0x2
#define CRYPTO_HASH_CTRL_HASH_BITS 0x001C
#define CRYPTO_HASH_CTRL_HASH_DISABLED 0x000
#define CRYPTO_HASH_CTRL_HASH_SHA_1 0x0004
#define CRYPTO_HASH_CTRL_HASH_SHA_224 0x0008
#define CRYPTO_HASH_CTRL_HASH_SHA_256 0x000C
#define CRYPTO_HASH_CTRL_HASH_SHA_384 0x0010
#define CRYPTO_HASH_CTRL_HASH_SHA_512 0x0014
#define CRYPTO_HASH_CTRL_LAST 0x20

/* Crypto CRC control Register bits */
#define CRYPTO_CRC_ENABLE				0x01
#define CRYPTO_CRC_MSB_LSB_SELECT 		0x02
#define CRYPTO_CRC_PRNG_ENABLE			0x04
#define CRYPTO_CRC_ENTROPY_ENABLE		0x08
#define CRYPTO_CRC_HMMING_CODE_ENABLE	0x10
#define CRYPTO_CRC_HMMING_CODE_RESET	0x20


typedef volatile struct _mq55_crypto_regs_{
	unsigned crypto_control;	//< Crypto Control Register
	unsigned crypto_cipher_control;	//< Crypto Cipher Control register
	unsigned crypto_hash_control;	//< Crypto Hash Control register
	unsigned crypto_crc_control;	//< Crypto CRC Control register
	unsigned crypto_dma_src;	//< Crypto DMA SRC register
	unsigned crypto_dma_dest;	//< Crypto DMA DEST register
	unsigned crypto_dma_cnt;	//< Crypto DMA COUNT register
	unsigned crypto_maa_control;	//< Crypto MAA Control register
	unsigned crypto_DIN_0;	//<  Crypto Data IN register
	unsigned crypto_DIN_1;	//< Crypto Data IN register
	unsigned crypto_DIN_2;	//< Crypto Data IN register
	unsigned crypto_DIN_3;	//< Crypto Data IN register
	unsigned crypto_DOUT_0;	//< Crypto Data OUT register
	unsigned crypto_DOUT_1;	//< Crypto Data OUT register
	unsigned crypto_DOUT_2;	//< Crypto Data OUT register
	unsigned crypto_DOUT_3;	//< Crypto Data OUT register
	unsigned crypto_CRC_POLY;	//< Crypto CRC Polynomial register
	unsigned crypto_CRC_VAL;	//< Crypto CRC Value register
	unsigned crypto_CRC_PRNG;	//< Crypto Psuedo Random Number Generator register
	unsigned crypto_HAM_ECC;	//< Crypto Hamming ECC register
	unsigned crypto_cipher_init_0;	//< Crypto Cipher INIT Vector register
	unsigned crypto_cipher_init_1;	//< Crypto Cipher INIT Vector register
	unsigned crypto_cipher_init_2;	//< Crypto Cipher INIT Vector register
	unsigned crypto_cipher_init_3;	//< Crypto Cipher INIT Vector register
	unsigned crypto_cipher_key_0;	//< Crypto Cipher KEY register
	unsigned crypto_cipher_key_1;	//< Crypto Cipher KEY register
	unsigned crypto_cipher_key_2;	//< Crypto Cipher KEY register
	unsigned crypto_cipher_key_3;	//< Crypto Cipher KEY register
	unsigned crypto_cipher_key_4;	//< Crypto Cipher KEY register
	unsigned crypto_cipher_key_5;	//< Crypto Cipher KEY register
	unsigned crypto_cipher_key_6;	//< Crypto Cipher KEY register
	unsigned crypto_cipher_key_7;	//< Crypto Cipher KEY register
	unsigned crypto_hash_digest_0;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_1;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_2;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_3;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_4;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_5;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_6;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_7;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_8;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_9;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_10;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_11;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_12;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_13;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_14;	//< Crypto Hash Digest register
	unsigned crypto_hash_digest_15;	//< Crypto Hash Digest register
	unsigned crypto_hash_mesg_size_0;	//< Crypto Hash Message Size
	unsigned crypto_hash_mesg_size_1;	//< Crypto Hash Message Size
	unsigned crypto_hash_mesg_size_2;	//< Crypto Hash Message Size
	unsigned crypto_hash_mesg_size_3;	//< Crypto Hash Message Size

} mml_crypto_regs_t;

#endif

#endif /* MQ55_CRYPTO_REGS_H_ */
