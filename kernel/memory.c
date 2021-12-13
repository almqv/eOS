#include "memory.h"
#include "../drivers/vga.h"

// https://wiki.osdev.org/Page_Frame_Allocation
// page = block

// MAX_BLOCK_SIZE_IN_BITS/8 bytes
// i.e. : bit i of byte n define status of block 8n+i
// block = 8n+i

// in 32-bit mode, we have access to 2^32 blocks
// which is (2^32)*BLOCK_SIZE blocks
// and with a blocksize of 1024, we git around 4.3 trillion blocks
// which is more than enough

#define CHECK_BITMAP(map, idx) ((map) & (1<<(idx)))

#define BLOCK_TO_MEMP(idx) (int*)(PM_MEM_START + (idx*BLOCK_SIZE))


static int bitmap = 0; 
static uint last_block;
void mod_bitmap(uint bit, uint bflag) {
	// create a bitmask that will be applied to the bitmap
	int bitmask = 1 << bit;

	// apply the bitmask, resulting in the bit:n bit will set 
	// set to bflag
	bitmap = (((bitmap & ~bitmask)) | (bflag << bit));
}


int* block_alloc(uint blockidx) {
	int block_bflag;
	block_bflag = CHECK_BITMAP(bitmap, blockidx);

	if( block_bflag == BM_FREE ) { // check if block is free
		println("Alloc!", DEFAULT_COLOR);

		mod_bitmap(blockidx, 1);
		last_block = blockidx;

		return BLOCK_TO_MEMP(blockidx); // placeholder
	} else {
		println("ERROR! Attemped to allocate non-free block.", 0x0c);

		return 0;
	}
}

void block_free(uint blockidx) {
	println("Dealloc block...", DEFAULT_COLOR);	
	mod_bitmap(blockidx, BM_FREE);
	last_block = blockidx;
}

void pm_alloc_range(uint start, uint end, bool force) {
	uint idx_start;
	uint idx_end;

	// calculate idx_start and idx_end
	// if not force, check if avaliable
	// allocate (if permitted)
}

/*
int* pm_malloc(uint block_count) {
	
}
*/
