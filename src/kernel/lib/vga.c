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
static int cursor_row = 0;

/*
	VGA & Memory Functions
*/
char* get_vga_memory_pointer(unsigned int col, unsigned int row) { 
	return (char*)(VIDEO_MEM + 2*((row*80) + col)); 
}

void putc(char c, unsigned int col, unsigned int row) {
	*get_vga_memory_pointer(col, row) = c;
}

/*
	Graphics Functions
*/
void clear_screen() {
	for( char* c = VIDEO_MEM; c <= VIDEO_MEM_MAX; c += 2 ) {
		*c = 0x20;
	}
}


/*
	General Printing Functions
*/
void print(char* str, unsigned int str_len) {
	for( char* c = str; *c != '\0'; c++ ) 
		putc(*c, (int)(c - str), cursor_row);
}

void println(char* str, unsigned int str_len) {
	print(str, str_len);
	cursor_row++; // Increment to next y-pos (newline)
}
