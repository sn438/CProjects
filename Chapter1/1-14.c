#include <stdio.h>

int main(void) {
	int c;
	int clength[128] = {0};
	while((c = getchar()) != EOF) {
		clength[c] = clength[c] + 1;
		}
	for (int i = 0; i < 128; i++){
	       	printf("%d : ", i);
	        for (int j = 0; j < clength[i]; j++){
	 	       printf("-");
		}
		printf("\n");
	}		
}
