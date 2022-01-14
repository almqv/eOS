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

	// Allocate VGA memory range
	println("Allocating VGA memory...", DEFAULT_COLOR);
	pm_malloc_range(VGA_ADDRESS, VGA_ADDRESS_MAX, true); // force alloc the VGA range

	// TODO: MAKE THESE DYNAMIC
	print("Kernel offset: ", DEFAULT_COLOR);
	println("0x1000", DEFAULT_COLOR);
	
	println("-VGA Stats-", DEFAULT_COLOR);
	print("Start: ", DEFAULT_COLOR);
	println("0xb7000", DEFAULT_COLOR);

	print("End:   ", DEFAULT_COLOR);
	println("0xb8fa0", DEFAULT_COLOR);

	// ENABLE PAGING 
	// TODO: make this work
	// enable_paging();

	println("");
	char* title = "eOS Version 0.4 2022";
	println(title, DEFAULT_COLOR);

	char* subtitle = "A x86 operating system, licenced under GPL-2.0";
	println(subtitle, DEFAULT_COLOR);

	// Memory allocation testing
	printalign("-- PMM malloc Tests --", DEFAULT_COLOR, MIDDLE);

	println("THESE MALLOC SHOULD WORK (no text => success):", 0xa0);
	for(int i=0; i < 4; i++) {
		pm_malloc(1);
	}

	println("(2) THIS ALLOC SHOULD FAIL:", 0xc0);
	block_alloc(2); // this should fail

	println("(2) Freeing 2nd block, alloc after should succeed", DEFAULT_COLOR);
	block_free(2); // after this, allocation of 2nd block should work
	block_alloc(2);

	printalign("-- End of PMM malloc Tests --", DEFAULT_COLOR, MIDDLE);

	char* strbuf = "Concat test: ";
	char* str2 = "Works!";
	strbuf = strcat(strbuf, str2); 
	println(strbuf, DEFAULT_COLOR);
}
