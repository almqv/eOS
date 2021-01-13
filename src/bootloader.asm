[org 0x7c00] ; bootsector

mov bx, welcomeString ; Print the welcome string
call println

jmp $  ; inf loop

;; includes
; EQU
%include "equ/BIOS.asm"
%include "equ/ASCII.asm"

; eLIB
%include "elib/io.asm"

;; Data
welcomeString:
	db "Welcome to eOS", ASCII_END

; Magic BIOS number 
times 510-($-$$) db 0
db 0x55, 0xaa
