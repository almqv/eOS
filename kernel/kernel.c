#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/strf.h"

void main() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	char* title = "eOS Version 0.1 2021";
	set_cursor_pos(0, 2);
	printalign(title, 0xf0, MIDDLE);

	char* subtitle = "A x86 operating system, licenced under GPL-2.0";
	set_cursor_pos(0, 3);
	printalign(subtitle, 0xf8, MIDDLE);


	char* strbuf = "Hello";
	char* str2 = "World!";
	strbuf = strcat(strbuf, str2); 
	set_cursor_pos(0, 0);
	println(strbuf, 0xf0);
}
