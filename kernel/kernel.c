#include "kernel.h"

void kernel_init() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	println("Kernel loaded", SUCCESS_COLOR);

	// Allocate VGA memory range
	pm_malloc_range(VGA_ADDRESS, VGA_ADDRESS_MAX, true); // force alloc the VGA range

	// ENABLE PAGING 
	// TODO: make this work
	// enable_paging();

	println("");
	char* title = "eOS - lim[h->0] (1+h)^(1/h) OS";
	println(title, DEFAULT_COLOR);

	char* subtitle = "A x86 operating system, licenced under GPL-2.0";
	println(subtitle, DEFAULT_COLOR);

	char* e820_addr = (char*)0x9820;
	uint e820_count = &e820_addr;
	if ( e820_count <= 0 ) {
		println(":(", DEFAULT_COLOR);
	} else {
		println(":D", DEFAULT_COLOR);
	}
	
}
