#include "interupt.h"

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

void init_IDT(uint type_attr) {
	__attribute__((aligned(4)))
	static idt_entry IDT[256];
	static idtr	IDTR;
}

__attribute__((noreturn))
void exception_handler(void);
void exception_handler() {
	__asm__ __volatile__("cli; hlt");
}

void interupt_handler() {
	__asm__("pusha");
	// handle stuff
	__asm__("popa; leave; iret");
}
