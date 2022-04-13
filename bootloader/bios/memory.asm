; SRs to find memory size and leave it as a "note" for the kernel

; mmap_probe:		; literally just test the memory boundaries
; 	push eax
; 	push ebx
; 	push edx
; 	push ebp
; 
; 	mov ebp, esi
; 	add esi, 0x00000ff
; 	and esi, ~0x00000ff
; mmap_probe_addr:
; 
; mmap_probe_done:

e820:
	mov di, 0x8004
	mov ebx, 0	; Must be 0 
	mov bp, 0	; entry count

	mov eax, 0xe820	; function reg
	mov edx, 'SMAP' ; function sig

	; TODO: update es:di to e820_dt
	mov [es:di + 20], dword 1	; fill
	mov ecx, 24					; ask for 24 bytes
	int 0x15					; Do the interupt

	; carry flag = (un)supported function
	jc e820_fail			; Try probing instead

	cmp eax, edx				; eax should be = 'SMAP'
	jne e820_fail			; if not then fail

	test ebx, ebx				; no entries
	je e820_fail



e820_fail:
	stc
	ret

e820_dt_start:	
	e820_low: dd 0
	e820_high: dd 0
	e820_len_low: dd 0
	e820_len_high: dd 0
	e820_type: dd 0
e820_dt_end:

