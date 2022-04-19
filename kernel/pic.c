#include "pic.h"
#include "io.h"

void pic_send_eoi(uint8 irq) {
	if( irq >= 8 ) 
		outb(PIC2_CMD, PIC_EOI);
	outb(PIC1_CMD, PIC_EOI);
}

// disable the PIC
void pic_disable() {
	outb(PIC1_DATA, 0xff);
	outb(PIC2_DATA, 0xff);
}

void pic_remap(uint offset_1, uint offset_2) {
	// Start the init sequance
	outb_w(PIC1_CMD, ICW_INIT_MASK); // write ICW1 to PIC master
	outb_w(PIC2_CMD, ICW_INIT_MASK); // --||-- to PIC slave

	outb_w(PIC1_DATA, offset_1);  // remap master
	outb_w(PIC2_DATA, offset_2);  // remap slave

	outb_w(PIC1_DATA, 0x04); // IRQ2 to slave 
	outb_w(PIC2_DATA, 0x02);

	outb_w(PIC1_DATA, ICW4_8086); // write ICW4 to PIC master
	outb_w(PIC2_DATA, ICW4_8086); // --||-- to PIC slave

	//pic_disable();

	// enable all
	outb(PIC1_DATA, 0x01);
	outb(PIC2_DATA, 0x01);
}

void pic_init() {
	pic_remap(0x20, 0x28);
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

