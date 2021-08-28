#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/strf.h"

void main() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	set_cursor_pos(28, 2);
	print("eOS Version 0.1 2021", 0x0f);


	char* strbuf = "Hello";
	char* str2 = "World!";
	strbuf = strcat(strbuf, str2); 
	set_cursor_pos(0, 0);
	println(strbuf, 0x0f);
}
