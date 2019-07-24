#include <stdio.h>
/*
 * The reason x &= (x-1) deletes the rightmost 1 bit is because while doing x-1 if the least significant bit of x is 1, the bit gets set to 0. Then x & x-1 would set the right most bit to 0 because 1 & 0 = 0. If the first 1-bit is not the least significant bit, the least significant bit will borrow from the rightmost 1 bit making it 0. That way, when &ing with x, the right most 1-bit will automatically be set to 0, and all the intermediary bits will also be set to 0 as x-1 will set them to 1 while they are 0 in x.
 * */ 

int bitcount(unsigned x);

int main(void){
	printf("%d\n", bitcount(0xf));
	printf("%d\n", bitcount(0xff));
	printf("%d\n", bitcount(0xfff));
	printf("%d\n", bitcount(0xffff));
	printf("%d\n", bitcount(0xffffffff));
	printf("%d\n", bitcount(0x0));
}

int bitcount(unsigned x){
	int returnvalue = 0;
	while(x != 0){
		x &= (x-1);
		returnvalue++;
	}
	return returnvalue;
}
