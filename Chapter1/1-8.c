#include <stdio.h>

int main(void) {
	int c, nb, nt, nl;
	nl = 0;	
       	nt = 0;
	nb = 0;
	while((c = getchar()) != EOF){
		if(c == ' '){
			++nb;
		}
		if(c == '\t'){
			++nt;
		}
		if (c == '\n'){
			++nl;
		}
	}
	printf("%16s,\t %d\n", "Number of Blanks", nb);	
	printf("%16s,\t %d\n", "Number of Tabs", nt);
	printf("%16s,\t %d\n", "Number of Lines", nl);

}
