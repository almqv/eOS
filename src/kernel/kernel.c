#include "lib/vga.c"

void main() {
	vga_init();

	set_cursor_pos(28, 2);
	print("eOS Version 0.1 2021", 0xf0);
}
