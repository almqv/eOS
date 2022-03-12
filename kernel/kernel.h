
#include "memory.h"
#include "paging.h"
#include "../drivers/vga.h"
#include "../lib/str.h"
#include "../lib/conv.h"

#define STATUS_TEXT_COLOR 0x0f

void init();
void display_status(char*, unsigned int); 
