/********************************************************************
*
*
* FILE NAME: command.c
*
*
* PURPOSE: This is the implementation of command functions.
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
* 05-19-16 Chiate.Wang             1    Initial code
* 05-26-16 Chiate.Wang             1    Modify API, ReceiveMessage
*                                       Handle command start with SOH and
*                                       end with ETB
* 05-31-16 Chiate.Wang             1    Modify API, ReceiveMessage and dispatchMessage
*
******************************************************************** */

/* Global includes */
#include <errors.h>
#include <cobra_functions.h>

/* Other includes */


/* Local includes */
#include <printf_lite.h>
/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include <private.h>
//#include <screen.h>
//#ifdef _USE_LCD_SCREEN_
//#include <framebuffer.h>
//#include <color.h>
//#endif /* #ifdef _USE_LCD_SCREEN_ */
#include "cmdtransceiver.h"
#include "command_port.h"
//#include "commonUtil.h"
#include <mml_dma.h>
#include <mml_uart.h>
//#include "status.h"
#include <ucl/ucl_types.h>
//#include "sys_cmdprocessor.h"

/* Define Area */
//#define _CMD_ECHO_
//#define _ENQ_HANDSHAKING_

#define CMD_QUEUE_SIZE              ( 10 )

#define CMD_START_STR               ( "STX" )
#define CMD_INNER_ID                ( "MCT" )
#define CMD_OUTER_ID                ( "XXX" )
#define CMD_BOOT_ID                 ( "BLD" )
#define CMD_END_STR                 ( "ETX" )
#define CMD_LRC_LEN                 ( 1 )

#define CMD_CHAR_S                  ( 'S' )
#define CMD_CHAR_T                  ( 'T' )
#define CMD_CHAR_X                  ( 'X' )
#define CMD_CHAR_E                  ( 'E' )
#define CMD_CHAR_A                  ( 'A' )
#define CMD_CHAR_C                  ( 'C' )
#define CMD_CHAR_K                  ( 'K' )
#define CMD_CHAR_O                  ( 'O' )
#define CMD_CHAR_H                  ( 'H' )
#define CMD_CHAR_B                  ( 'B' )

#define CMD_START_CHAR_S_MASK       ( 0x01 )
#define CMD_START_CHAR_T_MASK       ( 0x01 << 1 )
#define CMD_START_CHAR_X_MASK       ( 0x01 << 2 )
#define CMD_END_CHAR_E_MASK         ( 0x01 << 3 )
#define CMD_END_CHAR_T_MASK         ( 0x01 << 4 )
#define CMD_END_CHAR_X_MASK         ( 0x01 << 5 )
#define CMD_LRC_MASK                ( 0x01 << 6 )
#define CMD_BOOT_CHAR_A_MASK        ( 0x01 << 7 )
#define CMD_BOOT_CHAR_C_MASK        ( 0x01 << 8 )
#define CMD_BOOT_CHAR_K_MASK        ( 0x01 << 9 )
#define CMD_START_CHAR_O_MASK       ( 0x01 << 10 )
#define CMD_START_CHAR_H_MASK       ( 0x01 << 11 )
#define CMD_END_CHAR_B_MASK         ( 0x01 << 12 )

