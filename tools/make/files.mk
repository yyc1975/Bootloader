#
# tools/make/files.mk
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
# $Rev:: 1351          $:  Revision of last commit
# $Author:: james.cott#$:  Author of last commit
# $Date:: 2011-03-09 0#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

ifeq "$(UseLibCobra)" "True"
	srcDirs += $(initDir)/$(CPU)
	srcDirs += $(initDir)/$(PLATFORM)
endif

ifeq "$(UseLibDev)" "True"
	srcDirs += $(initDir)/dev
endif

ifeq "$(UseLibC)" "True"
	srcDirs += $(libDir)/$(CPU)/libc
endif

ifeq "$(TARGET_TYPE)" "archive"
	publicInc = $(patsubst %, %/include,$(filter src/%,$(srcDirs)))
	incDirs += $(publicInc)
endif

vpath	%.c		$(srcDirs) $(initDir) $(libcDir)
vpath	%.S		$(srcDirs) $(initDir)
vpath	%.cpp	$(srcDirs)
vpath 	%.h		$(srcDirs) $(incDirs)
vpath 	%.ld	$(ldScriptsDir)
vpath 	%.inc	$(ldScriptsDir)
vpath	%.o		$(objDir)
vpath	%.d		$(depDir)
vpath	%.dx	$(depDir)
vpath	%.a		$(buildDir) $(libDirs)
vpath	%.elf	$(buildDir)
vpath	%.bin	$(buildDir)
vpath	%.hex	$(buildDir)
vpath	%.size	$(buildDir)
vpath	%.dasm	$(buildDir)
vpath	%.dox	$(rootDir)/docs

## -----------------------------------------------------------------------------
# Sources
MKFILES   = $(abspath Makefile) $(wildcard $(makeDir)/*.mk)
DOXFILES  = $(wildcard $(rootDir)/docs/*.dox)
HFILES    = $(sort $(foreach DIR, $(incDirs), $(notdir $(wildcard $(DIR)/*.h))))
CFILES   += $(sort $(foreach DIR, $(srcDirs), $(notdir $(wildcard $(DIR)/*.c))))
CPPFILES  = $(sort $(foreach DIR, $(srcDirs), $(notdir $(wildcard $(DIR)/*.cpp))))
SFILES    = $(sort $(foreach DIR, $(srcDirs), $(notdir $(wildcard $(DIR)/*.S))))

# Objects
OBJS += $(CFILES:.c=.o)
OBJS += $(CPPFILES:.cpp=.o)
OBJS += $(SFILES:.S=.o)

# Dependencies
DEPS += $(SFILES:.S=.d)
DEPS += $(CFILES:.c=.d)
DEPS += $(CPPFILES:.cpp=.d)

$(foreach DEP, $(DEPS), $(eval -include $(depDir)/$(DEP)))

ALLOBJS := $(OBJS)

## -----------------------------------------------------------------------------
# Public header files for libraries
PHFILES  = $(foreach DIR, $(publicInc), $(notdir $(wildcard $(DIR)/*.h)))
PHEADERS = $(patsubst %, $(buildDir)/include/%,$(PHFILES))
