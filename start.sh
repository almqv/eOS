#!/usr/bin/bash

bootloader=bin/bootloader.bin

start_bootloader() {
	qemu-system-x86_64 $bootloader
}

if test -f "$PWD/$bootloader" then
	start_bootloader
else
	/usr/bin/bash $PWD/compile.sh && start_bootloader
fi
