#include <stdio.h>

void strcats(char *s, char * t);

int main(void) {
	char s [] = "Hello World, ";
	char t [] = "my name is Sujith.";
	strcats(s, t);
	printf("%s\n", s);
	char s1 [] = "";
	char t1 [] = "Empty first blank";
	strcats(s1, t1);
	printf("%s\n", s1);
	char s2 [] = "Empty second blank";
	char t2 [] = "";
	strcats(s2, t2);
	printf("%s\n", s2);
}

/* strcat: concatenate t to end of s; s must be big enough */
 void strcats(char * s, char * t) {
 	while (*s++) /* find end of s */
 		;
	s--;
 	while(*s++ = *t++)  /* copy t */
 		;
 }
