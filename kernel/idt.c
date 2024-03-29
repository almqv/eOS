#include "idt.h"
// VGA stuff
extern void set_cursor_pos(uint, uint);
extern void print(char*, int);

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

void interupt_handler(uint8 interupt) {
	char* buf;
	set_cursor_pos(0, 0);
	print("[int] ", EXC_COLOR);
	buf = itoa(interupt, buf, 10);
	print(buf, 0x0c);

	pic_send_eoi(interupt); // ack int
}

void idt_set_desc(uint8 idx, void* isr, uint8 flags) {
	idt_entry* desc = &IDT[idx]; // get descriptor

	uint* gdt_code_ptr = (uint*)0xee88;
	uint8 gdt_code = *gdt_code_ptr;

	desc->offset_1	= (ulong) isr & 0xffff;
	desc->selector	= gdt_code; // kernel code selector for the GDT 
	desc->reserved	= 0; 
	desc->type_attr	= flags;
	desc->offset_2	= (ulong) isr >> 16;
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
