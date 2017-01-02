/***********************************************************************
*
*
* FILE NAME: private.c
*
*
* PURPOSE: This is the implementation of HW configuration and common 
*          functions.
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
* Source : private.h
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
*
*
* DEVELOPMENT HISTORY:
* Date      Name         Change Release Description
*                        ID
* -------- ------------- ------ ------- --------------------------
* 04-22-16 Mark Chang              1    Initial code
* 05-11-16 Chiate Wang                  Add API, Config_rtc and Config_security
* 08-22-16 Chiate Wang                  Add API, Unlock_security
*
******************************************************************** */

/* Global includes */
#include <config.h>
#include <errors.h>

/* Other includes */
#include <cobra_defines.h>
#include <cobra_functions.h>
#include <mml.h>
#include <mml_gcr.h>
#include <mml_uart.h>
#include <mml_uart_regs.h>
#include <mml_gpio.h>
#include <mml_gpio_regs.h>
#include <mml_spi.h>
#include <mml_spi_regs.h>
#include <mml_tmr.h>
#include <mml_tmr_regs.h>
#include <mml_smon.h>
#include <mml_smon_regs.h>
#include <mml_trng.h>
#include <mml_scbr_regs.h>
#include <ucl/ecdsa_generic_api.h>
#include <ucl/ucl_retdefs.h>

/* Local includes */
#include <printf_lite.h>
#include <private.h>
#include <uart_config.h>
#include <portmacro.h>

/* FreeRTOS includes*/
#include <FreeRTOS.h>
#include "task.h"
#include "timers.h"
#include <nvsram.h>

/* Define Area */
#define SNVSRAM_SIGNATURE   0xDEADBEEF
//#define _LOCK_MECHANISM_

/*RTC*/
#define RTC_BASE 		0x40006000
#define RTC_RTCSEC		RTC_BASE + 0x0
#define RTC_RTCSSEC		RTC_BASE + 0x04
#define RTC_RTCCN		RTC_BASE + 0x10

/* Global Variable */
char signature_string[HEADER_SYNC_LEN+1];
unsigned char version_string[HEADER_VERSION_LEN];
unsigned char load_address_string[HEADER_LOAD_ADDRESS_LEN];
unsigned char binary_length_string[HEADER_BINARY_LEN];
unsigned char jump_address_string[HEADER_JUMP_ADDRESS_LEN];
unsigned char application_version_string[HEADER_APPLICATION_VERSION_LEN];
unsigned char arguments_string[HEADER_ARGV_LEN];

unsigned int image_length = 0;
unsigned int image_version = 0;
unsigned int image_load_address = 0;
unsigned int image_jump_address = 0;
unsigned int image_application_version = 0;
unsigned int image_arguments = 0;

static xTimerHandle xTouchTimeOutHandle;
static xTimerHandle xRebootTimeOutHandle;

/* Global Function */
void (* const bootloader_jumper)(void)      = (void (*)(void))(0x10060020 | 0x1);
void (* const mitac_test_app_jumper)(void)  = (void (*)(void))(0x10060020 | 0x1);
void (* const application_2_jumper)(void)   = (void (*)(void))(0x10060020 | 0x1);
void (* const application_3_jumper)(void)   = (void (*)(void))(0x100A0020 | 0x1);
void (* const application_4_jumper)(void)   = (void (*)(void))(0x100C0020 | 0x1);
void (* const application_5_jumper)(void)   = (void (*)(void))(0x100E0020 | 0x1);


/* External Function */


/* External Variable */
extern unsigned int __section_nvic_start;

/*******************************************************************
*
* FUNCTION NAME: Uart_write_char
*
* PURPOSE: Oupput character to UART FIFO register.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* in            const char      I  input character
*
* RETURN VALUE:
*       the error code (/include/errors.h)
*
*******************************************************************/
int Uart_write_char(const char c)
{
    return mml_uart_write_char(MML_UART_DEV1, c);
}

