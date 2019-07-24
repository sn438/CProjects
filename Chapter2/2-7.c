#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void){
	printf("%4x\n", invert(0xFFFF, 11, 8));
	printf("%4x\n", invert(0xFFFF, 7, 8));
	printf("%4x\n", invert(0xFFFF, 15, 8));
	printf("%4x\n", invert(0xFFFF, 11, 0));
	printf("%4x\n", invert(0xFFFF, 11, 4));

}

unsigned invert(unsigned x, int p, int n) {
	unsigned y = ~x;
	unsigned mask = ~(~0 << (p + 1)); // mask is used to set irrelevant bits in y to left of relevant region to 0
	unsigned mask1 = ~0 << (p - n - 1); // mask1 is used to set irrelevant bits to right of relevant region to 0
        unsigned mask2 = (~0 << (p + 1)) | ~(~0 << p - n + 1); //mask2 is used to set the relevant bits in x to 0
        y = y & mask & mask1;
        x = x & mask2;
        return y | x;
}
