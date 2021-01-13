[org 0x7c00] ; bootsector

jmp $  ; inf loop

;; includes
; EQU
%include "equ/BIOS.asm"
%include "equ/ASCII.asm"

; eLIB
;%include "elib/io.asm"

;; Data
welcomeString:
	db "Welcome to eOS", ASCII_CARRIAGE_RETURN, ASCII_LINEBREAK

; Magic BIOS number 
times 510-($-$$) db 0
db 0x55, 0xaa
