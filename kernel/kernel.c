#include "kernel.h"

char** eos_art = {
	"\0"
};

void kernel_init() {
	vga_init(); 	// Initialize the screen first
			// i.e. clear the screen et cetera.

	// Allocate VGA memory range
	pm_malloc_range(VGA_ADDRESS, VGA_ADDRESS_MAX, true); // force alloc the VGA range

	// ENABLE PAGING 
	// TODO: make this work
	// enable_paging();

	printalign("      ___  ____                           ", BANNER_COLOR, MIDDLE);
	printalign("  ___ / _ \\/ ___|                           ", BANNER_COLOR, MIDDLE);
	printalign(" / _ \\ | | \\___ \\                           ", BANNER_COLOR, MIDDLE);
	printalign("|  __/ |_| |___) |    A x86 operating system,", BANNER_COLOR, MIDDLE);
	printalign(" \\___|\\___/|____/     licenced under GPL-2.0", BANNER_COLOR, MIDDLE);

	println("");

	printalign("Fun fact: e = lim[h->0] (1+h)^(1/h)", DEFAULT_COLOR, MIDDLE);
	printalign("Created by Elias Almqvist", DEFAULT_COLOR, MIDDLE);

// 	for(char* line = *eos_art; line; line=*++eos_art) {
// 		print(":::: ");
// 		printalign(line, DEFAULT_COLOR);
// 	}
}
