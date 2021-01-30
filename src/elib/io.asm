; eLibrary
; Input/Output subroutines

; Subroutine to print a string
print:
	pusha ; save current state of registers

	printLoop:
		; Char check
		mov al, [bx] ; load the char
		cmp al, ASCII_END ; check if end of string
		je printreturn ; if al == ASCII_END then return end | lua is good psuedo-code


		; BIOS Printing
		mov ah, BIOS_MODE_TELETYPE ; enter tty mode
		int BIOS_INT ; interupt and print the char (from line 10)

		; Preperation for next iteration
		inc bx ; increment the pointer to get next char
		jmp printLoop ; repeat 

	printreturn:
		popa ; restore all registers
		ret ; return to previous location


newline: db ASCII_CARRIAGE_RETURN, ASCII_LINEBREAK, ASCII_END ; used for printing newlines

; Subroutine to print a string on a new line
println:
	pusha

	; Print the input string
	call print ; this will print whatever is in [bx], so clear it if you dont want to print anything

	; Print the newline
	mov bx, newline
	call print

	popa
	ret 
