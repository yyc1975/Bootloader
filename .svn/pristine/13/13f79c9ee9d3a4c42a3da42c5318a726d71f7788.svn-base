#
# Makefile
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
# $Rev:: 3             $:  Revision of last commit
# $Author:: gregory.ro#$:  Author of last commit
# $Date:: 2010-05-28 2#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

PROJECT         = template
PROJECT_VERSION = 1.0
PROJECT_RELEASE = -trunk

CROSS_COMPILE = arm-none-eabi-

# ------------------------------------------------------------------------------
# POJECT CONFIGURATION
# ------------------------------------------------------------------------------

# final target will be:
#   - lib$(TARGET_NAME).a if TARGET_TYPE = archive
#   - $(TARGET_NAME).elf if TARGET_TYPE = bin

TARGET_NAME = $(PROJECT)-$(PROJECT_VERSION)$(PROJECT_RELEASE)
TARGET_TYPE = bin

# Options could be define in Eclipse project
ifndef ECLIPSE
# ---------------------------------------------
# OPTIONS
# ---------------------------------------------
PROJECT_CONFIG  = debug

# Platform: defines the platform
#  - jibe  -- jibe
#  - londa -- londa
PLATFORM=londa

# System: defines application architecture
#  - jtag-ram -- All is loaded by jtag, only one section for code and data
#  - jtag-rom -- All is loaded by jtag, two different sections for code and data
SYSTEM=jtag-ram

# Layout:
#  - sdram -- All executed in sdram (Bypass) !!Jibe Only!!
#  - sram  -- All executed in internal sram
LAYOUT=sram

## Enable debug flags
DebugEnabled = True

## Enable IRQ
EnableIRQ = True
## Enable FIQ
EnableFIQ = True
## Enable DCache
EnableDCache = True
## Enable ICache
EnableICache = True
## Implement DTCM
ArmHasDTCM = True
## Implement ITCM
ArmHasITCM = True

endif # ifndef ECLIPSE

# JTAG Probe Configuration
#  - rvi -- Real View Ice
#  - ash -- Ashling
JtagProbe = rvi
RemoteHost = 10.201.0.108

# Linked libraries (default already included)
LIBS =

# ---------------------------------------------
# PATHS 
# ---------------------------------------------

# Where to find headers
incDirs = src/include
# Where to find libs
libDirs =
# Where to find sources (you must includes sub-directories)
srcDirs = src
# Where to put init files (link scripts and startup code)
initDir = init

# Build directory
buildDir := build/$(PLATFORM)-$(SYSTEM)/$(LAYOUT)/$(PROJECT_CONFIG)
# Where to find tools
toolsDir = $(rootDir)/tools

# ------------------------------------------------------------------------------
# !!DO NOT MODIFY!!
# ------------------------------------------------------------------------------
rootDir  = $(shell pwd)
include $(toolsDir)/make/init.mk
