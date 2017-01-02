#!/bin/bash
#
# hudson.bash -- 
#
# Copyright (c) 2010, Maxim Integrated Products
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#	 * Redistributions of source code must retain the above copyright
#		notice, this list of conditions and the following disclaimer.
#	 * Redistributions in binary form must reproduce the above copyright
#		notice, this list of conditions and the following disclaimer in the
#		documentation and/or other materials provided with the distribution.
#	 * Neither the name of the Maxim Integrated Products nor the
#		names of its contributors may be used to endorse or promote products
#		derived from this software without specific prior written permission.
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
# Created on: Jul 2, 2010
#	 Author: 
#
# ---- Subversion keywords
# $Rev::				$:  Revision of last commit
# $Author:: gregory.ro#$:  Author of last commit
# $Date:: 2010-11-19 1#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

if [ "$IRQ" == "EnableIRQ" ] ;
then 
	export EnableFIQ=True
	export EnableIRQ=True
else
	export EnableFIQ=False
	export EnableIRQ=False
fi

if [ "$CACHE" == "EnableCache" ] ;
then 
	export EnableICache=True
	export EnableDCache=True
else
	export EnableICache=False
	export EnableDCache=False
fi

if [ "$TCM" == "EnableTCM" ] ;
then 
	export ArmHasITCM=True
	export ArmHasDTCM=True
else
	export ArmHasITCM=False
	export ArmHasDTCM=False
fi

if [ "x$LAYOUT" == "x" ] ;
then
	export LAYOUT=default
fi

if [ "x$PLATFORM" == "x" ] ;
then
	
	export PLATFORM=londa
else
	export PLATFORM=$PLATFORM
fi

if [ "x$SYSTEM" == "x" ] ;
then
	export SYSTEM=rom
fi

export ECLIPSE=1
export DebugEnabled=True
export EnableUart=True
export EnableGpio=False
export EnableMMU=True
export buildDir=build/debug

export PATH=$PATH:/opt/CodeSourcery/Sourcery_G++_Lite/bin

rm -rf *.log result.xml

echo "[INFO] Clean"
make distclean

echo "[INFO] Documentation generation"
make docs

echo "[INFO] Build template"
make show-config
make all || exit 1
make dasm
make size
make hex

#echo "[INFO] Test template with FPGA"
#make autodebug

#BUILD_DIR=$(make show-builddir)
#TARGET_NAME=$(make show-targetname)

#if ! rvigdbconfig.sh fpga_londa.rvc ;
#then
#	echo "[INFO] FAILED: Unable to configure the probe"
#	exit 0
#fi 

#arm-none-eabi-gdb -batch -x ${BUILD_DIR}/gdbinit -x tools/gdb/gdbinit-auto ${BUILD_DIR}/${TARGET_NAME}.elf
#pkill empty

#cat debug.log | grep "error" 2>/dev/null >&2 && echo "[INFO] Test FAILED"
#cat debug.log | grep "ERROR" 2>/dev/null >&2 && echo "[INFO] Test FAILED"

#tr -cd '\11\12\40-\176' < telnet.log | grep "<" | grep -v "<<<" > result.xml
#cat telnet.log 

exit 0 
