#include "lib/vga.c"

void main() {
	// Do kernel stuff
	char* vidmem = (char*)0xb8000;
	*vidmem = 'X';

	clear_screen();
	println("eOS Version 0.0 2021", 0x0f);
}
