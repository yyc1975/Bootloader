/*
 * io.c -- libc io implementation for bare system using a serial port
 *
 * ----------------------------------------------------------------------------
 * Copyright (c) 2010, Maxim Integrated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
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
 * Created on: May 26, 2010
 * Author:
 *
 * ---- Subversion keywords (need to set the keyword property)
 * $Revision:: 2426     $:  Revision of last commit
 * $Author:: yann.gaude $:  Author of last commit
 * $Date:: 2012-02-13 1#$:  Date of last commit
 * [/INTERNAL] -------------------------------------------------------------- */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <sys/time.h>
#include <errno.h>

#include <stdio.h>
#include <stdarg.h>

#include "config.h"
#include "arch/arm/dcc.h"

#if ENABLE_UART == 1

cobra_uart_t *_uart_stdin = 0;
cobra_uart_t *_uart_stdout = 0;
cobra_uart_t *_uart_stderr = 0;

#  define __unused__

#else
#  define __unused__ __attribute__ ((unused))
#endif /* #if ENABLE_UART == 1 */

#if ENABLE_MMU == 1
extern char __section_end_heap_va;
extern char __section_start_heap_va;
#  define __section_end_heap (__section_end_heap_va)
#  define __section_start_heap (__section_start_heap_va)
#else
extern char __section_end_heap;
extern char __section_start_heap;
#endif

#ifdef LIBC_HAS_NOFLOAT
int sla_private_printf_r(struct _reent *reent, const char *fmt, va_list list) {
	return _viprintf_r(reent, fmt, list);
}

int _vfprintf_r(struct _reent *reent, FILE *fp, const char *fmt, va_list list) {
	return _vfiprintf_r(reent, fp, fmt, list);
}
#endif

/* ------------------------------------------------------------------------- */
/** io read
 * Read bytes from the serial port.
 *
 * @note fd could be used to select the serial port
 */
int _read(int fd __unused__, char *buf, int nbytes) {
	int i = 0;
#if ENABLE_UART == 1
	cobra_uart_t *uart;

	switch (fd) {
	case STDIN_FILENO:
		uart = _uart_stdin;
		break;
	default:
		errno = EIO;
		return -1;
	}

	if (0 == uart) {
		errno = EIO;
		return -1;
	}
#endif /* #if ENABLE_UART == 1 */

	for (i = 0; i < nbytes; i++) {
#if ENABLE_UART == 1
		*(buf + i) = cobra_uart_read_byte(uart);
#else
		*(buf + i) = read_dcc_char();
#endif /* #if ENABLE_UART == 1 */
		if ((*(buf + i) == '\n') || (*(buf + i) == '\r')) {
			(*(buf + i)) = 0;
			break;
		}
	}
	return (i);
}

/* ------------------------------------------------------------------------- */
/** io write
 * Write bytes from the serial port.
 *
 * @note fd could be used to select the serial port
 */
int _write(int fd __unused__, char *buf, int nbytes) {
	int i;
#if ENABLE_UART == 1
	cobra_uart_t *uart;

	switch (fd) {
	case STDOUT_FILENO:
		uart = _uart_stdout;
		break;
	case STDERR_FILENO:
		uart = _uart_stderr;
		break;
	default:
		errno = EIO;
		return -1;
	}

	if (0 == uart) {
		errno = EIO;
		return -1;
	}
#endif /* #if ENABLE_UART == 1 */
	for (i = 0; i < nbytes; i++) {
		if (*(buf + i) == '\n') {
#if ENABLE_UART == 1
			cobra_uart_write_byte(uart, '\r');
#else
			write_dcc_char('\r');
#endif /* #if ENABLE_UART == 1 */
		}
#if ENABLE_UART == 1
		cobra_uart_write_byte(uart, *(buf + i));
#else
		write_dcc_char(*(buf + i));
#endif /* #if ENABLE_UART == 1 */
	}
	return (nbytes);
}

/* ------------------------------------------------------------------------- */
/** io open
 * Open a file descriptor.
 *
 * @note We don't have a filesystem, so we return an error.
 */
int _open(char *buf __attribute__((unused)), int flags __attribute__((unused)),
		int mode __attribute__((unused))) {
	errno = EIO;
	return (-1);
}

/* ------------------------------------------------------------------------- */
/** io close
 * Close a file descriptor.
 *
 * @note We don't need to do anything, but pretend we did.
 */
int _close(int fd __attribute__((unused))) {
	return (0);
}

/* ------------------------------------------------------------------------- */
/** io sbrk
 * Changes heap size.
 *
 * @note We just increment a pointer in what's left of memory.
 */
caddr_t _sbrk(int nbytes) {
	static caddr_t heap_ptr = NULL;
	caddr_t base;

	if (heap_ptr == NULL) {
		heap_ptr = (caddr_t) &__section_start_heap;
	}

	if ((&__section_end_heap - heap_ptr) >= 0) {
		base = heap_ptr;
		heap_ptr += nbytes;
		return (base);
	} else {
		errno = ENOMEM;
		return ((caddr_t) -1);
	}
}

/* ------------------------------------------------------------------------- */
/** io isatty
 * Terminal device connection status.
 *
 * @note We are always connected.
 *
 * @todo Check if it's possible to verify the connection.
 */
int _isatty(int fd __attribute__((unused))) {
	return (1);
}

/* ------------------------------------------------------------------------- */
/** io lseek
 * Move read/write pointer.
 *
 * @note Since a serial port is non-seekable, we return an error.
 */
off_t _lseek(int fd __attribute__((unused)),
		off_t offset __attribute__((unused)),
		int whence __attribute__((unused))) {
	errno = ESPIPE;
	return ((off_t) - 1);
}

/* ------------------------------------------------------------------------- */
/** io fstat
 * Get status of a file.
 *
 * @note Since we have no file system, we just return an error.
 */
int _fstat(int fd __attribute__((unused)), struct stat *buf __attribute__((unused))) {
	errno = EIO;
	return (-1);
}

/* ------------------------------------------------------------------------- */
/** _gettimeofday
 *
 * @param tp	Pointer to timeval structure
 * @param tzvp	Time Zone
 *
 * @todo No yet implemented
 *
 * @return Always an error
 */
int _gettimeofday (struct timeval * tp, void * tzvp)
{
	struct timezone *tzp = (struct timezone *)tzvp;
	int ret;
#if PLATFORM_HAS_RTC == 1
#if __londa__ == 1
	unsigned status;
	londa_rtc_regs_t *rtc = (londa_rtc_regs_t *) LONDA_RTC_IOBASE;
#endif /* #if __londa__ == 1 */
#endif /* #if PLATFORM_HAS_RTC == 1 */

	tzp->tz_dsttime = 0;
	tzp->tz_minuteswest = 0;

#if PLATFORM_HAS_RTC == 1
	ret = 0;

#if __londa__ == 1
	do {
		status = IO_REG_BF_GET_VALUE(&rtc->cr, LONDA_RTC_CR_RDY);
	}while (0 == status);
	tp->tv_sec = rtc->sec;
	do {
		status = IO_REG_BF_GET_VALUE(&rtc->cr, LONDA_RTC_CR_RDY);
	}while (0 == status);
	tp->tv_usec = (rtc->ssec >> 1)*LONDA_RTC_SSEC_RESOLUTION;
#endif /* #if __londa__ == 1 */

#else /* #if PLATFORM_HAS_RTC == 1 */
	ret = -1;
	errno = EIO;

	tp->tv_sec = 0;
	tp->tv_usec = 0;
#endif /* #if PLATFORM_HAS_RTC == 1 */

	return ret;
}
