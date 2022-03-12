[bits 32]
[extern kernel_init]

multiboot2:
	dw 0xE85250D6

call kernel_init 
jmp $
