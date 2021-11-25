#include "paging.h"

struct page_entry {
	unsigned int index;
	unsigned int start_addr;
}; 

page_entry page_table[PAGE_TABLE_SIZE];
