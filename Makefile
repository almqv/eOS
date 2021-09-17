C_SOURCES = $(wildcard kernel/*.c drivers/*.c lib/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h lib/*.h)
OBJ = $(C_SOURCES:.c=.o)

all: eos.iso

run: all
	qemu-system-x86_64 eos.iso


drun: clean run

grub: eos_grub.iso
	qemu-system-x86_64 eos_grub.iso

eos_grub.iso : kernel.bin grub/grub.cfg
	mkdir -p boot/grub
	cp $< boot/eOS.bin
	cp grub/grub.cfg boot/grub/grub.cfg
	grub-mkrescue -o eos_grub.iso ./

eos.iso: bootloader/bootloader.bin kernel.bin
	cat $^ > eos.iso

kernel.bin: kernel/kernel_entry.o $(OBJ) 
	gcc -o $@ $^ -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32


%.o : %.c ${HEADERS}
	gcc -fno-pie -m32 -Os -ffreestanding -c $< -o $@

%.o : %.asm
	nasm $< -f elf -o $@

%.bin : %.asm
	nasm $< -f bin -o $@

clean:
	rm -fr *.bin *.dis *.o eos.iso *.map boot/ *.iso
	rm -fr kernel/*.o bootloader/*.bin drivers/*.o
