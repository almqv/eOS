isr_debug_ptr equ 0xe222

%macro isr_err_stub 1
isr_stub_%+%1:
	cli
	pusha
	push byte %1
	call interupt_handler
	pop eax
	popa
	sti
	iret
%endmacro

extern interupt_handler
isr_err_stub	0
isr_err_stub	1 
isr_err_stub	2
isr_err_stub	3
isr_err_stub	4
isr_err_stub	5
isr_err_stub	6
isr_err_stub	7
isr_err_stub	8 ; err
isr_err_stub	9 ; keyboard?
isr_err_stub	10
isr_err_stub	11
isr_err_stub	12
isr_err_stub	13
isr_err_stub	14
isr_err_stub	15
isr_err_stub	16
isr_err_stub	17
isr_err_stub	18
isr_err_stub	19
isr_err_stub	20
isr_err_stub	21
isr_err_stub	22
isr_err_stub	23
isr_err_stub	24
isr_err_stub	25
isr_err_stub	26
isr_err_stub	27
isr_err_stub	28
isr_err_stub	29
isr_err_stub	30
isr_err_stub	31

global isr_stub_table
isr_stub_table:
	%assign i 0 
	%rep 32 
		dd isr_stub_%+i 
	%assign i i+1 
	%endrep
