#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int toplam=0, aratoplam;

	while(1){
		aratoplam = rand()%9+1;
		if(toplam+ aratoplam > 500) break; //döngüden çıkar
		if((toplam + aratoplam) % 2 == 0) continue; //döngüde o adımı atlar sonraki adıma geçer
		toplam+=aratoplam;
	}
	printf("%d\n",toplam);
	return 0;
}