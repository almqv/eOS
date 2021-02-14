[org 0x7c00] ; bootsector

	mov bx, welcomeString		; Print the welcome string
	call println

	mov bx, infoString		; Print version info
	call println

	mov bx, hexTestPrefixString	; Hex print test (not needed but fun)
	call print

	pusha
	mov dx, 0x002e ; test the conversion
	call hexToASCII
	call println
	popa

	jmp $  ; inf loop

; Load the EQUs
%include "equ/BIOS.asm"
%include "equ/ASCII.asm"

; SRs
%include "elib/io.asm"
%include "elib/convert.asm"

welcomeString:		db "Welcome to: e Operating-System (eOS)", ASCII_END
infoString: 		db "Version 2021 0.0", ASCII_END
hexTestPrefixString:	db "Hex printing test: ", ASCII_END

times 510-($-$$) db 0
db 0x55, 0xaa ; magic BIOS numbers
