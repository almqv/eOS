[bits 32]

; VGA base address: 0xb8000
; Charpos = 0xb8000 + 2(row*80 + col)

vga_print:
	pusha
	mov edx, VIDEO_MEM

	vga_print_loop:
		mov al, [ebx]		; Pointer to char
		mov ah, 0x8f		; Color code

		cmp al, ASCII_END	; Check if end of string
		je vga_print_return	; If end then return

		mov [edx], ax		; Move charpos
		inc ebx			; Increment to next
		add edx, 2

		jmp vga_print_loop	; Loop back until end of string
	
	vga_print_return:
		popa
		ret
