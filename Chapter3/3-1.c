#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void){
	int testarray[100000];
	for (int i = 0; i < 100000; i++){
		testarray[i] = i;
	}
	for (int i = 0; i < 100000; i++) {
		printf("%d\n", binsearch(i, testarray, 100000));
	}
}

int binsearch(int x, int v[], int n) {
	    int low, mid, high; 
	    low = 0;
	    high = n - 1;
	    while ( low <= high ) {
	        mid = (low+high) / 2;
	        if ( x < v[mid] )
	            high = mid - 1;
	        else if ( x > v[mid] )
	            low = mid + 1;
	       else
	            return mid;
	    }
	   return -1;
}
