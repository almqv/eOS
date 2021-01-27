HEX_OUT: db "0x0000", ASCII_END

; SR to convert hex values into ASCII strings
; This SR is going to mess up some registers
; since it fills the register with the desired 
; pointer toward the string.
hexToASCII:
	; pusha
	mov cx, 0 ; incrementor

	hexloop:
		cmp cx, 4 ; check if we reached the end 
		je return ; if so just return our new ASCII string
		
		mov ax, dx

		; mask the hex value in ax so that we get the last "char"
		and ax, 0x000f
	
		; convert ax into ASCII (numeric)
		add al, ASCII_OFFSET_NUM ; add 0x30

		cmp al, 0x39 ; if al (char) > "9"
		jle hexloop2

		add al, 7 ; 7 distance from "A"

	hexloop2:
		; Write the char into the HEX_OUT string
		mov bx, HEX_OUT + 5
		sub bx, cx

		mov [bx], al ; write the char into the string
		ror dx, 4 ; "rotate" the string

		inc cx ; increment and go onto next char
		jmp hexloop

	return:
		mov bx, HEX_OUT
		ret
