[bits 32]
[extern init]

multiboot2:
	dw 0xE85250D6

call init 
jmp $
