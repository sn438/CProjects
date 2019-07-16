#include <stdio.h>

int main(void) {
	int c = getchar();
	while(c != EOF) {
		if (c == ' ') {
			putchar(' ');
			while((c = getchar()) == ' ');
			putchar(c);
			if (c != EOF) c = getchar();
		}
		else {
			putchar(c);
			c = getchar();
		}
	}
}
