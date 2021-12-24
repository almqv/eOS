#include "util.h"

uint ulong_len(ulong i) {
    int len = 0;
    while (i != 0) {
        i = i / 10;
        ++len;
    }
    return len;
}
