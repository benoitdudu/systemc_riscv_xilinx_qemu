#!/bin/bash
set -e

SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

mkdir -p build/platform
cd build/platform
cmake ../../src/ -DCMAKE_INSTALL_PREFIX=${SCRIPTPATH}/build/install/platform
make -j3 install 
