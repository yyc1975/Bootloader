#
# tools/make/rules.mk
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

## Directories -----------------------------------------------------------------
$(depDir)/.dir: $(buildDir)/.dir
	@echo "-- MKDIR   $(@D)"
	$(Q)mkdir -p $(@D)
	$(Q)touch $@

$(buildDir)/include/.dir: $(buildDir)/.dir
	@echo "-- MKDIR   $(@D)"
	$(Q)mkdir -p $(@D)
	$(Q)touch $@

$(objDir)/.dir: $(buildDir)/.dir
	@echo "-- MKDIR   $(@D)"
	$(Q)mkdir -p $(@D)
	$(Q)touch $@

$(buildDir)/.dir:
	@echo "-- MKDIR   $(@D)"
	$(Q)mkdir -p $(@D)
	$(Q)touch $@

$(ldScriptsDir)/.dir: $(buildDir)/.dir
	@echo "-- MKDIR   $(@D)"
	$(Q)mkdir -p $(@D)
	$(Q)touch $@
	
$(buildDir)/sloccount/.dir: $(buildDir)/.dir
	@echo "-- MKDIR   $(@D)"
	$(Q)mkdir -p $(@D)
	$(Q)touch $@

## Dependencies ----------------------------------------------------------------

%.ld: $(ldScriptsSrcDir)/%.ld.S $(ldScriptsDir)/.dir
	@echo "-- CPP     $(@F)"
	$(Q)$(CPP) -P -D__ASSEMBLER__ $(CPPFLAGS) $(patsubst %, -I%,$(incDirs)) -o $(ldScriptsDir)/$@ $<

memories.inc: $(ldScriptsSrcDir)/memories.inc $(ldScriptsDir)/.dir
	@echo "-- CP      $(@F)"
	$(Q)if [ -f $(ldScriptsDir)/$@ ] ; then cp -- $(ldScriptsDir)/$@ $(ldScriptsDir)/$@.orig ; fi
	$(Q)$(CPP) -P -D__ASSEMBLER__ $(CPPFLAGS) $(patsubst %, -I%,$(incDirs)) -o $(ldScriptsDir)/$@ $<

ifeq ($(LAYOUT),framework)
ifeq "$(PLATFORM)" "mq55"
import.inc: $(exportDir)/angela_tags.export $(ldScriptsDir)/.dir
endif
ifeq "$(PLATFORM)" "yumen"
import.inc: $(exportDir)/lhassa_tags.export $(ldScriptsDir)/.dir
endif
ifeq "$(PLATFORM)" "jibe"
import.inc: $(exportDir)/flora_tags.export $(ldScriptsDir)/.dir
endif
	@echo "-- CP      $(@F)"
	$(Q)if [ -f $(ldScriptsDir)/$@ ] ; then cp -- $(ldScriptsDir)/$@ $(ldScriptsDir)/$@.orig ; fi
	$(Q)$(CPP) -P -D__ASSEMBLER__ $(CPPFLAGS) $(patsubst %, -I%,$(incDirs)) -o $(ldScriptsDir)/$@ $<
endif

layout.inc: $(ldScriptsSrcDir)/$(LAYOUT).inc $(ldScriptsDir)/.dir
	@echo "-- CP      $(@F)"
	$(Q)if [ -f $(ldScriptsDir)/$@ ] ; then cp -- $(ldScriptsDir)/$@ $(ldScriptsDir)/$@.orig ; fi
	$(Q)$(CPP) -P -D__ASSEMBLER__ $(CPPFLAGS) $(patsubst %, -I%,$(incDirs)) -o $(ldScriptsDir)/$@ $<

$(depDir)/%.d: %.S $(CONFIG_H) $(depDir)/.dir $(MKFILES)
	@echo "-- DEP     $(@F)"
	$(Q)$(CC) -MM $(CAFLAGS) $(patsubst %, -I%,$(incDirs)) $< > $@.$$$$; 	\
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; 	\
		rm -f $@.$$$$

$(depDir)/%.d: %.c $(CONFIG_H) $(depDir)/.dir $(MKFILES)
	@echo "-- DEP     $(@F)"
	$(Q)$(CC) -MM $(CAFLAGS) $(patsubst %, -I%,$(incDirs)) $< > $@.$$$$; 	\
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; 	\
		rm -f $@.$$$$

