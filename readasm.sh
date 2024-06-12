#!/bin/bash
#filename='stip.txt'
filename=$1
n=1
insn=$(riscv32-linux-objdump -dtr ../../linux-kernel/vmlinux)
while read line; do
echo "$insn" | grep "$line"
n=$((n+1))
done < $filename

