#!/bin/bash

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"
APPNAME="Mosaic-Engine-Tester"
APPNAMEDEBUG="Mosaic-Engine-Tester_debug"

install_name_tool -change @rpath/libndi.3.dylib @executable_path/libndi.3.dylib $SCRIPTPATH/bin/$APPNAME.app/Contents/MacOS/$APPNAME
install_name_tool -change @rpath/libndi.3.dylib @executable_path/libndi.3.dylib $SCRIPTPATH/bin/$APPNAMEDEBUG.app/Contents/MacOS/$APPNAMEDEBUG
