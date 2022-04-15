#include "kernel.h"

void kernel_motd() {
	printalign("      ___  ____                           ", BANNER_COLOR, MIDDLE);
	printalign("  ___ / _ \\/ ___|                           ", BANNER_COLOR, MIDDLE);
	printalign(" / _ \\ | | \\___ \\                           ", BANNER_COLOR, MIDDLE);
	printalign("|  __/ |_| |___) |    A x86 operating system,", BANNER_COLOR, MIDDLE);
	printalign(" \\___|\\___/|____/     licenced under GPL-2.0", BANNER_COLOR, MIDDLE);

	println("");

	printalign("Fun fact: e = lim[h->0] (1+h)^(1/h)", DEFAULT_COLOR, MIDDLE);
	printalign("Created by Elias Almqvist", DEFAULT_COLOR, MIDDLE);
}

void kernel_init() {
	// Display a nice MOTD
	clear_screen();
	kernel_motd();

	vga_init(); 	// Initialize the screen first
					// i.e. clear the screen et cetera.

	// Allocate VGA memory range
	pm_malloc_range(VGA_ADDRESS, VGA_ADDRESS_MAX, true); // force alloc the VGA range
	// ENABLE PAGING 
	// TODO: make this work
	// enable_paging();

	set_cursor_pos(0, 8);
	print("E820 loaded entries: ", DEFAULT_COLOR);
	uint entries = get_phys_mem_size();
	char* buf;
	buf = int_to_str(entries, buf);
	println(buf, DEFAULT_COLOR);
}
