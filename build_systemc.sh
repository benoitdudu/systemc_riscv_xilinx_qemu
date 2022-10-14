#!/bin/bash
set -e

SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

mkdir -p build/systemc
cd build/systemc
cmake ../../systemc/ -DCMAKE_CXX_STANDARD=14  -DCMAKE_INSTALL_PREFIX=${SCRIPTPATH}/build/install/systemc
make -j3 install
