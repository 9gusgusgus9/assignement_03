#ifndef __MCD__
#define __MCD__

#include <stdlib.h>

void swap (int* a, int* b){
    int* c = a;
    a = b;
    b = c;
}


int mcd (int a, int b) {

	a = abs(a);
	b = abs(b);
	
	if(a==0)
		return b;
	if(b==0)
		return a;

	if (a < b) swap(&a,&b);

	int temp_a;
	int temp_b;

	while(b != 0){
		temp_a = b;
		temp_b = a % b;

		a = temp_a;
		b = temp_b;
	}

	return a;
}

#endif