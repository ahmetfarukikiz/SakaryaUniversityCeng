#include "Dosya.h"

Dosya new_Dosya(char* yol){
	Dosya this;
	this = (Dosya) malloc(sizeof(struct DOSYA));
	this->yol = yol;
	this->icerik = NULL;
	this->oku = &oku;
	this->delete_dosya = &delete_Dosya;
	return this;
}

char* oku(const Dosya this){
	char* icerik = NULL;
	int boyut = 0;
	FILE *fp;
	fp = fopen(this->yol,"r");
	if(!fp) throw;
	fseek(fp,0,SEEK_END); //sayfanın sonuna git
	boyut = ftell(fp);
	rewind(fp); //sayfanın en başına git
	icerik = (char*) malloc(sizeof(char)*(boyut+1));
	size_t uzunluk = fread(icerik,1,boyut,fp);
	icerik[uzunluk] = '\0'; //string sonlandırma
	fclose(fp);
	this->icerik = icerik;
	return icerik;
}

void delete_Dosya(Dosya this){
	if(this == NULL) return;
	if(this->icerik != NULL) free(this->icerik);
	free(this);
}