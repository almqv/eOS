#include "../lib/types.h"

#define BIOS_E820 (char*)0x9820

#define BLOCK_SIZE 1024 // 1 KiB
#define MAX_BLOCK_COUNT 32 // placeholder
#define MEMSIZE_TO_BLOCKS(n) ((n*1024)/BLOCK_SIZE)

#define BM_FREE 0

#define PM_MEM_START 0x000000 // start of memory
#define PM_MEM_END 0xb7000 // end of memory  TODO: fix me/change or something

// void init_pmm(uint map_addr, uint bsize); // Initialize physical memory manager

int get_bitmap();
void mod_bitmap(uint bit, uint flag);

pointer block_alloc(uint blockidx); // allocate a block
void block_free(uint blockidx); // free a block

bool check_block_range(uint start, uint end);
int find_free(uint block_count);

void pm_malloc_range(ulong start, ulong end, bool force); // allocate a range of memory 

pointer pm_malloc(uint block_count); // allocate some blocks
void pm_free(int* p); // free a var (if allocated with pm_malloc)

uint get_phys_mem_size(); // physical memory size with e820 left by the bootloader
