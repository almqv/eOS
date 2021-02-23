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
	jc disk_error ; if flag is set then jump to error

disk_error:
	mov bx, DISK_ERROR
	call println

	mov dh, ah


DISK_ERROR: db "Disk read error", ASCII_END
SECTORS_ERROR: db "Invalid number of sectors read", ASCII_END
