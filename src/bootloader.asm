[org 0x7c00] ; bootsector

mov bx, welcomeString ; Print the welcome string
call println

mov bx, infoString
call println

jmp $  ; inf loop

;; includes
; EQU
%include "equ/BIOS.asm"
%include "equ/ASCII.asm"

; eLIB
%include "elib/io.asm"

;; Data
welcomeString: db "Welcome to    e Operating-System (eOS)", ASCII_END
infoString: db "eOS: 2021 v0.0"

; Magic BIOS number 
times 510-($-$$) db 0
db 0x55, 0xaa
