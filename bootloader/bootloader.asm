[org 0x7c00] ; bootsector
	KERNEL_OFFSET equ 0x1000

	; Save the boot drive index
	mov [BOOT_DRIVE], dl

	; Move the stack pointer somewhere safe
	mov bp, 0x9000 ; move it to 0x8000
	mov sp, bp

	; Load kernel into memory
	mov bx, stat_kernel_load
	call println
	call load_kernel

	; Switching to PM
	mov bx, stat_pm_init
	call println
	call pm_preinit

	jmp $  ; inf loop

%include "bootloader/equ/ascii.asm"
%include "bootloader/bios.asm"
%include "bootloader/pm.asm"

BEGIN_PM:
	; Inform of mode switch
	mov ebx, stat_boot_success 
	call vga_print

	; Execute kernel code
	call KERNEL_OFFSET

	jmp $

[bits 16]

load_kernel:
	mov bx, KERNEL_OFFSET	; Load kernel at the kernel offset
	mov dh, 9		; Read 15 sectors
	mov dl, [BOOT_DRIVE]	; Drive index
	call disk_read		; Load the kernel

	ret

stat_pm_init:		db "Entering 32bit Protected Mode...", ASCII_END
stat_kernel_load:	db "Loading kernel into memory...", ASCII_END
stat_boot_success:	db "Booting complete!", ASCII_END

BOOT_DRIVE: db 0

; Bootsector
times 510-($-$$) db 0
dw 0xaa55 ; magic BIOS numbers
