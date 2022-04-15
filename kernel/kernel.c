#include "kernel.h"

void print_kernel_motd() {
	printalign("      ___  ____                           ", BANNER_COLOR, MIDDLE);
	printalign("  ___ / _ \\/ ___|                           ", BANNER_COLOR, MIDDLE);
	printalign(" / _ \\ | | \\___ \\                           ", BANNER_COLOR, MIDDLE);
	printalign("|  __/ |_| |___) |    A x86 operating system,", BANNER_COLOR, MIDDLE);
	printalign(" \\___|\\___/|____/     licenced under GPL-2.0", BANNER_COLOR, MIDDLE);

	println("");
	printalign("Fun fact: e = lim[h->0] (1+h)^(1/h)", DEFAULT_COLOR, MIDDLE);
	printalign("Created by E. Almqvist", DEFAULT_COLOR, MIDDLE);
	println("");
}

void print_kernel_stats() {
	char* buf;
	// Memory stats
	print("MEMORY BITMAP: ", 0x0f);
	buf = itoa(get_bitmap(), buf, 2);
	println(buf, DEFAULT_COLOR);

	println("");

	println("BIOS E820", 0x0f);
	print("Loaded Entries: ", DEFAULT_COLOR);
	uint entries = get_phys_mem_size();
	buf = itoa(entries, buf, 10);
	println(buf, DEFAULT_COLOR);

	print("Physical Memory Size: ");
	println("?", DEFAULT_COLOR);

	println("");

	// VGA stats	
	println("Display (VGA)", 0x0f);
	print("Memory Range: ", DEFAULT_COLOR);
	buf = itoa(VGA_ADDRESS, buf, 16);
	print(buf, DEFAULT_COLOR);
	print(" - ");
	buf = itoa(VGA_ADDRESS_MAX, buf, 16);
	println(buf, DEFAULT_COLOR);

	print("Screen Dimensions: ", DEFAULT_COLOR);
	buf = itoa(MAX_COLS, buf, 10);
	print(buf, DEFAULT_COLOR);
	print("x");
	buf = itoa(MAX_ROWS, buf, 10);
	println(buf, DEFAULT_COLOR);

	uint ticks = 0;
	while (true) {
		set_cursor_pos(0, 20);
		buf = itoa(ticks, buf, 10);
		printalign(buf, 0x0f, MIDDLE);
		++ticks;
	}

}

void kernel_init() {
	// Display a nice MOTD
	clear_screen();
	print_kernel_motd();

	vga_init(); 	// Initialize the screen first
					// i.e. clear the screen et cetera.

	// Allocate VGA memory range
	pm_malloc_range(VGA_ADDRESS, VGA_ADDRESS_MAX, true); // force alloc the VGA range
	// ENABLE PAGING 
	// TODO: make this work
	// enable_paging();

	print_kernel_stats();

}
