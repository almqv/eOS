#include "pic.h"
#include "io.h"

void PIC_sendEOI(uint8 irq) {
	if( irq >= 8 ) 
		outb(PIC2_CMD, PIC_EOI);
	outb(PIC1_CMD, PIC_EOI);
}

void PIC_remap(uint offset_1, uint offset_2) {
	uint8 a1, a2; 
	a1 = inb(PIC1_DATA);
	a2 = inb(PIC2_DATA);

	// Start the init sequance
	outb_w( PIC1_CMD, ICW_INIT_MASK );

	outb_w(PIC2_CMD, ICW_INIT_MASK );

	outb_w(PIC1_DATA, offset_1); // ICW2 master offset
	outb_w(PIC2_DATA, offset_2); // ICW2 slave offset

	outb_w(PIC1_DATA, 0x4);
	outb_w(PIC2_DATA, 0x2);
}