/*******************************************************************
*
* FUNCTION NAME: Init_interfaces
*
* PURPOSE: To reset periphery hardware interface.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE:
*
*******************************************************************/
void Init_interfaces(void)
{
    /* Main interfaces used by Secure ROM code, let's reset'em */
#ifndef _GPIO_RESET_AT_INIT_
    /* GPIOS */
    /* Reset all GPIOs' interface */
    volatile mml_gcr_regs_t *mml_gcr = (volatile mml_gcr_regs_t*)MML_GCR_IOBASE;
    mml_gcr->rstr |= MML_GCR_RSTR_GPIO_MASK;
    
    /* Wait for GPIOs reset to be done */
    while( MML_GCR_RSTR_GPIO_MASK & mml_gcr->rstr );
    /* No clock for GPIOs */
#endif // #ifndef _GPIO_RESET_AT_INIT_

#ifndef _UART_RESET_AT_INIT_
    /* UARTS */
    /* Reset all UARTs' interface */
    mml_gcr->rstr |= MML_GCR_RSTR_UARTS_MASK;
    /* Wait for UARTs reset to be done */
    while( MML_GCR_RSTR_UARTS_MASK & mml_gcr->rstr );
    
    /* Stop clock of each UART. It'll be set independently */
    mml_gcr->perckcn |= ( 1 << MML_PERCKCN_DEV_UART0 );
    mml_gcr->perckcn |= ( 1 << MML_PERCKCN_DEV_UART1 );
#endif // #ifndef _UART_RESET_AT_INIT_

#ifndef _TIMER_RESET_AT_INIT_
    /* TIMERS */
    /* Reset all TIMERs' interface */
    mml_gcr->rstr |= MML_GCR_RSTR_TIMERS_MASK;
    
    /* Wait for TIMERs reset to be done */
    while( MML_GCR_RSTR_TIMERS_MASK & mml_gcr->rstr );
    
    /* Stop clock of each Timer. It'll be set independently */
    mml_gcr->perckcn |= ( 1 << MML_PERCKCN_DEV_T0 );
    mml_gcr->perckcn |= ( 1 << MML_PERCKCN_DEV_T1 );
    mml_gcr->perckcn |= ( 1 << MML_PERCKCN_DEV_T2 );
    mml_gcr->perckcn |= ( 1 << MML_PERCKCN_DEV_T3 );
#endif // #ifndef _TIMER_RESET_AT_INIT_

	return;
}

/*******************************************************************
*
* FUNCTION NAME: Config_uart
*
* PURPOSE: To configure uart interface to n, 8, 1, 115200.
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
int Config_uart(void)
{
    mml_uart_config_t uart_conf;
    int result = COMMON_ERR_UNKNOWN;
    
    uart_conf.baudrate = K_LITE_UART0_DEFAULT_BAUDRATE;
    uart_conf.data_bits = MML_UART_DATA_TRANSFER_SIZE_8_BITS;
    uart_conf.flwctrl = MML_UART_HW_FLOW_CTL_DISABLE;
    uart_conf.parity = MML_UART_PARITY_NONE;
    uart_conf.parity_mode = MML_UART_PARITY_MODE_ONES;
    uart_conf.rts_ctl = MML_UART_RTS_IO_LEVEL_LOW;
    uart_conf.stop_bits = MML_UART_STOPBITS_ONE;
    uart_conf.handler = (mml_uart_handler_t)Config_uart;

    result = mml_uart_init(MML_UART_DEV0, uart_conf);
    if(result)
        return result;

    return  mml_uart_init(MML_UART_DEV1, uart_conf);
}

/*******************************************************************
*
* FUNCTION NAME: Config_gpio
*
* PURPOSE: To configure gpio setting.
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
int Config_gpio(void)
{
    int nRet = COMMON_ERR_UNKNOWN;  /* return value */
    mml_gpio_config_t config;
    
    /* Configure the gpio pin to output mode */
    config.gpio_direction = MML_GPIO_DIR_OUT;
    config.gpio_function = MML_GPIO_NORMAL_FUNCTION;
    config.gpio_intr_mode = 0;
    config.gpio_intr_polarity = 0;
    config.gpio_pad_config = MML_GPIO_PAD_NORMAL;
    
    /* Configure GPIO0_21 to output mode */
    nRet = mml_gpio_init(MML_GPIO_DEV0, MML_GPIO0_RED_LED_PIN, 1, config);
    if ( NO_ERROR == nRet ) {
        /* Set GPIO0_21 to output low level */
        nRet = mml_gpio_write_bit_pattern(MML_GPIO_DEV0, MML_GPIO0_RED_LED_PIN, 1, 0x01);
        if ( nRet ) {
            return nRet;
        }
    }
    else {
        return nRet;
    }
    
    /* Configure GPIO0_22 to output mode */
    nRet = mml_gpio_init(MML_GPIO_DEV0, MML_GPIO0_GREEN_LED_PIN, 1, config);
    if ( NO_ERROR == nRet ) {
        /* Set GPIO0_22 to output low level */
        nRet = mml_gpio_write_bit_pattern(MML_GPIO_DEV0, MML_GPIO0_GREEN_LED_PIN, 1, 0x01);
        if ( nRet ) {
            return nRet;
        }
    }
    else {
        return nRet;
    }
    
    return NO_ERROR;
}

