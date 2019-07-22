#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
	unsigned char currentuchar = 1;
	unsigned char previousuchar = 0;
	int boolean = 1;
	while (boolean){
		previousuchar = currentuchar;
		++currentuchar;
		if ((currentuchar - previousuchar) != 1){
			printf("%s: %d\n", "UCHAR_MAX", previousuchar);
		       boolean = 0;	
		}
	}
	currentuchar = 0;
	previousuchar = 1;
	boolean = 1;
	while (boolean){
		previousuchar = currentuchar;
		--currentuchar;
		if ((currentuchar - previousuchar) != -1){
			printf("%s: %d\n", "UCHAR_MIN", previousuchar);
		       boolean = 0;	
		}
	}
	
	signed char currentschar = 1;
	signed char previousschar = 0;
	boolean = 1;
	while (boolean){
		previousschar = currentschar;
		++currentschar;
		if ((currentschar - previousschar) != 1){
			printf("%s: %d\n", "SCHAR_MAX", previousschar);
		       boolean = 0;	
		}
	}
	
	currentschar = 0;
	previousschar = 1;
	boolean = 1;
	while (boolean){
		previousschar = currentschar;
		--currentschar;
		if ((currentschar - previousschar) != -1){
			printf("%s: %d\n", "SCHAR_MIN", previousschar);
		        boolean = 0;	
		}
	}
	
	// the same sort of computation takes too long for int or long so I will just print out the max and min values
	
	printf("%s: %d\n", "UINT_MAX", UINT_MAX);
	printf("%s: %d\n", "UINT_MIN", 0);
	printf("%s: %d\n", "INT_MAX", INT_MAX);
	printf("%s: %d\n", "INT_MIN", INT_MIN);
	printf("%s: %ld\n", "ULONG_MAX", ULONG_MAX);
	printf("%s: %d\n", "ULONG_MIN", 0);
	printf("%s: %ld\n", "LONG_MAX", LONG_MAX);
	printf("%s: %ld\n", "LONG_MIN", LONG_MIN);
	printf("%s: %.10e\n", "FLOAT_MAX", FLT_MAX);
	printf("%s: %.10e\n", "FLOAT_MIN", FLT_MIN);
	printf("%s: %.10e\n", "DOUBLE_MAX", DBL_MAX);
	printf("%s: %.10e\n", "DOUBLE_MIN", DBL_MIN);
	printf("%s: %.10Le\n", "LDOUBLE_MAX", LDBL_MAX);
	printf("%s: %.10Le\n", "LDOUBLE_MIN", LDBL_MIN);










			
	

}





