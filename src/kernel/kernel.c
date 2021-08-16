#include <stdio.h>
#include "lib/vga.c"

void main() {
	clear_screen();
	set_cursor_pos(28, 2);
	print("eOS Version 0.0 2021", 0xf0);
}
