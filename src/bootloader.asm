%include "BIOS_equ.asm"
mov ah, 0x0e ; enter teletype mode (BIOS)

mov al, "e"
int BIOS_INT 

mov al, "O"
int BIOS_INT

mov al, "S"
int BIOS_INT

mov al, 10 ; linebreak
int BIOS_INT

; ALPHABET PRINT
mov al, 64 ; one less than A since we are printing in a loop and it increments before sys interupt
loop:
	inc al ; move to next char
	int BIOS_INT ; bios interupt to print it
	push al ; push al onto stack

	mov al, 10 ; ASCII linebreak
	int BIOS_INT 

	pop al ; return to char

	cmp al, 91 ; 26 letters in english alphabet (65 + 26)
	jl loop ; if al < 65+26: jmp loop

jmp $ 

times 510-($-$$) db 0
db 0x55, 0xaa
