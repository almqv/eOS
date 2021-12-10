#include "../lib/types.h"

#define BLOCK_SIZE 1024 // 1 KiB
#define MAX_BLOCK_COUNT 32 // placeholder
#define MEMSIZE_TO_BLOCKS(n) ((n*1024)/BLOCK_SIZE)

// void init_pmm(uint map_addr, uint bsize); // Initialize physical memory manager

void mod_bitmap(uint bit, uint flag);

int block_alloc(uint blockidx);
void block_free(uint blockidx);
