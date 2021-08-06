; GDT

gdt_start:

gdt_null:		; NULL descriptor
	dd 0x0		; 4-bytes of 
	dd 0x0		; 0x0 (0) = NULL

gdt_code: 		; Code SD
	; Range: 	0x0 - 0xfffff
	; Flags1: 	1001b (present:2 privilege:descriptor type)
	; Type:		1010b (code:conforming:readable:accessed)
	; Flags2:	1100b (granularity:32bit default:64bit seg:AVL)

	dw 0xffff		; Limit (bits 0-15)
	dw 0x0			; Base (bits 0-15)
	db 0x0			; Base (bits 16-23)
	db 10011010b 	; Flags1 : Type
	db 11001111b	; Flags2 : Limit (16-19)
	db 0x0			; Base (bits 24-31)

gdt_data:		; Data SD
	; Same flags as gdt_code but different type flags
	; Type: 	0010b (code:expand dowm:writable:accessed)

	dw 0xffff		; Limit (bits 0-15)
	dw 0x0			; Base (bits 0-15)
	db 0x0			; Base (bits 16-23)
	db 10010010b 	; Flags1 : Type
	db 11001111b	; Flags2 : Limit (16-19)
	db 0x0			; Base (bits 24-31)

gdt_end:		; Mark the end so we can get the delta-memory (size of GDT)

; GDT descriptor
gdt_descriptor:
	dw gdt_end - gdt_start - 1		; Size of GDT is always -1 of actual size (WHY?!?!?!?!??!)
	dd gdt_start					; Pointer to the GDT


; Lazy constants
GDT_CODE_SEG equ gdt_code - gdt_start
GDT_DATA_SEG equ gdt_data - gdt_start
