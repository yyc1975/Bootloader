#
# VERSION.mk -- Lib version
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
# Created on: Oct 04, 2012
#     Author: Yann G. <yann.gaude@maximintegrated.com>
#
# ---- Subversion keywords
# $Rev:: $: Revision of last commit
# $Author:: $: Author of last commit
# $Date:: $: Date of last commit
#
# [/INTERNAL] ==================================================================

LIB_VERSION_MAJOR = 3
LIB_VERSION_MINOR = 2
LIB_VERSION_PATCH = 7
LIB_VERSION_EXT = release

## ------------------------------------------------------------------------------
# !!DO NOT MODIFY!!
# ------------------------------------------------------------------------------
-include $(buildDir)/LIB-SVN-INFO.mk
