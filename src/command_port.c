/********************************************************************
*
*
* FILE NAME: command_port.c
*
*
* PURPOSE: This is the implementation of command port functions.
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
* 05-18-16 Chiate.Wang             1    Initial code
*
******************************************************************** */

/* Global includes */
#include <stdarg.h> /** For va_start(), etc ... */
#include <config.h>
#include <errors.h>

/* Other includes */
#include <cobra_defines.h>
#include <cobra_macros.h>
#include <cobra_functions.h>
#include <mml_uart.h>

/* Local includes */
/* FreeRTOS includes */
#include <FreeRTOS.h>
#include <semphr.h>
#include "command_port.h"

/* Define Area */


/* Global Variable */
static xSemaphoreHandle g_hMutexCmdPort = NULL;

/* Global Function */
static void cmd_write_num(int n, int base, int sign, int pfzero, int width);
static void cmd_write_string(const char *text);
static int cmd_check_string(const char *str);
static int private_cmd_send(void (*putc)(char c), char *fmt, va_list ap);
static void cmd_write_char(char c);
static void cmd_write_long(unsigned long long n, int base, int sign, int pfzero, int width);
static void cmd_write_hex(int n);
static int cmd_cvt(unsigned long long val, char *buf, long radix, char *digits);

/* External Function */


/* External Variable */


/*******************************************************************
*
* FUNCTION NAME: CreateCmdPortMutex
*
* PURPOSE: To create command port access mutex.
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
int CreateCmdPortMutex(void)
{
    g_hMutexCmdPort = xSemaphoreCreateMutex();
    if(g_hMutexCmdPort == NULL)
        return pdFAIL;
    else
        return pdPASS;
}

/******************************************************************************/
int Cmd_Send(const char *fmt, ...)
{
    int result = COMMON_ERR_UNKNOWN;
	va_list ap;

	xSemaphoreTake(g_hMutexCmdPort, portMAX_DELAY);

    va_start(ap, fmt);
    result = private_cmd_send(cmd_write_char, (char*)fmt, ap);
    va_end(ap);

    xSemaphoreGive(g_hMutexCmdPort);

    return result;
}

/******************************************************************************/
int Cmd_Send_Char(unsigned char c)
{
    int result = NO_ERROR;
    
	xSemaphoreTake(g_hMutexCmdPort, portMAX_DELAY);

	result = mml_uart_write_char(SB_COMMAND_PORT, c);

    xSemaphoreGive(g_hMutexCmdPort);
	
    return result;
}

/******************************************************************************/
int Cmd_Receive(unsigned char *c)
{
    int result = NO_ERROR;
    
	//xSemaphoreTake(g_hMutexCmdPort, portMAX_DELAY);

	result = mml_uart_read_char(SB_COMMAND_PORT, c);

    //xSemaphoreGive(g_hMutexCmdPort);
	
    return result;
}

/******************************************************************************/
static void cmd_write_char(const char c)
{
	/** Send character */
    while( mml_uart_write_char(SB_COMMAND_PORT, c) != NO_ERROR ) ;
    /** Translate LF into CRLF */
    if ( '\n' == c ) {
        while( mml_uart_write_char(SB_COMMAND_PORT, '\r') != NO_ERROR ) ;
    }

    return;
}

/******************************************************************************/
/* Write zero terminated string */
static void cmd_write_string(const char *psz)
{
    while( *psz )
	{
    	cmd_write_char(*psz++);
	}
    /** We're done */
    return;
}

/******************************************************************************/
/* Write decimal value */
/* Remove compiler warning about unused function. */
#if 0
static void cmd_write_dec(int n)
{
    int sign = '+';

    if ( n < 0 ) {
    	n = -n;
    	sign = '-';
    }

    cmd_write_num( n, 10, sign, FALSE, 0);

    return;
}
#endif

/******************************************************************************/
/* Write hexadecimal value */
static void cmd_write_hex(int n)
{
    cmd_write_num( n, 16, '+', FALSE, 0);
}

/******************************************************************************/
/* Generic number writing function                                      */
/* The parameters determine what radix is used, the signed-ness of the  */
/* number, its minimum width and whether it is zero or space filled on  */
/* the left.                                                            */

