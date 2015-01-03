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
# ToyReco
rootlibmap libCPPExample_ToyReco.rootmap libCPPExample_ToyReco.so $CPPEXAMPLE_DIR/ToyReco/LinkDef.h \
    libTree.so \
    libHist.so \
    libGpad.so \
    libPhysics.so
