#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int atoii(char s[]);
double atoff(char s[]);

int main(void){
	double atoff(char []);
	printf("%10f\n", atoff("123.45e-6"));
	printf("%10f\n", atoff("123.45"));
	printf("%10f\n", atoff("1.23e-3"));
}

/* atoff: convert string s to double */
double atoff(char s[])
{
	double val, power, returnvalue;
	int exponent = 0;
	int i, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if(s[i] == 'e' || s[i] == 'E'){
		exponent = atoii(&s[i+1]);
	}
	if (exponent != 0) {
		for (int i = 0; i < abs(exponent); i++){
			if (exponent > 0)
				power /= 10.0;
			else
				power *= 10.0;
		}
	}
	return sign * val / power;
}

/* atoii: convert s to integer; version 2 */
int atoii(char s[])
{
	int i, n, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');
	return sign * n;
}
