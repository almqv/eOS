all: os-image

run: all
	qemu-system-x86_64 os-image

grub: eOS.iso
	qemu-system-x86_64 eOS.iso

eOS.iso : kernel.bin src/grub/grub.cfg
	mkdir -p boot/grub
	cp $< boot/eOS.bin
	cp src/grub/grub.cfg boot/grub/grub.cfg
	grub-mkrescue -o eOS.iso ./

os-image: bootloader.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel_entry.o kernel.o
	gcc -o kernel.bin $^ -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32

kernel.o : src/kernel/kernel.c
	gcc -fno-pie -m32 -Os -ffreestanding -c $< -o $@

kernel_entry.o : src/kernel/kernel_entry.asm
	nasm $< -f elf -o $@

bootloader.bin : src/bootloader/bootloader.asm
	nasm $< -f bin -o $@

clean:
	rm -fr *.bin *.dis *.o os-image *.map boot/ *.iso

kernel.dis : kernel.bin
	ndisasm -b 32 $< > $@

