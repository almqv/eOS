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
%include "bootloader/equ/bios.asm"

; BIOS SRs
%include "bootloader/bios/convert.asm"
%include "bootloader/bios/print.asm"
%include "bootloader/bios/disk.asm"

; Protected Mode SRs 
%include "bootloader/equ/vga.asm"
%include "bootloader/pm/vga/print.asm"

; GDT & switching to PM
%include "bootloader/pm/gdt.asm" 	; GDT defined here

; Switching to PM
[bits 16]
pm_preinit:
	cli			; Switch interupts

	lgdt [gdt_descriptor] 	; Tell the CPU about the GDT

	mov eax, cr0		; Set first bit of the CR0 register
	or eax, 0x1		; to 1
	mov cr0, eax		; Update the control register

	; Initialize PM
	jmp GDT_CODE_SEG:pm_init	

[bits 32]
; Init registers & stack when in PM
pm_init:
	mov ax, GDT_DATA_SEG	; Point the segment registers to GDT_DATA_SEG
	; Segment registers
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov ebp, 0x900000	; Update the stack pointer
	mov esp, ebp

	call BEGIN_PM

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
	mov dh, 10				; Read sectors
	mov dl, [BOOT_DRIVE]	; Drive index
	call disk_read			; Load the kernel

	ret

stat_pm_init:		db "Entering 32bit Protected Mode...", ASCII_END
stat_kernel_load:	db "Loading kernel into memory...", ASCII_END
stat_boot_success:	db "Booting finished. Loading kernel...", ASCII_END

BOOT_DRIVE: db 0

; Bootsector
times 510-($-$$) db 0
dw 0xaa55 ; magic BIOS numbers
