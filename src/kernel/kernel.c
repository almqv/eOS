#include "lib/vga.c"

void main() {
	// Do kernel stuff
	char* vidmem = (char*)0xb8000;
	*vidmem = 'X';

	clear_screen();
	set_cursor_pos(24, 0);
	println("\t eOS Version 0.0 2021", 0xf0);
}
