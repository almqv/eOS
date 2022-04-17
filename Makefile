# Compiler/assembler settings
CC			= gcc
CFLAGS 		= -fno-pie -m32 -Os -ffreestanding

AA			= nasm
AFLAGS		= 

LD			= gcc
LDFLAGS		= -Wl,--oformat=binary -ffreestanding -nostdlib -shared -Ttext 0x1000 -m32

# VM/Debug settings
VM			= qemu-system-x86_64
VMFLAGS		= 


# Do not touch these.
C_SOURCES 	= $(wildcard kernel/*.c drivers/*.c lib/*.c)
HEADERS 	= $(wildcard kernel/*.h drivers/*.h lib/*.h)
OBJ 		= $(C_SOURCES:.c=.o)

all: eos.iso

run: all
	$(VM) $(VMFLAGS) eos.iso


drun: clean run

grub: eos_grub.iso
	$(VM) $(VMFLAGS) eos_grub.iso

eos_grub.iso : kernel.bin grub/grub.cfg
	mkdir -p boot/grub
	cp $< boot/eOS.bin
	cp grub/grub.cfg boot/grub/grub.cfg
	grub-mkrescue -o eos_grub.iso ./

eos.iso: bootloader/bootloader.bin kernel.bin
	cat $^ > eos.iso

kernel.bin: kernel/multiboot2.o kernel/kernel_entry.o kernel/enable_paging.o $(OBJ) 
	$(LD) -o $@ $^ $(LDFLAGS) 


%.o : %.c ${HEADERS}
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.asm
	$(AA) $< -f elf -o $@ $(AFLAGS)

%.bin : %.asm
	$(AA) $< -f bin -o $@ $(AFLAGS)

clean:
	rm -fr *.bin *.dis *.o eos.iso *.map boot/ *.iso
	rm -fr kernel/*.o bootloader/*.bin drivers/*.o
