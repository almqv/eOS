#include "kernel.h"
#include "memory.h"
#include "paging.h"
#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/conv.h"

void init() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	println("Kernel loaded", SUCCESS_COLOR);

	// enable_paging();

	println("");
	char* title = "eOS Version 0.3 2021";
	println(title, DEFAULT_COLOR);

	char* subtitle = "A x86 operating system, licenced under GPL-2.0";
	println(subtitle, DEFAULT_COLOR);

	/*
	print("Kernel offset: ", DEFAULT_COLOR);
	println("0x1000", DEFAULT_COLOR);
	*/


	char* intbuf = "xxxx";
	int num = 1234;
	intbuf = int_to_str(num, intbuf);
	print("TEST NUM: ", DEFAULT_COLOR);
	println(intbuf, DEFAULT_COLOR);

	/*

	// Memory allocation testing
	printalign("-- PMM Tests --", DEFAULT_COLOR, MIDDLE);

	println("THESE ALLOC SHOULD WORK:", 0xa0);
	for(int i=0; i < 4; i++) {
		block_alloc(i);
	}

	println("(2) THIS ALLOC SHOULD FAIL:", 0xc0);
	block_alloc(2); // this should fail

	println("(2) Freeing 2nd block, alloc after should succeed", DEFAULT_COLOR);
	block_free(2); // after this, allocation of 2nd block should work
	block_alloc(2);

	printalign("-- End of PMM Tests --", DEFAULT_COLOR, MIDDLE);

	char* strbuf = "Concat test: ";
	char* str2 = "Works!";
	strbuf = strcat(strbuf, str2); 
	println(strbuf, DEFAULT_COLOR);
	*/
}
