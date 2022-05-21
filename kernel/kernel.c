#include "kernel.h"

void print_kernel_motd() {
	set_cursor_pos(0, 0);
	printalign("      ___  ____                           ", BANNER_COLOR, MIDDLE);
	printalign("  ___ / _ \\/ ___|                           ", BANNER_COLOR, MIDDLE);
	printalign(" / _ \\ | | \\___ \\                           ", BANNER_COLOR, MIDDLE);
	printalign("|  __/ |_| |___) |    A x86 operating system,", BANNER_COLOR, MIDDLE);
	printalign(" \\___|\\___/|____/     licenced under GPL-2.0", BANNER_COLOR, MIDDLE);

	new_line();
	printalign("e = lim[h->0] (1+h)^(1/h)", DEFAULT_COLOR, MIDDLE);
	printalign("Created by E. Almqvist", DEFAULT_COLOR, MIDDLE);
	new_line();
}

/*
void print_kernel_stats() {
	char* buf;
	set_cursor_pos(0, 12);

	// GDT stuff
	print("GDT Code Seg: ", 0x0f);
	uint* code_ptr = 0xee88;
	uint8 code = *code_ptr;
	buf = itoa(code, buf, 16);
	println(buf, DEFAULT_COLOR);

	print("GDT Data Seg: ", 0x0f);
	uint* data_ptr = 0xee89;
	uint8 data = *data_ptr;
	buf = itoa(data, buf, 16);
	println(buf, DEFAULT_COLOR);

	new_line();

	// Memory stats
	print("MEMORY BITMAP: ", 0x0f);
	buf = itoa(get_bitmap(), buf, 2);
	println(buf, DEFAULT_COLOR);

	new_line();

	println("BIOS E820", 0x0f);
	print("Loaded Entries: ", DEFAULT_COLOR);
	uint entries = get_phys_mem_size();
	buf = itoa(entries, buf, 10);
	println(buf, DEFAULT_COLOR);

	print("Physical Memory Size: ");
	println("?", DEFAULT_COLOR);

	new_line();

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
	
}
*/

void kernel_init() {
	pic_init();		// Init the PIC and remap it
	idt_init();		// Enable interupts

	//enable_paging();

	vga_init(); 	// Initialize the screen

	// Allocate VGA memory range
	pm_malloc_range(VGA_ADDRESS, VGA_ADDRESS_MAX, true); // force alloc the VGA range
	// ENABLE PAGING 
	// TODO: make this work

	clear_screen();
	print_kernel_motd();
	//print_kernel_stats();

	char* buf;
	uint i = 0;
	set_cursor_pos(0, 9);
	printalign("[Ticks since boot]", 0xf0, MIDDLE);
	while(true) {
		set_cursor_pos(0, 10);
		buf = itoa(i, buf, 10);
		printalign(buf, 0x0f, MIDDLE);
		++i;
	}
	//while(true) { __asm__("hlt"); } // never escape this function
}
