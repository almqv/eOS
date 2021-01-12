#!/usr/bin/bash

srcDir=src
binDir=bin

nasm -f bin $srcDir/bootloader.asm -i $srcDir -o $binDir/bootloader.bin
