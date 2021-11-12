#include "kernel.h"
#include "memory.h"
#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/strf.h"

void display_status(char* status_text) {
	clear_row(0);
	set_cursor_pos(0, 0);

	print(status_text, 0x7f);
}

void init() {
	clear_screen();
	display_status("Kernel loaded");

	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	char* title = "eOS Version 0.2 2021";
	println(title, DEFAULT_COLOR);

	char* subtitle = "A x86 operating system, licenced under GPL-2.0";
	println(subtitle, DEFAULT_COLOR);

	/*
	print("Kernel offset: ", DEFAULT_COLOR);
	println("0x1000", DEFAULT_COLOR);
	*/

	char* strbuf = "Concat test: ";
	char* str2 = "Works!";
	strbuf = strcat(strbuf, str2); 
	println(strbuf, DEFAULT_COLOR);
}
