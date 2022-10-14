
#!/bin/bash
set -e

SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

mkdir -p build/qemu
cd build/qemu

if [ ! -f "Makefile" ]; then
    ../../xilinx_qemu/configure --target-list=riscv64-softmmu \
                --prefix=$SCRIPTPATH/build/install/qemu
fi
make -j4
make install

