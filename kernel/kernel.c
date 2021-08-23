#define NULL ((void*)0x0)

#include "../drivers/vga.h"

void main() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	set_cursor_pos(28, 2);
	print("eOS Version 0.1 2021", 0xf0);
}
