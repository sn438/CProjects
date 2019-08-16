#include <stdio.h>

int reverse(char s[], int i);

int main(void){
	char s0[] = "hello";
	reverse(s0, 0);
	printf("%s\n", s0);
	char s1[] = "my";
	reverse(s1, 0);
	printf("%s\n", s1);
	char s2[] = "name";
	reverse(s2, 0);
	printf("%s\n", s2);
	char s3[] = "is";
	reverse(s3, 0);
	printf("%s\n", s3);
	char s4[] = "Sujith";
	reverse(s4, 0);
	printf("%s\n", s4);
	return 0;
}

/* s is the string being reversed, i is to keep track of the index of the string*/
int reverse(char s[], int i){
	int j;
	char temp = s[i++];
	if (temp == '\0')
		return 0;
	j = reverse(s, i);
	s[j++] = temp;;
	s[j] = '\0';
	return j; 	
}
