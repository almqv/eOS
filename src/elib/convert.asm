HEX_OUT: db "0x0000", ASCII_END

; SR to convert hex values into ASCII strings
; This SR is going to mess up some registers
; since it fills the register with the desired 
; pointer toward the string.
hexToASCII:
	mov cx, 0 ; incrementor

	hexloop:
		

	return:
		mov bx, HEX_OUT
		ret
