#include "../lib/types.h"

#define IDT_MAX_DESCS 256
#define EXC_COLOR	0x08

__attribute__((noreturn))
void exception_handler();

void idt_set_desc(uint8, void*, uint8);
void idt_init();
