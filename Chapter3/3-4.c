/*
 * It is not possible to convert the largest possible negative number using the existing itoa function because the line n = -n would cause overflow. This is because the absolute value of the largest possible negative number is larger than the absolute value of the largest possible positive number
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int n, char s[]);
void reverse(char * str);
int main(void){
	char s1[10000] = {0};
	itoa(-2147483648, s1);
	printf("%s\n", s1);
	itoa(2147483647, s1);
	printf("%s\n", s1);
}

void itoa(int n, char s[]) {
	int i, sign;
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = n % 10;  /* get next digit */
		if(n < 0) 
			s[i-1] *= -1;
		s[i-1] += '0';
		n /= 10;
	} while (abs(n) > 0); /* delete it */
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char *str)
{
	if (!str || ! *str)
		return;

	int i = strlen(str) - 1, j = 0;
        char ch;
        while (i > j) {
            ch = str[i];
            str[i] = str[j];
            str[j] = ch;
            i--;
            j++;
       }
		    
}
