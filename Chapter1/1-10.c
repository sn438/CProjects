#include <stdio.h>

int main(void) {
	int c;
	while((c = getchar()) != EOF){
		if (c == '\t'){
			printf("\\t");
		}
		else if (c == '\b'){
			printf("\\b");
		}
		else if (c == '\\'){
			printf("\\");
			printf("\\");
		}
		else{
			putchar(c);
		}
		
	}
}
