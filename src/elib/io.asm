; eLibrary
; Input/Output subroutines

; String structure
; ASCII Offset = 8 bits
; Array of the char  bytes, ending with 0 (ASCII_END)

eLIB_STR_OFFSET equ 8 ; 8 bits

print:	; Subroutine to print strings (from stack)
	; Input: RCX, takes pointer to string from stack
	pop rcx

	; rcx now holds the starting point (address)

	printLoop:
		; Print the char
		mov al, [rcx] ; dereference address to get value
		cmp al, ASCII_END ; check if ASCII end
		je printExit ; if reached the end then return

		int BIOS_INT ; system interupt (print string)
		add rcx, eLIB_STR_OFFSET ; increase with offset
		jmp printLoop ; loop for next char

	printExit:
		ret
