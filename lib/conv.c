#include "conv.h"
#include "../drivers/vga.h"

// char* int_to_str(int i, char* buf) {
// 	ulong num = (ulong)i; // convert to ulong
// 	uint len = ulong_len(num); // number of digits
// 
// 	*(buf+len) = '\0'; // add a "end-of-string" at the end
// 
// 	int j;
// 	for(j = 0; j < len; j++) { // iterate over each digit and assign it to the buffer
// 		// super dangerous memory write 
// 		*(buf+j) = (char)(ndigit(num, len-1-j) + ASCII_OFFSET); // apply the ascii offset so that i becomes a char
// 		println(*(buf+j), 0xc0);
// 	}
// 	
// 	return buf;
// }

char* int_to_str(int i, char* buf) {
	char* sign = (i < 0) ? "-" : "+";
	return (char*) sign;
}
