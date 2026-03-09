#include <stdio.h>
#include <stdlib.h>

int main() {
	int sayilar[] = {10, 20, 30 ,40 ,50};
		//int index = 0; bu şekil başa da yazılabilir
		for(int index = 0; index < 5; index++) {
			printf("%d\n",sayilar[index]);
		}



		//while koşullu olarak çalışır
		int toplam = 0;
		while(toplam < 500){
			toplam += rand()%9+1;
		}
		printf("%d\n",toplam);


		//do-while her zaman bir kez çalışır. sonda koşul kontrol edilir.
		do{

		}while(1);

	return 0;
}