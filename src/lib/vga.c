// VGA Graphics Library

// VGA base address: 0xb8000
// Charpos = 0xb8000 + 2(row*80 + col)

#define VIDEO_MEM (char*)0xb8000
static char* cursor_pos = VIDEO_MEM;
static int cursor_y = 0;

void set_cursor_pos(unsigned int row, unsigned int col) { cursor_pos = (char*)(VIDEO_MEM + 2*(row*80 + col)); }

void print(char* str, unsigned int str_len) {
	for( unsigned int i = 0; i < str_len; i++ ) {
		set_cursor_pos(i, cursor_y); 	// set cursor pos
		*cursor_pos = str[i];		// Write char to video memory
	}
}

void println(char* str, unsigned int str_len) {
	print(str, str_len);
	cursor_y++;				// Increment to next y-pos (newline)
}
