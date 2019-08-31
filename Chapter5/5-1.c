#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int *pn);

int main(void){
	int i;
	printf("%d\n", getint(&i));
	printf("%d\n", i);

}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
	int c, sign;
 	while (isspace(c = getch())) /* skip white space */
 		;
 	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
 		ungetch(c); /* it is not a number */
 		return 0;
 	}
 	sign = (c == '-') ? -1 : 1;
 	int temp;
	if (c == '+'|| c == '-'){
 		temp  = getch();
		if (!isdigit(temp)){
			ungetch(c);
			return 0;
		}
		c = temp;
	}
 	for (*pn = 0; isdigit(c); c = getch())
 		*pn = 10 * *pn + (c - '0');
 	*pn *= sign;
	if (c != EOF)
 		ungetch(c);
 	return c;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
 	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
	 if (bufp >= BUFSIZE)
 	 	printf("ungetch: too many characters\n");
 	 else
 		buf[bufp++] = c;
}
