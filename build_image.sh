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

function build_image()
{
    echo
    echo '[[[[[[[ Build Image ]]]]]]]'
    echo
    echo

    rm -R build
    make distclean
    make

    check_exit
}

function sign_image()
{
    echo
    echo '[[[[[[[ Sign Image ]]]]]]]'
    echo

    if [ -f $OUT_DIR/$IMAGE_NAME.elf ]; then
        cd $SIGN_DIR
        cp $OUT_DIR/$IMAGE_NAME.elf .
        ./sign_image.sh $IMAGE_NAME
        
        if [ -f $SIGN_DIR/$IMAGE_NAME.sbin ]; then

            if [ -d $IMAGE_NAME ]; then    
                rm -R $IMAGE_NAME
            fi

            ./build_bootloader.sh $IMAGE_NAME.sbin $IMAGE_NAME keys/maximtestcrk.key
        else
            echo "  ERROR!!! Cannot find $IMAGE_NAME.sbin..." 
            echo
        fi
    else
        echo "  ERROR!!! Cannot find $IMAGE_NAME.elf..." 
        echo
    fi
   
    cd $ROOT_DIR

    check_exit
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

    build_image
    sign_image
    #write_image
    
    END_TIME=`date +%s`
    let "ELAPSED_TIME=$END_TIME-$START_TIME"
    echo "Total compile time is $ELAPSED_TIME seconds"
    
    echo ok success !!!

exit 0
