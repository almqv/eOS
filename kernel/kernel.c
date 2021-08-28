#include "../drivers/vga.h"
#include "../lib/strf.h"

void main() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	int test = 1234;
	char* teststr;
	teststr = int_to_str(test, teststr);
	println(teststr, 0xf0);

	set_cursor_pos(28, 2);
	print("eOS Version 0.1 2021", 0xf0);
}
