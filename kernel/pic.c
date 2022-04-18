#include "pic.h"
#include "io.h"

void pic_send_eoi(uint8 irq) {
	if( irq >= 8 ) 
		outb(PIC2_CMD, PIC_EOI);
	outb(PIC1_CMD, PIC_EOI);
}

void pic_remap(uint offset_1, uint offset_2) {
	uint8 a1, a2; 
	a1 = inb(PIC1_DATA);
	a2 = inb(PIC2_DATA);

	// Start the init sequance
	outb_w(PIC1_CMD, ICW_INIT_MASK);

	outb_w(PIC2_CMD, ICW_INIT_MASK);

	outb_w(PIC1_DATA, offset_1); // ICW2 master offset
	outb_w(PIC2_DATA, offset_2); // ICW2 slave offset

	outb_w(PIC1_DATA, 0x4); 
	outb_w(PIC2_DATA, 0x2);

	outb_w(PIC1_DATA, ICW4_8086);
	outb_w(PIC2_DATA, ICW4_8086);

	// restore old masks
	outb(PIC1_DATA, a1);
	outb(PIC2_DATA, a2);
}

// disable the PIC
void pic_disable() {
	outb(PIC1_DATA, 0xff);
	outb(PIC2_DATA, 0xff);
}
