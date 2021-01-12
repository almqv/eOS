#!/usr/bin/bash

binDir=bin

nasm -f bin bootloader.asm -o $binDir/bootloader.bin
