/********************************************************************
*
*
* FILE NAME: selftest.c
*
*
* PURPOSE: This is the implementation of self test functions.
*
*
* FILE REFERENCES:
*
* Name                      IO          Description
* ------------              --          ---------------------------------
* none
*
*
* EXTERNAL VARIABLES:
*
* Source : 
*
* Name                  Type    IO          Description
* -------------         ------- --          -----------------------------
* 
*
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
* none
*
*
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS: none
*
*
* NOTES:
* CALLED BY: 
*
*
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
* ANS X9.24-1:2009, Annex A: Derived Unique Key Per Transaction
*
*
* DEVELOPMENT HISTORY:
* Date      Name         Change Release Description
*                        ID
* -------- ------------- ------ ------- --------------------------
* 06-15-16 Chiate.Wang             1    Initial code
* 06-15-16 YY. Chen                1    Added tests for TDES/DES/AES/TRNG/RSA
*
******************************************************************** */

/* Global includes */
#include <errors.h>

/* Other includes */
#include <mml_smon.h>
#include <mml_smon_regs.h>

/* Local includes */
#include <printf_lite.h>
#include <crypto_tests.h>

/* Define Area */


/* Global Variable */


/* Global Function */


/* External Function */


/* External Variable */


/*******************************************************************
*
* FUNCTION NAME: temperTest
*
* PURPOSE: To execute temper self test
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       the error code (/include/errors.h)
*
*******************************************************************/
int temperTest(void)
{
    unsigned int reg = 0;
    int result = NO_ERROR;

    /* Check enable of internal sensors */
    mml_smon_readintscn(&reg);
    if((reg & 0x00000007) != 0x07) {
        result = COMMON_ERR_FATAL_ERROR;
        goto fail;
    }

    /* Check enable of external sensors */
    mml_smon_readextscn(&reg);
    if((reg & 0x0000003F) != 0x3F) {
        result = COMMON_ERR_FATAL_ERROR;
        goto fail;
    }

    mml_smon_readsecalm(&reg);
    /* Check status of internal sensors */
    if((reg & 0x0000003C) != 0) {
        result = COMMON_ERR_FATAL_ERROR;
        goto fail;
    }
    
    /* Check status of internal sensors */
    mml_smon_readsecalm(&reg);
    if((reg & 0x3C000000) != 0) {
        result = COMMON_ERR_FATAL_ERROR;
        goto fail;
    }

fail:

    return result;
}

/*******************************************************************
*
* FUNCTION NAME: SelfTest
*
* PURPOSE: To execute self test
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       the error code (/include/errors.h)
*
*******************************************************************/
int SelfTest(void)
{
    int result = COMMON_ERR_UNKNOWN;

    lite_printf("==== Self Test ====\n");
    
    /* Application code validation */

    /* Removal sensors testing */

    /* Encryption engine validation (DES/AES) */
    result = TDESTest();
    if(result)        
        goto error;  

    result = DESTest();
    if(result)        
        goto error;     

    result = AESTest();
    if(result)        
        goto error; 
    
    /* RSA engine validation */
    result = RSATest();
    if(result)        
        goto error; 
    
    /* Tamper test and status */
    result = temperTest();
    if(result)
        goto error;

    /* Battery status */

    /* SHA Test */
    result = SHA256Test();
    if(result)        
        goto error;     

    /* RNG Test */
    result = TRNGTest();
    if(result)        
        goto error;    
    
    /* Device log */

error:
    lite_printf("\n");
    return result;
}

