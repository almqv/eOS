// VGA Graphics Library
#include "vga.h"
#include "../lib/types.h"
#include "../kernel/io.h"
#include "../kernel/memory.h"
#include "../lib/str.h"
#include "../lib/conv.h"

static uint cursor_row = 0;
static uint cursor_col = 0;

void vga_init() {
	// Allocate VGA memory range
	pm_malloc_range(VGA_ADDRESS, VGA_ADDRESS_MAX, true); // force alloc the VGA range

	// Disable cursor
	port_outb(0x3d4, 0x0a);
	port_outb(0x3d5, 0x20);

	// Clear screen
	// clear_row(0);
	clear_screen();

	set_cursor_pos(0, 0);
}

/*
	VGA & Memory Functions
*/
char* get_memory_charpos(uint col, uint row) { 
	return (char*)(VGA_ADDRESS + 2*((row*80) + col)); 
}

void writechar(char c, uint col, uint row, int attribute_byte) {

	if( !attribute_byte ) 
		attribute_byte = DEFAULT_COLOR;

	char* mem = get_memory_charpos(col, row);
	*mem = c; 			// Write the character
	*(mem+1) = attribute_byte;	// Write the attribute_byte

}

void set_cursor_pos(uint col, uint row) {
	cursor_col = col;
	cursor_row = row;
}


/*
	Graphics Functions
*/
void clear_row(uint row) {
	for( int c = 0; c < MAX_COLS; c++ ) 
		writechar(0x20, c, row, 0x0);
}


void clear_screen() {
	for( int r = 0; r < MAX_ROWS; r++ )
		clear_row(r);
}

/*
	General Printing Functions
*/
void print(char* str, int attribute_byte) {
	for( char* c = str; *c != '\0'; c++ ) 
		writechar(*c, (uint)(c - str) + cursor_col, cursor_row, attribute_byte);
}

void println(char* str, int attribute_byte) {
	print(str, attribute_byte);
	cursor_row++; // Increment to next y-pos (newline)
}

void printint(int i, int attribute_byte) {
	/*
	char* strbuf;

	strbuf = int_to_str(i, strbuf);
	println(strbuf, attribute_byte);
	*/
}

void printalign(char* str, int attribute_byte, enum align alignment) {
	uint strlenbuf = strlen(str);

	if( !alignment || alignment == LEFT ) {
		set_cursor_pos(0, cursor_row);
	} else if ( alignment == RIGHT ) {
		set_cursor_pos(MAX_COLS - strlenbuf, cursor_row);
	} else if ( alignment == MIDDLE ) {
		set_cursor_pos((MAX_COLS/2) - (strlenbuf/2), cursor_row);
	}

	print(str, attribute_byte);
	set_cursor_pos(0, cursor_row+1);
}
