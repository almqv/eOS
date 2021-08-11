// VGA Graphics Library

// VGA base address: 0xb8000
// Charpos = 0xb8000 + 2(row*80 + col)

#define VIDEO_MEM (char*)0xb8000
static int cursor_y = 0;

char* get_cursor_pos(unsigned int row, unsigned int col) { return (char*)(VIDEO_MEM + 2*(row*80 + col)); }

void print(char* str, unsigned int str_len) {
	for( unsigned int i = 0; i < str_len; i++ ) {
		*get_cursor_pos(i, cursor_y) = str[i]; 	// write to video memory 
	}
}

void println(char* str, unsigned int str_len) {
	print(str, str_len);
	cursor_y++;				// Increment to next y-pos (newline)
}
