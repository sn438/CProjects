#include <stdio.h>

#define swap(t, x, y) {t temp = y; y = x; x = temp;}

int main(void){
	int x = 5;
	int y = 3;
	printf("x:%d y:%d\n", x, y);
	swap(int, x, y);
	printf("x:%d y:%d\n", x, y);
}
