#include "Koleksiyon.h"

Koleksiyon new_Koleksiyon(int* sayilar, int uzunluk){
	Koleksiyon this;
	this = (Koleksiyon)malloc(sizeof(struct KOLEKSIYON));
	this->super = new_Topluluk(sayilar, uzunluk);
	this->ortalama = &ortalama;
	this->yazdir = &yazdir_;
	this->delete_Koleksiyon = &delete_Koleksiyon;
	return this;
}
double ortalama(const Koleksiyon this){
	double toplam =0; 
	for(int i = 0; i < this->super->uzunluk; i++) {
		toplam += this->super->sayilar[i];
	}
	return toplam/this->super->uzunluk;
}
void yazdir_(const Koleksiyon this){
	this->super->yazdir(this->super);
	printf("\nOrtalama: %lf", ortalama(this));
}
void delete_Koleksiyon(const Koleksiyon this){
	if(this == NULL) return;
	this->super->delete_Topluluk(this->super);
	free(this);
}