$(depDir)/%.d: %.cpp $(CONFIG_H) $(depDir)/.dir $(MKFILES)
	@echo "-- DEP     $(@F)"
	$(Q)$(CXX) -MM $(CAFLAGS) $(patsubst %, -I%,$(incDirs)) $< > $@.$$$$; 	\
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; 	\
		rm -f $@.$$$$

## Objects ---------------------------------------------------------------------

%.o: %.S %.d $(objDir)/.dir
	@echo "-- AS      $@"
	$(Q)$(AS) $(ASFLAGS) 				\
		$(patsubst %, -I%,$(incDirs)) 	\
		-o $(objDir)/$(@F) $<

%.o: %.c %.d $(objDir)/.dir
	@echo "-- CC      $@"
	$(Q)$(CC) $(CFLAGS) 				\
		$(patsubst %, -I%,$(incDirs)) 	\
		-o $(objDir)/$(@F) $<

%.o: %.cpp %.d $(objDir)/.dir
	@echo "-- CXX     $@"
	$(Q)$(CXX) $(CXXFLAGS) 				\
		$(patsubst %, -I%,$(incDirs)) 	\
		-o $(objDir)/$(@F) $<

$(buildDir)/include/%.h: %.h $(buildDir)/include/.dir
	@echo "-- CP      $(@F)"
	$(Q)cp $< $(buildDir)/include/$(@F)

## Final targets ---------------------------------------------------------------

ifeq "$(AppIsInRom)" "False"
%_norom.elf: $(subst _norom,,%).elf
	@echo "-- OBJCOPY $@"
	$(Q)$(OBJCOPY) -R ".bootstrap" $(buildDir)/$(<F) $(buildDir)/$@

%_rom.elf: $(subst _rom,,%).elf
	@echo "-- OBJCOPY $@"
	$(Q)$(OBJCOPY) -j ".bootstrap" $(buildDir)/$(<F) $(buildDir)/$@ 2> /dev/null
endif


%.elf: $(ALLOBJS) $(LDSCRIPTS)
	@echo "-- LD      $@"
	$(Q)$(LD) $(LDFLAGS) -o $(buildDir)/$@ 				\
		$(patsubst %, $(objDir)/%, $(filter %.o,$(^F)))	\
		$(patsubst %, -L%,$(libDirs)) 					\
		$(patsubst %, -l%,$(LIBS))
	$(Q)mv $(TARGET_NAME).map $(buildDir)/$(TARGET_NAME).map

%.a: $(OBJS)
	@echo "-- AR      $@"
	$(Q)$(AR) rcs $(buildDir)/$@ $(patsubst %, $(objDir)/%,$(OBJS))

## Extra targets ---------------------------------------------------------------

%.elf.strip: %.elf
	@echo "-- STRIP   $@"
	$(Q)cp $(buildDir)/$(<F) $(buildDir)/$@
	$(Q)$(STRIP) -x -g $(buildDir)/$@

%.bin: %.elf
	@echo "-- OBJCOPY $@"
	$(Q)$(OBJCOPY) -Obinary $(buildDir)/$(<F) $(buildDir)/$@

ifeq "$(AppIsInRom)" "True"
rom.notscrambled.hex: $(TARGET_NAME).bin $(TARGET_NAME).dasm $(toolsDir)/scripts/bin2vhx.pl
	@echo "-- BIN2VHX $@"
	$(Q)$(BIN2VHX) -EL -32 -H < $(buildDir)/$(<F) > $(buildDir)/$@
else
rom.notscrambled.hex: $(TARGET_NAME)_rom.bin $(TARGET_NAME)_rom.dasm $(toolsDir)/scripts/bin2vhx.pl
	@echo "-- BIN2VHX $@"
	$(Q)$(BIN2VHX) -EL -32 -H < $(buildDir)/$(<F) > $(buildDir)/$@

norom.hex: $(TARGET_NAME)_norom.bin $(TARGET_NAME)_norom.dasm $(toolsDir)/scripts/bin2vhx.pl
	@echo "-- BIN2VHX $@"
	$(Q)$(BIN2VHX) -EL -32 -H < $(buildDir)/$(<F) > $(buildDir)/$@
endif

ts3ga32768x32m32_c050228.hex: rom.notscrambled.hex $(CONV_ROM)
	$(Q)$(CONV_ROM) $(buildDir)/$(<F)
	
