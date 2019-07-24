#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void) {
	printf("%8x\n", rightrot(0xff, 0));
	printf("%8x\n", rightrot(0xff, 4));	
	printf("%8x\n", rightrot(0xff, 8));
	printf("%8x\n", rightrot(0xff, 16));
	printf("%8x\n", rightrot(0xff, 32));
}

unsigned rightrot(unsigned x, int n) {
	int mask = 1; // retains the value in leftmost bit and sets all other bits to 0
	int temp;
	for (int i = 0; i < n; i++){
		temp = x & mask;
		temp = temp << 31; // shifting least significant bit to the right most bit
		x = x >> 1;
		x = x | temp;
	}
	return x;
}
