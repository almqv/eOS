#include "paging.h"

struct page_entry {
	int index;
	int start_addr;
} page_table[PAGE_TABLE_SIZE];
