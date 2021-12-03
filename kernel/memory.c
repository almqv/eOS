#include "memory.h"

// https://wiki.osdev.org/Page_Frame_Allocation
// page = block

// MAX_BLOCK_SIZE_IN_BITS/8 bytes
// i.e. : bit i of byte n define status of block 8n+i
// block = 8n+i

int* alloc_cursor; // keep track of last location that was allocated (may improve speed)

void init_pmm(unsigned int map_addr, unsigned int bsize) {

}
