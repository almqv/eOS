#include "lib/vga.c"

void main() {
	// Do kernel stuff
	char* vidmem = (char*)0xb8000;
	*vidmem = 'X';
	for( int i = 0; i < 16; i++ ) {
		println("C-Printing test!", 16);
	}
}
