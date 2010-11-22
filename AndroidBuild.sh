#!/bin/sh

LOCAL_PATH=`dirname $0`
LOCAL_PATH=`cd $LOCAL_PATH && pwd`

../setEnvironment.sh make -C newraw -j2 && cp -rf newraw/raw libapplication.so
