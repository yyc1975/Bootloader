#
# ext_drv.mk
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
# Created on: Nov 07, 2014
#     Author: Yann G. <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords
# $Rev:: $: Revision of last commit
# $Author:: $: Author of last commit
# $Date:: $: Date of last commit
#
# [/INTERNAL] ==================================================================

##MQ55 platform drivers
incExtDrv = $(extdriversDir)/common/include \
			$(extdriversDir)/dma/include \
			$(extdriversDir)/gcr/include \
			$(extdriversDir)/gpio/include \
			$(extdriversDir)/i2c/include \
			$(extdriversDir)/intc/include \
			$(extdriversDir)/mcr/include \
			$(extdriversDir)/sci/include \
			$(extdriversDir)/skbd/include \
			$(extdriversDir)/spi/include \
			$(extdriversDir)/tdc/include \
			$(extdriversDir)/tmr/include \
			$(extdriversDir)/uart/include \
            $(extdriversDir)/smon/include \
            $(extdriversDir)/trng/include

srcExtDrv = $(extdriversDir)/common \
			$(extdriversDir)/dma \
			$(extdriversDir)/gcr \
			$(extdriversDir)/gpio \
			$(extdriversDir)/i2c \
			$(extdriversDir)/intc \
			$(extdriversDir)/mcr \
			$(extdriversDir)/sci \
			$(extdriversDir)/skbd \
			$(extdriversDir)/spi \
			$(extdriversDir)/tdc \
			$(extdriversDir)/tmr \
			$(extdriversDir)/uart \
            $(extdriversDir)/smon \
            $(extdriversDir)/trng

# EOF
