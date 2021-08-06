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
	dw 0x0			; Base (bits 16-23)
	db 10011010b 	; Flags1 : Type
	db 11001111b	; Flags2 : Limit (16-19)
	db 0x0			; Base (bits 24-31)
