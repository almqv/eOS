#include "../lib/types.h"

#define BLOCK_SIZE 1024 // 1 KiB
#define MEMSIZE_TO_BLOCKS(n) ((n*1024)/BLOCK_SIZE)

enum bitmap_flag;

// void init_pmm(uint map_addr, uint bsize); // Initialize physical memory manager

void mod_bitmap(uint block, uint bit, uint flag);
