#include "Kisi.h"

int main(){

	Kisi k = new_Kisi("Ahmet",30,5);
	// sindirimSistemi(k, 1500); //burası uyarı verir ve düzgün çalışmaz çünkü kisi.h'ta yok.
	yemekYe(k, 1500); //kisi.h'ta olan fonku çağırmalıyız
	printf("isim: %s", getIsim(k));
	printf("\nKilo: %f", getKilo(k));
	delete_Kisi(k);

	return 0;
}


