/*
 * ttb.c --
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
 * Created on: Jun 22, 2010
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 2269     $:  Revision of last commit
 * $Author:: yann.gaude $:  Author of last commit
 * $Date:: 2011-11-22 2#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#include "config.h"
#include "arch/arm/ttb.h"

#define	K_COBRA_1_KB				1024
#define	K_COBRA_1_MB				(1024 * K_COBRA_1_KB)
#define	K_COBRA_1_GB				(1024 * K_COBRA_1_MB)

#define TTB_SIZE				4096
#define USES_4KB_PAGES			1
#define COARSE_TABLE_SIZE		256
#define	MEMORY_TRANSLATED_SIZE	(64 * K_COBRA_1_KB)
#define	MEMORY_TRANSLATED_BASE	0xffff0000

#define RAM_1MBPAGE_ADDRESS		((RAM_BASE)&0xFFF00000)
#define RAM_4KBPAGE_INDEX		(((RAM_BASE)&0x000FFFFF)>>12)
#define RAM_4KBPAGE_SIZE		((RAM_SIZE)>>12)

#if ENABLE_MMU == 1

/** TTB First Level.
 * 1MB Pages
 */
static unsigned _ttb[TTB_SIZE] __attribute__ ((section (".ttb")));

/** TTB 4KB Coarse Tables */
/** One for direct mapping of internal RAM */
static unsigned _ttb_prim[COARSE_TABLE_SIZE] __attribute__ ((section (".ttb.prim")));
/** One for mapped area of internal RAM */
static unsigned _ttb_sec[COARSE_TABLE_SIZE] __attribute__ ((section (".ttb.sec")));

extern char __section_start_stack;
extern char __section_start_heap;
extern char __section_start_ttb;

extern char __section_end_stack;
extern char __section_end_heap;
extern char __section_end_ttb;

