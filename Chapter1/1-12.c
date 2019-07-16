#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main(void) {
	int c, state;
	
	state = OUT;
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			putchar('\n');
		}
		else { 
			state = IN;
			putchar(c);
		}		
	}
	return 0;
}
