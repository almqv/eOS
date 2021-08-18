unsigned char port_byte_in(unsigned short port) {
	unsigned char res;
	__asm__("in %%dx, %%al" : "=a" (res) : "d" (port));

	return res;
}

void port_byte_out(unsigned short port, unsigned char data) {
	
}
