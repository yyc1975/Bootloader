#
# compilation_flags.mk
#
# Copyright (c) 2012, Maxim Integrated
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Maxim Integrated nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY MAXIM INTEGRATED ''AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# [INTERNAL] ===================================================================
#
# Created on: Jun 08, 2012
#     Author: Y. Gaude <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords
# $Rev: 4371 $: Revision of last commit
# $Author: yann.gaude $: Author of last commit
# $Date: 2014-11-13 10:06:17 +0100 (Thu, 13 Nov 2014) $: Date of last commit
#
# [/INTERNAL] ==================================================================
## Extra flags
CXXEFLAGS +=

## FPGA specific code activation
ifeq "$(PLATFORM_VERSION)" "fpga"
CEFLAGS   +=	-D_FPGA_WORKAROUND_
else
CEFLAGS   +=	-U_FPGA_WORKAROUND_
endif

CEFLAGS   +=	-D__$(PLATFORM) \
				-D__$(FRAMEWORK) \
				-D_GPIO_RESET_AT_INIT_ \
				-D_UART_RESET_AT_INIT_ \
				-D_TIMER_RESET_AT_INIT_ \
				-D_SPI_RESET_AT_INIT_ \
				-D_NO_GLOBAL_INTERRUPT_ENABLE_ON_STARTUP \
				-DWORD32 \
				-U_DUMMY_CODE_ \
				-DDEBUG
CPPFLAGS  +=	-D__MEM_STORAGE=$(MEM_STORAGE) \
				-D__MEM_EXEC=$(MEM_EXEC) \
				-D__STORAGE_START=$(STORAGE_START) \
				-D__EXECUTION_START=$(EXECUTION_START) \
				-D__$(PLATFORM) \
				-D__$(FRAMEWORK) \
				-U_DUMMY_CODE_
ASEFLAGS  +=	-D__$(FRAMEWORK) \
				-D__$(PLATFORM) \
				-U_DUMMY_CODE_
LDEFLAGS  +=

# EOF
