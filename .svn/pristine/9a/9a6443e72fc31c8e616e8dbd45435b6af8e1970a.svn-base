#
# tools/make/targets.mk
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
# $Rev:: 1646          $:  Revision of last commit
# $Author:: gregory.ro#$:  Author of last commit
# $Date:: 2011-04-14 1#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

.PHONY: build
build: $(OBJS)

.PHONY: strip
strip: $(TARGET_NAME).stripped

.PHONY: rebuild
rebuild: clean $(TARGET)

.PHONY: debug-gui
debug-gui: $(buildDir)/gdbinit $(TARGET_NAME).elf
	$(Q)$(TERMINAL) --geometry=80x50 -e "$(GDB)tui -x $(buildDir)/gdbinit $(buildDir)/$(TARGET)"

.PHONY: debug
debug: $(buildDir)/gdbinit $(TARGET_NAME).elf
	$(Q)$(GDB) -x $(buildDir)/gdbinit $(buildDir)/$(TARGET_NAME).elf

.PHONY: autodebug
autodebug: $(buildDir)/gdbinit $(TARGET_NAME).elf

.PHONY: clean
clean:
	@echo "-- CLEAN"
	$(Q)rm -f $(patsubst %, $(objDir)/%,$(ALLOBJS))
	$(Q)rm -f $(patsubst %, $(depDir)/%,$(DEPS)) 
	$(Q)rm -f $(patsubst %, $(depDir)/%,$(INITDEPS)) 
	$(Q)rm -f $(depDir)/platform.d

.PHONY: distclean
distclean: clean
	@echo "-- DISTCLEAN"
	
.PHONY: rmdir
rmdir: 
	@echo "-- RMDIR"
	$(Q)rm -rf -- $(buildDir)
#	$(Q)rm -rf -- $(initDir)
	
.PHONY: dasm
dasm: $(TARGET_NAME).dasm

.PHONY: binary
binary: $(TARGET_NAME).bin

.PHONY: hex
ifeq "$(AppIsInRom)" "True"
hex: rom.hex
else
hex: rom.hex norom.hex
endif

.PHONY: cppcheck
cppcheck: $(buildDir)/cppcheck.xml

.PHONY: sloccount
sloccount: $(buildDir)/sloccount.sc

.PHONY: size
size: $(TARGET_NAME).size
	@cat $(buildDir)/$(<F)
	
.PHONY: docs
docs: docs/private/html/index.html

.PHONY: public_docs
public_docs: docs/public/html/index.html

.PHONY: cobra_docs
cobra_docs: docs/cobra/html

.PHONY: show-defines
show-defines: $(TARGET_NAME).defs
	@cat $(buildDir)/$(<F)
	
.PHONY: show-gccenv
show-gccenv: $(TARGET_NAME).gccenv
	@cat $(buildDir)/$(<F)

.PHONY: pack
pack: $(TARGET_NAME).tar.bz2

.PHONY: help
help:
	@echo "No help available"

.PHONY: show-files
show-files:
	@echo
	@echo " ** Files **"
	@echo
	@echo "  TARGET:     $(TARGET)"
	@echo "  OBJS:       $(OBJS)"
	@echo "  LIBCOBJS:   $(LIBCOBJS)"
	@echo "  INITOBJS:   $(INITOBJS)"
	@echo "  LDSCRIPTS:  $(LDSCRIPTS)"
	@echo "  INITCFILES: $(INITCFILES)"
	@echo "  INITSFILES: $(INITSFILES)"
	@echo "  INITDEPS:   $(INITDEPS)"
	@echo "  PHEADERS:   $(PHEADERS)"

.PHONY: show-config
show-config:
	@echo
	@echo " ** Configuration **"
	@echo
	@echo "  PLATFORM:         $(PLATFORM)"
	@echo "  PLATFORM_VERSION: $(PLATFORM_VERSION)"
	@echo "  SYSTEM:           $(SYSTEM)"
	@echo "  LAYOUT:           $(LAYOUT)"
	@echo "  BOARD:            $(BOARD)"
	@echo "  DebugEnabled:     $(DebugEnabled)"
	@echo "  ProfilingEnabled: $(ProfilingEnabled) (not yet implemented)"
	@echo "  EnableIRQ:        $(EnableIRQ)"
	@echo "  EnableFIQ:        $(EnableFIQ)"
	@echo "  EnableMMU:        $(EnableMMU)"
	@echo "  EnableDCache:     $(EnableDCache)"
	@echo "  EnableICache:     $(EnableICache)"
	@echo "  ArmHasDTCM:       $(ArmHasDTCM)"
	@echo "  ArmHasITCM:       $(ArmHasITCM)"
	@echo "  UseHighVectors    $(UseHighVectors)"
	@echo "  EnableUart:       $(EnableUart)"
	@echo "  AllowDeprecated:  $(AllowDeprecated)"
	@echo "  EnableScrambling: $(EnableScrambling)"
	@echo "  AppIsInRom:       $(AppIsInRom)"
	@echo "  SCRAMBLED_NAME:   $(SCRAMBLED_NAME)"

.PHONY: show-pathes
show-pathes:
	@echo
	@echo " ** Pathes **"
	@echo
	@echo "  buildDir: $(buildDir)"
	@echo "  rootDir:  $(rootDir)"
	@echo "  toolsDir: $(toolsDir)"
	@echo "  includeDir: $(includeDir)"
	@echo "  initDir: $(initDir)"
	@echo "  libDir: $(libDir)"
	@echo "  linkDir: $(linkDir)"
	@echo "  PWD:      $(PWD)"

.PHONY: show-targetname
show-targetname:
	@echo -n $(TARGET_NAME)

.PHONY: show-builddir
show-builddir:
	@echo -n $(buildDir)

version:
	@echo
	@echo "** Versions **"
	@echo "  Project Version:  $(VERSION)"
	@echo "  Tools Version:    $(TOOLS_VERSION)"
	@echo "  Include Version:  $(INC_VERSION)"
	@echo "  Init Version:     $(INIT_VERSION)"
	@echo "  Library Version:  $(LIB_VERSION)"
	@echo "  Link Version:     $(LINK_VERSION)"
	@echo "  Make version:     $(shell $(MAKE) --version 2>/dev/null | sed -n "s/.*\(3\.\([0-9]*\)\).*/\1/p")"
	@echo "  GCC version:      $(shell $(CC) --version 2>/dev/null | sed -n "s/.*\([0-9]\.[0-9]*\.[0-9]*\).*/\1/p")"
	@echo "  SVN version:      $(shell svn --version 2>/dev/null | sed -n "s/.*\([0-9]\.[0-9]*\.[0-9]*\).*/\1/p")"

FORCE: