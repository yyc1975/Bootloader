#
# platform.mk
#
# Copyright (c) 2010, Maxim Integrated Products
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
# Created on: Nov 06, 2014
#     Author: Yann G. <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords
# $Rev:: 368           $:  Revision of last commit
# $Author:: yann.gaude $:  Author of last commit
# $Date:: 2010-10-21 1#$:  Date of last commit
#
# [/INTERNAL] ==================================================================

# PROJECT_CONFIG: just to complete the target name (optional)
PROJECT_CONFIG = debug

# PLATFORM: defines the targeted platform
#  - jibe  -- MAX32590
#  - londa -- MAX32580
#  - mq55 -- MAX32550
#  - yumen -- MAX32555
PLATFORM = mq55
SECUREROMCODEREF = angela
MAXIMREF = max32550

PLATFORM_UPPER = $(shell echo $(PLATFORM) | tr '[:upper:][:lower:]' '[:lower:][:upper:]')
SECUREROMCODEREF_UPPER = $(shell echo $(SECUREROMCODEREF) | tr '[:upper:][:lower:]' '[:lower:][:upper:]')
MAXIMREF_UPPER = $(shell echo $(MAXIMREF) | tr '[:upper:][:lower:]' '[:lower:][:upper:]')

# PLATFORM_VERSION: defines the targeted platform version
#  jibe
#  or londa
#  or mq55
#  or yumen
#     -- fpga
#     -- silicon
PLATFORM_VERSION = silicon

# BOARD: defines the targeted board
# Not used (overwritten) for 'sim' target.
#  - eek10 - EEK v1.0
#  - eek20 - EEK v2.0
#  - eek30 - EEK v3.0
#  - eek45 - EEK v4.5
#  - evk10 - EV Kit v1.0
#  - evk20 - EV Kit v2.0
#  - evk30 - EV Kit v3.0
#
BOARD = evk30

# SYSTEM: defines the software architecture
#  - default -- All is loaded by jtag, only one section for code and data
#  - sla -- Second Level Application
#  - scp_aplt -- SCP Applet
#  - stp_app -- STP Application
SYSTEM = default_bin

# LAYOUT: defines the memory layout for the different sections
# - default -- All executed in iflash and iram
# - iram
# - irom
# - framework
LAYOUT = default_bin

# FRAMEWORK: defines what framework is targetted
# - SLA = 3 -- 2nd level application based on Secure ROM Code
# - SCP_APLT = 2 -- SCP applet based on Secure ROM Code
# - STP_APP = 1 -- STP application based on Secure ROM Code
# - NO_FWK = 0 -- Secure ROM code building
FRAMEWORK = NO_FWK

# CPU: defines the CPU type for the platform
#  - arm926 -- ARM926EJ-S
#  - cortex-m3 -- ARM CORTEX-M3
CPU = cortex-m3

# LIBUCL_REV: defines the revision of Lib UCL to use
LIBUCL_REV = 2.5.5

## Activate THUMB for ARM platform
PlatformSpecific = -mcpu=$(CPU) -mthumb -mapcs-frame -mtune=$(CPU)

# EOF
