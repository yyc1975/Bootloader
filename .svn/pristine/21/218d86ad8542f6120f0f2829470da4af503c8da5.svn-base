/***********************************************************************
 *
 * FILE NAME: command_port.h
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
 * 05-18-16 Chiate Wang                1    Initial Code
 *
 ***********************************************************************/

#ifndef _COMMAND_PORT_H_
#define _COMMAND_PORT_H_

#define SB_COMMAND_PORT MML_UART_DEV0

/******************************************************************************/
int CreateCmdPortMutex(void);
int Cmd_Send(const char *fmt, ...);
int Cmd_Receive(unsigned char *c);
int Cmd_Send_Char(unsigned char c);

#endif /* _COMMAND_PORT_H_ */

/******************************************************************************/
/* EOF */
