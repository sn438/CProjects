#include <stdio.h>

void itoa(int n);

int sindex = 0;
char s[10000];

int main(void){
	itoa(5);
	printf("%s\n", s);
	sindex = 0;
	itoa(-5);
	printf("%s\n", s);
	sindex = 0;
	itoa(305);
	printf("%s\n", s);
	sindex = 0;
	itoa(-4567);
	printf("%s\n", s);
	return 0;
}

void itoa(int n){
	if (n < 0) {
 		s[sindex++] = '-';
		n = -n;
 	}	
	if (n / 10)
 		itoa(n / 10);
	s[sindex++] = n % 10 + '0';
	s[sindex] = '\0';
}

