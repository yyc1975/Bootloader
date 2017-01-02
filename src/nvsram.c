/********************************************************************
*
*
* FILE NAME: nvsram.c
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
* 04-27-16 Chiate.Wang             1    Initial code
* 06-01-16 Chiate.Wang                  Add API, MemTest().
* 06-13-16 Chiate.Wang                  Move API, MemTest() and internalMemTest() to test_api.c.
*
******************************************************************** */

/* Global includes */
#include <errors.h>

/* Other includes */
#include <cobra_functions.h>

/* Local includes */
#include <nvsram.h>
#include <printf_lite.h>

/* Define Area */
#define SNVSRAM_ALIGNMENT               ( 4 )
#define SNVSRAM_ALIGNMENT_MASK          ( 0x0003 )
#define SNVSRAM_TAG_MAX_LEN             ( 10 )
#define SNVSRAM_USAGE_MAX_RECORD        ( 20 )

typedef struct nvsramUsageRecord
{
    unsigned int    startAddr;
    size_t          len;
    signed char		tagName[ SNVSRAM_TAG_MAX_LEN ];
} nvsUR;

/* Global Variable */
static unsigned int ucNextFreeAddr = SNVSRAM_DYNAMIC_START_ADDRESS;
static unsigned int nvsramIndex = 0;
static nvsUR nvsramRecord[SNVSRAM_USAGE_MAX_RECORD];
static nvsUR staticRecord[] = {
  {
    SNVSRAM_KS_START_ADDRESS,
    SNVSRAM_KS_USAGE_LEN,
    "KS"
  },
  {
    SNVSRAM_SIGNATURE_START_ADDRESS,
    SNVSRAM_SIGNATURE_LEN,
    "Signature"
  }
};

static unsigned int processing = FALSE;

/* Global Function */


/* External Function */


/* External Variable */


/*******************************************************************
*
* FUNCTION NAME: NvsramSignatureRead
*
* PURPOSE: To read 4-bytes signature from NVSRAM signature address.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: unsigned int
*       the 4-bytes signature data
*
*******************************************************************/
unsigned int NvsramSignatureRead(void)
{
    unsigned int signature = 0;

    IO_READ_U32(SNVSRAM_SIGNATURE_START_ADDRESS, signature);
    
    return signature;
}

/*******************************************************************
*
* FUNCTION NAME: NvsramSignatureWrite
*
* PURPOSE: To write 4-bytes signature into NVSRAM signature address.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* signature     unsigned int    I  input signature
*
* RETURN VALUE: none
*
*******************************************************************/
void NvsramSignatureWrite(unsigned int signature)
{
    IO_WRITE_U32(SNVSRAM_SIGNATURE_START_ADDRESS, signature);
}

/*******************************************************************
*
* FUNCTION NAME: NvsramEraseAll
*
* PURPOSE: To write 4-bytes signature into NVSRAM signature address.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: none
*
*******************************************************************/
void NvsramEraseAll(void)
{
    unsigned char *addr = (unsigned char *)MML_MEM_SNVSRAM_BASE;

    memset(addr, 0, MML_MEM_SNVSRAM_SIZE);
}

/*******************************************************************
*
* FUNCTION NAME: SecureMemAlloc
*
* PURPOSE: To provide a NVSRAM area pointer base on length.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* tag            signed char *   I request program tag
* len            size_t          I request NVSRAM length
*
* RETURN VALUE: void*
*       the void memory pointer to NVSRAM
*
*******************************************************************/
void *SecureMemAlloc(const signed char * const tag, size_t len)
{
    unsigned int pAddr = 0;
    unsigned int i = 0;
    nvsUR *record = NULL;

    if(processing)
        return NULL;
    else
        processing = TRUE;

    if((len > 0) && ((ucNextFreeAddr + len) < SNVSRAM_SIGNATURE_START_ADDRESS)) {

        if( ( len & SNVSRAM_ALIGNMENT_MASK ) != 0x00 )
        {
            /* Byte alignment required. */
            len += (SNVSRAM_ALIGNMENT - (len & SNVSRAM_ALIGNMENT_MASK));
        }

        if(nvsramIndex < SNVSRAM_TAG_MAX_LEN) {
            
            record = &nvsramRecord[nvsramIndex];
            if(record != NULL) {
                record->startAddr = ucNextFreeAddr;
                record->len = len;

            	for( i=0; i<SNVSRAM_TAG_MAX_LEN ; i++ )
            	{
            		record->tagName[ i ] = tag[ i ];

            		if( tag[ i ] == 0x00 )
            		{
            			break;
            		}
            	}
                nvsramIndex++;
            }
        }

        pAddr = ucNextFreeAddr;
        ucNextFreeAddr += len;
    }

    processing = FALSE;

    return (void *)pAddr;
}

/*******************************************************************
*
* FUNCTION NAME: GetSecureMemFreeSize
*
* PURPOSE: To get free NVSRAM memory size.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: size_t
*       the free NVSRAM size
*
*******************************************************************/
size_t GetSecureMemFreeSize(void)
{
    size_t freesize = 0;

    freesize = SNVSRAM_SIGNATURE_START_ADDRESS - ucNextFreeAddr;

    return freesize;
}

/*******************************************************************
*
* FUNCTION NAME: GetSecureMemUsage
*
* PURPOSE: To report NVSRAM memory usage.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: none
*
*******************************************************************/
void GetSecureMemUsage(void)
{
    unsigned int i = 0;
    
    lite_printf("NVSRAM (0x20080000 ~ 0x20081FFF)\n");
    lite_printf("Start        Length(bytes)   TAG\n");
    lite_printf("-------------------------------------\n");

    for(i=0; i<(sizeof(staticRecord)/sizeof(staticRecord[0])); i++) {
        lite_printf("0x%x     %4d          %s\n", staticRecord[i].startAddr,
                   staticRecord[i].len, staticRecord[i].tagName);
    }
    
    lite_printf("0x%x     %4d          Dynamic\n", SNVSRAM_DYNAMIC_START_ADDRESS,
               SNVSRAM_DYNAMIC_USAGE_LEN);

    for(i=0; i<nvsramIndex; i++) {
        lite_printf("  0x%x   %4d          %s\n", nvsramRecord[i].startAddr,
                  nvsramRecord[i].len, nvsramRecord[i].tagName);
    }

    lite_printf("-------------------------------------\n");
}

