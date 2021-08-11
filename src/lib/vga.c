// VGA Graphics Library

// VGA base address: 0xb8000
// Charpos = 0xb8000 + 2(row*80 + col)

#define VIDEO_MEM (char*)0xb8000
#define GET_INDEX(s, c) (int)(c-s)
static int cursor_y = 0;

char* get_cursor_pos(unsigned int col, unsigned int row) { 
	return (char*)(VIDEO_MEM + 2*((row*80) + col)); 
}

void print(char* str, unsigned int str_len) {
	for( char* c = str; *c != '\0'; c++ ) 
		*get_cursor_pos( GET_INDEX(str, c), cursor_y ) = 'Y';
}

void println(char* str, unsigned int str_len) {
	print(str, str_len);
	cursor_y++; // Increment to next y-pos (newline)
}
