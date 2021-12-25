#include "math.h"

long pow(int num, uint expon) {
	long prod = 1;
	while(expon > 0)	
		prod *= num;
		expon--;

	return prod;
}
