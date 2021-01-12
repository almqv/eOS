%include "equ/BIOS.asm"
%include "equ/ASCII.asm"

mov ah, BIOS_MODE_TELETYPE ; enter teletype mode (BIOS)

mov al, ASCII_LINEBREAK ; linebreak
int BIOS_INT

; Print "eOS"
mov al, "e"
int BIOS_INT 

mov al, "O"
int BIOS_INT

mov al, "S"
int BIOS_INT

mov al, ASCII_CARRIAGE_RETURN
int BIOS_INT

mov al, ASCII_LINEBREAK ; linebreak
int BIOS_INT

; ALPHABET PRINT TEST
mov al, 64 ; one less than A since we are printing in a loop and it increments before sys interupt
loop:
	; Print the alphabetic char
	inc al ; move to next char
	int BIOS_INT ; bios interupt to print it

	cmp al, 90 ; 26 letters in english alphabet (64 + 26)
	jl loop ; if al < 64+26: jmp loop


jmp $ 

times 510-($-$$) db 0
db 0x55, 0xaa
