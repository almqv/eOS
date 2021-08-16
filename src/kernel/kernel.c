#include <stdio.h>
#include "lib/vga.c"

void main() {
	clear_screen();
	set_cursor_pos(24, 0);
	println("eOS Version 0.0 2021", 0xf0);
}
