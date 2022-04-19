#include "conv.h"
#include "../drivers/vga.h"

char* itoa( int value, char * str, int base ) {
	char* rc;
	char* ptr;
	char* low;

	// Check for supported base.
	if( base < 2 || base > 36 ) {
		*str = '\0';
		return str;
	}
	rc = ptr = str;

	switch(base) {
		case 16:
			*ptr++ = '0';
			*ptr++ = 'x';
		case 10:
			if(value < 0)
				*ptr++ = '-';
	}

	// Remember where the numbers start.
	low = ptr;

	// The actual conversion.
	do {
		// Modulo is negative for negative value. This trick makes abs() unnecessary.
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
		value /= base;
	} while(value);

	// Terminating the string.
	*ptr-- = '\0';

	// Invert the numbers.
	while ( low < ptr ) {
		char tmp = *low;
		*low++ = *ptr;
		*ptr-- = tmp;
	}
	return rc;
}
