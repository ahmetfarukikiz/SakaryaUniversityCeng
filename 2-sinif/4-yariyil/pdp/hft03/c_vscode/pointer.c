#include "stdio.h"

int main() {
	int a = 100;
	printf("%d\n",a); //100
	printf("%X\n",&a); //61FF1C

	int a = 100;
	int *p = &a;
	
	return 0;
}