#define PAGE_SIZE 100
#define PAGE_TABLE_SIZE 128

void enable_paging();

struct page_entry;

char** heap_alloc(unsigned int size); // Process heap allocation
int get_phys_addr(int virt_addr);
