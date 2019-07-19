#include <stdio.h>
#define MAXLINE 80 /* maximum input line length */
int getlinea(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
int main(void)
{
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	int c;
	while ((len = getlinea(line, MAXLINE)) > 0){
		if (len == (MAXLINE - 1) && line[MAXLINE-2] != '\n' && line[MAXLINE-2] != EOF){
			printf("%s", line);
			while((c = getchar()) != EOF && c != '\n'){
				putchar(c);
			}
			putchar(c);	
		}
	}
	return 0;
}
/* getlinea: read a line into s, return length */
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
/* copy: copy ’from’ into ’to’; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