/*******************************************************************
*
* FUNCTION NAME: Blink_led
*
* PURPOSE: To blink red led.
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
int Blink_led(void)
{
    int nRet = COMMON_ERR_UNKNOWN;  /* return value */
    
    // Delay
    vTaskDelay( 200 / portTICK_PERIOD_MS );
    
    // Off LED
    nRet = mml_gpio_write_bit_pattern(MML_GPIO_DEV0, MML_GPIO0_RED_LED_PIN, 1, 0x01);
    if ( NO_ERROR == nRet ) {
        // Delay
        vTaskDelay( 200 / portTICK_PERIOD_MS );
        
        // On LED
        nRet = mml_gpio_write_bit_pattern(MML_GPIO_DEV0, MML_GPIO0_RED_LED_PIN, 1, 0x00);
    }
    
    return nRet;
}

/*******************************************************************
*
* FUNCTION NAME: Image_ecdsa_verification
*
* PURPOSE: To verify image's ecdsa signature.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* nAppId        int             I  indicate ID of application
*
* RETURN VALUE: int
*       the error code (/include/ucl/ucl_retdefs.h)
*
*******************************************************************/
int Image_ecdsa_verification(int nAppId)
{
    int nRet = UCL_ERROR;   /* return value */
    unsigned int memory_addr = INTERNAL_FLASH_AP1;
    int ii;
    
    unsigned char a[]  = {0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, \
                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, \
                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC};
    unsigned char xg[] = {0x6B, 0x17, 0xD1, 0xF2, 0xE1, 0x2C, 0x42, 0x47, \
                          0xF8, 0xBC, 0xE6, 0xE5, 0x63, 0xA4, 0x40, 0xF2, \
                          0x77, 0x03, 0x7D, 0x81, 0x2D, 0xEB, 0x33, 0xA0, \
                          0xF4, 0xA1, 0x39, 0x45, 0xD8, 0x98, 0xC2, 0x96};
    unsigned char yg[] = {0x4F, 0xE3, 0x42, 0xE2, 0xFE, 0x1A, 0x7F, 0x9B, \
                          0x8E, 0xE7, 0xEB, 0x4A, 0x7C, 0x0F, 0x9E, 0x16, \
                          0x2B, 0xCE, 0x33, 0x57, 0x6B, 0x31, 0x5E, 0xCE, \
                          0xCB, 0xB6, 0x40, 0x68, 0x37, 0xBF, 0x51, 0xF5};
    unsigned char n[]  = {0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, \
                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, \
                          0xBC, 0xE6, 0xFA, 0xAD, 0xA7, 0x17, 0x9E, 0x84, \
                          0xF3, 0xB9, 0xCA, 0xC2, 0xFC, 0x63, 0x25, 0x51};
    unsigned char p[]  = {0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, \
                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                          0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, \
                          0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    
    /* MiTAC public key for internal applications verification */
    unsigned char xq3[] = {0x59, 0x15, 0x5f, 0xfe, 0x99, 0xf1, 0xbe, 0x21, \
                           0xee, 0x28, 0x40, 0xa9, 0xa8, 0x35, 0x01, 0xc0, \
                           0xab, 0xe7, 0x8a, 0x07, 0xd8, 0x7f, 0xe2, 0x51, \
                           0xa4, 0x01, 0x24, 0x14, 0xe4, 0xf4, 0xfd, 0x75};
    unsigned char yq3[] = {0x6b, 0x49, 0x2e, 0x40, 0x06, 0x0c, 0x7d, 0x03, \
                           0x43, 0xde, 0x20, 0x46, 0xda, 0xa2, 0x3c, 0x6c, \
                           0xa2, 0xce, 0x6e, 0xe3, 0xa7, 0x62, 0x0e, 0xd9, \
                           0xc4, 0x47, 0xbd, 0xac, 0xc9, 0x7f, 0x15, 0x05};
    
    /* Test ECDSA pattern */
    // =============================================================
    unsigned char msg3[] = {'a','b','c'};
    /* test public key */
    unsigned char xq3_test[] = {0x24, 0x42, 0xA5, 0xCC, 0x0E, 0xCD, 0x01, 0x5F,
                                0xA3, 0xCA, 0x31, 0xDC, 0x8E, 0x2B, 0xBC, 0x70,
                                0xBF, 0x42, 0xD6, 0x0C, 0xBC, 0xA2, 0x00, 0x85,
                                0xE0, 0x82, 0x2C, 0xB0, 0x42, 0x35, 0xE9, 0x70};
    unsigned char yq3_test[] = {0x6F, 0xC9, 0x8B, 0xD7, 0xE5, 0x02, 0x11, 0xA4,
                                0xA2, 0x71, 0x02, 0xFA, 0x35, 0x49, 0xDF, 0x79,
                                0xEB, 0xCB, 0x4B, 0xF2, 0x46, 0xB8, 0x09, 0x45,
                                0xCD, 0xDF, 0xE7, 0xD5, 0x09, 0xBB, 0xFD, 0x7D};
    /* test signature for the message above */
    unsigned char r3[] = {0xCB, 0x28, 0xE0, 0x99, 0x9B, 0x9C, 0x77, 0x15,
                          0xFD, 0x0A, 0x80, 0xD8, 0xE4, 0x7A, 0x77, 0x07,
                          0x97, 0x16, 0xCB, 0xBF, 0x91, 0x7D, 0xD7, 0x2E,
                          0x97, 0x56, 0x6E, 0xA1, 0xC0, 0x66, 0x95, 0x7C};
    unsigned char s3[] = {0x86, 0xFA, 0x3B, 0xB4, 0xE2, 0x6C, 0xAD, 0x5B,
                          0xF9, 0x0B, 0x7F, 0x81, 0x89, 0x92, 0x56, 0xCE,
                          0x75, 0x94, 0xBB, 0x1E, 0xA0, 0xC8, 0x92, 0x12,
                          0x74, 0x8B, 0xFF, 0x3B, 0x3D, 0x5B, 0x03, 0x15};
    // =============================================================
    
    DEBUG_PRINT(("Image_ecdsa_verification()+\n"));
    
    if ( (nAppId < 0) || (nAppId >= APP_END) ) {
        DEBUG_PRINT(("Image_ecdsa_verification(#1) - Unrecognized ApplicationID!!!(nAppId: %d)\n", nAppId));
        goto image_verify_out;
    }
    
    DEBUG_PRINT(("ECDSA-P256r1-SHA256 test pattern verification..."));
    nRet = ucl_ecdsa_verify_p256r1_sha256(32, xg, yg, xq3_test, yq3_test, r3, s3, a, n, p, msg3, sizeof(msg3));
    if ( nRet == UCL_OK ) {
        DEBUG_PRINT(("PASS\n"));
    }
    else {
        DEBUG_PRINT(("FAILED (%d) \n", nRet));
        goto image_verify_out;
    }
    
    nRet = UCL_ERROR;
    if (nAppId == MITAC_TEST_APP) {
        // Get signature from internal flash
        memory_addr = INTERNAL_FLASH_AP1;
        memcpy(signature_string, (unsigned char*)memory_addr, HEADER_SYNC_LEN);
        DEBUG_PRINT(("Image_ecdsa_verification() - signature_string: %s\n", signature_string));
        
        if ( strcmp(signature_string, "HISWEDGD") == 0 ) {
            // Get version from internal flash
            memory_addr = INTERNAL_FLASH_AP1 + HEADER_SYNC_LEN;
            memcpy(version_string, (unsigned char*)memory_addr, HEADER_VERSION_LEN);
            image_version = (unsigned int)(version_string[0] << 24) + (unsigned int)(version_string[1] << 16) + (unsigned int)(version_string[2] << 8) + (unsigned int)(version_string[3]);
            DEBUG_PRINT(("Image_ecdsa_verification() - image_version(0x%8x): 0x%08x\n", memory_addr, image_version));
            
            // Get load address from internal flash
            memory_addr = INTERNAL_FLASH_AP1 + HEADER_SYNC_LEN + HEADER_VERSION_LEN;
            memcpy(load_address_string, (unsigned char*)memory_addr, HEADER_LOAD_ADDRESS_LEN);
            image_load_address = (unsigned int)(load_address_string[0] << 24) + (unsigned int)(load_address_string[1] << 16) + (unsigned int)(load_address_string[2] << 8) + (unsigned int)(load_address_string[3]);
            DEBUG_PRINT(("Image_ecdsa_verification() - image_load_address(0x%8x): 0x%08x\n", memory_addr, image_load_address));
            
            // Get load address from internal flash
            memory_addr = INTERNAL_FLASH_AP1 + HEADER_SYNC_LEN + HEADER_VERSION_LEN + HEADER_LOAD_ADDRESS_LEN;
            memcpy(binary_length_string, (unsigned char*)memory_addr, HEADER_BINARY_LEN);
            image_length = (unsigned int)(binary_length_string[0] << 24) + (unsigned int)(binary_length_string[1] << 16) + (unsigned int)(binary_length_string[2] << 8) + (unsigned int)(binary_length_string[3]);
            DEBUG_PRINT(("Image_ecdsa_verification() - image_length(0x%8x): 0x%x(%d)\n", memory_addr, image_length, image_length));
            
            // Get jump address from internal flash
            memory_addr = INTERNAL_FLASH_AP1 + HEADER_SYNC_LEN + HEADER_VERSION_LEN + HEADER_LOAD_ADDRESS_LEN + HEADER_BINARY_LEN;
            memcpy(jump_address_string, (unsigned char*)memory_addr, HEADER_JUMP_ADDRESS_LEN);
            image_jump_address = (unsigned int)(jump_address_string[0] << 24) + (unsigned int)(jump_address_string[1] << 16) + (unsigned int)(jump_address_string[2] << 8) + (unsigned int)(jump_address_string[3]);
            DEBUG_PRINT(("Image_ecdsa_verification() - image_load_address(0x%8x): 0x%08x\n", memory_addr, image_jump_address));
            
            // Get application version from internal flash
            memory_addr = INTERNAL_FLASH_AP1 + HEADER_SYNC_LEN + HEADER_VERSION_LEN + HEADER_LOAD_ADDRESS_LEN + HEADER_BINARY_LEN + HEADER_JUMP_ADDRESS_LEN;
            memcpy(application_version_string, (unsigned char*)memory_addr, HEADER_APPLICATION_VERSION_LEN);
            image_application_version = (unsigned int)(application_version_string[0] << 24) + (unsigned int)(application_version_string[1] << 16) + (unsigned int)(application_version_string[2] << 8) + (unsigned int)(application_version_string[3]);
            DEBUG_PRINT(("Image_ecdsa_verification() - image_application_version(0x%8x): 0x%08x\n", memory_addr, image_application_version));
            
            // Get arguments from internal flash
            memory_addr = INTERNAL_FLASH_AP1 + HEADER_SYNC_LEN + HEADER_VERSION_LEN + HEADER_LOAD_ADDRESS_LEN + HEADER_BINARY_LEN + HEADER_JUMP_ADDRESS_LEN + HEADER_APPLICATION_VERSION_LEN;
            memcpy(arguments_string, (unsigned char*)memory_addr, HEADER_ARGV_LEN);
            image_arguments = (unsigned int)(arguments_string[0] << 24) + (unsigned int)(arguments_string[1] << 16) + (unsigned int)(arguments_string[2] << 8) + (unsigned int)(arguments_string[3]);
            DEBUG_PRINT(("Image_ecdsa_verification() - image_arguments(0x%8x): 0x%08x\n", memory_addr, image_arguments));
            
            // Get public key x and y.
            memory_addr = (INTERNAL_FLASH_AP1 + 32 + image_length);
            DEBUG_PRINT(("Image_ecdsa_verification() - r3 memory_addr: 0x%x\n", memory_addr));
            for( ii=0; ii<ECDSA_MODULUS_LEN; ii++ ) {
                r3[ii] = *(unsigned char*)(memory_addr+ii);
            }
            
            memory_addr = (INTERNAL_FLASH_AP1 + 32 + image_length + ECDSA_MODULUS_LEN);
            DEBUG_PRINT(("Image_ecdsa_verification() - s3 memory_addr: 0x%x\n", memory_addr));
            for ( ii=0; ii<ECDSA_MODULUS_LEN; ii++) {
                s3[ii] = *(unsigned char*)(memory_addr+ii);
            }
            
            DEBUG_PRINT(("\nr3:"));
            for ( ii=0 ; ii<ECDSA_MODULUS_LEN ; ii++ ) {
                DEBUG_PRINT(("%02x", r3[ii]));
            }
            
            DEBUG_PRINT(("\ns3:"));
            for ( ii=0 ; ii<ECDSA_MODULUS_LEN ; ii++ ) {
                DEBUG_PRINT(("%02x", s3[ii]));
            }
            DEBUG_PRINT(("\n\n"));
            
            DEBUG_PRINT(("ECDSA-P256r1-SHA256 singature verification..."));
            nRet = ucl_ecdsa_verify_p256r1_sha256(32, xg, yg, xq3, yq3, r3, s3, a, n, p, (unsigned char*)INTERNAL_FLASH_AP1, image_length + 32);
            if ( nRet == UCL_OK ) {
                DEBUG_PRINT(("PASS\n"));
            }
            else {
                DEBUG_PRINT(("FAILED (%d) \n", nRet));
            }
        }
        else {
            DEBUG_PRINT(("Image_ecdsa_verification() - Verifying image signature falied.\n"));
            nRet = COMMON_ERR_NO_MATCH;
        }
    }
    else {
        DEBUG_PRINT(("Image_ecdsa_verification(#2) - Unrecognized ApplicationID!!!(nAppId: %d)\n", nAppId));
        nRet = COMMON_ERR_NO_MATCH;
    }

image_verify_out:
    DEBUG_PRINT(("Image_ecdsa_verification()-\n"));
    
    return nRet;
}

/*******************************************************************
*
* FUNCTION NAME: Application_jump
*
* PURPOSE: To jump PC register to the specific address of application image.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* nAppId        int             I  indicate ID of application
*
* RETURN VALUE: int
*       the error code (/include/errors.h)
*
*******************************************************************/
int Application_jump(int nAppId)
{
    int result = COMMON_ERR_UNKNOWN;    /* return value */
    
    if ( nAppId == BOOTLOADER ) {   /* Bootloader image is at 0x10000020 */
        DEBUG_PRINT(("Jump to Bootloader image.\n"));
        vTaskEndScheduler();    /* Stop task scheduling */
        bootloader_jumper();    /* jump to bootloader image application */
        while(1);
    }
    else if (nAppId == MITAC_TEST_APP) {    /* MiTAC demo image is at 0x10060020 */
        DEBUG_PRINT(("Jump to MiTAC test application image.\n"));
        vTaskEndScheduler();    /* Stop task scheduling*/
        mitac_test_app_jumper();/* jump to mitac test application */
        while(1);
    }
    else {
        DEBUG_PRINT(("Cannot recognize this application ID.(%d)\n", nAppId));
        result = COMMON_ERR_OUT_OF_RANGE;
    }
    
    return result;
}

/*******************************************************************
*
* FUNCTION NAME: Config_timer
*
* PURPOSE: To configure timer setting.
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
int Config_timer(void)
{
    int nRet = COMMON_ERR_UNKNOWN;  /* return value */
    
    // Clear interruption
    mml_tmr_interrupt_clear(MML_TMR_DEV0);
    
    // Disable timer
    nRet = mml_tmr_disable(MML_TMR_DEV0);
    
    return nRet;
}

