#include "../lib/types.h"

#define IDT_MAX_DESCS 256

__attribute__((noreturn))
void exception_handler();

__attribute__((noreturn))
void interupt_handler();

void idt_set_desc(uint8, void*, uint8);
void idt_init();
