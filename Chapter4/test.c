#include <stdio.h>

int test(void);

int main(void) {
	printf("%d\n", test());
}

int test(void){
	int c = 0;
	return (c = 3);
}
