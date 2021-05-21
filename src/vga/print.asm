[bits 32]

; VGA base address: 0xb8000
; Charpos = 0xb8000 + 2 * (row * 80 + col)

vga_print:
	pusha
	mov edx, VIDEO_MEM

	vga_print_loop:
		mov al, [ebx]
		mov ah, 0x0f

		cmp al, ASCII_END
		je vga_print_return

		mov [edx], ax
		inc ebx
		add edx, 2

		jmp vga_print_loop
	
	vga_print_return:
		popa
		ret