/** Generate TTBs */
void ttb_init(enum cache_config config)
{
	unsigned int				i;
	unsigned int				index;
	unsigned int				base;
	unsigned int				end;
	unsigned int				size;

	/** Invalidate pages not in RAM for 1st coarse table */
	size = COARSE_TABLE_SIZE;
	for( i = 0;i < size;i++ )
	{
		_ttb_prim[i] = 0;
	}
	/** Coarse */
	base = RAM_4KBPAGE_INDEX;
	/** Flat mapping of the RAM */
	for( i = base;i < size;i++ )
	{
		_ttb_prim[i] = RAM_1MBPAGE_ADDRESS + (i << 12);
		_ttb_prim[i] |= ( COARSE_4KBPAGE_SETAP0(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP1(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP2(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP3(PAGE_AP_MANAGER) |
						COARSE_ENTRY_4KBPAGE );
		_ttb_prim[i] |= COARSE_4KBPAGE_SETCACHE(config);
	}
	/** ... Then remove page of stack (4K aligned) ... */
	base = ( ((unsigned int)&__section_start_stack) & 0x000fffff ) >> 12;
/** _DBG_YG_ */
//	end = ( ((unsigned int)&__section_end_stack) & 0x000fffff ) >> 12;
	end = ((unsigned int)&__section_end_stack) & 0x000fffff;
	/** Check if end is 4K aligned */
	if ( end & 0x00000fff )
	{
		/** Take next 4K page too */
		end = end >> 12;
		end++;
	}
	else
	{
		/** It is aligned */
		end = end >> 12;
	}
	/**  */
/*  */
	for( i = base;i < end;i++ )
	{
		_ttb_prim[i] = RAM_1MBPAGE_ADDRESS + (i << 12);
		_ttb_prim[i] |= ( COARSE_4KBPAGE_SETAP0(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP1(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP2(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP3(PAGE_AP_MANAGER) |
						COARSE_ENTRY_4KBPAGE );
		_ttb_prim[i] |= COARSE_4KBPAGE_SETCACHE(CACHE_DISABLED_NOTBUFFERABLE);
	}
	/** ... heap (4K aligned) ... */
	base = ( ((unsigned int)&__section_start_heap) & 0x000fffff ) >> 12;
/** _DBG_YG_ */
//	end = ( ((unsigned int)&__section_end_heap) & 0x000fffff ) >> 12;
	end = ((unsigned int)&__section_end_heap) & 0x000fffff;
	/** Check if end is 4K aligned */
	if ( end & 0x00000fff )
	{
		/** Take next 4K page too */
		end = end >> 12;
		end++;
	}
	else
	{
		/** It is aligned */
		end = end >> 12;
	}
	/**  */
/*  */
	for( i = base;i < end;i++ )
	{
		_ttb_prim[i] = RAM_1MBPAGE_ADDRESS + (i << 12);
		_ttb_prim[i] |= ( COARSE_4KBPAGE_SETAP0(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP1(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP2(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP3(PAGE_AP_MANAGER) |
						COARSE_ENTRY_4KBPAGE );
		_ttb_prim[i] |= COARSE_4KBPAGE_SETCACHE(CACHE_DISABLED_NOTBUFFERABLE);
	}
	/** ... and ttb (4k aligned) ... */
	base = ( ((unsigned int)&__section_start_ttb) & 0x000fffff ) >> 12;
/** _DBG_YG_ */
//	end = ( ((unsigned int)&__section_end_ttb) & 0x000fffff ) >> 12;
	end = ((unsigned int)&__section_end_ttb) & 0x000fffff;
	/** Check if end is 4K aligned */
	if ( end & 0x00000fff )
	{
		/** Take next 4K page too */
		end = end >> 12;
		end++;
	}
	else
	{
		/** It is aligned */
		end = end >> 12;
	}
	/**  */
/*  */
	for( i = base;i < end;i++ )
	{
		_ttb_prim[i] = RAM_1MBPAGE_ADDRESS + (i << 12);
		_ttb_prim[i] |= ( COARSE_4KBPAGE_SETAP0(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP1(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP2(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP3(PAGE_AP_MANAGER) |
						COARSE_ENTRY_4KBPAGE );
		_ttb_prim[i] |= COARSE_4KBPAGE_SETCACHE(CACHE_DISABLED_NOTBUFFERABLE);
	}
	/** Second coarse table for last 64KB of memory mapping
	 * from 0xffff 0000 to 0xffff ffff */
	/** Set no action for this coarse table */
	size = COARSE_TABLE_SIZE;
	/** Last megabyte of memory mapping = last entry of TTB array */
	base = ( TTB_SIZE - 1 ) << 20;
	for( i = 0;i < size;i++ )
	{
		_ttb_sec[i] = base + (i << 12);
		_ttb_sec[i] |= ( COARSE_4KBPAGE_SETAP0(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP1(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP2(PAGE_AP_MANAGER) |
						COARSE_4KBPAGE_SETAP3(PAGE_AP_MANAGER) |
						COARSE_ENTRY_4KBPAGE );
		_ttb_sec[i] |= COARSE_4KBPAGE_SETCACHE(CACHE_DISABLED_NOTBUFFERABLE);
	}
	/** Now repeat the mapping for the last 64KB from primary coarse table */
	/** Last 64KB */
	size = ( ( MEMORY_TRANSLATED_SIZE & 0x000fffff) >> 12 );
	/** Last 16 indexes */
	index = COARSE_TABLE_SIZE - size;
	/** Base index in primary coarse table */
	base = RAM_4KBPAGE_INDEX;
	for( i = 0;i < size;i++ )
	{
		_ttb_sec[index + i] = _ttb_prim[base + i];
	}
	/** The first level TTB defines a flat mapping for all but the last section.
	 *
	 * The ROM could be "emulated" with RAM (on FPGA); set the ROM as Read Only
	 * to avoid error. The Domain 0 will be set to AP Client and ROM protection
	 * will be enabled.
	 *
	 * By default all non RAM/ROM is not cached.
	 */
	_ttb[0] = SECTION_SETAP(PAGE_AP_NONE) |
				SECTION_SETDOMAIN(0) |
				SECTION_SETRFU() |
				SECTION_SETCACHE(config) |
				TTB_ENTRY_SECTION;

	for( i = 1;i < TTB_SIZE;i++ )
	{
		_ttb[i] = ( (i << 20) |
					( SECTION_SETAP(PAGE_AP_MANAGER) |
					SECTION_SETDOMAIN(15) |
					SECTION_SETRFU() |
					SECTION_SETCACHE(CACHE_DISABLED_NOTBUFFERABLE) |
					TTB_ENTRY_SECTION) );
	}
	/** Map the RAM with gap to avoid buffer overflows. Moreover this mapping
	 * does not include the TTBs which are directly used by the ARM
	 * (physically addressed).
	 */
	/** Attach a coarse table to the genuine internal RAM area */
	/** Base address of internal memory area
	 * It should be less than 1MB */
	index = RAM_BASE >> 20;
	_ttb[index] =  ( ((unsigned int)_ttb_prim) & 0xfffffc00 ) |
					( SECTION_SETDOMAIN(15) |
					SECTION_SETRFU() |
					TTB_ENTRY_COARSE );
	/** Attach a coarse table to the last 1MB page */
	_ttb[TTB_SIZE - 1] = ( ((unsigned int)_ttb_sec) & 0xfffffc00 ) |
							( SECTION_SETDOMAIN(15) |
							SECTION_SETRFU() |
							TTB_ENTRY_COARSE );
	/** We're done */
	return;
}

void ttb_section_setcache(unsigned addr, enum cache_config config) {
	_ttb[(addr >> 20)] &= ~SECTION_CB_MASK;
	_ttb[(addr >> 20)] |= SECTION_SETCACHE(config);
}


void ttb_4kbpage_setcache(unsigned addr, enum cache_config config)
{
//FIXME: Take care of secondary coarse table because it has to echo cache policy into it
	_ttb_prim[(addr >> 12)] &= ~COARSE_4KBPAGE_CB_MASK;
	_ttb_prim[(addr >> 12)] |= (config << 2);
}


#endif /* #if ENABLE_MMU == 1 */

