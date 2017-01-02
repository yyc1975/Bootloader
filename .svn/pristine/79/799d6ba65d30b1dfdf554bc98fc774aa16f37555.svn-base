#
# Makefile
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
# Created on: Jun 14, 2012
#     Author: Yann G. <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords
# $Rev:: $: Revision of last commit
# $Author:: $: Author of last commit
# $Date:: $: Date of last commit
#
# [/INTERNAL] ==================================================================

# ------------------------------------------------------------------------------
# !!DO NOT MODIFY!!
# ------------------------------------------------------------------------------
rootDir = .

# ------------------------------------------------------------------------------
# CONFIGURABLE PART
# ------------------------------------------------------------------------------
include $(rootDir)/framework_config.mk

# Override with full path if necessary
include $(rootDir)/compilation.mk

# ---------------------------------------------
# OPTIONS
# ---------------------------------------------
include $(rootDir)/platform.mk

include $(rootDir)/compilation_flags.mk

include $(rootDir)/libraries.mk

# ---------------------------------------------
# PROJECT PATHS 
# ---------------------------------------------
include $(rootDir)/paths.mk

## Where to find headers and sources of external drivers
include $(rootDir)/ext_drv.mk

## Gathering of where to find headers and sources
include $(rootDir)/sources.mk

# ---------------------------------------------
# OPTIONS
# ---------------------------------------------
include $(rootDir)/compilation_flags.mk
include $(exportDir)/$(SECUREROMCODEREF)_version.export

# ------------------------------------------------------------------------------
# !!DO NOT MODIFY!!
# ------------------------------------------------------------------------------
# Cygwin pathes
CYGWIN=$(shell if cygpath --version >/dev/null 2>&1 ; then echo "True"; fi)
ifeq "$(CYGWIN)" "True"
	buildDir 	:= $(subst C:, /cygdrive/c, $(subst \,/,$(buildDir)))
	toolsDir 	:= $(subst C:, /cygdrive/c, $(subst \,/,$(toolsDir)))
endif
include $(rootDir)/VERSION.mk
include $(includeDirs)/VERSION.mk
include $(libDir)/VERSION.mk
include $(linkDir)/VERSION.mk
include $(initDir)/VERSION.mk
include $(toolsDir)/make/init.mk

# ------------------------------------------------------------------------------
# Framework specific
# ------------------------------------------------------------------------------
image: all
	@echo " ----> Create SRecord file"
	$(Q)$(OBJCOPY) -O srec --srec-forceS3 --srec-len=128 $(buildDir)/$(TARGET_NAME).elf $(buildDir)/$(TARGET_NAME).s19
	@echo " ----> Done !"
	@echo ""

dasm: all
	@echo "-----> Create DASM file"
	$(Q)$(OBJDUMP) -D -S $(buildDir)/$(TARGET_NAME).elf > $(buildDir)/$(TARGET_NAME).dasm
	@echo " ----> Done !"
	@echo ""

binary: dasm
	@echo "-----> Create Binary file"
	$(Q)$(OBJCOPY) -O binary $(buildDir)/$(TARGET_NAME).elf $(buildDir)/$(TARGET_NAME).bin
	@echo " ----> Done !"
	@echo ""

sla.notscrambled.hex: binary
	@echo "Creating .hex file"
	$(Q)$(BIN2VHX) $(BIN2VHX_FLAGS) < $(buildDir)/$(TARGET_NAME).bin > $(buildDir)/sla.notscrambled.hex
	@echo " ----> Done !"
	@echo ""

include $(rootDir)/framework_targets.mk

# EOF
