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
# ToyMC
rootlibmap libCPPExample_ToyMC.rootmap libCPPExample_ToyMC.so $CPPEXAMPLE_DIR/ToyMC/LinkDef.h \
    libTree.so \
    libHist.so \
    libGpad.so \
    libPhysics.so
