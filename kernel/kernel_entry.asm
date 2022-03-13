[bits 32]
[extern kernel_init]

MBOOT_PAGE_ALIGN        equ 1<<0
MBOOT_MEMORY_INFO       equ 1<<1
MBOOT_HEADER_MAGIC      equ 0x1BADB002
MBOOT_HEADER_FLAGS      equ MBOOT_PAGE_ALIGN | MBOOT_MEMORY_INFO
MBOOT_CHECKSUM          equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

;align 4
;multiboot_header:
;	dd MBOOT_HEADER_MAGIC
;    dd MBOOT_HEADER_FLAGS
;    dd MBOOT_CHECKSUM
	

call kernel_init 
jmp $
