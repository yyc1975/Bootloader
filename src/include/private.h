/***********************************************************************
 *
 * FILE NAME: private.h
 *
 *
 * PURPOSE: Defines all reference variables and functions.
 *
 *
 * GLOBAL VARIABLES:
 *
 *
 * Variables     Type     Description
 * ------------- -------- ---------------------------
 * none
 *
 * DEVELOPMENT HISTORY:
 *
 * Date     Author       Change ID Release Description of Change
 * -------- ------------ --------- ------- ------------------------------
 * 04-22-16 Mark Chang                1    Initial Code
 *
 ***********************************************************************/

#ifndef _PRIVATE_H_
#define _PRIVATE_H_

/* Global includes */
#include <config.h>


/* Other includes */
#include <mml.h>


/* Local includes */


/* Define Area */
#ifdef DEBUG
#define DEBUG_PRINT_LINE(x) lite_printf("%s, %d ", __FILE__, __LINE__); lite_printf x
#define DEBUG_PRINT(x) lite_printf x
#else
#define DEBUG_PRINT_LINE(x) do {} while (0)
#define DEBUG_PRINT(x) do {} while (0)
#endif

#define INTERNAL_FLASH_BL               0x10000000
#define INTERNAL_FLASH_HW               0x10020000
#define INTERNAL_FLASH_AP1              0x10060000
#define INTERNAL_FLASH_AP2              0x10080000
#define INTERNAL_FLASH_AP3              0x100A0000
#define INTERNAL_FLASH_AP4              0x100C0000
#define INTERNAL_FLASH_AP5              0x100E0000

#define HEADER_SYNC_LEN                 8
#define HEADER_VERSION_LEN              4
#define HEADER_APPLICATION_VERSION_LEN  4
#define HEADER_LOAD_ADDRESS_LEN         4
#define HEADER_JUMP_ADDRESS_LEN         4
#define HEADER_BINARY_LEN               4
#define HEADER_ARGV_LEN                 4

#define ECDSA_MODULUS_LEN               32

#define	K_UCL_USECASE_BUFFER_SIZE_INT   2048

#define	MML_GPIO0_RED_LED_PIN           21
#define	MML_GPIO0_GREEN_LED_PIN         22

enum ApplicationID {
    BOOTLOADER = 0,
    MITAC_TEST_APP,
    APP_END,
};

enum DriverID {
    REBOOT_DRIVER = 0,
    TOUCH_DRIVER = 1,
    END_DRIVER,
};

/******************************************************************************/
void Init_interfaces(void);
int Uart_write_char(const char c);
int Config_uart(void);
int Config_gpio(void);
int Config_timer(void);
int Config_rtc(void);
int Config_security(void);
int Unlock_Security(void);

int Blink_led(void);
int Application_jump(int nAppId);
int Image_ecdsa_verification(int nAppId);

void TimeoutFuncAdd(int nDriverID, void *Func, unsigned int delay_ms);
void TimeoutFuncDel(int nDriverID);
#endif /* _PRIVATE_H_ */

/******************************************************************************/
/* EOF */
