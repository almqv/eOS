all: os-image

run: all
	qemu-system-x86_64 os-image

os-image: bootloader.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel_entry.o kernel.o
	ld -o kernel.bin -Ttext 0x1000 $^ --oformat binary

kernel.o : src/kernel/kernel.c
	gcc -ffreestanding -c $< -o $@

kernel_entry.o : src/kernel/kernel_entry.asm
	nasm $< -f elf -o $@

bootloader.bin : src/bootloader/bootloader.asm
	nasm $< -f bin -o $@

clean:
	rm -fr *.bin *.dis *.o os-image *.map

kernel.dis : kernel.bin
	ndisasm -b 32 $< > $@
