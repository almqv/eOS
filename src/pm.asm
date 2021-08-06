; Utils
%include "equ/vga.asm" 
%include "pm/vga/print.asm" 

; GDT & switching to PM
%include "pm/gdt.asm" 	; GDT defined here

; Switching to PM
[bits 16]
switch_to_pm:
	cli			; Switch interupts

	lgdt [gdt_descriptor] 	; Tell the CPU about the GDT

	mov eax, cr0		; Set first bit of the CR0 register
	or eax, 0x1		; to 1
	mov cr0, eax		; Update the control register

[bits 32]
; Init registers & stack when in PM
init_pm:
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

