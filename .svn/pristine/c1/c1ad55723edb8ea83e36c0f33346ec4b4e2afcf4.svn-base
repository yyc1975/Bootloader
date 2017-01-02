/*
 * main.c --
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2014, Maxim Integrated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Maxim Integrated nor the
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
 * Created on: Feb 14, 2014
 * Author: Stephane Di Vito (stephane.divito@maximintegrated.com)
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: $: Revision of last commit
 * $Author:: $: Author of last commit
 * $Date:: $: Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

/* Global includes */
#include <config.h>
#include <errors.h>
#include <string.h>

/* Other includes */
#include <cobra_defines.h>
#include <mml_nvic_regs.h>
#include <mml_gcr_regs.h>
#include <mml_gcr.h>
#include <mml_gpio.h>
#include <mml_tmr_regs.h>
#include <mml_tmr.h>
#include <mml_uart_regs.h>
#include <mml_uart.h>
#include <mml_mcr.h>
#include "ucl/ucl_types.h"
#include <ucl/ucl_sys.h>

/* Local includes */
#include <uart_config.h>
#include <printf_lite.h>
#include <private.h>
#include "cmdtransceiver.h"

/* FreeRTOS includes*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "selftest.h"

/* Define Area */


/* Global Variable */
unsigned int init_buffer[K_UCL_USECASE_BUFFER_SIZE_INT];
static int giSysLock = pdFALSE;


/* Global Function */
static void prvSetupHardware( void );
static void vJumpTask( void *pvParameter );
static void vBLCommandTask( void *pvParameter );  /* Bootloader command task */


/* External Function */


/* External Variable */


/*******************************************************************
*
* FUNCTION NAME: main
*
* PURPOSE: 
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* none
*
* RETURN VALUE: int
*       the error code (/include/errors.h)
*
*******************************************************************/
int main( void )
{
    int err;
    
    /* Configure the clocks, UART and GPIO. */
    prvSetupHardware();
    
    DEBUG_PRINT(("\n=============================================\n"));
    DEBUG_PRINT(("=== MiTAC Bootloader FreeRTOS Application ===\n"));
    DEBUG_PRINT(("=============================================\n"));

    if (giSysLock == pdFALSE) {    
        /* Initial ucl buffer. */
        err = ucl_init(init_buffer, K_UCL_USECASE_BUFFER_SIZE_INT);
        if ( err ) {
            DEBUG_PRINT(("Cannot initial ucl library!!!\n"));
            while(1);
        }

        /* Execute self test. */
        err = SelfTest();
        if ( err ) {
            DEBUG_PRINT(("Self Test Fail!!!\n"));
            //while(1);
        } else {
            DEBUG_PRINT(("Self Test Success!!!\n"));
        }

        /* Verifying image's ecdsa signature. */
        err = Image_ecdsa_verification(MITAC_TEST_APP);
        if ( err ) {
            DEBUG_PRINT(("Verifying MITAC_TEST_APP image failed\n"));
            while(1);
        }
        
        /* Create a task to jump application. */
        err = xTaskCreate( vJumpTask, (signed char*)"JUMP", 100, NULL, 4, NULL );
        if ( err != pdPASS ) {
            while(1);
        }
    } else {
        err = CreateTransceiverTask();
        if ( err != pdPASS ) {
            DEBUG_PRINT(("CreateTransceiverTask failed\n"));
            while(1);
        } else {
            err = xTaskCreate( vBLCommandTask, (signed char*)"BootloaderCommand", 500, NULL, 2, NULL );
            if ( err != pdPASS ) {
                DEBUG_PRINT(("Create Bootloader command task failed\n"));
                while(1);
            }
        }
    }
    
    /* Start the scheduler. */
    vTaskStartScheduler();
    
    /* Will only get here if there was insufficient heap to start the scheduler. */
    return 0;
}

/*******************************************************************
*
* FUNCTION NAME: vBLCommandTask
*
* PURPOSE: Parse/handle bootloader command
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* none
*
* RETURN VALUE:
*
*******************************************************************/
static void vBLCommandTask( void *pvParameters )
{
    /* Remove compiler warning about unused parameter. */
    (void) pvParameters;
    unsigned char buff[CMD_PORT_BUF_LEN];
    unsigned int len = 0;
    cmd_start_t start = STX;
    cmd_end_t end = ETX;
    int result = COMMON_ERR_UNKNOWN;

    while(1){
        if(ReceiveMessage(OUTER, buff, CMD_PORT_BUF_LEN, &len, BLOCK, &start, &end)) {
            if((start == STX) && (!memcmp(buff, "OPENSESAME", 10)) && (end == ETX)) {

                /* Clear security sensor alarm */
                Unlock_Security();
                
                /* Debounce */
                vTaskDelay( 3000 / portTICK_PERIOD_MS );

                /* Initialize security monitor with default configurations */
                result = Config_security();
                if ( result ) {
                    giSysLock = pdTRUE;
                } else {
                    giSysLock = pdFALSE;

                    SendMessage(BOOT, (unsigned char *)"OK", 2);
                    vTaskDelay( 1000 / portTICK_PERIOD_MS );

                    DEBUG_PRINT(("System unlocked. Reboot!!!\n"));
                    
                    /** Now reset platform */
                    mml_reset_system();
                }
            }
            SendMessage(BOOT, (unsigned char *)"FAIL", 4);
        }
        
        vTaskDelay( 100 / portTICK_PERIOD_MS );
    }
}

/*******************************************************************
*
* FUNCTION NAME: prvSetupHardware
*
* PURPOSE: Configure system and peripferal settings
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* none
*
* RETURN VALUE: int
*       the error code (/include/errors.h)
*
*******************************************************************/
static void prvSetupHardware( void )
{
    int result = COMMON_ERR_UNKNOWN;
    
    /* Set the system frequency */
    result = mml_set_system_frequency(MML_GCR_SYSFREQ_108MHZ);
    if ( result ) {
        goto main_out;
    }
    
    /* Reset interfaces */
    Init_interfaces();
    
    /* Configure LED GPIO settings. */
    result = Config_gpio();
    if ( result ) {
        goto main_out;
    }
    
    /* Initialize UART0 port with default configurations */
    result = Config_uart();
    if ( result ) {
        goto main_out;
    }

    /* Initialize RTC with default configurations */
    result = Config_rtc();
    if ( result ) {
        goto main_out;
    }

    /* Initialize security monitor with default configurations */
    result = Config_security();
    if ( result ) {
        giSysLock = pdTRUE;
    }

    /* All is OK. Program will continue to setup tasks */
    return;
    
main_out:
    while(1);
}


/*******************************************************************
*
* FUNCTION NAME: vJumpTask
*
* PURPOSE: Jumping PC register to specific application image
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* none
*
* RETURN VALUE:
*
*******************************************************************/
static void vJumpTask( void *pvParameters )
{
    /* Remove compiler warning about unused parameter. */
    (void) pvParameters;
    
    /* Jump PC register to MiTAC test application. */
    Application_jump(MITAC_TEST_APP);
}

/******************************************************************************/
/* EOF */

