#include <stdio.h>

int lower(int c);

int main(void) {
	printf("%c\n", lower('c'));
	printf("%c\n", lower('C'));
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; 
}
