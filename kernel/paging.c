#include "paging.h"
#include "../drivers/vga.h"

void enable_paging() {
	println("Enabling paging...", DEFAULT_COLOR);

	// extern int enable_paging_registers(); // Call the assembly SR
	// enable_paging_registers(); // and enable paging

	return;
}

// Page Entry struct
struct page_entry {
	unsigned int index;
	unsigned int start_addr;
} page_table[PAGE_TABLE_SIZE];

int get_phys_addr(int virt_addr) {
	int index = virt_addr / PAGE_SIZE; // page index for the virtual address
	int offset = virt_addr % PAGE_SIZE; // actual physical offset for the address

	return page_table[index].start_addr + offset;
}
