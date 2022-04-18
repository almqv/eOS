unsigned char inb(unsigned short);
void outb(unsigned short, unsigned char);

unsigned short inw(unsigned short);
void outw(unsigned short, unsigned short);

static inline void io_wait();

// wrappers but with io_wait
unsigned char inb_w(unsigned short);
void outb_w(unsigned short, unsigned char);

unsigned short inw_w(unsigned short);
void outw_w(unsigned short, unsigned short);
