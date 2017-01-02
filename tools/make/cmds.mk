#
# tools/make/cmds.mk
#
# Copyright (c) 2010, Maxim Integrated
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
# Created on: Mar 30, 2010
#     Author: Grégory Romé <gregory.rome@maxim-ic.com>
#
# ---- Subversion keywords
# $Rev:: 2166          $:  Revision of last commit
# $Author:: yann.gaude $:  Author of last commit
# $Date:: 2011-09-29 2#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

AR		=$(CROSS_COMPILE)ar
AS		=$(CROSS_COMPILE)gcc -c
CC		=$(CROSS_COMPILE)gcc -c
CXX		=$(CROSS_COMPILE)g++ -c
LD		=$(CROSS_COMPILE)gcc -Xlinker
LDD		=$(CROSS_COMPILE)ldd
NM		=$(CROSS_COMPILE)nm
CPP		=$(CROSS_COMPILE)cpp
COV		=$(CROSS_COMPILE)gcov
GDB		=$(CROSS_COMPILE)gdb
OBJCOPY	=$(CROSS_COMPILE)objcopy
OBJDUMP	=$(CROSS_COMPILE)objdump
RANLIB	=$(CROSS_COMPILE)ranlib
READELF	=$(CROSS_COMPILE)readelf
SIZE	=$(CROSS_COMPILE)size
STRINGS	=$(CROSS_COMPILE)strings
STRIP	=$(CROSS_COMPILE)strip
BIN2VHX =perl $(toolsDir)/scripts/bin2vhx.pl
CONV_ROM = $(toolsDir)/host/conv_rom/conv_rom
CPPCHECK = cppcheck
SLOCCOUNT = sloccount

TERMINAL = gnome-terminal

export AR AS CC LD NM CPP COV GDB OBJCOPY OBJDUMP
export RANLIB READELF SIZE STRINGS STRIP

##
ifndef BIN2VHX_FLAGS
BIN2VHX_FLAGS = -EL -32 -H
endif

CPPCHECKFLAGS = --enable=all --xml --quiet
SLOCCOUNTFLAGS = --wide --details

## Architecture flags
CXXAFLAGS = $(PlatformSpecific) -mlittle-endian -msoft-float -D__$(PLATFORM)__ -D__$(PLATFORM)_$(PLATFORM_VERSION)__ -D__$(BOARD)__
CAFLAGS   = $(PlatformSpecific) -mlittle-endian -msoft-float -D__$(PLATFORM)__ -D__$(PLATFORM)_$(PLATFORM_VERSION)__ -D__$(BOARD)__
ASAFLAGS  = $(PlatformSpecific) -mlittle-endian -msoft-float -D__$(PLATFORM)__ -D__$(PLATFORM)_$(PLATFORM_VERSION)__ -D__$(BOARD)__
LDAFLAGS  = $(PlatformSpecific) -mlittle-endian -msoft-float -D__$(PLATFORM)__ -D__$(PLATFORM)_$(PLATFORM_VERSION)__ -D__$(BOARD)__
CPPFLAGS  += -D__$(PLATFORM)__ -D__$(PLATFORM)_$(PLATFORM_VERSION)__ -D__$(BOARD)__

## Extra flags
CXXEFLAGS += -W -Wall -fmessage-length=0 -fno-common
CEFLAGS   += -W -Wall -fmessage-length=0 -fno-common
ASEFLAGS  += -W -Wall -fmessage-length=0 -fno-common -D__ASSEMBLER__
LDEFLAGS  += -Map=$(TARGET_NAME).map -nostdlib -nostartfiles

LIBS += c gcc m

## Debug flags
ifeq "$(DebugEnabled)" "True"
	ifndef COFLAGS
		COFLAGS = -O0
	endif
	ifndef CXXOFLAGS
		CXXOFLAGS = -O0
	endif
	ifndef ASOFLAGS
		ASOFLAGS = -O0
	endif

	CXXDFLAGS = -g -D_DEBUG
	CDFLAGS   = -g -D_DEBUG
	ASDFLAGS  = -g -D_DEBUG
	CPPFLAGS  += -D_DEBUG

else ## Optimization flags

	ifndef COFLAGS
		COFLAGS = -Os
	endif
	ifndef CXXOFLAGS
		CXXOFLAGS = -Os
	endif
	ifndef ASOFLAGS
		ASOFLAGS = -Os
	endif

	CXXDFLAGS = -DNDEBUG
	CDFLAGS   = -DNDEBUG
	ASDFLAGS  = -DNDEBUG
	LDDFLAGS  = -s --discard-local --discard-all

endif

ifeq "$(ProfilingEnabled)" "True"
	CXXDFLAGS += -pg
	CDFLAGS   += -pg
	ASDFLAGS  += -pg
	LDDFLAGS  += -pg
endif

ifeq "$(IsHosted)" "True"
	CXXDFLAGS  += -D_IS_HOSTED
	CDFLAGS    += -D_IS_HOSTED
	ASDFLAGS   += -D_IS_HOSTED
endif

ifeq "$(HasConfig)" "True"
	CXXDFLAGS  += -DHAVE_CONFIG_H
	CDFLAGS    += -DHAVE_CONFIG_H
	ASDFLAGS   += -DHAVE_CONFIG_H
endif

ifeq "$(SYSTEM)" "plugin"
	CXXDFLAGS += -fpie
	CDFLAGS   += -fpie
	ASDFLAGS  += -fpie
	LDDFLAGS  += -fpie
endif

## Flags
LDFLAGS  = $(LDEFLAGS) $(LDAFLAGS)  $(LDDFLAGS) $(LDPFLAGS) $(LDOFLAGS) -L$(ldScriptsDir) -T $(LDSCRIPT)
CFLAGS   = $(CAFLAGS) $(COFLAGS) $(CDFLAGS) $(CPFLAGS) $(CEFLAGS)
ASFLAGS   = $(ASAFLAGS) $(ASOFLAGS) $(ASDFLAGS) $(ASPFLAGS) $(ASEFLAGS)
CXXFLAGS = $(CXXAFLAGS) $(CXXOFLAGS) $(CXXDFLAGS) $(CXXPFLAGS) $(CXXEFLAGS)
