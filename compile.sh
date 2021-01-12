#!/usr/bin/bash

srcDir=src
binDir=bin

nasm -f bin $srcDir/bootloader.asm -o $binDir/bootloader.bin
