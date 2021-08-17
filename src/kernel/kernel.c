#include "lib/vga.c"
#include <string.h>

void main() {
	clear_screen();
	set_cursor_pos(28, 2);
	print("eOS Version 0.1 2021", 0xf0);
}
