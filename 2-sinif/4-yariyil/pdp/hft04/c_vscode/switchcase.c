#include "stdio.h"

int main() {
	
	int not;
	printf("x:");
	scanf("%d",&not);
	if(not<60) printf("DD");
	else if(not<60) printf("CC");
	else if(not<70) printf("BB");
	else if(not<80) printf("BA");
	else printf("AA");
	
	printf("\n\ntamsayi: ");
	int tamsayi;
	scanf("%d",&tamsayi);
	//c'de switch tam sayı mantığıyla çalışır.
	switch (tamsayi) //sadece sayı kontrol edilebilir.
	{
	case 1:
		printf("1");
		break;
	case 2: {
		printf("2"); //break olmadığından 3 de yazdırılır.
	}
	case 3: { //köşeli parantez şart değildir
		printf("3");
		break;
	}
	
	default:
		printf("gecerli bir sayi girilmedi");
		break;
	}
	
	return 0;

}