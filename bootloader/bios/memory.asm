; SRs to find memory size and leave it as a "note" for the kernel

mmap_e820:
	mov di, 0x8004
	mov ebx, 0	; Must be 0 
	mov bp, 0	; entry count

	mov eax, 0xe820	; function reg
	mov edx, 'SMAP'

	mov [es:di + 20], dword 1	; fill
	mov ecx, 24					; ask for 24 bytes
	int 0x15					; Do the interupt

	; carry flag = (un)supported function
	jc short mmap_fail

	; TODO more error stuff
	cmp eax, edx
	jne short mmap_fail

	test ebx, ebx
	je short mmap_fail

mmap_fail:
	stc
	ret

e820_dt_start:	
	e820_low: dd 0
	e820_high: dd 0
	e820_len_low: dd 0
	e820_len_high: dd 0
	e820_type: dd 0
e820_dt_end:

