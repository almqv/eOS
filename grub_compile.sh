#!/usr/bin/bash

srcdir=src
bindir=bin

make_grub() {
	echo "Making GRUB..."
	mkdir -p $bindir/boot/grub
	cp $bindir/kernel.bin $bindir/boot/eOS.bin
	cp $srcdir/grub/grub.cfg $bindir/boot/grub/grub.cfg
	grub-mkrescue -o $bindir/eOS.iso $bindir
}

compile_kernel() {
	echo "Compiling kernel... "
	gcc -fno-pie -m32 -Os -ffreestanding -c $srcdir/kernel/kernel.c -o $bindir/kernel.o && gcc -o $bindir/kernel.bin $bindir/kernel.o -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32 
}

compile_kernel
make_grub
