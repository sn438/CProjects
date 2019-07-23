#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void){
	printf("%d\n", setbits(0xFFFF, 11, 8, 0));
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
	y << (p -n - 1);
	int mask = ~(~0 << (p + 1));
}
