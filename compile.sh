#!/usr/bin/bash

srcdir=src
bindir=bin

compile_bootloader() {
	echo "Compiling bootloader... "
	nasm -f bin $srcdir/bootloader/bootloader.asm -i $srcdir/bootloader -o $bindir/bootloader.bin 
}

compile_kernel() {
	echo "Compiling kernel... "
	gcc -fno-pie -m32 -Os -ffreestanding -c $srcdir/kernel/kernel.c -o $bindir/kernel.o && gcc -o $bindir/kernel.bin $bindir/kernel.o -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32 
}

create_os_image() {
	echo "Creating OS image... "
	cat $bindir/bootloader.bin $bindir/kernel.bin > $bindir/os-image 
}



compile_bootloader
compile_kernel
create_os_image
