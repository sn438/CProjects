#include <stdio.h>

int strindex(char s[], char t[]);

int main(void){
	printf("%d\n", strindex("hello hello hello", "hello"));
	printf("%d\n", strindex("hello my name is Sujith, hello", "hello")); 
	printf("%d\n", strindex("yes yes", "hello"));
	printf("%d\n", strindex("", "hello"));
}
/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	int returnvalue = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			returnvalue = i;
	}
	return returnvalue;
}
