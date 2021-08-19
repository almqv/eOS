// VGA Graphics Library
#include "../kernel/io.h"

// VGA base address: 0xb8000
// Charpos = 0xb8000 + 2(row*80 + col)

// Memory
#define VIDEO_MEM 	(char*)0xb8000
#define VIDEO_MEM_MAX	(char*)0xb8fa0

// Global
static unsigned int cursor_row = 0;
static unsigned int cursor_col = 0;

/*
	VGA & Memory Functions
*/
char* get_vga_charpos_pointer(unsigned int col, unsigned int row) { 
	return (char*)(VIDEO_MEM + 2*((row*80) + col)); 
}

void writechar(char c, unsigned int col, unsigned int row, int attribute_byte) {
	char* mem = get_vga_charpos_pointer(col, row);
	*mem = c; 		// Write the character
	*(mem+1) = attribute_byte;	// Write the attribute_byte

}

/*
	Graphics Functions
*/
void clear_screen() {
	// Make all the characters spaces
	for( char* c = VIDEO_MEM; c <= VIDEO_MEM_MAX; c += 2 )
		*c = 0x20;
}

void disable_vga_cursor() {
	port_outb(0x0a, 0x3d4);
	port_outb(0x20, 0x3d5);
}


/*
	General Printing Functions
*/
void set_cursor_pos(unsigned int x, unsigned int y) {
	cursor_col = x;
	cursor_row = y;
}

void print(char* str, int attribute_byte) {
	for( char* c = str; *c != '\0'; c++ ) 
		writechar(*c, (unsigned int)(c - str) + cursor_col, cursor_row, attribute_byte);
}

void println(char* str, int attribute_byte) {
	print(str, attribute_byte);
	cursor_row++; // Increment to next y-pos (newline)
}


// VGA Initialization Function
void vga_init() {
	disable_vga_cursor();
	clear_screen();
}
