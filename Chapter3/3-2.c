#include <stdio.h>

void escape(char s[], char t[]);

int main(void) {
	char holderString[10000];
	escape("Hello my name is Sujith. \t \n This is a test for escape \n. One more just for good measure.", holderString);
	printf("%s\n", holderString);
}

void escape(char s[], char t[]){
	int i;
	for (i = 0; s[i] != '\0'; i++){
		switch(s[i]) {
			case '\n':  
				t[i] = '\\';
				t[++i] = 'n';
				break;
			case '\t':
				t[i] = '\\';
				t[++i] = 't';
				break;
			default:
				t[i] = s[i];
				break;
		}
	}
	t[i] = '\0';	
}
