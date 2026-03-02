#include "stdio.h"

int main() {
	
	/*
	int x;
	printf("x: ");
	scanf("%d",&x);
	if(x%2 == 0)
	if(x<100)
	if(x>10)
	printf("100den kucuk 10 dan buyuk cift sayi");
	else //en alttaki if in else si.
	printf("sayi tektir.");
	return 0;
	*/

	//aşağıdaki yazım okunuş kolaylığı sağlar şart değildir (python dili olmadığından)
	int x;
	printf("x: ");
	scanf("%d",&x);
	if(x%2 == 0)
		if(x<100)
			if(x>10)
				printf("100den kucuk 10 dan buyuk cift sayi");
			else //en alttaki if in else si.
				printf("sayi tektir.");
	return 0;


	//eğer else en yukardaki if'in olsun istiyorsak {} kullanmalıyız.
}