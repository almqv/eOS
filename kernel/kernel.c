#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/strf.h"

void main() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	char* strbuf = "HEJ";
	char* str2 = "xD";
	strbuf = strcat(strbuf, str2); 
	println(strbuf, 0xf0);

	set_cursor_pos(28, 2);
	print("eOS Version 0.1 2021", 0xf0);
}
