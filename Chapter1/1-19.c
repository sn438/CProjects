#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getlinea(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int length);
/* print the longest input line */
int main(void) {
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	while ((len = getlinea(line, MAXLINE)) > 0)
		reverse(line, len);
	return 0;
}
/* getline: read a line into s, return length */
int getlinea(char s[],int lim)
{
	int c, i;
	for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char line[], int length){
	for (int i = length-1; i >= 0; i--)
		putchar(line[i]);
	putchar('\n');
}
