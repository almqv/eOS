[org 0x7c00] ; bootsector
	; Save the boot drive index
	mov [BOOT_DRIVE], dl

	; Move the stack pointer somewhere safe
	mov bp, 0x8000 ; move it to 0x8000
	mov sp, bp

	; Print the welcome string
	mov bx, welcome_string
	call println

	; Read second sector (outside bootsector)
	mov bx, 0x9000			; LOAD LOCATION 
	mov dh, 2			; SECTOR-COUNT
	mov dl, [BOOT_DRIVE]		; DISK-INDEX
	call disk_read


	; Print out whatever bloated data that was read
	mov dx, [0x9000]
	call print_hex

	mov bx, [ASCII_END]
	call println

	mov dx, [0x9000 + 512] ; read from second sector too
	call print_hex

	jmp $  ; inf loop

%include "equ/ascii.asm"
%include "bios.asm"

; Data
welcome_string:	db "e Operating-System (eOS)", ASCII_CARRIAGE_RETURN, ASCII_LINEBREAK, "Version 2021 0.0", ASCII_END
BOOT_DRIVE: db 0

; Bootsector
times 510-($-$$) db 0
dw 0xaa55 ; magic BIOS numbers

; After bootsector 
times 256 dw 0xEEEE
times 256 dw 0xAAAA
