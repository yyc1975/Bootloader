#!/bin/sh

usage() {
    echo
    echo "Runs an sign image script for MAX32550 SecureROM loader."
    echo ""
    echo " Syntax: sign_image.sh <filename>"
    echo
    echo "    <filename> = image's name (e.g. bootloader)"
    echo ""
}

case $# in
1)	readonly filename=$1
	;;
*)	usage  >&2
	exit 2
	;;
esac

if [ -f $1.bin ]; then
  rm $1.bin
fi

if [ -f $1_new.bin ]; then
  rm $1_new.bin
fi

if [ -f $1.sbin ]; then
  rm $1.sbin
fi

if [ -f $1.elf ]; then
    #/usr/local/arm/arm-2010q1-eabi/bin/arm-none-eabi-objcopy -O binary $1.elf $1.bin
    ../arm-2010q1-eabi/bin/arm-none-eabi-objcopy -O binary $1.elf $1.bin

    if [ -f $1.bin ]; then
        ./ca_sign_build algo=ecdsa ca=$1.bin sca=$1.sbin load_address=10000000 jump_address=10000020 arguments= version=01000003 application_version=02030001 verbose=no
    else
        echo "  ERROR!!! Cannot find $1.bin..." 
    fi

    rm $1.elf
else
    echo "  ERROR!!! Cannot find $1.elf..." 
fi
   