#define CMD_COLLECT_STAGE_0         ( 0 )
#define CMD_COLLECT_STAGE_S         ( CMD_COLLECT_STAGE_0 | CMD_START_CHAR_S_MASK )
#define CMD_COLLECT_STAGE_ST        ( CMD_COLLECT_STAGE_S | CMD_START_CHAR_T_MASK )
#define CMD_COLLECT_STAGE_STX       ( CMD_COLLECT_STAGE_ST | CMD_START_CHAR_X_MASK )
#define CMD_COLLECT_STAGE_STXE      ( CMD_COLLECT_STAGE_STX | CMD_END_CHAR_E_MASK )
#define CMD_COLLECT_STAGE_STXET     ( CMD_COLLECT_STAGE_STXE | CMD_END_CHAR_T_MASK )
#define CMD_COLLECT_STAGE_STXETX    ( CMD_COLLECT_STAGE_STXET | CMD_END_CHAR_X_MASK )
#define CMD_COLLECT_STAGE_STXETB    ( CMD_COLLECT_STAGE_STXET | CMD_END_CHAR_B_MASK )
#define CMD_COLLECT_STAGE_STXETXLRC ( CMD_COLLECT_STAGE_STXETX | CMD_LRC_MASK )
#define CMD_COLLECT_STAGE_STXETBLRC ( CMD_COLLECT_STAGE_STXETB | CMD_LRC_MASK )

#define CMD_COLLECT_STAGE_BOOT_A    ( CMD_COLLECT_STAGE_0 | CMD_BOOT_CHAR_A_MASK )
#define CMD_COLLECT_STAGE_BOOT_AC   ( CMD_COLLECT_STAGE_BOOT_A | CMD_BOOT_CHAR_C_MASK )
#define CMD_COLLECT_STAGE_BOOT_ACK  ( CMD_COLLECT_STAGE_BOOT_AC | CMD_BOOT_CHAR_K_MASK )

#define CMD_COLLECT_STAGE_SO        ( CMD_COLLECT_STAGE_S | CMD_START_CHAR_O_MASK )
#define CMD_COLLECT_STAGE_SOH       ( CMD_COLLECT_STAGE_SO | CMD_START_CHAR_H_MASK )
#define CMD_COLLECT_STAGE_SOHE      ( CMD_COLLECT_STAGE_SOH | CMD_END_CHAR_E_MASK )
#define CMD_COLLECT_STAGE_SOHET     ( CMD_COLLECT_STAGE_SOHE | CMD_END_CHAR_T_MASK )
#define CMD_COLLECT_STAGE_SOHETB    ( CMD_COLLECT_STAGE_SOHET | CMD_END_CHAR_B_MASK )
#define CMD_COLLECT_STAGE_SOHETX    ( CMD_COLLECT_STAGE_SOHET | CMD_END_CHAR_X_MASK )
#define CMD_COLLECT_STAGE_SOHETBLRC ( CMD_COLLECT_STAGE_SOHETB | CMD_LRC_MASK )
#define CMD_COLLECT_STAGE_SOHETXLRC ( CMD_COLLECT_STAGE_SOHETX | CMD_LRC_MASK )

#define getStartHeaderOffset()      ( strlen(CMD_START_STR) )
#define getBufferStartOffset()      ( getStartHeaderOffset() + strlen(CMD_INNER_ID) )
#define getTotalHeaderLen()         ( getBufferStartOffset() + strlen(CMD_END_STR) + \
                                        CMD_LRC_LEN )

#define CMD_RECEIVE_TIMEOUT_TICK    15000

#define DMA_BUFFER_SIZE             512

/* Global Variable */
static int w_idx = 0;
static int giCmdForm = 0;
static int giInitialized = 0;
static int giNakSend = pdFALSE;

#ifdef _ENQ_HANDSHAKING_
static xTaskHandle xHandleENQ;
#endif

static xTimerHandle xHandleTimeOut;

xQueueHandle xInnerReceiveQueue = NULL;
xQueueHandle xOuterReceiveQueue = NULL;
xQueueHandle xResponseTransportQueue = NULL;

/* Global Function */
static void vCmdTransceiverTask( void *pvParameters );
#ifdef _ENQ_HANDSHAKING_
static void vEnqTask( void *pvParameters );
#endif
void handleTransport(void);

static unsigned int dma_r = 0;
static unsigned int dma_w = 0;
static unsigned char dst[DMA_BUFFER_SIZE];

/* External Function */


/* External Variable */


/*******************************************************************
*
* FUNCTION NAME: ComputeLRC
*
* PURPOSE: To compute LRC of input array.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* in            unsigned char*  I  input array
* len           int             I  length of input array
* lrc           unsigned char*  O  calculated LRC byte
*
* RETURN VALUE: none
*
*******************************************************************/
void ComputeLRC(const unsigned char *in, int len, unsigned char *lrc)
{
    unsigned char rc = 0;
    
    while (len--) {
        rc ^= *in++;
    }
    
    if (lrc) {
        *lrc = rc;
    }    
}

/*******************************************************************
*
* FUNCTION NAME: vTimeOutCallback
*
* PURPOSE: Command time out callback
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
void vTimeOutCallback(xTimerHandle pxTimer)
{
    configASSERT(pxTimer);

    giNakSend = pdTRUE;
}

/*******************************************************************
*
* FUNCTION NAME: createCmdTransceiverQueue
*
* PURPOSE: To create command transceiver queue.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: none
*       pdPASS or pdFAIL
*
*******************************************************************/
int createCmdTransceiverQueue(void)
{
    xInnerReceiveQueue = xQueueCreate(CMD_QUEUE_SIZE, sizeof(cmd_message_t));
    if(xInnerReceiveQueue == NULL)
        return pdFAIL;

    xOuterReceiveQueue = xQueueCreate(CMD_QUEUE_SIZE, sizeof(cmd_message_t));
    if(xOuterReceiveQueue == NULL)
        return pdFAIL;

    xResponseTransportQueue = xQueueCreate(CMD_QUEUE_SIZE, sizeof(cmd_message_t));
    if(xResponseTransportQueue == NULL)
        return pdFAIL;

    return pdPASS;
}

/*******************************************************************
*
* FUNCTION NAME: dma_reload_callback
*
* PURPOSE: The callback function for chaining DMA buffer
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* rld_addr      mml_dma_addr_t  O  Reload buffer address
* next_rld      int             O  Reload flag
*
* RETURN VALUE: none
*
*******************************************************************/
static void dma_reload_callback(mml_dma_addr_t *rld_addr, int *next_rld)
{
    lite_printf("--dma_reload_callback--\n");

    /* Chaining the same buffer to become a ring buffer */
    if(SB_COMMAND_PORT == MML_UART_DEV0)
        rld_addr->src = 0x40020020; /* UART0 Data Register */
    else
        rld_addr->src = 0x40021020; /* UART1 Data Register */
    rld_addr->dst = (unsigned int)dst;
    rld_addr->count = DMA_BUFFER_SIZE;

    *next_rld = 1;
}

/*******************************************************************
*
* FUNCTION NAME: setupUartDMA
*
* PURPOSE: To setup DMA for command port.
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
static int setupUartDMA(void)
{
    volatile mml_uart_regs_t *reg_uart;
    mml_dma_channel_t ch = MML_DMA_CH3;
    int irq = MML_INTNUM_DMA3;
    mml_dma_config_t config;
    mml_dma_addr_t addr;
    int result = NO_ERROR;

    if(SB_COMMAND_PORT == MML_UART_DEV0)
        reg_uart = (volatile mml_uart_regs_t*)MML_UART0_IOBASE;
    else
        reg_uart = (volatile mml_uart_regs_t*)MML_UART1_IOBASE;

    /* RX DMA channel enable with 0 threshold */
    reg_uart->dma = MML_UART_DMA_RXEN_MASK;
    
    config.priority = MML_DMA_PRIORITY_HIGHEST;
    if(SB_COMMAND_PORT == MML_UART_DEV0)
        config.request = 0x04; /* UART0 RX to memory */
    else
        config.request = 0x05; /* UART1 RX to memory */
    config.req_wait = MML_DMA_START_TIMER_NORMAL;
    config.timeout = MML_DMA_PRESCALE_CLOCKS_3TO4;
    config.prescale = MML_DMA_PRESCALE_DIVIDER_DISABLE;
    config.src_width = MML_DMA_DATA_WIDTH_BYTE;
    config.src_increment = 0;
    config.dst_width = MML_DMA_DATA_WIDTH_BYTE;
    config.dst_increment = 1;
    config.burst_size = 0; /* Burst size: 1 */

    if(SB_COMMAND_PORT == MML_UART_DEV0)
        addr.src = 0x40020020; /* UART0 Data Register */
    else
        addr.src = 0x40021020; /* UART1 Data Register */
    addr.dst = (unsigned int)dst;
    addr.count = DMA_BUFFER_SIZE;
    
    result = mml_dma_init(ch, irq, config, addr);
    if(result) {
        return result;
    }

    result = mml_dma_set_chaintransfer(ch, addr, dma_reload_callback);
    if(result) {
        return result;
    }

    result = mml_dma_enable(ch);

    return result;
}

