[org 0x7c00] ; bootsector
	KERNEL_OFFSET equ 0x1000

	; Save the boot drive index
	mov [BOOT_DRIVE], dl

	; Move the stack pointer somewhere safe
	mov bp, 0x9000 ; move it to 0x8000
	mov sp, bp

	; Load kernel into memory
	call load_kernel

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


[bits 16]
load_kernel:
	mov bx, KERNEL_OFFSET	; Load kernel at the kernel offset
	mov dh, 15		; Read 15 sectors
	mov dl, [BOOT_DRIVE]	; Drive index
	call disk_read		; Load the kernel

	ret

welcome_string:		db "e Operating-System (eOS): Version 2021 0.0", ASCII_END

stat_realmode:		db "Entering 16bit Real Mode...", ASCII_END
stat_pm_init:		db "Entering 32bit Protected Mode...", ASCII_END

stat_success:		db " [OK]", ASCII_CARRIAGE_RETURN, ASCII_NEWLINE, ASCII_END

BOOT_DRIVE: db 0

; Bootsector
times 510-($-$$) db 0
dw 0xaa55 ; magic BIOS numbers
