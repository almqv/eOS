#include "pic.h"

void PIC_sendEOI(uint8 irq) {
	if( irq >= 8 ) 
		port_outb(PIC2_CMD, PIC_EOI);
	port_outb(PIC1_CMD, PIC_EOI);
}

