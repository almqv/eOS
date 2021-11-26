[bits 32]  ; 32-bit mode

PAGING_ENABLE_FLAG equ 0x80000001
PAGE_DIRECTORY_ADDR equ 0xffffffff ; TODO: change me to something good

global enable_paging_registers ; make the SR "global" so that we can access it in the kernel etc
enable_paging_registers:
	mov eax, PAGE_DIRECTORY_ADDR ; Move the address of the 
	; page register (page directory) into eax
	; (Using eax as a middle-man register)
	mov cr3, eax ; Put the address into the cr3 register (required by the MMU)

	mov eax, cr0 ; eax as a middle-man register (again)
	or eax, PAGING_ENABLE_FLAG ; perform the OR operation on eax (ex: 0b01 or 0b10 = 0b11)
	; This is needed to enable paging (set the flag as "enabled")
	
	; DANGER: past this op memory will get weird
	mov cr0, eax ; Move it into cr0 to finally enable paging 
	; TODO: Make this work to prevent kernel "panic" (actually death) -> bootloop

	ret ; return to last location


