C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)
OBJ = $(C_SOURCES:.c=.o)

all: os-image

run: all
	qemu-system-x86_64 os-image

drun: clean run

grub: eOS.iso
	qemu-system-x86_64 eOS.iso

eOS.iso : kernel/kernel.bin grub/grub.cfg
	mkdir -p boot/grub
	cp $< boot/eOS.bin
	cp grub/grub.cfg boot/grub/grub.cfg
	grub-mkrescue -o eOS.iso ./

os-image: bootloader/bootloader.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel/kernel_entry.o $(OBJ) 
	gcc -o $@ $^ -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32

%.o : %.c
	gcc -fno-pie -m32 -Os -ffreestanding -c $< -o $@

%.o : %.asm
	nasm $< -f elf -o $@

%.bin : %.asm
	nasm $< -f bin -o $@

clean:
	rm -fr *.bin *.dis *.o os-image *.map boot/ *.iso
	rm -fr kernel/*.o boot/*.bin drivers/*.o
