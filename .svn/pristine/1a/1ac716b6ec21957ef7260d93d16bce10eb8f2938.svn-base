#
# tools/make/vars.mk
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
# $Rev:: 3321          $:  Revision of last commit
# $Author:: jeremy.bro#$:  Author of last commit
# $Date:: 2014-04-02 0#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

# ==============================================================================

ifeq "$(LAYOUT)" "irom"
	AppIsInRom = True
else
	AppIsInRom = False
endif

## Final target name with extension
ifeq "$(TARGET_TYPE)" "bin"
	TARGET = $(TARGET_NAME).elf
	HasConfig = True
	CONFIG_H = $(buildDir)/config.h
endif
ifeq "$(TARGET_TYPE)" "sim"

	BOARD = simulator

	ifeq "$(AppIsInRom)" "True"
		TARGET = rom.hex
	else
		TARGET = rom.hex norom.hex
	endif

	SIMULATION=1
	ifndef EnableUart
		EnableUart = False
	endif
	ifndef EnableGpio
		EnableGpio = True
	endif
	HasConfig = True
	CONFIG_H = $(buildDir)/config.h
else
	ifndef EnableUart
		EnableUart = True
	endif
	ifndef EnableGpio
		EnableGpio = False
	endif
	SIMULATION=0
endif
ifeq "$(TARGET_TYPE)" "archive"
	TARGET = lib$(TARGET_NAME).a
#	HasConfig = False
	HasConfig = True
	CONFIG_H = $(buildDir)/config.h
	UseLibCobra = False
	UseLibDev = False
	UseLibC = False
endif

ifeq "$(SYSTEM)" "plugin"
	UseLibCobra = False
	UseLibDev = False
	UseLibC = False
endif

# ==============================================================================
# Version number
ifdef SVN_REVISION
	VERSION := $(VERSION_MAJOR).$(VERSION_MINOR)

	ifdef VERSION_PATCH
		VERSION := $(VERSION).$(VERSION_PATCH)
	endif

	VERSION := $(VERSION)-$(subst /,_,$(SVN_BRANCH))-rev$(SVN_REVISION)

	ifeq "$(SVN_IS_DIRTY)" "True"
		VERSION := $(VERSION)-dirty
	endif
else
	VERSION := $(VERSION_MAJOR).$(VERSION_MINOR)

	ifdef VERSION_PATCH
		VERSION := $(VERSION).$(VERSION_PATCH)
	endif
endif

# Tools Version number
ifdef TOOLS_SVN_REVISION
	TOOLS_VERSION := $(TOOLS_VERSION_MAJOR).$(TOOLS_VERSION_MINOR)

	ifdef TOOLS_VERSION_PATCH
		TOOLS_VERSION := $(TOOLS_VERSION).$(TOOLS_VERSION_PATCH)
	endif

	ifdef TOOLS_VERSION_EXT
		TOOLS_VERSION := $(TOOLS_VERSION).$(TOOLS_VERSION_EXT)
	endif

	TOOLS_VERSION := $(TOOLS_VERSION)-$(subst /,_,$(TOOLS_SVN_BRANCH))-rev$(TOOLS_SVN_REVISION)

	ifeq "$(TOOLS_SVN_IS_DIRTY)" "True"
		TOOLS_VERSION := $(TOOLS_VERSION)-dirty
	endif
else
	TOOLS_VERSION := $(TOOLS_VERSION_MAJOR).$(TOOLS_VERSION_MINOR)

	ifdef TOOLS_VERSION_PATCH
		TOOLS_VERSION := $(TOOLS_VERSION).$(TOOLS_VERSION_PATCH)
	endif

	ifdef TOOLS_VERSION_EXT
		TOOLS_VERSION := $(TOOLS_VERSION).$(TOOLS_VERSION_EXT)
	endif
endif

# Include Version number
ifdef INC_SVN_REVISION
	INC_VERSION := $(INC_VERSION_MAJOR).$(INC_VERSION_MINOR)

	ifdef INC_VERSION_PATCH
		INC_VERSION := $(INC_VERSION).$(INC_VERSION_PATCH)
	endif

	ifdef INC_VERSION_EXT
		INC_VERSION := $(INC_VERSION).$(INC_VERSION_EXT)
	endif

	INC_VERSION := $(INC_VERSION)-$(subst /,_,$(INC_SVN_BRANCH))-rev$(INC_SVN_REVISION)

	ifeq "$(INC_SVN_IS_DIRTY)" "True"
		INC_VERSION := $(INC_VERSION)-dirty
	endif
