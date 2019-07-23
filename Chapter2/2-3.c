#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);
int main(void){
	char s[11];
	scanf("%s", s);
	printf("%d\n", htoi(s));
}

// htoi assumes that there is no malicious input from the user
int htoi(char s[]){
	int index = 0;
	int multiplier = 1;
	int returnvalue = 0;
	int tempvalue = 0;
	if (s[index] == '0') 
	index = 2;
	for (index; s[index] != '\0'; ++s){
		if(isdigit(s[index])) 
			tempvalue = s[index] - '0';
		else{
			s[index] = tolower(s[index]);
			tempvalue = s[index] - 'a' + 10;
		}
		returnvalue = returnvalue*16 + tempvalue;
	}	
	return returnvalue;
}
