#include "Kisi.h"

void sindirimSistemi(const Kisi this, float kalori) { //private fonksiyon
		this->kilo += (kalori/1000);
		if(this->yas < 20) this->boy++;
}

Kisi new_Kisi(char* isim, float boy, float kilo){
	Kisi this;
	this = (Kisi)malloc(sizeof(struct KISI)); //buraya KISI* yazmıyoruz KISI'nin kapladığı yer kadar
	this->isim = isim;
	this->boy = boy;
	this->kilo = kilo;
	this->yas = 0;
	return this; //Javada otomatik isim döndürür biz elle döndürücez
}
void yemekYe(const Kisi this, float kalori){
	sindirimSistemi(this, kalori);
}
void yaslan(const Kisi this, int yil){
	this->yas += yil;
}
char* getIsim(const Kisi this){
	return this->isim;
}
float getKilo(const Kisi this){
	return this->kilo;
}
void delete_Kisi(const Kisi this){
	free(this);
}