else
	INC_VERSION := $(INC_VERSION_MAJOR).$(INC_VERSION_MINOR)

	ifdef INC_VERSION_PATCH
		INC_VERSION := $(INC_VERSION).$(INC_VERSION_PATCH)
	endif

	ifdef INC_VERSION_EXT
		INC_VERSION := $(INC_VERSION).$(INC_VERSION_EXT)
	endif
endif

# Init Version number
ifdef INIT_SVN_REVISION
	INIT_VERSION := $(INIT_VERSION_MAJOR).$(INIT_VERSION_MINOR)
	ifdef INIT_VERSION_PATCH
		INIT_VERSION := $(INIT_VERSION).$(INIT_VERSION_PATCH)
	endif

	ifdef INIT_VERSION_EXT
		INIT_VERSION := $(INIT_VERSION).$(INIT_VERSION_EXT)
	endif

	INIT_VERSION := $(INIT_VERSION)-$(subst /,_,$(INIT_SVN_BRANCH))-rev$(INIT_SVN_REVISION)
	ifeq "$(INIT_SVN_IS_DIRTY)" "True"
		INIT_VERSION := $(INIT_VERSION)-dirty
	endif
else
	INIT_VERSION := $(INIT_VERSION_MAJOR).$(INIT_VERSION_MINOR)

	ifdef INIT_VERSION_PATCH
		INIT_VERSION := $(INIT_VERSION).$(INIT_VERSION_PATCH)
	endif

	ifdef INIT_VERSION_EXT
		INIT_VERSION := $(INIT_VERSION).$(INIT_VERSION_EXT)
	endif
endif

# Library Version number
ifdef LIB_SVN_REVISION
	LIB_VERSION := $(LIB_VERSION_MAJOR).$(LIB_VERSION_MINOR)
	ifdef LIB_VERSION_PATCH
		LIB_VERSION := $(LIB_VERSION).$(LIB_VERSION_PATCH)
	endif

	ifdef LIB_VERSION_EXT
		LIB_VERSION := $(LIB_VERSION).$(LIB_VERSION_EXT)
	endif

	LIB_VERSION := $(LIB_VERSION)-$(subst /,_,$(LIB_SVN_BRANCH))-rev$(LIB_SVN_REVISION)
	ifeq "$(LIB_SVN_IS_DIRTY)" "True"
		LIB_VERSION := $(LIB_VERSION)-dirty
	endif
else
	LIB_VERSION := $(LIB_VERSION_MAJOR).$(LIB_VERSION_MINOR)

	ifdef LIB_VERSION_PATCH
		LIB_VERSION := $(LIB_VERSION).$(LIB_VERSION_PATCH)
	endif

	ifdef LIB_VERSION_EXT
		LIB_VERSION := $(LIB_VERSION).$(LIB_VERSION_EXT)
	endif
endif

# Link Version number
ifdef LINK_SVN_REVISION
	LINK_VERSION := $(LINK_VERSION_MAJOR).$(LINK_VERSION_MINOR)
	ifdef LINK_VERSION_PATCH
		LINK_VERSION := $(LINK_VERSION).$(LINK_VERSION_PATCH)
	endif

	ifdef LINK_VERSION_EXT
		LINK_VERSION := $(LINK_VERSION).$(LINK_VERSION_EXT)
	endif

	LINK_VERSION := $(LINK_VERSION)-$(subst /,_,$(LINK_SVN_BRANCH))-rev$(LINK_SVN_REVISION)
	ifeq "$(LINK_SVN_IS_DIRTY)" "True"
		LINK_VERSION := $(LINK_VERSION)-dirty
	endif
else
	LINK_VERSION := $(LINK_VERSION_MAJOR).$(LINK_VERSION_MINOR)

	ifdef LINK_VERSION_PATCH
		LINK_VERSION := $(LINK_VERSION).$(LINK_VERSION_PATCH)
	endif

	ifdef LINK_VERSION_EXT
		LINK_VERSION := $(LINK_VERSION).$(LINK_VERSION_EXT)
	endif
endif


# ==============================================================================
## Check options

ifndef buildDir
	$(error Set the build directory buildDir)
endif

ifneq "$(TARGET_TYPE)" "archive"
	ifndef PLATFORM
		$(error Set the platform PLATFORM)
	endif
	ifndef SYSTEM
		$(error Set the system SYSTEM)
	endif
	ifndef LAYOUT
		$(error Set the layout LAYOUT)
	endif
endif

# ==============================================================================
## Default options values

ifndef BOARD
BOARD = emulator_ig1
endif

ifndef PLATFORM_VERSION
ifeq "$(BOARD)" "simulator"
PLATFORM_VERSION = top_lvl5
else
ifeq "$(BOARD)" "emulator_ig1"
PLATFORM_VERSION = top_lvl4
else
PLATFORM_VERSION = top_lvl5
endif
endif
endif

