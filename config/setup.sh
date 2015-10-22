#!/bin/bash

# clean up previously set env
me="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"
`python $me/python/clean_env.py LD_LIBRARY_PATH`
`python $me/python/clean_env.py DYLD_LIBRARY_PATH`
`python $me/python/clean_env.py PYTHONPATH`
`python $me/python/clean_env.py PATH`

if [[ -z $FORCE_CPPEXAMPLE_DIR ]]; then
    # If CPPEXAMPLE_DIR not set, try to guess
    # Find the location of this script:
    me="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
    # Find the directory one above.
    export CPPEXAMPLE_DIR="$( cd "$( dirname "$me" )" && pwd )"
else
    export CPPEXAMPLE_DIR=$FORCE_CPPEXAMPLE_DIR
fi
unset me;

echo "CPPEXAMPLE_DIR = $CPPEXAMPLE_DIR"
if [[ -z $CPPEXAMPLE_DIR ]]; then
    echo \$CPPEXAMPLE_DIR not set! 
    echo You have to set this first.
    return;
fi

# Abort if ROOT not installed. Let's check rootcint for this.
if [ `command -v rootcling` ]; then
    export CPPEXAMPLE_ROOT6=1
else
    if [[ -z `command -v rootcint` ]]; then
	echo
	echo Looks like you do not have ROOT installed.
	echo You cannot use LArLite w/o ROOT!
	echo Aborting.
	echo
	return;
    fi
fi
CPPEXAMPLE_OS=`uname -s`

# Set path to sub directories
export CPPEXAMPLE_LIBDIR=$CPPEXAMPLE_DIR/lib

if [[ -z $USER_MODULE ]]; then
    export USER_MODULE=""
fi

# Check compiler availability for clang++ and g++
CPPEXAMPLE_CXX=clang++
if [ `command -v $CPPEXAMPLE_CXX` ]; then
    export CPPEXAMPLE_CXX="clang++ -std=c++11";
else
    CPPEXAMPLE_CXX=g++
    if [[ -z `command -v $CPPEXAMPLE_CXX` ]]; then
	echo
	echo Looks like you do not have neither clang or g++!
	echo You need one of those to compile CPPExample... Abort config...
	echo
	return;
    fi
    export CPPEXAMPLE_CXX;
    if [ $CPPEXAMPLE_OS = 'Darwin' ]; then
	echo $CPPEXAMPLE_OS
	echo
	echo "***************** COMPILER WARNING *******************"
	echo "*                                                    *"
	echo "* You are using g++ on Darwin to compile CPPExample. *"
	echo "* Currently CPPExample assumes you do not have C++11 *"
	echo "* in this combination. Contact the author if this is *"
	echo "* not the case. At this rate you have no ability to  *"
	echo "* compile packages using C++11 in CPPExample.        *"
	echo "*                                                    *"
	echo "* Help to install clang? See manual/contact author!  *"
	echo "*                                                    *"
	echo "******************************************************"
	echo 
    fi
fi

if [[ -z $ROOTSYS ]]; then
    echo
    echo "****************** PyROOT WARNING ********************"
    echo "*                                                    *"
    echo "* Did not find your \$ROOTSYS. To use PyROOT feature, *"
    echo "* Make sure ROOT.py is installed (comes with ROOT).  *"
    echo "* You need to export \$PYTHONPATH to include the dir  *"
    echo "* where ROOT.py exists.                              *"
    echo "*                                                    *"
    echo "* Help to install PyROOT? See manual/contact author! *"
    echo "*                                                    *"
    echo "******************************************************"
    echo
else
    export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH;
fi

export LD_LIBRARY_PATH=$CPPEXAMPLE_LIBDIR:$LD_LIBRARY_PATH
export PYTHONPATH=$CPPEXAMPLE_DIR/python:$PYTHONPATH
if [ $CPPEXAMPLE_OS = 'Darwin' ]; then
    export DYLD_LIBRARY_PATH=$CPPEXAMPLE_LIBDIR:$DYLD_LIBRARY_PATH
fi
export PATH=$CPPEXAMPLE_DIR/bin:$PATH
echo
echo "Finish configuration."
echo

