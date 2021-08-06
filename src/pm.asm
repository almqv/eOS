; Utils
%include "equ/vga.asm" 
%include "pm/vga/print.asm" 

; GDT & switching to PM
%include "pm/gdt.asm" 	; GDT defined here

; Switching to PM
lgdt [gdt_descriptor] 	; Tell the CPU about the GDT

mov eax, cr0			; Set first bit of the CR0 register
or eax, 0x1			; to 1
mov cr0, eax			; Update the control register
