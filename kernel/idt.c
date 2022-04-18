#include "idt.h"

typedef struct {
	uint16	offset_1;	// offset 0 to 15 bits
	uint16	selector;	// code segment sel
	uint8	reserved;	// should be zero
	uint8	type_attr;	// type & attr stuff
	uint16	offset_2;	// offset 16 to 31
} __attribute__((packed)) idt_entry;

typedef struct {
	uint16	limit;
	uint	base;
} __attribute__((packed)) idtr;

__attribute__((aligned(16)))
static idt_entry IDT[IDT_MAX_DESCS];
static idtr	IDTR;

void exception_handler() {
	uint* debug_ptr = 0xe222;
	uint8 debug = *debug_ptr;

	char* buf;

	print("[E] ", INT_COLOR);

	buf = itoa(debug, buf, 10);
	println(buf, 0x0f);

	__asm__ __volatile__("cli; iret");
}

void idt_set_desc(uint8 idx, void* isr, uint8 flags) {
	idt_entry* desc = &IDT[idx]; // get descriptor

	desc->offset_1	= (uint) isr & 0xffff;
	desc->selector	= 0x08; // kernel code selector for the GDT 
	desc->reserved	= 0; 
	desc->type_attr	= flags;
	desc->offset_2	= (uint) isr >> 16;
}

extern void* isr_stub_table[];
void idt_init() {
	IDTR.base = (uintptr) &IDT[0]; // base offset
	IDTR.limit = (uint16) sizeof(idt_entry) * IDT_MAX_DESCS - 1;

	for (uint8 idx = 0; idx < 32; idx++) 
		idt_set_desc(idx, isr_stub_table[idx], 0x8e);

	__asm__ __volatile__("lidt %0" : : "m"(IDTR));
	__asm__ __volatile__("sti");
}
