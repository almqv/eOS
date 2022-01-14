#include "memory.h"
#include "../drivers/vga.h"
#include "../lib/conv.h"

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

#define BLOCK_TO_MEMP(idx) (pointer)(PM_MEM_START + (idx*BLOCK_SIZE))

#define MEMP_TO_BLOCK(memp) (uint)((memp - PM_MEM_START)/BLOCK_SIZE)

static int bitmap = 0; 
static uint last_block;
void mod_bitmap(uint bit, uint bflag) {
	// create a bitmask that will be applied to the bitmap
	int bitmask = 1 << bit;

	// apply the bitmask, resulting in the bit:n bit will set 
	// set to bflag
	bitmap = (((bitmap & ~bitmask)) | (bflag << bit));
}


pointer block_alloc(uint blockidx) {
	int block_bflag;
	block_bflag = CHECK_BITMAP(bitmap, blockidx);

	if( block_bflag == BM_FREE ) { // check if block is free
		println("Allocating block...", DEFAULT_COLOR);

		mod_bitmap(blockidx, 1);
		last_block = blockidx;

		return BLOCK_TO_MEMP(blockidx); 
	} else {
		println("[ERROR] Attemped to allocate non-free block.", 0x0c);

		return 0;
	}
}

void block_free(uint blockidx) {
	println("Dealloc block...", DEFAULT_COLOR);	
	mod_bitmap(blockidx, BM_FREE);
	last_block = blockidx;
}

bool check_block_range(uint start, uint end) {
	bool allowed = true;	

	uint idx;
	for(idx = start; idx <= end; idx++) {
		if( CHECK_BITMAP(bitmap, idx) != BM_FREE ) {
			allowed = false;
			break;
		}
	}

	return allowed;
}

int find_free(uint block_count) {
	// Loop through bitmap starting at last_block 
	for( uint lower = 0; lower < MAX_BLOCK_COUNT - block_count; lower++ ) {
		bool range_is_free = check_block_range(lower, lower + block_count);

		if(range_is_free == true) { // if range is free
			return lower;
		}
	}

	return -1; // return the lower block index
}

void pm_malloc_range(ulong start, ulong end, bool force) {
	uint idx_start;
	uint idx_end;

	ulong d_addr = end - start; // memory size
	uint num_blocks = (d_addr/BLOCK_SIZE) + 1; // amount of blocks to be allocated

	uint start_block = MEMP_TO_BLOCK(start); // start idx, end = start_block + num_blocks - 1
	bool allowed = true && check_block_range(start_block, start_block + num_blocks - 1);

	// allocate (if permitted)
	if( allowed ) {
		uint idx;
		for(idx=start_block; idx <= start_block + num_blocks - 1; idx++) 
			block_alloc(idx);

		return;
	} else {
		println("[ERROR] Tried to allocate memory range without permission!", URGENT_COLOR);
		return;
	}
}

pointer pm_malloc(uint block_count) {
	// find free block range and get lower offset
	int lower;
	lower = find_free(block_count);
	println("lower: ", DEFAULT_COLOR);
	println((lower+46), 0xfc);

	if( lower < 0 ) {
		println("malloc: OUT OF MEMORY :(", URGENT_COLOR);
		// do some out-of-memory interupt
		return 0x0;
	}

	// allocate those blocks
	uint i;
	for( i = lower; i <= lower + block_count - 1; i++ ) 
		block_alloc(i);
		
	// return pointer to start of first block
	return BLOCK_TO_MEMP(lower);
}