ifndef UseHighVectors
UseHighVectors = False
endif

ifndef EnableScrambling
EnableScrambling = True
endif

ifndef SCRAMBLED_NAME
SCRAMBLED_NAME = ts3ga32768x32m32_c050228
endif

ifndef AllowDeprecated
AllowDeprecated = True
endif

ifndef UseLibCobra
UseLibCobra = True
endif

ifndef UseLibDev
UseLibDev = False
endif

ifndef UseLibC
UseLibC = True
endif

ifndef DebugEnabled
DebugEnabled = True
endif

ifndef ProfilingEnabled
ProfilingEnabled = False
endif

ifndef EnableIRQ
EnableIRQ = False
endif

ifndef EnableFIQ
EnableFIQ = False
endif

ifndef EnableDCache
EnableDCache = False
endif

ifndef EnableICache
EnableICache = False
endif

ifndef ArmHasDTCM
ArmHasDTCM = True
endif

ifndef ArmHasITCM
ArmHasITCM = True
endif

ifndef EnableMMU
ifeq "$(EnableDCache)" "True"
EnableMMU = True
endif
endif

ifndef UseAttributeIRQ
UseAttributeIRQ = False
endif

# ==============================================================================
## Set defines

PFM_SUFFIX = $(shell echo $(PLATFORM) | tr '[:lower:]' '[:upper:]')

ifeq "$(UseHighVectors)" "True"
USE_HIGH_VECTORS = 1
else
USE_HIGH_VECTORS = 0
endif

ifeq "$(AllowDeprecated)" "True"
	ALLOW_DEPRECATED_MACROS = 1
else
	ALLOW_DEPRECATED_MACROS = 0
endif

ifeq "$(UseGenericName)" "True"
	USE_GENERIC_NAME = 1
else
	USE_GENERIC_NAME = 0
endif

ifeq "$(UseAttributeIRQ)" "True"
	USE_ATTRIBUTE_IRQ = 1
else
	USE_ATTRIBUTE_IRQ = 0
endif

ifeq "$(EnableGpio)" "True"
	ENABLE_GPIO=1
else
	ENABLE_GPIO=0
endif

ifeq "$(EnableUart)" "True"
	ENABLE_UART=1
else
	ENABLE_UART=0
endif

ifeq "$(EnableIRQ)" "True"
	ENABLE_IRQ=1
else
	ENABLE_IRQ=0
endif
ifeq "$(EnableFIQ)" "True"
	ENABLE_FIQ=1
else
	ENABLE_FIQ=0
endif
ifeq "$(EnableMMU)" "True"
	ENABLE_MMU=1
else
	ENABLE_MMU=0
endif
ifeq "$(EnableDCache)" "True"
	ENABLE_DCACHE=1
else
	ENABLE_DCACHE=0
endif
ifeq "$(EnableICache)" "True"
	ENABLE_ICACHE=1
else
	ENABLE_ICACHE=0
endif
ifeq "$(ArmHasDTCM)" "True"
	ARM_HAS_DTCM=1
else
	ARM_HAS_DTCM=0
endif
ifeq "$(ArmHasITCM)" "True"
	ARM_HAS_ITCM=1
else
	ARM_HAS_ITCM=0
endif

# ============================================================================
## Pathes

PWD = $(strip $(shell pwd))

objDir = $(buildDir)/objs
depDir = $(buildDir)/deps

ifeq "$(IsHosted)" "True"
	PROJECT_CONFIG := $(PROJECT_CONFIG)-hosted
endif

ifeq "$(IsHosted)" "True"
HOSTED = -hosted
else
HOSTED = 
endif

# Link scripts

ldScriptsSrcDir = $(linkDir)/$(PLATFORM)
ldScriptsDir    = $(buildDir)/link

LDSCRIPT = $(ldScriptsDir)/$(SYSTEM)$(HOSTED).ld

LDSCRIPTS  =  $(SYSTEM)$(HOSTED).ld
LDSCRIPTS +=  layout.inc
LDSCRIPTS +=  memories.inc
ifeq ($(LAYOUT),framework)
LDSCRIPTS +=  import.inc
endif

# Includes
incDirs += $(include) $(include)/$(PLATFORM)
incDirs += $(buildDir)

# Libraries
libDirs += $(rootDir)/lib

# ---------------------------------------------------------------------------
# To put more focus on warnings, be less verbose as default
# Use 'make V=1' to see the full commands

ifdef V
  ifeq ("$(origin V)", "command line")
    VERBOSE = $(V)
  endif
endif
ifndef VERBOSE
  VERBOSE = 0
endif

ifeq ($(VERBOSE),1)
  quiet = @
  Q =
else
  quiet=
  Q = @
endif

export quiet Q VERBOSE
