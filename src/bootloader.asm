[org 0x7c00] ; bootsector

	; Print the welcome string
	mov bx, welcome_string
	call println

	; Read second sector


	jmp $  ; inf loop

%include "equ/ASCII.asm"
%include "bios.asm"

; Data
welcome_string:		db "e Operating-System (eOS)", ASCII_CARRIAGE_RETURN, ASCII_LINEBREAK, "Version 2021 0.0", ASCII_END
read_test_string:	db "Read bytes: ", ASCII_END

; Bootsector
times 510-($-$$) db 0
dw 0xaa55 ; magic BIOS numbers

; After bootsector 
times 256 dw 0xEEEE
times 256 dw 0xAAAA
