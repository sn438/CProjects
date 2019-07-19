#include <stdio.h>

#define MAXBUFFER 10000

int main(void) {
	char empty[MAXBUFFER];
	int index = 0;
	int c;
	while((c = getchar()) != EOF){
		if (c == ' ' || c == '\t') {
			if (index < MAXBUFFER - 1){
				empty[index] = c;
				++index;
			}		
		}
		else if (c != '\n'){
			empty[index] = '\0';
			printf("%s", empty);
			index = 0;
			empty[index] = '\0';
			putchar(c);
		}
		else {
			putchar('\n');
			index = 0;
			empty[index] = '\0';
		}
	}
}	

