#include <stdio.h>

void expand(char s1 [], char s2 []);

int main(void){
	char * s1 = "a-z";
	char s2[10000] = {0};
	expand(s1, s2);
	printf("%s\n", s2);
	s1 = "0-9";
	expand(s1, s2);
	printf("%s\n", s2);
	s1 = "a-b-c";
	expand(s1, s2);
	printf("%s\n", s2);	
	s1 = "a-b-z";
	expand(s1, s2);
	printf("%s\n", s2);	
	s1 = "z-b-z";
	expand(s1, s2);
	printf("%s\n", s2);	
	s1 = "xywa-aktp";
	expand(s1, s2);
	printf("%s\n", s2);	
	s1 = "a-z0-9";
	expand(s1, s2);
	printf("%s\n", s2);	




}

void expand(char s1 [], char s2 []){
	int i, j;
	j = 0;
	for (i = 0; s1[i] != '\0'; i++){
		if (s1[i] != '-') {
			s2[j++] = s1[i];
		}
		else if (s1[i-1] < s1[i+1]){
			for (int k = s1[i-1] + 1; k <= s1[i+1]; k++){
		      		s2[j++] = k;	
			}	
			i++;
		}	
		else {
			s2[j++] = '-';
		}	
		}
	s2[j] = '\0';
}