/*******************************************************************
*
* FUNCTION NAME: waitRtcBusy
*
* PURPOSE: To wait for the RTC counter register update finish.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: None
*
*******************************************************************/
void waitRtcBusy(void)
{
    unsigned int value = 0;

	/** Wait for the busy flag */
	IO_READ_U32(RTC_RTCCN, value);
	while( ((value>>3) & 0x1) == 1)
		IO_READ_U32(RTC_RTCCN, value);
}

/*******************************************************************
*
* FUNCTION NAME: Config_rtc
*
* PURPOSE: To configure rtc setting.
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
int Config_rtc(void)
{
    unsigned int value = 0;

    waitRtcBusy();    
	/** read RTC control register */
	IO_READ_U32(RTC_RTCCN, value);

    if ((value & 0x00000001) == 0) {

        waitRtcBusy();
    	/** define second value */
    	IO_WRITE_U32(RTC_RTCSEC, 0x00000000);

        waitRtcBusy();
    	/** define sub-second value */
    	IO_WRITE_U32(RTC_RTCSSEC, 0x00000000);

        waitRtcBusy();
    	/** set RTC ctrl write enable */
    	IO_WRITE_U32(RTC_RTCCN, 0x8000);

        waitRtcBusy();
    	/** set RTC control register (quiet mode) */
    	IO_WRITE_U32(RTC_RTCCN, 0xC801);

        DEBUG_PRINT(("RTC Enabled!\n"));
    }

	/** poll on RTC ready bit */
	IO_READ_U32(RTC_RTCCN, value);
	while( ((value>>4) & 0x1) == 0)
		IO_READ_U32(RTC_RTCCN, value);
    IO_READ_U32(RTC_RTCSEC, value);
    DEBUG_PRINT(("RTC Second Counter Register Value: 0x%x\n", value));

    return NO_ERROR;
}

