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
# Package_Name
rootlibmap libCPPExample_Package_Name.rootmap libCPPExample_Package_Name.so $CPPEXAMPLE_DIR/Package_Name/LinkDef.h \
    libTree.so \
    libHist.so \
    libGpad.so \
    libPhysics.so
