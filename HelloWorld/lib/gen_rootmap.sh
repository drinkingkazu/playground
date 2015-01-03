#!/bin/bash

temp=make_rootmap.$$.temp

rootlibmap() {
 ROOTMAP=$1
 SOFILE=$2
 LINKDEF=$3
 shift 3
 DEPS=$*
 if [[ -e $SOFILE && -e $LINKDEF ]]; then
     rlibmap -f -o $ROOTMAP -l $SOFILE -d $DEPS -c $LINKDEF 2>> $temp
     rm -f $temp
 fi
}

######################################################
# HelloWorld
rootlibmap libCPPExample_HelloWorld.rootmap libCPPExample_HelloWorld.so $CPPEXAMPLE_DIR/HelloWorld/LinkDef.h \
    libTree.so \
    libHist.so \
    libGpad.so \
    libPhysics.so
