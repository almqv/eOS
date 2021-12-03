#define BLOCK_SIZE 4 // 32 bits = 4 bytes
#define MEMSIZE_TO_BLOCKS(n) ((n*1024)/BLOCK_SIZE)

void init_pmm(unsigned int map_addr, unsigned int bsize); // Initialize physical memory manager

