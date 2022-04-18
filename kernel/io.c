// Function to read a byte from port
unsigned char port_inb(unsigned short port) {
	unsigned char res;
	__asm__("in %%dx, %%al" : "=a" (res) : "d" (port));

	return res;
}

// to write a byte to port
void port_outb(unsigned short port, unsigned char data) {
	__asm__("out %%al, %%dx" : :"a" (data), "d" (port));	
}


// Read word from port
unsigned short port_inw(unsigned short port) {
	unsigned short res;
	__asm__("in %%dx, %%ax" : "=a" (res) : "d" (port));

	return res;
}

// write word to port
void port_outw(unsigned short port, unsigned short data) {
	__asm__("out %%ax, %%dx" : :"a" (data), "d" (port));
}


static inline void io_wait() { port_outb(0x80, 0); }
