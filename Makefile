all: os-image

run: all
	qemu bin/os-image

os-image: bin/bootloader.bin bin/kernel.bin
	cat $^ > bin/os-image

kernel.bin: bin/kernel_entry.o bin/kernel.o
	ld -o kernel.bin -Ttext 0x1000 $^ --oformat binary

kernel.o : src/kernel/kernel.c
	gcc -ffreestanding -c $< -o $@

kernel_entry.o : src/kernel/kernel_entry.asm
	nasm $< -f elf -o $@

bootloader.bin : src/bootloader/bootloader.asm
	nasm $< -o $@

clean:
	rm -fr bin/*.bin bin/*.dis bin/*.o bin/os-image bin/*.map

kernel.dis : bin/kernel.bin
	ndisasm -b 32 $< > $@
