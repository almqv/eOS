#!/usr/bin/bash

bootloader=bin/bootloader.bin
osimage=bin/os-image

start_bootloader() {
	qemu-system-x86_64 $osimage
}

compile() {
	/usr/bin/bash $PWD/compile.sh
}

if test -f "$PWD/$bootloader"; then
	rm $PWD/$bootloader
fi


compile && start_bootloader
