// VGA Graphics Library

// VGA base address: 0xb8000
// Charpos = 0xb8000 + 2(row*80 + col)

// Screen Dimensions
#define WIDTH 640
#define HEIGHT 480

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

void putc(char c, unsigned int col, unsigned int row, int colorcode) {
	char* mem = get_vga_charpos_pointer(col, row);
	*mem = c; 		// Write the character
	*(mem+1) = colorcode;	// Write the colorcode

}

/*
	Graphics Functions
*/
void clear_screen() {
	// Make all the characters spaces
	for( char* c = VIDEO_MEM; c <= VIDEO_MEM_MAX; c += 2 )
		*c = 0x20;
}


/*
	General Printing Functions
*/
void set_cursor_pos(unsigned int x, unsigned int y) {
	cursor_col, cursor_row = x, y;
}

void print(char* str, int colorcode) {
	for( char* c = str; *c != '\0'; c++ ) 
		putc(*c, (unsigned int)(c - str + cursor_col), cursor_row, colorcode);
}

void println(char* str, int colorcode) {
	print(str, colorcode);
	cursor_row++; // Increment to next y-pos (newline)
}