/*******************************************************************
*
* FUNCTION NAME: gecko_default_nmi_
*
* PURPOSE: To handle NMI exception
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: none
*
*******************************************************************/
__attribute__((section(".text.init"))) void gecko_default_nmi_(void)
{
    register unsigned int i;
    volatile unsigned int *p_scbr = (volatile unsigned int*)SCB_BASE;

    /**  */
    DEBUG_PRINT(("\n\t[EXCEPTION] [SYSTEM CONTROL BLOCK]\n\n"));
    for( i = 0;i < ( sizeof(mml_scbr_regs_t) / sizeof(unsigned int) );i++ )
    {
        /**  */
        DEBUG_PRINT(("\t\t@ 0x%08x = 0x%08x\n", &p_scbr[i], p_scbr[i]));
    }

    DEBUG_PRINT(("System reboot!!!\n"));

    /** Now reset platform */
    mml_reset_system();

    /** We're done */
    return;
}

/*******************************************************************
*
* FUNCTION NAME: Config_security
*
* PURPOSE: To configure security monitor sensors.
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
int Config_security(void)
{
    unsigned int value = 0;
    volatile unsigned int *p_my_rom_vectors  = 
                                 (volatile unsigned int*)&__section_nvic_start;

    /** Copy the reset vectors from ROM to SRAM. */
    p_my_rom_vectors[2] = (volatile unsigned int)gecko_default_nmi_;

