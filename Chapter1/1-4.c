#include <stdio.h>

int main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("%7s \t %10s \n", "Celsius", "Fahrenheit"); 
	celsius =  lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%7.0f \t  %9.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
