#include "util.h"

uint ulong_len(ulong n) { // get the digit length of a number
    int len = 0;
    while (n != 0) {
        n = n / 10;
        ++len;
    }
    return len;
}

uint ndigit(ulong n, uint i) { // OBS: index order is reversed
	return (n/(10**i)) % 10
}
