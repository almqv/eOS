#include "strf.h"

#define int_offset 48
// 0:48 - 9:57

char* int_to_str(int i, char* strbuf) {
	if( i == 0 ) {
		return (char*)(int_offset);
	} else {
		char cbuf;
		cbuf = (char)((i % 10) + int_offset);

		return int_to_str(i / 10, strbuf + cbuf);
	}
}
