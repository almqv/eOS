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

e820_stats_addr equ 0x9820

e820:
	mov di, e820_stats_addr + 4
	mov ebx, 0	; Must be 0 
	mov bp, 0	; entry count

	mov eax, 0xe820	; function reg
	mov edx, 'SMAP' ; function sig

	mov [es:di + 20], dword 1	; fill
	mov ecx, 24					; ask for 24 bytes
	int 0x15					; Do the interupt

	; carry flag = (un)supported function
	jc e820_fail_unsup			; TODO: Try probing instead

	cmp eax, edx				; eax should be = 'SMAP'
	jne e820_fail_smap			; if not then fail

	test ebx, ebx				; no entries
	je e820_fail_noent

e820_lp:
	mov eax, 0xe820
	mov [es:di + 20], dword 1
	mov ecx, 24
	int 0x15
	jc e820_finish ; carry => finished -> save entry count

e820_iter:
	; skip 0 entries
	jcxz e820_skip

	; check resp
	cmp cl, 20
	jbe e820_ntxt

	; check the ignore bit 
	test byte [es:di + 20], 1
	je e820_skip

e820_ntxt:
	mov ecx, [es:di + 8] ; lower mem length
	; test for 0
	or ecx, [es:di + 12] 
	jz e820_skip

	; next entry
	inc bp
	add di, 24

e820_skip:
	test ebx, ebx ; of ebx = 0 then complete
	jne e820_lp

e820_finish:
	mov [e820_stats_addr], bp ; save entry count at e820_ent
	clc
	ret

e820_fail_unsup:
	mov [e820_stats_addr], byte -1 
	jmp e820_fail
e820_fail_smap:
	mov [e820_stats_addr], byte -2 
	jmp e820_fail
e820_fail_noent:
	mov [e820_stats_addr], byte -3
	jmp e820_fail

e820_fail:
	stc
	ret
