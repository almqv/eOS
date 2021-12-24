#include "conv.h"

void int_to_str(int i, char* buf) {
	bool use_sign = false;

	if( i < 0 ) {
		i = (ulong)(i * (-1))
		use_sign = true;
	}

	uint len = ulong_len(i); 
}
