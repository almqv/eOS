;disk_read:
;	push dx
;	mov ah, BIOS_DISK_READ 
;	mov al, dh ; sector count 
;	mov cl, 0x02 ; second sector (after bootsection)
;
;	mov ch, 0x00 ; read from first cylinder
;	mov dh, 0x00 ; head
;
;	; data pointer: es:bx (standard)
;	int BIOS_DISK_INT ; do the interrupt
;	jc read_error ; if flag is set then jump to error
;
;	pop dx
;	cmp al, dh
;	jne sector_error
;	
;	ret 

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

disk_loop:
	jmp $

read_error_string:		db "Disk read error!", ASCII_END
sector_error_string:	db "Invalid number of sectors read!", ASCII_END
