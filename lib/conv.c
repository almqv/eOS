#include "conv.h"
#include "../drivers/vga.h"

char* int_to_str(int i, char* buf) {
	ulong num = (ulong)i; // convert to ulong
	uint len = ulong_len(num); // number of digits

	*(buf+len) = '\0'; // add a "end-of-string" at the end

	int j;
	for(j = 0; j < len; j++) // iterate over each digit and assign it to the buffer
		// super dangerous memory write 
		println("char!", DEFAULT_COLOR);
		*(buf+j) = (char)(ndigit(num, len-1-j) + ASCII_OFFSET); // apply the ascii offset so that i becomes a char
	
	return buf;
}
