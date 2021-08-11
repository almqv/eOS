//#include "lib/vga.c"

void main() {
	// Do kernel stuff
	char* vidmem = (char*)(0xb8000);
	*vidmem = 'X';
	//println("C-Printing test!", 16);
}
