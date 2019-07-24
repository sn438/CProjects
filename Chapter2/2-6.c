#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void){
	printf("%4x\n", setbits(0xFFFF, 11, 8, 0));
	printf("%4x\n", setbits(0xFFFF, 7, 8, 0));	
	printf("%4x\n", setbits(0xFFFF, 15, 8, 0));
	printf("%4x\n", setbits(0xFFFF, 11, 0, 0));
	printf("%4x\n", setbits(0xFFFF, 11, 4, 0));
	
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
	y << (p -n - 1);
	unsigned mask = ~(~0 << (p + 1)); // mask is used toset all irrelevant bits to the left of relevant region in y to 0 
	unsigned mask2 = (~0 << (p + 1)) | ~(~0 << p - n + 1); //mask2 is used to set the relevant bits in x to 0
	y = y & mask;
	x = x & mask2;
	return y | x; 
	
}