$(CONV_ROM):
	@echo "-- GCC      $@"
	$(Q)cd $(toolsDir)/host/conv_rom;gcc -o conv_rom conv_rom.c

ifeq "$(EnableScrambling)" "True"
rom.hex: ts3ga32768x32m32_c050228.hex
	@echo "-- CP      $(<F) $@"
	$(Q)cp -- $(<F) $(buildDir)/$@
else
rom.hex: rom.notscrambled.hex
	@echo "-- CP      $(<F) $@"
	$(Q)cp -- $(buildDir)/$(<F) $(buildDir)/$@
endif

%.dasm: %.elf
	@echo "-- OBJDUMP $@"
	$(Q)$(OBJDUMP) -D -S $(buildDir)/$(<F) > $(buildDir)/$@

%.size: %.elf $(ALLOBJS)
	@echo "-- SIZE    $@"
	@echo "** Final Application **" > $(buildDir)/$@
	$(Q)$(SIZE) $(buildDir)/$(<F) >> $(buildDir)/$@
	@echo "** Without standard libraries **" >> $(buildDir)/$@
	$(Q)$(SIZE) --totals $(patsubst %, $(objDir)/%, $(filter %.o,$(^F))) >> $(buildDir)/$@

$(buildDir)/gdbinit: $(toolsDir)/gdb/gdbinit-$(JtagProbe)
	@echo "-- CP      $(@F)"
	$(Q)sed -e 's/@REMOTE_HOST@/$(RemoteHost)/g' $< > $@

$(buildDir)/SVN-INFO.mk: $(buildDir)/.dir FORCE
	$(Q)$(SHELL) $(toolsDir)/scripts/svn-describe $(rootDir) > $@-tmp
	$(Q)if $(SHELL) $(toolsDir)/scripts/move-if-change $@-tmp $@ ; then echo "-- UPDATE  $(@F)" ; fi
	
$(buildDir)/TOOLS-SVN-INFO.mk: $(buildDir)/.dir FORCE
	$(Q)$(SHELL) $(toolsDir)/scripts/svn-describe $(toolsDir) TOOLS > $@-tmp
	$(Q)if $(SHELL) $(toolsDir)/scripts/move-if-change $@-tmp $@ ; then echo "-- UPDATE  $(@F)" ; fi

$(buildDir)/INC-SVN-INFO.mk: $(buildDir)/.dir FORCE
	$(Q)$(SHELL) $(toolsDir)/scripts/svn-describe $(includeDirs) INC > $@-tmp
	$(Q)if $(SHELL) $(toolsDir)/scripts/move-if-change $@-tmp $@ ; then echo "-- UPDATE  $(@F)" ; fi

$(buildDir)/INIT-SVN-INFO.mk: $(buildDir)/.dir FORCE
	$(Q)$(SHELL) $(toolsDir)/scripts/svn-describe $(initDir) INIT > $@-tmp
	$(Q)if $(SHELL) $(toolsDir)/scripts/move-if-change $@-tmp $@ ; then echo "-- UPDATE  $(@F)" ; fi

$(buildDir)/LIB-SVN-INFO.mk: $(buildDir)/.dir FORCE
	$(Q)$(SHELL) $(toolsDir)/scripts/svn-describe $(libDir) LIB > $@-tmp
	$(Q)if $(SHELL) $(toolsDir)/scripts/move-if-change $@-tmp $@ ; then echo "-- UPDATE  $(@F)" ; fi

$(buildDir)/LINK-SVN-INFO.mk: $(buildDir)/.dir FORCE
	$(Q)$(SHELL) $(toolsDir)/scripts/svn-describe $(linkDir) LINK > $@-tmp
	$(Q)if $(SHELL) $(toolsDir)/scripts/move-if-change $@-tmp $@ ; then echo "-- UPDATE  $(@F)" ; fi