/*******************************************************************
*
* FUNCTION NAME: Cmd_DMA_Receive
*
* PURPOSE: To receive one character from DMA buffer.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* c             unsigned char*  O  Character received
*
* RETURN VALUE: int
*       the error code (/include/errors.h)
*
*******************************************************************/
static int Cmd_DMA_Receive(unsigned char *c)
{
    volatile mml_dma_regs_t *reg_dma = (volatile mml_dma_regs_t*)MML_DMA_IOBASE;

    dma_w = (DMA_BUFFER_SIZE) - (reg_dma->ch[MML_DMA_CH3].cnt & MML_DMA_CNT_MASK);

    if((dma_w != dma_r) && (dma_r < DMA_BUFFER_SIZE)) {
        *c = dst[dma_r];
        dma_r = (dma_r + 1)%DMA_BUFFER_SIZE;
    } else {
        return COMMON_ERR_RUNNING;
    }

    return NO_ERROR;
}

/*******************************************************************
*
* FUNCTION NAME: CreateTransceiverTask
*
* PURPOSE: To create command transceiver task.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       pdPASS or pdFAIL
*
*******************************************************************/
int CreateTransceiverTask(void)
{
    int result = NO_ERROR;

    giInitialized = 0;
    
    result = CreateCmdPortMutex();
    if(result == pdFAIL)
        goto Error;
    
    result = createCmdTransceiverQueue();
    if(result == pdFAIL)
        goto Error;

    xHandleTimeOut = xTimerCreate((const signed char * const)"TimeOut", 
                        (CMD_RECEIVE_TIMEOUT_TICK/portTICK_PERIOD_MS), 
                        pdFALSE, (void *)0, vTimeOutCallback);
    if(xHandleTimeOut == NULL)
        goto Error;

    result = setupUartDMA();
    if(result)
        goto Error;

#ifdef _ENQ_HANDSHAKING_
    result = xTaskCreate( vEnqTask, (signed char*)"ENQ", 100, NULL, 4, &xHandleENQ);
    if(result == pdFAIL)
        goto Error;
#endif

    result = xTaskCreate( vCmdTransceiverTask, (signed char*)"CMD_Transceiver", 
                        600, NULL, 4, NULL );
    if(result == pdPASS)
        giInitialized = 1;

Error:
    return result;
}

/*******************************************************************
*
* FUNCTION NAME: CreateMessage
*
* PURPOSE: To create message to send out.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* id            cmd_id_t        I  id for message
* buff          unsigned char*  I  data buffer to be create
* len           unsigned int    I  create length
*
* RETURN VALUE: unsigned char*
*       created message buffer pointer
*
*******************************************************************/
unsigned char *createMessage(cmd_id_t id, unsigned char *buff, int len)
{
    int total_len = len + getTotalHeaderLen();
    unsigned char *pHead = pvPortMalloc(total_len);
    unsigned char *p = (unsigned char *)(pHead + getBufferStartOffset());

    memcpy(pHead, CMD_START_STR, strlen(CMD_START_STR));
    memcpy(pHead+strlen(CMD_START_STR), ((id == INNER)?CMD_INNER_ID:((id == OUTER)?CMD_OUTER_ID:CMD_BOOT_ID)),
            strlen(CMD_INNER_ID));
    memcpy(p, buff, len);
    memcpy(p+len, CMD_END_STR, strlen(CMD_END_STR));
    ComputeLRC(pHead, total_len-1, (unsigned char *)(pHead+total_len-1));

    return pHead;
}

