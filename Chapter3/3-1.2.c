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
        mid = (low + high)/2;
	while ( low <= high && v[mid] != x) {
	        if ( x < v[mid] )
		        high = mid - 1;
		else 
		        low = mid + 1;
        	mid = (low + high)/2;
	}
	if (v[mid] == x) return mid;
	return -1;
}
