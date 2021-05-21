#!/usr/bin/bash

bootloader=bin/bootloader.bin

start_bootloader() {
	qemu-system-x86_64 $bootloader
}

compile() {
	/usr/bin/bash $PWD/compile.sh
}

if test -f "$PWD/$bootloader"; then
	rm $PWD/$bootloader
	compile
	start_bootloader
else
	 compile && start_bootloader
fi
