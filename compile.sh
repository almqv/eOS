#!/usr/bin/bash

done="[OK]"
fail="[FAIL]"

srcDir=src
binDir=bin

echo "Compiling bootloader... "
nasm -f bin $srcDir/bootloader.asm -i $srcDir -o $binDir/bootloader.bin 

echo "Compiling kernel... "
gcc -fno-pie -m32 -Os -ffreestanding -c $srcDir/kernel.c -o $binDir/kernel.o && gcc -o $binDir/kernel.bin $binDir/kernel.o -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32 

echo "Creating OS image... "
cat $binDir/bootloader.bin $binDir/kernel.bin > $binDir/os-image 
