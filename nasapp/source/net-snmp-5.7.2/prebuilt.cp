#! /bin/sh

cp ./agent/.libs/snmpd ../../prebuilt/bins.5281.3465/sbin/
cp ./apps/.libs/snmptrap ../../prebuilt/bins.5281.3465/sbin/

cp -P ./snmplib/.libs/libnetsnmp.so* ../../prebuilt/bins.5281.3465/lib
cp -P ./agent/.libs/libnetsnmpagent.so* ../../prebuilt/bins.5281.3465/lib
cp -P ./agent/.libs/libnetsnmpmibs.so* ../../prebuilt/bins.5281.3465/lib
cp -P ./agent/helpers/.libs/libnetsnmphelpers.so* ../../prebuilt/bins.5281.3465/lib
cp -P ./apps/.libs/libnetsnmptrapd.so* ../../prebuilt/bins.5281.3465/lib

