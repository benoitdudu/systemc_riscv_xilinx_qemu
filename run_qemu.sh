#!/bin/bash
set -e

MACHINE_PATH=${PWD}/build/install/machine_path
mkdir -p ${MACHINE_PATH}
#./build/install/qemu/bin/qemu-system-riscv64 \
./build/install/qemu_benoit/bin/qemu-system-riscv64 \
        -M virt-cosim \
        -m 256M \
        -serial stdio \
        -display none \
        -device loader,file=./tbm/build/ariane_soc/ctest-bare,cpu-num=0 \
        -machine-path ${MACHINE_PATH} \
        -icount 1 -sync-quantum 10000
