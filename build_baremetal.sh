#!/bin/bash
set -e

cd tbm
make CFG=configs/ariane.cfg  CROSS=riscv64-linux-gnu-
