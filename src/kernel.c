// VGA base address: 0xb8000
// Charpos = 0xb8000 + 2(row*80 + col)

void main() {
	char* video_mem = (char*)0xb8000; // VGA Video Memory location
	*video_mem = 'X'; 
}