ifeq "$(HasConfig)" "True"
$(buildDir)/config.h: $(rootDir)/include/config.h.in $(abspath Makefile) $(buildDir)/.dir FORCE
	$(Q)sed -e 's/@VERSION@/$(VERSION)/g' \
		-e 's:@VERSION_MINOR@:$(VERSION_MINOR):g' \
		-e 's:@VERSION_MAJOR@:$(VERSION_MAJOR):g' \
		-e 's:@VERSION_PATCH@:$(VERSION_PATCH):g' \
		-e 's:@TOOLS_VERSION@:$(TOOLS_VERSION):g' \
		-e 's:@INC_VERSION@:$(INC_VERSION):g' \
		-e 's:@INIT_VERSION@:$(INIT_VERSION):g' \
		-e 's:@LIB_VERSION@:$(LIB_VERSION):g' \
		-e 's:@LINK_VERSION@:$(LINK_VERSION):g' \
		-e 's/@ENABLE_IRQ@/$(ENABLE_IRQ)/g' \
		-e 's/@ENABLE_FIQ@/$(ENABLE_FIQ)/g' \
		-e 's/@ENABLE_DCACHE@/$(ENABLE_DCACHE)/g' \
		-e 's/@ENABLE_ICACHE@/$(ENABLE_ICACHE)/g' \
		-e 's/@ARM_HAS_DTCM@/$(ARM_HAS_DTCM)/g' \
		-e 's/@ARM_HAS_ITCM@/$(ARM_HAS_ITCM)/g' \
		-e 's/@USE_HIGH_VECTORS@/$(USE_HIGH_VECTORS)/g' \
		-e 's/@ENABLE_UART@/$(ENABLE_UART)/g' \
		-e 's/@ENABLE_GPIO@/$(ENABLE_GPIO)/g' \
		-e 's/@PLATFORM@/$(PLATFORM)/g' \
		-e 's/@SIMULATION@/$(SIMULATION)/g' \
		-e 's/@ENABLE_MMU@/$(ENABLE_MMU)/g' \
		-e 's/@USE_ATTRIBUTE_IRQ@/$(USE_ATTRIBUTE_IRQ)/g' \
		-e 's/@ALLOW_DEPRECATED_MACROS@/$(ALLOW_DEPRECATED_MACROS)/g' \
		-e 's/@USE_GENERIC_NAME@/$(USE_GENERIC_NAME)/g' \
		-e 's/@PFM_SUFFIX@/$(PFM_SUFFIX)/g' \
		$< > $@-tmp
	$(Q)if $(SHELL) $(toolsDir)/scripts/move-if-change $@-tmp $@ ; then echo "-- UPDATE  $(@F)" ; fi
endif

$(buildDir)/cppcheck.xml: $(HFILES) $(CFILES)
	@echo "-- CPPCHECK"
	$(Q)$(CPPCHECK) $(CPPCHECKFLAGS) $(patsubst %, -I%,$(incDirs)) $(srcDirs) \
		2> $@

$(buildDir)/sloccount.sc: $(HFILES) $(CFILES) $(buildDir)/sloccount/.dir
	@echo "-- SLOCCOUNT"
	$(Q)$(SLOCCOUNT) $(SLOCCOUNTFLAGS) --datadir $(buildDir)/sloccount \
	$(srcDirs) include headers > $@

# ============================================================================

docs/cobra/html: $(templatesDir)/cobra.Doxyfile $(wilcard $(docsDir)/*.dox) $(wilcard $(templatesDir)/*.html) $(DEPS)
	@echo "-- DOXYGEN"
	$(Q)mkdir -p docs/cobra
	$(Q)BUILD=$(buildDir) TEMPLATE="$(templatesDir)" PROJECT="COBRA Tools" \
		PLATFORM=$(PLATFORM) VERSION=$(TOOLS_VERSION) doxygen $<

docs/private/html/index.html: $(templatesDir)/private.Doxyfile $(MKFILES) $(HFILES) $(CFILES) $(DOXFILES) $(wilcard $(templatesDir)/*.html)
	@echo "-- DOXYGEN"
	$(Q)IP_VERSION=$(IP_VERSION) TEMPLATE=$(templatesDir) PROJECT=$(PROJECT) \
		BUILD_DIR=$(buildDir) VERSION=$(VERSION) doxygen $<
		
docs/public/html/index.html: $(templatesDir)/public.Doxyfile $(MKFILES) $(HFILES) $(CFILES) $(DOXFILES) $(wilcard $(templatesDir)/*.html)
	@echo "-- DOXYGEN"
	$(Q)IP_VERSION=$(IP_VERSION) TEMPLATE=$(templatesDir) PROJECT=$(PROJECT) \
		BUILD_DIR=$(buildDir) VERSION=$(VERSION) doxygen $<