static void cmd_write_long(unsigned long long  n, /* number to write               */
					int base,          /* radix to write to             */
					int sign,          /* sign, '-' if -ve, '+' if +ve  */
					int pfzero,        /* prefix with zero ?            */
					int width)         /* min width of number           */
{
    char    buf[32];
    int     bpos;
    char    bufinit = pfzero? '0':' ';
    char    *digits = "0123456789ABCDEF";

    /* init buffer to padding char: space or zero */
    for( bpos = 0; bpos < (int)sizeof(buf); bpos++ ) {
    	buf[bpos] = bufinit;
    }

    /* Set pos to start */
    bpos = 0;
    /* Construct digits into buffer in reverse order */
    if( n == 0 ) {
    	buf[bpos++] = '0';
    }
    else while( n != 0 )
    {
        int d = n % base;
        buf[bpos++] = digits[d];
        n /= base;
    }

    /* set pos to width if less. */
    if( width > bpos ) bpos = width;

    /* set sign if negative. */
    if( sign == '-' ) {
        if( buf[bpos-1] == bufinit ) bpos--;
        buf[bpos] = sign;
    }
    else bpos--;

    /* Now write it out in correct order. */
    while( bpos >= 0 ) {
        cmd_write_char( buf[bpos--]);
    }

    return;
}

/******************************************************************************/
static void cmd_write_num(int n, int base, int sign, int pfzero, int width)
{
    cmd_write_long((unsigned long long)n, base, sign, pfzero, width);
}


/******************************************************************************/
/* perform some simple sanity checks on a string to ensure that it      */
/* consists of printable characters and is of reasonable length.        */
static int cmd_check_string(const char *str)
{
    int result = TRUE;
    const char *s;

    if( str == NULL ) return FALSE;

    for( s = str ; result && *s ; s++ )
    {
        char c = *s;

        /* Check for a reasonable length string. */

        if( s-str > 2048 ) result = FALSE;

        /* We only really support CR, NL, and backspace at present. If
         * we want to use tabs or other special chars, this test will
         * have to be expanded.  */

        if( c == '\n' || c == '\r' || c == '\b' || c == '\t' )
            continue;

        /* Check for printable chars. This assumes ASCII */

        if( c < ' ' || c > '~' )
            result = FALSE;

    }

    return result;
}

/******************************************************************************/
static int cmd_cvt(unsigned long long val,
			char *buf,
			long radix,
			char *digits)
{
    char temp[80];
    char *cp = temp;
    int length = 0;
    unsigned int v = (unsigned int) val; /* to avoid a wrong division with
                                               long long number */
    if ( !v )
    {
        /* Special case */
        *cp++ = '0';
    }
    else
    {
        while (v)
        {
            *cp++ = digits[v % radix];
            v /= radix;
        }
    }
    while (cp != temp)
    {
        *buf++ = *--cp;
        length++;
    }
    *buf = '\0';
    return (length);
}

