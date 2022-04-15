#include "memory.h"
#include "paging.h"
#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/conv.h"

#define BANNER_COLOR 0x0f

void kernel_motd();
void kernel_init();