/*******************************************************************
*
* FUNCTION NAME: SendACK
*
* PURPOSE: To send out ACK message.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       pdPASS or pdFAIL
*
*******************************************************************/
int SendACK(void)
{
    int result = pdPASS;
    cmd_message_t mMessage;

    if(!giInitialized)
        return pdFAIL;

    mMessage.len = 3;
    mMessage.direct = 1;
    memcpy(mMessage.Message, "ACK", 3);
    if(xQueueSendToBack(xResponseTransportQueue, &mMessage, portMAX_DELAY) != pdPASS) {
        result = pdFAIL;
    }

    return result;
}

/*******************************************************************
*
* FUNCTION NAME: SendNAK
*
* PURPOSE: To send out NAK message.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: int
*       pdPASS or pdFAIL
*
*******************************************************************/
int SendNAK(void)
{
    int result = pdPASS;
    cmd_message_t mMessage;

    if(!giInitialized)
        return pdFAIL;

    mMessage.len = 3;
    mMessage.direct = 1;
    memcpy(mMessage.Message, "NAK", 3);
    if(xQueueSendToBack(xResponseTransportQueue, &mMessage, portMAX_DELAY) != pdPASS) {
        result = pdFAIL;
    }

    return result;
}

/*******************************************************************
*
* FUNCTION NAME: SendMessage
*
* PURPOSE: To send out message.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* id            cmd_id_t        I  id for send ACK
* buff          unsigned char*  I  Buffer to be copy to
* len           unsigned int    I  Copy length
*
* RETURN VALUE: int
*       pdPASS or pdFAIL
*
*******************************************************************/
int SendMessage(cmd_id_t id, unsigned char *buff, unsigned int len)
{
    int result = pdPASS;
    cmd_message_t mMessage;

    if(!giInitialized)
        return pdFAIL;

    mMessage.id = id;
    mMessage.len = len;
    mMessage.direct = 0;
    memcpy(mMessage.Message, buff, mMessage.len);
    if(xQueueSendToBack(xResponseTransportQueue, &mMessage, portMAX_DELAY) != pdPASS) {
        result = pdFAIL;
    }

    return result;
}

/*******************************************************************
*
* FUNCTION NAME: ReceiveMessage
*
* PURPOSE: To receive message in inner queue.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* id            cmd_id_t        I  id for send ACK
* buff          unsigned char*  O  Buffer to be copy to
* bufflen       unsigned int    I  Buffer length
* len           unsigned int*   O  Copy length
* block         cmd_block_t     I  block or not
* start         cmd_start_t*    O  If STX received
* end           cmd_end_t*      O  If ETX received
*
* RETURN VALUE: int
*       pdPASS or pdFAIL
*
*******************************************************************/
int ReceiveMessage(cmd_id_t id, unsigned char *buff, unsigned int bufflen, 
                        unsigned int *len, cmd_block_t block, cmd_start_t *start, cmd_end_t *end)
{
    int result = pdPASS;
    cmd_message_t mMessage;
    portTickType tick = 0;
    xQueueHandle queue = NULL;

    if(!giInitialized)
        return pdFAIL;

    if(id == INNER)
        queue = xInnerReceiveQueue;
    else
        queue = xOuterReceiveQueue;

    if(block == NO_BLOCK)
        tick = 0;
    else 
        tick = portMAX_DELAY;

    if(xQueueReceive(queue, &mMessage, tick)) {
        if(bufflen > mMessage.len) {
            *len = mMessage.len;
            *start = mMessage.start;
            *end = mMessage.end;
            memcpy(buff, mMessage.Message, mMessage.len);
        } else {
            *len = 0;
            result = pdFAIL;
        }
    } else {
        result = pdFAIL;
    }

    return result;
}

