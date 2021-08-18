// Function to read a byte from port
unsigned char port_byte_in(unsigned short port) {
	unsigned char res;
	__asm__("in %%dx, %%al" : "=a" (res) : "d" (port));

	return res;
}

// to write a byte to port
void port_byte_out(unsigned short port, unsigned char data) {
	__asm__("out %%al, %%dx" : :"a" (data), "d" (port));	
}


// Read word from port
unsigned short port_word_in(unsigned short port) {
	unsigned short res;
	__asm__("in %%dx, %%ax" : "=a" (res) : "d" (port));

	return res;
}

// write word to port
void port_word_out(unsigned short port, unsigned short data) {
	__asm__("out %%ax, %%dx" : :"a" (data), "d" (port));
}
