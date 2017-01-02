/********************************************************************
*
*
* FILE NAME: crypto_tests.c
*
*
* PURPOSE: This is the implementation of NVSRAM functions.
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
* 06-15-16 YY. Chen                  1    Initial Code
*
******************************************************************** */

/* Global includes */
#include <errors.h>
#include <defs.h>
#include <ucl/ucl_rng.h>
#include <ucl/ucl_stest.h>

/* Local includes */
#include <crypto_tests.h>
#include <printf_lite.h>

/*******************************************************************
*
* FUNCTION NAME: TRNGTest
*
* PURPOSE: To do the True Random Number Generator Tests
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       Test resut: NO_ERROR & COMMON_ERR_FATAL_ERROR
*
*******************************************************************/
int TRNGTest(void)
{
    int result = UCL_OK;

    unsigned char buf[2500];
    int i, j, k, s, sign, nsign, err = 0;
    unsigned long n1;
    unsigned long n2[16];
    unsigned long runs[2][34];
    int byteLen = 2500;
    /*
     * double d;
     */
    long d;

    int status;
    if((status = ucl_rng_read(buf, byteLen, UCL_RAND_DEFAULT)) != byteLen) {
        err++;
        goto err;        
    }

    n1 = 0;
    for (i = 0; i < 16; i++)
        n2[i] = 0;
    for (i = 0; i < 34; i++)
        runs[0][i] = runs[1][i] = 0;

    /* test 1 and 2 */
    sign = 0;
    nsign = 0;
    for (i = 0; i < 2500; i++) {
        j = buf[i];

        n2[j & 0x0f]++;
        n2[(j >> 4) & 0x0f]++;

        for (k = 0; k < 8; k++) {
            s = (j & 0x01);
            if (s == sign)
                nsign++;
            else {
                if (nsign > 34)
                    nsign = 34;
                if (nsign != 0) {
                    runs[sign][nsign - 1]++;
                    if (nsign > 6)
                        runs[sign][5]++;
                }
                sign = s;
                nsign = 1;
            }

            if (s)
                n1++;
            j >>= 1;
        }
    }
    if (nsign > 34)
        nsign = 34;
    if (nsign != 0)
        runs[sign][nsign - 1]++;

    /* test 1 */
    if (!((9654 < n1) && (n1 < 10346))) {
        err++;
    }

    /* test 2 */
#ifdef undef
    d = 0;
    for (i = 0; i < 16; i++)
        d += n2[i] * n2[i];
    d = d * 16.0 / 5000.0 - 5000.0;
    if (!((1.03 < d) && (d < 57.4))) {
        err++;
    }
#endif
    d = 0;
    for (i = 0; i < 16; i++)
        d += n2[i] * n2[i];
    d = (d * 8) / 25 - 500000;
    if (!((103 < d) && (d < 5740))) {
        err++;
    }

    /* test 3 */
    for (i = 0; i < 2; i++) {
        if (!((2267 < runs[i][0]) && (runs[i][0] < 2733))) {
            err++;
        }
        if (!((1079 < runs[i][1]) && (runs[i][1] < 1421))) {
            err++;
        }
        if (!((502 < runs[i][2]) && (runs[i][2] < 748))) {
            err++;
        }
        if (!((223 < runs[i][3]) && (runs[i][3] < 402))) {
            err++;
        }
        if (!((90 < runs[i][4]) && (runs[i][4] < 223))) {
            err++;
        }
        if (!((90 < runs[i][5]) && (runs[i][5] < 223))) {
            err++;
        }
    }

    /* test 4 */
    if (runs[0][33] != 0) {
        err++;
    }
    if (runs[1][33] != 0) {
        err++;
    }

 err:
    result = ((err == 0) ? UCL_OK: UCL_ERROR);

    if(result == UCL_OK)
        lite_printf("O");
    else
        lite_printf("X");
    
    return result;
}


/*******************************************************************
*
* FUNCTION NAME: SHA256Test
*
* PURPOSE: To do the SHA256 Tests
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       Test resut: NO_ERROR & COMMON_ERR_FATAL_ERROR
*
*******************************************************************/
int SHA256Test(void) 
{
    int result;

    result = ucl_hash_sha256_stest();

    if(result == UCL_OK)
        lite_printf("O");
    else
        lite_printf("X");    

    return result;   
}

/*******************************************************************
*
* FUNCTION NAME: TDESTest
*
* PURPOSE: To do the TDES Tests
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       Test resut: NO_ERROR & COMMON_ERR_FATAL_ERROR
*
*******************************************************************/
int TDESTest(void) 
{
    int result;
    
    result = ucl_cipher_3des_stest();

    if(result == UCL_OK)
        lite_printf("O");
    else
        lite_printf("X");

    return result;  
}

/*******************************************************************
*
* FUNCTION NAME: DESTest
*
* PURPOSE: To do the DES Tests
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       Test resut: NO_ERROR & COMMON_ERR_FATAL_ERROR
*
*******************************************************************/
int DESTest(void) 
{
    int result;
    
    result = ucl_cipher_des_stest();

    if(result == UCL_OK)
        lite_printf("O");
    else
        lite_printf("X");

    return result;  
}

/*******************************************************************
*
* FUNCTION NAME: AESTest
*
* PURPOSE: To do the AES Tests
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       Test resut: NO_ERROR & COMMON_ERR_FATAL_ERROR
*
*******************************************************************/
int AESTest(void) 
{
    int result;

    result = ucl_cipher_aes_stest();

    if(result == UCL_OK)
        lite_printf("O");
    else
        lite_printf("X");

    return result;  
}

/*******************************************************************
*
* FUNCTION NAME: RSATest
*
* PURPOSE: To do the RSA Tests
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       Test resut: NO_ERROR & COMMON_ERR_FATAL_ERROR
*
*******************************************************************/
int RSATest(void) 
{
    int result;

    result = ucl_pkc_rsa_stest();

    if(result == UCL_OK)
        lite_printf("O");
    else
        lite_printf("X");

    return result;  
}