/*******************************************************************
*
* FUNCTION NAME: dispatchMessage
*
* PURPOSE: To dispatch received message.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* id            cmd_id_t        I  Id for send ACK
* buff          unsigned char*  I  Buffer to be copy to
* len           unsigned int    I  Copy length
* start         cmd_start_t     I  If STX received
* end           cmd_end_t       I  If ETX received
*
* RETURN VALUE: int
*       pdPASS or pdFAIL
*
*******************************************************************/
int dispatchMessage(cmd_id_t id, unsigned char *buff, unsigned int len, cmd_start_t start, cmd_end_t end)
{
    int result = pdPASS;
    cmd_message_t mMessage;
    xQueueHandle queue = NULL;

    if(!giInitialized)
        return pdFAIL;

    if(id == INNER)
        queue = xInnerReceiveQueue;
    else
        queue = xOuterReceiveQueue;

    mMessage.id = id;
    mMessage.len = len;
    mMessage.end = end;
    mMessage.start = start;
    memcpy(mMessage.Message, buff, mMessage.len);
    if(xQueueSendToBack(queue, &mMessage, portMAX_DELAY) != pdPASS) {
        result = pdFAIL;
    }

    return result;
}

/*******************************************************************
*
* FUNCTION NAME: handleTransport
*
* PURPOSE: To wait response and send out to command port.
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
*
* RETURN VALUE: none
*
*******************************************************************/
void handleTransport(void)
{
    int result = pdPASS;
    cmd_message_t mMessage;
    unsigned char *outBuff = NULL;
    unsigned int i = 0;

    if(!giInitialized)
        return;

    do {
        result = xQueueReceive(xResponseTransportQueue, &mMessage, 0);
        if(result) {
            if(mMessage.direct == 0) {
                outBuff = createMessage(mMessage.id, mMessage.Message, mMessage.len);
                for(i=0; i<(mMessage.len+getTotalHeaderLen()); i++) {
                    Cmd_Send_Char(*(outBuff+i));
                }
                vPortFree(outBuff);
            } else {
                for(i=0; i<(mMessage.len); i++) {
                    Cmd_Send_Char(*(mMessage.Message+i));
                }
            }
        }
    } while(result);
}

/*******************************************************************
*
* FUNCTION NAME: vEnqTask
*
* PURPOSE: To sent "ENQ" to host every 500ms
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
#ifdef _ENQ_HANDSHAKING_
static void vEnqTask( void *pvParameters )
{
    /* Remove compiler warning about unused parameter. */
    (void) pvParameters;

    while(1) {
        Cmd_Send("ENQ");
    
        vTaskDelay( 500 / portTICK_PERIOD_MS );
    }
}
#endif

