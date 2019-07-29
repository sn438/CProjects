/*
 * It is not possible to convert the largest possible negative number using the existing itoa function because the line n = -n would cause overflow. This is because the absolute value of the largest possible negative number is larger than the absolute value of the largest possible positive number
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int n, char s[], int b);
void reverse(char * str);
int main(void){
	char s1[10000] = {0};
	itoa(-2147483648, s1, 2);
	printf("%s\n", s1);
	itoa(2147483647, s1, 16);
	printf("%s\n", s1);
	itoa(15, s1, 3);
	printf("%s\n", s1);
}

void itoa(int n, char s[], int b) {
	int i, sign;
	sign = n;
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = n % b;  /* get next digit */
		if(n < 0) 
			s[i-1] *= -1;
		if (s[i-1] < 10)
			s[i-1] += '0';
		else{
			s[i-1] -= 10;
			s[i-1] += 'a';
		}
		n /= b;
	} while (abs(n) > 0); /* delete it */
	if (sign < 0)
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
