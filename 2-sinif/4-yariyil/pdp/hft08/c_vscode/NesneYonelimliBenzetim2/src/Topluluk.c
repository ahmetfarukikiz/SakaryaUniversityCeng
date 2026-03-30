#include "Topluluk.h"

Topluluk new_Topluluk(int* sayilar, int uzunluk){
	Topluluk this;
	this = (Topluluk) malloc(sizeof(struct TOPLULUK));
	this->sayilar = malloc(sizeof(int)*uzunluk);
	this->uzunluk = uzunluk;
	for(int i = 0; i < uzunluk; i++) { 
		this->sayilar[i] = sayilar[i];
	}
	this->sirala = &sirala;
	this->yazdir = &yazdir;
	this->delete_Topluluk = &delete_Topluluk;
	return this;
}
int* sirala(const Topluluk this){
	for(int i =0; i< this->uzunluk-1; i++) {
		for(int j=1; j<this->uzunluk-i;j++) {
			if(this->sayilar[j] < this->sayilar[j-1]) {
				int yedek = this->sayilar[j];
				this->sayilar[j] = this->sayilar[j-1];
				this->sayilar[j-1] = yedek;
			}
		}
			
	}
	return this->sayilar;
}
void yazdir(const Topluluk this){
	this->sirala(this);
	for(int i = 0; i<this->uzunluk; i++){
		printf("%d ",this->sayilar[i]);
	}
}
void delete_Topluluk(const Topluluk this){ //hem sayilar dizisini hem topluluğu silicez
	if(this == NULL) return;
	free(this->sayilar);
	free(this);

}