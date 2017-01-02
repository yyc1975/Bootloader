#!/bin/bash

CLIENT=$(whoami)

IMAGE_NAME=bootloader
ROOT_DIR=$(pwd)
OUT_DIR="$ROOT_DIR/build/mq55-default_bin-default_bin-debug"
SIGN_DIR="$ROOT_DIR/ext_tools/mitac_tool"

function check_exit()
{
    if [ $? != 0 ]
    then
    	exit $?
    fi
}

function write_image()
{
    echo
    echo '[[[[[[[ Write Image ]]]]]]]'
    echo

    cd $SIGN_DIR
    if [ -d $IMAGE_NAME ]; then
        sudo ./sendscp.sh $IMAGE_NAME
    fi
    cd $ROOT_DIR

    check_exit
}


echo
echo "========================================================================="
echo "                       MITAC_SKU_NUM = MAX32550                          "
echo "========================================================================="
echo
echo

    START_TIME=`date +%s`

    write_image
    
    END_TIME=`date +%s`
    let "ELAPSED_TIME=$END_TIME-$START_TIME"
    echo "Total compile time is $ELAPSED_TIME seconds"
    
    echo ok success !!!

exit 0
