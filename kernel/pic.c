#include "pic.h"
#include "io.h"

void pic_send_eoi(uint8 irq) {
	if( irq >= 8 ) 
		outb(PIC2_CMD, PIC_EOI);
	outb(PIC1_CMD, PIC_EOI);
}

void pic_remap(uint offset_1, uint offset_2) {
	// Start the init sequance
	outb_w(PIC1_CMD, ICW_INIT_MASK);

	outb_w(PIC2_CMD, ICW_INIT_MASK);

	outb_w(PIC1_DATA, offset_1); 
	outb_w(PIC2_DATA, offset_2); 

	outb_w(PIC1_DATA, 0x4); 
	outb_w(PIC2_DATA, 0x2);

	outb_w(PIC1_DATA, ICW4_8086);
	outb_w(PIC2_DATA, ICW4_8086);

	outb(PIC1_DATA, 0xff);
	outb(PIC2_DATA, 0xff);
}

// disable the PIC
// will probably never use this.
void pic_disable() {
	outb(PIC1_DATA, 0xff);
	outb(PIC2_DATA, 0xff);
}


void pic_init() {
	pic_remap(PIC1, PIC2);
}

// (un)set a specific irq
void irq_mask(uint8 idx, bool t) {
	uint16 port;
	uint8 data;

	if(idx < 8) {
		port = PIC1_DATA;
	} else {
		port = PIC2_DATA;
		idx -= 8;
	}

	if( t == true ) { // set irq 
		data = inb(port) | (1 << idx);
		outb(port, data);
	} else { // clear irq
		data = inb(port) & ~(1 << idx);
		outb(port, data);
	}
}

static uint16 irq_reg(int ocw3) {
	outb(PIC1_CMD, ocw3);
	outb(PIC2_CMD, ocw3);
	return (inb(PIC2_CMD) << 8 | inb(PIC1_CMD));
}

uint16 get_irr() { return irq_reg(PIC_R_IRR); } // fetch IRR 
uint16 get_isr() { return irq_reg(PIC_R_ISR); } // fetch ISR

