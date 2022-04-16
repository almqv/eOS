#include "str.h"

unsigned int strlen(char* str) {
	unsigned int len = 0;
	for( char* c = str; *c != '\0'; c++ ) 	// search for end-of-string
		len++;
	
	return len;
}

char* strcat(char* buf, char* str) {
	unsigned int bufferlen = strlen(buf);

	// remove the 0x0 char from the buffer
	*(buf + bufferlen) = 0x3f;		// replace end-of-string 
						// with a placeholder

	// concat the str to buf
	int cc = 0;
	for( char* c = str; *c != '\0'; c++ ) {
		*(buf + bufferlen + cc) = *c;
		cc++;
	}

	*(buf + bufferlen + cc) = '\0'; 	// add end-of-string

	return buf;
}
