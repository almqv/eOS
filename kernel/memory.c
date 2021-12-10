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
int bitmap = 0; 

#define CHECK_BITMAP(map, idx) ((map) & (1<<(idx)))

void mod_bitmap(uint bit, uint bflag) {
	// create a bitmask that will be applied to the bitmap
	int bitmask = 1 << bit;

	// apply the bitmask, resulting in the bit:n bit will bet 
	// set to bflag
	bitmap = (((bitmap & ~bitmask)) | (bflag << bit));
}


int block_alloc(uint blockidx) {
	if( CHECK_BITMAP(bitmap, blockidx) == 1 ) { // check if block is free
		println("Alloc!", DEFAULT_COLOR);

		mod_bitmap(blockidx, 0);
		return 0; // placeholder

	} else {
		println("ERROR! Attemped to allocate non-free block.", 0x0c);
		return -1;
	}
}
