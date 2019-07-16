#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
	int c;
	int state = OUT;
	int length = 0;
	int nlength[20] = {0};
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			nlength[length] = nlength[length] + 1;
			length = 0;
		}
		else{
			state = IN;
			length = length + 1;
		}
	}
	
	for (int i = 0; i < 20; i++){
		printf("%d : ", i);
		for (int j = 0; j < nlength[i]; j++){
			printf("-");
		}
		printf("\n");
	}
}
