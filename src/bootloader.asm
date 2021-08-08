[org 0x7c00] ; bootsector
	; Save the boot drive index
	mov [BOOT_DRIVE], dl

	; Move the stack pointer somewhere safe
	mov bp, 0x8000 ; move it to 0x8000
	mov sp, bp

	; Switching to PM
	call pm_preinit

	jmp $  ; inf loop

%include "equ/ascii.asm"
%include "bios.asm"
%include "pm.asm"

BEGIN_PM:
	mov ebx, welcome_string
	call vga_print

	jmp $

welcome_string:	db "e Operating-System (eOS): Version 2021 0.0", ASCII_END
BOOT_DRIVE: db 0

; Bootsector
times 510-($-$$) db 0
dw 0xaa55 ; magic BIOS numbers
