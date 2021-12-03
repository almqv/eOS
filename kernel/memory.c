#include "memory.h"

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

enum bitmap_flag {
	FREE,
	ALLOC
};

void mod_bitmap(uint block, uint bit, uint bflag) {
	
}
