disk_read:
	pusha

	push dx
	mov ah, BIOS_DISK_READ 
	mov al, dh ; sector count 
	mov cl, 0x02

	mov ch, 0x00 ; read from first cylinder
	mov dh, 0x00 ; head

	; data pointer: es:bx (standard)
	int BIOS_DISK_INT ; do the interrupt
	jc read_error ; if flag is set then jump to error

	pop dx
	cmp al, dh
	jne sector_error
	
	popa
	ret 

sector_error:
	mov bx, sector_error_string
	call println

read_error:
	mov bx, read_error_string
	call println

	mov dh, ah
	call print_hex 

disk_loop:
	jmp $

read_error_string: 	db "Disk read error", ASCII_END
sector_error_string:	db "Invalid number of sectors read", ASCII_END
