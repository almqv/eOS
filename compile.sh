#!/usr/bin/bash

done="[OK]"
fail="[FAIL]"

srcDir=src
binDir=bin

echo -n "Compiling bootloader... "
nasm -f bin $srcDir/bootloader.asm -i $srcDir -o $binDir/bootloader.bin && echo $done

echo -n "Compiling kernel... "
gcc -ffreestanding -c $srcDir/kernel.c -o $binDir/kernel.o && ld -o $binDir/kernel.bin -Ttext 0x1000 $binDir/kernel.o --oformat binary 2>/dev/null && echo $done

echo -n "Creating kernel image... "
cat $binDir/bootloader.bin $binDir/kernel.bin > $binDir/os-image && echo $done
