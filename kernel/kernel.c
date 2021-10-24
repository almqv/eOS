#include "memory.h"
#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/strf.h"

void main() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	char* title = "eOS Version 0.2 2021";
	println(title, DEFAULT_COLOR);

	char* subtitle = "A x86 operating system, licenced under GPL-2.0";
	println(subtitle, DEFAULT_COLOR);

	char* strbuf = "String concat: ";
	char* str2 = "WORKS! :D";
	strbuf = strcat(strbuf, str2); 
	set_cursor_pos(0, 4);
	println(strbuf, DEFAULT_COLOR);
}
