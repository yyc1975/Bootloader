/***********************************************************************
 *
 * FILE NAME: nvsram.h
 *
 *
 * PURPOSE: Defines all reference data variables.
 *
 *
 * GLOBAL VARIABLES:*
 *
 * Variables     Type     Description
 * ------------- -------- ---------------------------
 * none
 *
 * DEVELOPMENT HISTORY:
 *
 * Date     Author       Change ID Release Description of Change
 * -------- ------------ --------- ------- ------------------------------
 * 04-27-16 Chiate Wang                1    Initial Code
 *
 ***********************************************************************/

#ifndef _NVSRAM_H_
#define _NVSRAM_H_

#include <mml.h>
#include <FreeRTOS.h>
#include "task.h"


#define SNVSRAM_DYNAMIC_USAGE_LEN       ( 252 )
#define SNVSRAM_SIGNATURE_LEN           ( 4 )

#define SNVSRAM_STATIC_START_ADDRESS    ( MML_MEM_SNVSRAM_BASE )
#define SNVSRAM_KS_START_ADDRESS        ( SNVSRAM_STATIC_START_ADDRESS )
#define SNVSRAM_KS_USAGE_LEN            ( MML_MEM_SNVSRAM_SIZE - \
                                          SNVSRAM_DYNAMIC_USAGE_LEN - \
                                          SNVSRAM_SIGNATURE_LEN )
#define SNVSRAM_DYNAMIC_START_ADDRESS  ( SNVSRAM_KS_START_ADDRESS + \
                                          SNVSRAM_KS_USAGE_LEN )

#define SNVSRAM_SIGNATURE_START_ADDRESS ( SNVSRAM_DYNAMIC_START_ADDRESS + \
                                          SNVSRAM_DYNAMIC_USAGE_LEN )

unsigned int NvsramSignatureRead(void);
void NvsramSignatureWrite(unsigned int signature);
void NvsramEraseAll(void);
void *SecureMemAlloc(const signed char * const tag, size_t len);
size_t GetSecureMemFreeSize(void);
void GetSecureMemUsage(void);

#endif /* _NVSRAM_H_ */

