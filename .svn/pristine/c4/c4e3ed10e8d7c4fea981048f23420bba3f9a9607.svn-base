#
# framework_targets.mk
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
# Created on: Oct 01, 2012
# Author: Yann G. <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords (need to set the keyword property)
# $Revision:: $: Revision of last commit
# $Author:: $: Author of last commit
# $Date:: $: Date of last commit
# [/INTERNAL] --------------------------------------------------------------

CASIGNBUILD_PATH=$(exttoolsDir)/ca_sign_build
DIGIT_KEY=ecdsa_file
CRK_FILE=crk_ecdsa_512bits_test1.key
ALGO_ROM=ecdsa

ifeq "$(CYGWIN)" "True"
  CASIGNBIN_PATH=$(CASIGNBUILD_PATH)/bin/cygwin
  CASIGNBUILD_EXE=ca_sign_build.exe
  LIBUCL=libucl.dll
else
  CASIGNBIN_PATH=$(CASIGNBUILD_PATH)/bin/linux
  CASIGNBUILD_EXE=ca_sign_build
  LIBUCL=libucl.so.2.4.1
endif

JUMP_ADDR=$(subst 0x,,$(shell grep -e __reset -w $(buildDir)/$(TARGET_NAME).map | grep -v reset.o | awk '{printf $$1}'))
LOAD_ADDR=$(subst 0x,,$(shell grep -e __sla_load_addr -w $(buildDir)/$(TARGET_NAME).map | awk '{printf $$1}'))
VERSION_ROM=$(shell printf "%02x" $($(SECUREROMCODEREF_UPPER)_VERSION_MAJOR))$(shell printf "%02x" $($(SECUREROMCODEREF_UPPER)_VERSION_MINOR))$(shell printf "%04x" $($(SECUREROMCODEREF_UPPER)_VERSION_PATCH))

casign_pre: binary
	@echo " ----> Entering Secure ROM code formatting process"
ifeq ($(CASIGNBUILD_PATH),)
	@echo "** CAUTION : No path defined to ca_sign_build application **"
endif
	@if [ -f $(CASIGNBUILD_PATH)/ca_sign_build.ini ] ; then echo " -----> Reuse already present ini file" ; else cp -f $(CASIGNBUILD_PATH)/data/ca_sign_build.ini $(CASIGNBUILD_PATH)/ ; echo " -----> Copy ini file from default location"; fi
	@if [ -f $(CASIGNBUILD_PATH)/$(CRK_FILE) ] ; then echo " -----> Reuse already present key file";	else cp -f $(CASIGNBUILD_PATH)/data/$(CRK_FILE) $(CASIGNBUILD_PATH)/ ; echo " -----> Copy key file from default location" ; fi
	@if [ -f $(CASIGNBUILD_PATH)/$(CASIGNBUILD_EXE) ] ; then echo " -----> Reuse already present application file" ; else cp -f $(CASIGNBIN_PATH)/$(CASIGNBUILD_EXE) $(CASIGNBUILD_PATH)/ ; echo " -----> Copy application file from default location" ; fi
	@if [ -f $(CASIGNBUILD_PATH)/$(LIBUCL) ] ; then echo " -----> Reuse already present LibUCL" ; else cp -f $(CASIGNBIN_PATH)/$(LIBUCL) $(CASIGNBUILD_PATH)/ ; echo " -----> Copy LibUCL file from default location" ; fi

casign: casign_pre
	@echo " -----> Retrieve generated binary file"
	@cp -f $(buildDir)/$(TARGET_NAME).bin $(CASIGNBUILD_PATH)/
	@echo " -----> Process binary file"
	cd $(CASIGNBUILD_PATH) ; ./$(CASIGNBUILD_EXE) algo=$(ALGO_ROM) $(DIGIT_KEY)=$(CRK_FILE) ca=$(TARGET_NAME).bin sca=$(TARGET_NAME).sbin \
	load_address=$(LOAD_ADDR) \
	jump_address=$(JUMP_ADDR) \
	arguments= \
	version=$(VERSION_ROM) \
	application_version=$(shell printf "%02x" $(VERSION_MAJOR))$(shell printf "%02x" $(VERSION_MINOR))$(shell printf "%04x" $(VERSION_PATCH)) \
	verbose=no
	@echo ""
	@echo " ----> Move signed binary to build folder"
	@cp -f $(CASIGNBUILD_PATH)/$(TARGET_NAME).sbin $(buildDir)/
	@echo " ----> Change name of signed binary for SEGGER's flasher"
	@cp -f $(CASIGNBUILD_PATH)/$(TARGET_NAME).sbin $(buildDir)/$(TARGET_NAME)_for_segger.bin
	@echo " ----> Remove temporary files"
	@rm $(CASIGNBUILD_PATH)/$(TARGET_NAME).bin $(CASIGNBUILD_PATH)/$(TARGET_NAME).sbin
	@echo " ----> And now, create SRecord file"
	@cd $(buildDir) ; $(OBJCOPY) -I binary -O srec --srec-forceS3 --srec-len=128 $(TARGET_NAME).sbin $(TARGET_NAME)_sec.s19 --adjust-vma $(STORAGE_START)
	@echo "  ---> Done !"
	@echo "" 

# EOF