#ifdef _LOCK_MECHANISM_
    /* Check if any DRS triggered/triggering */
    mml_smon_readsecalm(&value);
    if ((value & MML_SMON_SECALM_EXSTAT_MASK) ||
        (value & MML_SMON_SECALM_EXTSWARN_MASK) ||
        (value & MML_SMON_SECALM_SHIELDF_MASK) ||
        (value & MML_SMON_SECALM_LOTEMP_MASK) ||
        (value & MML_SMON_SECALM_HITEMP_MASK) ||
        (value & MML_SMON_SECALM_BATLO_MASK) ||
        (value & MML_SMON_SECALM_BATHI_MASK) ||
        (NvsramSignatureRead() != SNVSRAM_SIGNATURE)) {

        DEBUG_PRINT(("The Destructive Reset Source triggered: 0x%x\n", value));

        /* Clear NVSRAM */
        NvsramEraseAll();
        
        return COMMON_ERR_FATAL_ERROR;
    }
#else
    Unlock_Security();
#endif

    /* Check if any DRS triggered BEFORE */
    mml_smon_readsecdiag(&value);
    if (value & 0x000000FC) {
        DEBUG_PRINT(("The Destructive Reset Source triggered BEFORE!!!\n"));
        
        DEBUG_PRINT(("Security Diagnostic Register: 0x%x\n", value));
        mml_smon_readdlrtc(&value);
        DEBUG_PRINT(("DRS Log RTC Value: 0x%x\n", value));
    }

    /* Clear internal security sensor alarm state */
    mml_smon_clearsecalm(MML_SMON_SECALM_SHIELDF_MASK |
                         MML_SMON_SECALM_LOTEMP_MASK | 
                         MML_SMON_SECALM_HITEMP_MASK |
                         MML_SMON_SECALM_BATLO_MASK | 
                         MML_SMON_SECALM_BATHI_MASK);

    /* Enable internal and external security sensors */
    mml_Enable_Shield_sensor();
    mml_Enable_Temp_sensor();
    mml_Enable_Vbat_sensor();
    mml_lock_internel_sensor_control();
    mml_External_Sensor_Config();
    
    return NO_ERROR;
}

