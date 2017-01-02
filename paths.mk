#
# paths.mk
#
# Copyright (c) 2014, Maxim Integrated Products
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Maxim Integrated Products nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY MAXIM INTEGRATED PRODUCTS ''AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL MAXIM INTEGRATED PRODUCTS BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

# [INTERNAL] ===================================================================
#
# Created on: Aug 21, 2014
#     Author: Yann G. <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords
# $Rev:: 368           $:  Revision of last commit
# $Author:: yann.gaude $:  Author of last commit
# $Date:: 2010-10-21 1#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

## Where to find tools
toolsDir = $(rootDir)/tools

## Where to find external tools
exttoolsDir = $(rootDir)/ext_tools

## Where to find External Drivers
extdriversDir = $(rootDir)/ext_drivers

## Where to find libs
## $(rootDir)/lib is included by default
libDirs = $(rootDir)/lib
libDirs += $(rootDir)/lib/libucl/$(CPU)
libDirs += $(rootDir)/lib/libc/$(CPU)

## This varaible is defined to retrieve lib version only
libDir = $(rootDir)/lib

## Export directory
exportDir = $(rootDir)/export

## Where to find COBRA headers
includeDirs = $(rootDir)/include

## Where to find headers of miscellaneous elements
## Where to put init files (startup code)
initDir = $(rootDir)/init

## Where to find link files (scripts)
linkDir = $(rootDir)/link

## Build directory
buildDir = $(rootDir)/build/$(PLATFORM)-$(SYSTEM)-$(LAYOUT)-$(PROJECT_CONFIG)

# Default source list
# Source base
srcbase = $(rootDir)/src

# EOF