/*******************************************************************
*
* FUNCTION NAME: commandCollect
*
* PURPOSE: Parse/handle command
*
* ARGUMENT LIST:
*
* Argument      Type            IO Description
* ------------- --------------- -- ---------------------------------
* c             unsigned char   I  Char to be collect
*
* RETURN VALUE:
*
*******************************************************************/
static void commandCollect(unsigned char c)
{
    switch(giCmdForm) {
        case CMD_COLLECT_STAGE_0:
            if(c == CMD_CHAR_S)
                giCmdForm |= CMD_START_CHAR_S_MASK;
            else if(c == CMD_CHAR_A)
                giCmdForm |= CMD_BOOT_CHAR_A_MASK;
            break;
        case CMD_COLLECT_STAGE_S:
            if(c == CMD_CHAR_T)
                giCmdForm |= CMD_START_CHAR_T_MASK;
            else if(c == CMD_CHAR_O)
                giCmdForm |= CMD_START_CHAR_O_MASK;
            else if(c == CMD_CHAR_S)
                w_idx = 0;
            else
                giCmdForm = CMD_COLLECT_STAGE_0;
            break;
        case CMD_COLLECT_STAGE_ST:
            if(c == CMD_CHAR_X) {
                giCmdForm |= CMD_START_CHAR_X_MASK;
                xTimerReset(xHandleTimeOut, 0);
            } else if(c == CMD_CHAR_S) {
                w_idx = 0;
                giCmdForm &= ~CMD_START_CHAR_T_MASK;
            } else
                giCmdForm = CMD_COLLECT_STAGE_0;
            break;
        case CMD_COLLECT_STAGE_SO:
            if(c == CMD_CHAR_H) {
                giCmdForm |= CMD_START_CHAR_H_MASK;
                xTimerReset(xHandleTimeOut, 0);
            } else if(c == CMD_CHAR_S) {
                w_idx = 0;
                giCmdForm &= ~CMD_START_CHAR_O_MASK;
            } else
                giCmdForm = CMD_COLLECT_STAGE_0;
            break;
        case CMD_COLLECT_STAGE_STX:
        case CMD_COLLECT_STAGE_SOH:
            if(c == CMD_CHAR_E)
                giCmdForm |= CMD_END_CHAR_E_MASK;
            break;
        case CMD_COLLECT_STAGE_STXE:
        case CMD_COLLECT_STAGE_SOHE:
            if(c == CMD_CHAR_T)
                giCmdForm |= CMD_END_CHAR_T_MASK;
            else if(c != CMD_CHAR_E)
                giCmdForm &= ~(CMD_END_CHAR_E_MASK);
            break;
        case CMD_COLLECT_STAGE_STXET:
        case CMD_COLLECT_STAGE_SOHET:
            if(c == CMD_CHAR_X)
                giCmdForm |= CMD_END_CHAR_X_MASK;
            else if(c == CMD_CHAR_B)
                giCmdForm |= CMD_END_CHAR_B_MASK;
            else if(c == CMD_CHAR_E)
                giCmdForm &= ~(CMD_END_CHAR_T_MASK);
            else
                giCmdForm &= ~(CMD_END_CHAR_E_MASK|CMD_END_CHAR_T_MASK);
            break;
        case CMD_COLLECT_STAGE_STXETX:
        case CMD_COLLECT_STAGE_STXETB:
        case CMD_COLLECT_STAGE_SOHETX:
        case CMD_COLLECT_STAGE_SOHETB:
                giCmdForm |= CMD_LRC_MASK;
                xTimerStop(xHandleTimeOut, 0);
            break;
        case CMD_COLLECT_STAGE_BOOT_A:
            if(c == CMD_CHAR_C)
                giCmdForm |= CMD_BOOT_CHAR_C_MASK;
            else if(c != CMD_CHAR_A)
                giCmdForm = CMD_COLLECT_STAGE_0;
            break;
        case CMD_COLLECT_STAGE_BOOT_AC:
            if(c == CMD_CHAR_K)
                giCmdForm |= CMD_BOOT_CHAR_K_MASK;
            else if(c == CMD_CHAR_A)
                giCmdForm = CMD_COLLECT_STAGE_BOOT_A;
            else
                giCmdForm = CMD_COLLECT_STAGE_0;
            break;
        default:
            break;
    }
}

