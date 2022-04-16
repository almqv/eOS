#include "memory.h"
#include "paging.h"
#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/conv.h"

#define BANNER_COLOR 0x0c

void print_kernel_motd();
void print_kernel_stats();
void kernel_init();
