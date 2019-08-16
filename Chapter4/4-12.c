#include <stdio.h>

int itoa(int n, char s[], int i);

int sindex = 0;
char s[10000];

int main(void){
	itoa(5, s, 0);
	printf("%s\n", s);
	itoa(-5, s, 0);
	printf("%s\n", s);
	itoa(305, s, 0);
	printf("%s\n", s);
	itoa(-4567, s, 0);
	printf("%s\n", s);
	return 0;
}

int itoa(int n, char s[], int i)  {
	if (n < 0) {
 		s[i++] = '-';
		n = -n;
 	}	
	if (n / 10)
 		i = itoa(n / 10, s, i);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	return i;
}

