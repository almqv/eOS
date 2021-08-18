char* get_vga_charpos_pointer(unsigned int col, unsigned int row);
void writechar(char c, unsigned int col, unsigned int row, int colorcode);
void clear_screen();
void disable_cursor();
void set_cursor_pos();
void print();
void println();
void vga_init();
