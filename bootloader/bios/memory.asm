; SRs to find memory size and leave it as a "note" for the kernel
; Descriptor Table for address ranges
map_phys_mem_init:
	mov ebx, 0
map_phys_mem:
	mov eax, 0xE820 ; Function code
	; Tell the CPU about the descriptors location (ES:DI)
	;mov es, addr_rng_dt_start
	;mov di,
	mov ecx, ADDR_RNG_DT_SIZE
	mov edx, 'SMAP' ; Signature
	int BIOS_PMEM_INT

	ret

addr_rng_dt_start:	
	addr_rng_low: dd 0
	addr_rng_high: dd 0
	addr_rng_len_low: dd 0
	addr_rng_len_high: dd 0
	addr_rng_type: dd 0
addr_rng_dt_end:


ADDR_RNG_DT_SIZE equ addr_rng_dt_end - addr_rng_dt_start
