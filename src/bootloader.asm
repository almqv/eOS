[org 0x7c00] ; bootsector

	mov bx, welcome_string		; Print the welcome string
	call println

	mov bx, info_string		; Print version info
	call println

	mov bx, hex_test_string		; Hex print test (not needed but fun)
	call print

	pusha
	mov dx, 0x002e ; test the conversion
	call hex_to_ascii
	call println
	popa

	jmp $  ; inf loop

; Load the EQUs
%include "equ/BIOS.asm"
%include "equ/ASCII.asm"

; SRs
%include "elib/io.asm"
%include "elib/convert.asm"

welcome_string:		db "e Operating-System (eOS)", ASCII_END
info_string: 		db "Version 2021 0.0", ASCII_END
hex_test_string:	db "Hex printing test: ", ASCII_END

times 510-($-$$) db 0
db 0x55, 0xaa ; magic BIOS numbers
