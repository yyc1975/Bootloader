#!/bin/bash

PLATFORM=${1:-londa}
DIR=${2:-tools/include}

IPS="usb1a scc2b skbd2b spi3a uart2b i2c2b intc3a tmr3a gpio3a wdg3a fctrl1b \
tdc1b dma3a rtc3a sec1a trng1a sm2b gcr1a"

rm -f prop.txt

echo "Processing..."
for IP in $IPS
do
	IPNAME=$(echo $IP | sed -e "s/^\([a-z0-9]*[a-z]\)[0-9][a-z]$/\1/g")
	echo "  - $IP - $IPNAME"
	echo "^/drivers/$IP/trunk/$PLATFORM/src/include/${PLATFORM}_${IPNAME}_regs.h ${PLATFORM}_${IPNAME}_regs.h" >> prop.txt
done

svn propset -F prop.txt svn:externals $DIR/$PLATFORM/dev

exit 0

