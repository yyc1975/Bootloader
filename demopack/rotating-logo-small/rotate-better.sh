#!/bin/bash
# Y axis rotation of image
# usage: anime_rotate <filename> <steps>
# 
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Author: Stephane Di Vito (c)2014

identify $1

filename=`rev <<< "$1" | cut -d"." -f2- | rev`
fileext=`rev <<< "$1" | cut -d"." -f1 | rev`

width=$(identify -ping -format "%w" $1)
height=$(identify -ping -format "%h" $1)
step=$2
i=0

function rotate_sdv()
{
    start=$1
    stop=$2
    _step=$3
    inname=$4
    outname=$5
    ext=$6

#    for (( c=$start; c>=$stop; c=c+($_step) ))
    for c in $(seq $start $_step $stop)
    do
        num="00000000$i"
        num="${num:((${#num}-3)):${#num}}"
        if [ $c -le 0 ] 
        then 
           c=1
        fi 
        echo convert $inname.$ext -scale "$c"x"$height"\! $outname-$num.$ext
        convert $inname.$ext -scale "$c"x"$height"\! $outname-$num.$ext1
        echo convert $outname-$num.$ext1 -gravity center -background transparent -extent "$width"x"$height"  $outname-$num.$ext
        convert $outname-$num.$ext1 -gravity center -background transparent -extent "$width"x"$height"  $outname-$num.$ext
        rm $outname-$num.$ext1
        ((i++))
    done
}

function rotate()
{
    start=$1
    stop=$2
    _step=`echo "90/$3" |bc -l`
    inname=$4
    outname=$5
    ext=$6

    pi=`echo "4*a(1)" |bc -l`

#    for (( c=$start; c>=$stop; c=c+($_step) ))
    for c in $(seq $start $_step $stop)
    do
        num="00000000$i"
        num="${num:((${#num}-3)):${#num}}"
        rad=`echo "$c*($pi/180)" |bc -l`
        w=`echo "$width * c($rad)" |bc -l |awk '{printf("%d\n",$0+=$0<0?-0.5:0.5)}'`
        echo $w
        if [ $w -le 0 ]
        then
           w=1
        fi
        echo convert $inname.$ext -scale "$w"x"$height"\! $outname-$num.$ext
        convert $inname.$ext -scale "$w"x"$height"\! $outname-$num.$ext1
        echo convert $outname-$num.$ext1 -gravity center -background transparent -extent "$width"x"$height"  $outname-$num.$ext
        convert $outname-$num.$ext1 -gravity center -background \#3b3635 -extent "$width"x"$height"  $outname-$num.$ext
        rm $outname-$num.$ext1
        ((i++))
    done
}

convert $1 -flop $filename-inv.$fileext

#rotate $width 0 -$step $filename     $filename $fileext 
#rotate 0 $width  $step $filename-inv $filename $fileext
#rotate $width 0 -$step $filename-inv $filename $fileext
#rotate 0 $width  $step $filename     $filename $fileext


rotate 0 89 $step $filename     $filename $fileext 
rotate 90 1 -$step $filename-inv     $filename $fileext 
rotate 0 89 $step $filename-inv     $filename $fileext 
rotate 90 1 -$step $filename     $filename $fileext 


rm $filename-inv.$fileext