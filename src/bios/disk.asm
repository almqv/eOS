disk_read:
	push dx ; store dx on stack so that we can compare later

	mov ah, BIOS_DISK_READ ; specify function

	mov al, dh ; read dh amount of sectors
	mov ch, 0x00 ; CYLINDER
	mov dh, 0x00 ; HEAD
	mov cl, 0x02 ; SECTOR

	int BIOS_DISK_INT ; interrupt

	; Error checks
	jc read_error ; carry flag set -> error

	pop dx
	cmp dh, al ; if dh != al then error
	jne sector_error

	ret

sector_error:
	mov bx, sector_error_string
	call println

read_error:
	mov bx, read_error_string
	call println

	mov dh, ah
	call print_hex 

	jmp $

read_error_string:		db "Disk read error!", ASCII_END
sector_error_string:	db "Invalid number of sectors read!", ASCII_END
