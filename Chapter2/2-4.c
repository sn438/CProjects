#include <stdio.h>

void squeeze2(char s1[], char s2[]);

int main(void) {
    char s1[] = "hello meow meow princess";
    char s2[] = { 'a', 'e', 'm', '\0'};
    squeeze2(s1, s2);
    printf("%s\n", s1);
    return 0;	
}

void squeeze2(char s1[], char s2[]){
	for (int i = 0; s2[i] != '\0'; i++){
		int j,k;
		for (j = k = 0; s1[j] != '\0' ; j++)
			if (s1[j] != s2[i])
				s1[k++] = s1[j];
		s1[k] = '\0';
	}	
}

