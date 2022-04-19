#define VGA_ADDRESS 	0xb8000
#define VGA_ADDRESS_MAX	0xb8fa0

#define DEFAULT_COLOR 0x07 
#define URGENT_COLOR 0x0c
#define SUCCESS_COLOR 0x0a

#define MAX_ROWS 25
#define MAX_COLS 80

static unsigned int cursor_row;
static unsigned int cursor_col;

enum align {LEFT, RIGHT, MIDDLE};

char* get_memory_charpos(unsigned int col, unsigned int row);
void writechar(char c, unsigned int col, unsigned int row, int colorcode);
void clear_screen();
void clear_row(unsigned int row);
void set_cursor_pos();
void print();
void println();
void new_line();
void printalign(char* str, int attribute_byte, enum align alignment);
void vga_init();