/*******************************************************************
*
* FUNCTION NAME: vCmdTransceiverTask
*
* PURPOSE: Parse/handle command
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
static void vCmdTransceiverTask( void *pvParameters )
{
    /* Remove compiler warning about unused parameter. */
    (void) pvParameters;
    unsigned char c = 0;
    unsigned char lrc = 0;
    unsigned char buff[CMD_PORT_BUF_LEN];
    unsigned int len = 0;
    unsigned int result = COMMON_ERR_UNKNOWN;
    cmd_id_t id = INNER;
    cmd_start_t start = STX;
    cmd_end_t end = ETX;

    while(1) {

        if(giNakSend) {
            giNakSend = pdFALSE;
            giCmdForm = CMD_COLLECT_STAGE_0;
            w_idx = 0;
            SendNAK();
        }

#ifdef _ENQ_HANDSHAKING_
        if(xTaskIsTaskSuspended(xHandleENQ) == pdTRUE)
#endif
            handleTransport();

        /* Check command port if any command come in */
        result = Cmd_DMA_Receive(&c);
        if(result == NO_ERROR) {
            lite_printf("%c ", c);
#ifdef _CMD_ECHO_
            Cmd_Send("%c", c);
#endif
            commandCollect(c);
            if((giCmdForm == CMD_COLLECT_STAGE_0) ||
               (giCmdForm == CMD_COLLECT_STAGE_BOOT_A) ||
               (giCmdForm == CMD_COLLECT_STAGE_BOOT_AC)) {
                w_idx = 0;
                continue;
            } else if(giCmdForm == CMD_COLLECT_STAGE_BOOT_ACK) {
                giCmdForm = CMD_COLLECT_STAGE_0;
#ifdef _ENQ_HANDSHAKING_
                /* Stop NEQ if needed */
                if(xTaskIsTaskSuspended(xHandleENQ) == pdFALSE)
                    vTaskSuspend(xHandleENQ);
#endif
                continue;
            }

            buff[w_idx] = c;
            w_idx++;
            if(w_idx >= CMD_PORT_BUF_LEN) {
               giCmdForm = CMD_COLLECT_STAGE_0;
               w_idx = 0;
               lite_printf("\nBuffer overflow!!!\n");
            }

            if((giCmdForm == CMD_COLLECT_STAGE_STXETXLRC) ||
               (giCmdForm == CMD_COLLECT_STAGE_STXETBLRC) ||
               (giCmdForm == CMD_COLLECT_STAGE_SOHETBLRC) ||
               (giCmdForm == CMD_COLLECT_STAGE_SOHETXLRC)){

                len = w_idx;
                lrc = buff[len-1];
                ComputeLRC(buff, len-1, &c);
                lite_printf("\nLRC: %c\n", c);
#ifdef _CMD_ECHO_
                Cmd_Send("\nLRC: %c\n", c);
#endif
                /* Check LRC */
                if(c == lrc) {
#ifdef _ENQ_HANDSHAKING_
                    /* Stop NEQ if needed */
                    if(xTaskIsTaskSuspended(xHandleENQ) == pdFALSE)
                        vTaskSuspend(xHandleENQ);
#endif
                    if(!memcmp(&buff[getStartHeaderOffset()], CMD_INNER_ID, 
                                                          strlen(CMD_INNER_ID)))
                        id = INNER;
                    else if(!memcmp(&buff[getStartHeaderOffset()], CMD_OUTER_ID, 
                                                          strlen(CMD_OUTER_ID)))
                        id = OUTER;
                    else
                        id = BOOT;

                    if(giCmdForm & CMD_START_CHAR_X_MASK)
                        start = STX;
                    else
                        start = SOH;

                    if(giCmdForm & CMD_END_CHAR_X_MASK)
                        end = ETX;
                    else
                        end = ETB;

                    if(id == BOOT) {
                        /* ACK to notify host */
                        SendACK();

                        /* Dispatch command*/
                        dispatchMessage(id, buff+getBufferStartOffset(), 
                                               len-getTotalHeaderLen(), start, end);
                    } else {
                        SendNAK();
                    }
                } else {
                    /* Wrong LRC */
                    SendNAK();
                }
                w_idx = 0;
                giCmdForm = CMD_COLLECT_STAGE_0;
            } else {
                continue;
            }
        }

        vTaskDelay( 40 / portTICK_PERIOD_MS );
    }
}

