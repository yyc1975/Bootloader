#!/bin/bash
#
# set-driver-name.bash -- 
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
# Created on: Sep 14, 2010
#	 Author: Gregory Romé
#
# ---- Subversion keywords
# $Rev::				$:  Revision of last commit
# $Author:: 			$:  Author of last commit
# $Date:: 				$:  Date of last commit
#
# [/INTERNAL] ==================================================================

AWK=/usr/bin/awk

SRC_DIR=$1
PREFIX_DST=$2
PREFIX_SRC=${3:-xxx}
USE_SVN=${4:-YES}

PREFIX_SRC_UC=$(echo ${PREFIX_SRC} | $AWK '{print toupper($0)}')
PREFIX_SRC_LC=$(echo ${PREFIX_SRC} | $AWK '{print tolower($0)}')

PREFIX_DST_UC=$(echo $PREFIX_DST | $AWK '{print toupper($0)}')
PREFIX_DST_LC=$(echo $PREFIX_DST | $AWK '{print tolower($0)}')

CFILES=$(find $SRC_DIR -type f -name "*.c" | grep -v "svn/")
HFILES=$(find $SRC_DIR -type f -name "*.h" | grep -v "svn/")
FILES="$CFILES $HFILES"

if [ x"${USE_SVN}" == "xYES" ] 
then
	SVNRM="svn rm"
	ADD="svn add"
else
	SVNRM="touch"
	ADD="touch"
fi


echo "Processing files:"
for FILE in $FILES
do
	NEW_FILE=$(echo $FILE | sed -e "s/${PREFIX_SRC_LC}/${PREFIX_DST_LC}/g")

	echo " - ${FILE} -> ${NEW_FILE}"

	if [ "${NEW_FILE}" == "$FILE" ] 
	then
		FILE=${NEW_FILE}.old
		mv ${NEW_FILE} ${FILE}
		SVNRM="touch"
		ADD="touch"
	fi

	sed -e "s/$PREFIX_SRC_UC/$PREFIX_DST_UC/g" -e "s/$PREFIX_SRC_LC/$PREFIX_DST_LC/g" $FILE > $NEW_FILE

	$SVNRM $FILE
	rm -f $FILE
	$ADD $NEW_FILE
done

exit 0