/*******************************************************************
*
* FUNCTION NAME: Unlock_Security
*
* PURPOSE: To unlock security monitor sensors.
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
int Unlock_Security(void)
{
    /* Clear internal security sensor alarm state */
    mml_smon_clearsecalm(MML_SMON_SECALM_SHIELDF_MASK |
                         MML_SMON_SECALM_LOTEMP_MASK | 
                         MML_SMON_SECALM_HITEMP_MASK |
                         MML_SMON_SECALM_BATLO_MASK | 
                         MML_SMON_SECALM_BATHI_MASK);

    /* Clear external security sensor alarm state */
    mml_smon_clearsecalm(MML_SMON_SECALM_EXTSWARN_MASK |
                         MML_SMON_SECALM_EXSTAT_MASK | 
                         MML_SMON_SECALM_EXTF_MASK);

    /* Check if NVSRAM wiped */
    if(NvsramSignatureRead() != SNVSRAM_SIGNATURE) {
        
        DEBUG_PRINT(("AES Key for NVSRAM had been wiped !!!\n"));
        
        mml_trng_AES_keygen();

        /* Clear NVSRAM */
        NvsramEraseAll();
        
        NvsramSignatureWrite(SNVSRAM_SIGNATURE);
    }

    return NO_ERROR;
}

