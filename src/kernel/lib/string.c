// Generic String Library
#define INDEX(s, c) (int)(c-s) 

unsigned int length(char* str) {
	char* p;
	for( p = str; *p != '\0'; p++ ) {}
	return (unsigned int)(p-str);
}
