[org 0x7c00] ; bootsector

mov bx, welcomeString ; Print the welcome string
call println

mov bx, infoString
call println

mov bx, hexTestPrefixString
call print

mov dx, 0x002e ; test the conversion
call hexToASCII
call println

jmp $  ; inf loop

;; includes
; EQU
%include "equ/BIOS.asm"
%include "equ/ASCII.asm"

; eLIB
%include "elib/io.asm"
%include "elib/convert.asm"

;; Data
welcomeString:		db "Welcome to: e Operating-System (eOS)", ASCII_END
infoString: 		db "Version 2021 0.0", ASCII_END
hexTestPrefixString:	db "Hex printing test: ", ASCII_END

; Magic BIOS number 
times 510-($-$$) db 0
db 0x55, 0xaa
