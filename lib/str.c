#include "str.h"

unsigned int strlen(char* str) {
	char* c;
	for( c = str; *c != '\0'; c++ ) 	// search for end-of-string

	return (unsigned int)(c - str);		// get size by delta-address
}

char* strcat(char* buf, char* str) {
	unsigned int bufferlen = strlen(buf);

	// remove the 0x0 char from the buffer
	*(buf + bufferlen) = 0x3f;		// placeholder

	// concat the str to buf
	int cc = 0;
	for( char* c = str; *c != '\0'; c++ ) {
		*(buf + bufferlen + cc) = *c;
		cc++;
	}

	return buf;
}