/******************************************************************************/
static int private_cmd_send(void (*putc)(const char c),
								char *fmt,
								va_list ap)
{
    char						buf[sizeof(unsigned long long) * 8];
    char						c;
    char						sign;
    char						*cp = buf;
    int							left_prec;
    int							right_prec;
    int							zero_fill;
    int							pad;
    int							pad_on_right;
    int							i;
    int							islong;
    int							islonglong;
    long long					val = 0;
    int							res = 0;
    int							length = 0;

    if ( FALSE == cmd_check_string(fmt) )
    {
        cmd_write_string("<Bad format string: ");
        cmd_write_hex((unsigned int)fmt);
        cmd_write_string(" :");
        for( i = 0; i < 8; i++ )
        {
            cmd_write_char(' ');
            val = va_arg(ap, unsigned long);
            cmd_write_hex(val);
        }
        cmd_write_string(">\n");
        return NO_ERROR;
    }
    /**  */
    while ((c = *fmt++) != '\0')
    {
        if (c == '%')
        {
            c = *fmt++;
            left_prec = right_prec = pad_on_right = islong = islonglong = 0;
            if (c == '-')
            {
                c = *fmt++;
                pad_on_right++;
            }
            if (c == '0')
            {
                zero_fill = TRUE;
                c = *fmt++;
            } else {
                zero_fill = FALSE;
            }
            while( M_COBRA_IS_DIGIT(c) )
            {
                left_prec = (left_prec * 10) + (c - '0');
                c = *fmt++;
            }
            if (c == '.')
            {
                c = *fmt++;
                zero_fill++;
                while( M_COBRA_IS_DIGIT(c) )
                {
                    right_prec = (right_prec * 10) + (c - '0');
                    c = *fmt++;
                }
            }
            else
            {
                right_prec = left_prec;
            }
            sign = '\0';
            if (c == 'l')
            {
                // 'long' qualifier
                c = *fmt++;
		        islong = 1;
                if (c == 'l')
                {
                    // long long qualifier
                    c = *fmt++;
                    islonglong = 1;
                }
            }
            // Fetch value [numeric descriptors only]
            switch (c)
            {
            case 'p':
		      islong = 1;
            case 'd':
            case 'D':
            case 'x':
            case 'X':
            case 'u':
            case 'U':
            case 'b':
            case 'B':
                if (islonglong)
                {
                    val = va_arg(ap, long long);
                }
                else if (islong)
                {
                    val = (long long)va_arg(ap, long);
                }
                else
                {
                    val = (long long)va_arg(ap, int);
                }
                if ((c == 'd') || (c == 'D'))
                {
                    if (val < 0)
                    {
                        sign = '-';
                        val = -val;
                    }
                }
                else
                {
                    // Mask to unsigned, sized quantity
                    if (islong)
                    {
                        val &= ((unsigned long long)1
                                    << (sizeof(unsigned long) * 8)) - 1;
                    }
                    else
                    {
                        val &= ((unsigned long long)1
                                    << (sizeof(unsigned int) * 8)) - 1;
                    }
                }
                break;
            default:
                break;
            }
            // Process output
            switch (c)
            {
            case 'p':  // Pointer
                (*putc)('0');
                (*putc)('x');
                zero_fill = TRUE;
                left_prec = sizeof(unsigned long)*2;
                length = cmd_cvt(val, buf, 16, "0123456789abcdef");
                cp = buf;
                break;
            case 'd':
            case 'D':
            case 'u':
            case 'U':
                length = cmd_cvt(val, buf, 10, "0123456789");
                cp = buf;
                break;
            case 'x':
                length = cmd_cvt(val, buf, 16, "0123456789abcdef");
                cp = buf;
                break;
            case 'X':
                length = cmd_cvt(val, buf, 16, "0123456789ABCDEF");
                cp = buf;
                break;
            case 's':
            case 'S':
                cp = va_arg(ap, char *);
                if (cp == NULL)
                    cp = "<null>";
                else if (!cmd_check_string(cp))
                {
                    cmd_write_string("<Not a string: 0x");
                    cmd_write_hex((unsigned int)cp);
                    cp = ">";
                }
                length = 0;
                while (cp[length] != '\0') length++;
                break;
            case 'c':
            case 'C':
                c = va_arg(ap, int /*char*/);
                (*putc)(c);
                res++;
                continue;
            case 'b':
            case 'B':
                length = left_prec;
                if (left_prec == 0)
                {
                    if (islonglong)
                        length = sizeof(unsigned long)*8;
                    else if (islong)
                        length = sizeof(long)*8;
                    else
                        length = sizeof(int)*8;
                }
                for (i = 0;  i < length-1;  i++)
                {
                    buf[i] = ((val & ((unsigned long)1<<i)) ? '1' : '.');
                }
                cp = buf;
                break;
            case '%':
                (*putc)('%');
                break;
            default:
                (*putc)('%');
                (*putc)(c);
                res += 2;
            }
            pad = left_prec - length;
            if (sign != '\0')
            {
                pad--;
            }
            if (zero_fill)
            {
                c = '0';
                if (sign != '\0')
                {
                    (*putc)(sign);
                    res++;
                    sign = '\0';
                }
            }
            else
            {
                c = ' ';
            }
            if (!pad_on_right)
            {
                while (pad-- > 0)
                {
                    (*putc)(c);
                    res++;
                }
            }
            if (sign != '\0')
            {
                (*putc)(sign);
                res++;
            }
            while (length-- > 0)
            {
                c = *cp++;
                (*putc)(c);
                res++;
            }
            if (pad_on_right)
            {
                while (pad-- > 0)
                {
                    (*putc)(' ');
                    res++;
                }
            }
        }
        else
        {
            (*putc)(c);
            res++;
        }
    }
    return (res);
}

/******************************************************************************/
/* EOF */
