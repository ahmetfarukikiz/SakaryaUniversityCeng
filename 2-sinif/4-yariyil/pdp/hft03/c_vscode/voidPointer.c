#include "stdio.h"

int main() {
	double a = 10.5;
	void* obj = &a;
	printf("%lf\n",*(double*)obj); //double pointera dönüştürdükten sonra * ile içindeki değeri gösteriyoruz.

	int x = 100;
	obj = &x;

	printf("%d",*(int*)obj); 
	
	return 0;
}	