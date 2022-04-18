// Function to read a byte from port
unsigned char inb(unsigned short port) {
	unsigned char res;
	__asm__("in %%dx, %%al" : "=a" (res) : "d" (port));

	return res;
}

// to write a byte to port
void outb(unsigned short port, unsigned char data) {
	__asm__("out %%al, %%dx" : :"a" (data), "d" (port));	
}


// Read word from port
unsigned short inw(unsigned short port) {
	unsigned short res;
	__asm__("in %%dx, %%ax" : "=a" (res) : "d" (port));

	return res;
}

// write word to port
void outw(unsigned short port, unsigned short data) {
	__asm__("out %%ax, %%dx" : :"a" (data), "d" (port));
}


static inline void io_wait() { 
	outb(0x80, 0); 
}

unsigned char inb_w(unsigned short port) {
	inb(port);
	io_wait();
}

void outb_w(unsigned short port, unsigned char data) {
	outb(port, data);
	io_wait();
}

unsigned short inw_w(unsigned short port) {
	inw(port);
	io_wait();
}

void outw_w(unsigned short port, unsigned short data) {
	outw(port, data);
	io_wait();
}

