#include "interupt.h"

struct InteruptDescriptor {
	uint16	offset_1;	// offset 0 to 15 bits
	uint16	selector;	// code segment sel
	uint8	null;		// "padding", should be zero
	uint8	type_attr;	// type & attr stuff
	uint16	offset_2;	// offset 16 to 31
};

void init_IDT(uint type_attr) {
	__asm__ __volatile__("lgdt %[idt_pointer]");
}

void int_handler() {
	__asm__("pusha");
	// handle stuff
	__asm__("popa; leave; iret");
}
