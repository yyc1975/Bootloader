#
# framework_config.mk
#
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
#
# [INTERNAL] ------------------------------------------------------------------
# Created on: Feb 01, 2012
# Author: Yann G. <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords (need to set the keyword property)
# $Revision:: $: Revision of last commit
# $Author:: $: Author of last commit
# $Date:: $: Date of last commit
# [/INTERNAL] --------------------------------------------------------------

## Framework environment parameters used for COBRA
PROJECT = bootloader

# final target will be:
#   - lib$(TARGET_NAME).a if TARGET_TYPE = archive  -- Library
#   - $(TARGET_NAME).elf if TARGET_TYPE = bin       -- Binary for JTAG
#   - $(TARGET_NAME).hex if TARGET_TYPE = sim       -- Binary for Simulation
TARGET_NAME = $(PROJECT)
TARGET_TYPE = bin

## Enable debug flags
DebugEnabled = True
## Enable IRQ
EnableIRQ = False
# Use UART for printf
EnableUart = False
# use GPIO for status
EnableGpio = False
# No deprecated declarations
AllowDeprecated = False

# *_norom.hex generation options
BIN2VHX_FLAGS = -EL -32 -H

# Force optimization option
COFLAGS = -O3
CXXOFLAGS = -O0
ASOFLAGS = -O0

# Remove unused sections from linking process
LDOFLAGS = -Wl,--gc-sections

## List of available external memories
# - INT_RAM = 0
# - INT_FLASH = 1
# Where to store SLA
MEM_STORAGE = 1
STORAGE_START = 0x10000000
# Where to copy & execute SLA
MEM_EXEC = 1
EXECUTION_START = 0x10000000

# EOF
