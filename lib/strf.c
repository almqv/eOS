#include "strf.h"

#define int_offset 48
// 0:48 - 9:57

char* int_to_str(int i) {
	char* strbuf = "XXXXXX";

	while( i > 0 ) {
		*(strbuf + 1) = (i % 10) + int_offset;
		i /= 10;
	}

	return strbuf;
}
