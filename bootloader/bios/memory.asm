; SRs to find memory size and leave it as a "note" for the kernel
[org 0x0000]

sig_0x15: db "SMAP"

; Descriptor Table for address ranges
addr_rng_dt_start:	
	addr_rng_low: dd 0
	addr_rng_high: dd 0
	addr_rng_len_low: dd 0
	addr_rng_len_high: dd 0
	addr_rng_type: dd 0
addr_eng_dt_end:

map_phys_mem_init:
	mov ebx, 0
map_phys_mem:
	mov eax, 0xe820 ; Function code
	mov es, addr_rng_dt_start
	mov edx, sig_0x15 ; Signature
	int BIOS_PMEM_INT


