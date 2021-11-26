#include "paging.h"

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