/*******************************************************************
*
* FUNCTION NAME: TimeoutFuncAdd
*
* PURPOSE: Setup a timer to trigger a callback function
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* nDriverID     int             I  Driver ID
* Func          void*           I  Callback function
* delay_ms      int             I  Delay time in ms
*
* RETURN VALUE: none
*
*******************************************************************/
void TimeoutFuncAdd(int nDriverID, void *Func, unsigned int delay_ms)
{
    if ( nDriverID == REBOOT_DRIVER ) {
        xRebootTimeOutHandle = xTimerCreate( (const signed char * const)"RebootTimeOut",
                                             ((delay_ms+100)/portTICK_PERIOD_MS),
                                             pdFALSE, 
                                             (void *)0,
                                             Func);
        
        if ( xRebootTimeOutHandle != NULL ) {
            xTimerStart(xRebootTimeOutHandle, 0);
        }
        else {
            DEBUG_PRINT(("TimeoutFuncAdd() - TimerHandle is a NULL pointer. (nDriverID:%d)\n", nDriverID));
        }
    }
    else if ( nDriverID == TOUCH_DRIVER ) {
        xTouchTimeOutHandle = xTimerCreate( (const signed char * const)"TouchDriver", 
                                            ((delay_ms+100)/portTICK_PERIOD_MS),
                                            pdFALSE, 
                                            (void *)0,
                                            Func);
        
        if ( xTouchTimeOutHandle != NULL ) {
            xTimerStart(xTouchTimeOutHandle, 0);
        }
        else {
            DEBUG_PRINT(("TimeoutFuncAdd() - TimerHandle is a NULL pointer. (nDriverID:%d)\n", nDriverID));
        }
    }
}

/*******************************************************************
*
* FUNCTION NAME: TimeoutFuncDel
*
* PURPOSE: Delete this timer
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* nDriverID     int             I  Driver ID
*
* RETURN VALUE: none
*
*******************************************************************/
void TimeoutFuncDel(int nDriverID)
{
    if ( nDriverID == REBOOT_DRIVER ) {
        if ( xRebootTimeOutHandle != NULL ) {
            xTimerStop(xRebootTimeOutHandle, 0);
            xTimerDelete(xRebootTimeOutHandle, 0);
        }
        else {
            DEBUG_PRINT(("TimeoutFuncDel() - TimerHandle is a NULL pointer. (nDriverID:%d)\n", nDriverID));
        }
    }
    else if ( nDriverID == TOUCH_DRIVER ) {
        if ( xTouchTimeOutHandle != NULL ) {
            xTimerStop(xTouchTimeOutHandle, 0);
            xTimerDelete(xTouchTimeOutHandle, 0);
        }
        else {
            DEBUG_PRINT(("TimeoutFuncDel() - TimerHandle is a NULL pointer. (nDriverID:%d)\n", nDriverID));
        }
    }
    else {
        DEBUG_PRINT(("TimeoutFuncDel() - Cannot recognize this driver ID. (nDriverID:%d)\n", nDriverID));
    }
}

/******************************************************************************/
/* EOF */
