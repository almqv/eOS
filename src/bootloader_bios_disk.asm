disk_read:
	pusha

	mov ah, BIOS_DISK_READ 
	mov al, dh ; number of sectors to read
