[org 0x7c00] ; bootsector

	mov bx, welcome_string		; Print the welcome string
	call println

	mov bx, info_string		; Print version info
	call println

	; Read from disk
	mov bp, 0x8000
	mov sp, bp ; move the stack away so that it does not get overwritten

	mov bx, 0x9000
	mov dh, 2 ; read 2 sectors
	call disk_read ; read

	mov bx, read_test_string
	call print

	mov dx, [0x9000]
	call print_hex

	mov bx, byte_sep_string
	call print

	mov dx, [0x9000 + 512]
	call print_hex

	mov bx, empty_string
	call println

	jmp $  ; inf loop

; Constants
%include "equ/ASCII.asm"

; SRs etc
%include "bios.asm"

welcome_string:		db "e Operating-System (eOS)", ASCII_END
info_string: 		db "Version 2021 0.0", ASCII_END
read_test_string:	db "Read bytes: ", ASCII_END
byte_sep_string:	db "; ", ASCII_END
empty_string:		db ASCII_END

times 510-($-$$) db 0
db 0x55, 0xaa ; magic BIOS numbers

; Bloat bytes to test reading
times 256 dw 0xEEEE
times 256 dw 0xAAAA
