#include "math.h"

long pow(int num, uint expon) {
	long prod = 1;
	while(expon > 0)	
		prod *= num;
		expon--;

	return prod;
}

long square(uint num) {
	long sum = num - 1;
	while(num > 0) {
		sum += num*2;
		num--;
	}
	return sum + 1;
}
