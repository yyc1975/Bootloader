#
# tools/make/init.mk
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
# $Rev:: 1888          $:  Revision of last commit
# $Author:: yann.gaude $:  Author of last commit
# $Date:: 2011-06-23 1#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

# Scripts are made for bash
SHELL=bash

# disable Make's built-in imlpicit rules (for speed)
.SUFFIXES:

# Fill FRAMEWORK variable if no value has been set
ifndef FRAMEWORK
FRAMEWORK = NO_FWK
endif

# ----------------------------------------------------------------------------
# Cygwin pathes
CYGWIN=$(shell if cygpath --version >/dev/null 2>&1 ; then echo "True"; fi)
ifeq "$(CYGWIN)" "True"
	buildDir 	:= $(subst C:, /cygdrive/c, $(subst \,/,$(buildDir)))
	toolsDir 	:= $(subst C:, /cygdrive/c, $(subst \,/,$(toolsDir)))
endif

makeDir      = $(toolsDir)/make
ifndef
linkDir      = $(rootDir)/link
endif
libcDir      = $(rootDir)/lib/libc
gdbDir       = $(toolsDir)/gdb
templatesDir = $(toolsDir)/templates
docsDir      = $(toolsDir)/docs

include $(makeDir)/macros.mk

include $(makeDir)/vars.mk

include $(makeDir)/cmds.mk

all: $(TARGET)
ifeq "$(DebugEnabled)" "True"
	@echo "** WARNING: Target generated with debug information **"
endif
ifeq "$(AllowDeprecated)" "True"
	@echo "** WARNING: Deprecated macros are allowed **"
endif

include $(makeDir)/files.mk

include $(makeDir)/rules.mk

include $(makeDir)/targets.mk
