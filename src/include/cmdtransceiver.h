/***********************************************************************
 *
 * FILE NAME: cmdtransceiver.h
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
 * 05-19-16 Chiate Wang                1    Initial Code
 *
 ***********************************************************************/

#ifndef _CMDTRANSCEIVER_H_
#define _CMDTRANSCEIVER_H_

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "queue.h"

#define CMD_PORT_BUF_LEN            ( 320 )

extern xQueueHandle xInnerReceiveQueue;
extern xQueueHandle xInnerTransportQueue;

typedef enum {
    NO_BLOCK = 0,
    BLOCK,
} cmd_block_t;

typedef enum {
    INNER = 0,
    OUTER,
    BOOT,
} cmd_id_t;

typedef enum {
    ETB = 0,
    ETX,
} cmd_end_t;

typedef enum {
    SOH = 0,
    STX,
} cmd_start_t;

typedef struct _cmd_message
{
    unsigned char Message[CMD_PORT_BUF_LEN];
    unsigned int  len;
    cmd_id_t      id;
    unsigned int  direct;
    cmd_start_t   start;
    cmd_end_t     end;
}cmd_message_t;

int SendACK(void);
int SendNAK(void);
int SendMessage(cmd_id_t id, unsigned char *buff, unsigned int len);
int ReceiveMessage(cmd_id_t id, unsigned char *buff, unsigned int bufflen, unsigned int *len, cmd_block_t block, cmd_start_t *start, cmd_end_t *end);
int CreateTransceiverTask(void);

#endif /* _CMDTRANSCEIVER_H_ */

