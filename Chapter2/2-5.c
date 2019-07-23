#include <stdio.h>

int any(char s1[], char s2[]);

int main(void){
	char s1[] = "hello meow meow princess";
     	char s2[] = {'a', 'e', 'm', '\0'};
	printf("%d\n", any(s1, s2));
	return 0;
}

int any(char s1[], char s2[]){
	for (int i = 0; s2[i] != '\0'; i++){
		for (int j = 0; s1[j] != '\0'; j++){
			if (s1[j] == s2[i]) return j;		
		}
	}
	return -1;
}
