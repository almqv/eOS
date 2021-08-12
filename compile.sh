#!/usr/bin/bash

option=$1

srcDir=src
binDir=bin

compile_bootloader() {
	echo "Compiling bootloader... "
	nasm -f bin $srcDir/bootloader/bootloader.asm -i $srcDir/bootloader -o $binDir/bootloader.bin 
}

compile_kernel() {
	echo "Compiling kernel... "
	gcc -fno-pie -m32 -Os -ffreestanding -c $srcDir/kernel/kernel.c -o $binDir/kernel.o && gcc -o $binDir/kernel.bin $binDir/kernel.o -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32 
}

create_os_image() {
	echo "Creating OS image... "
	cat $binDir/bootloader.bin $binDir/kernel.bin > $binDir/os-image 
}



compile_bootloader
compile_kernel
create_os_image
