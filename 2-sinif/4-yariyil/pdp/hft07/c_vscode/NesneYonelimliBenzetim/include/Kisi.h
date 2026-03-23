#ifndef KISI_H
#define KISI_H

#include <stdio.h>
#include <stdlib.h>

struct KISI
{
	char* isim;
	int yas;
	float boy;
	float kilo;
};
typedef struct KISI* Kisi; //"struct KISI*"" yazılacak her yerde arıtk "Kisi" yazicaz

//javaya benzesin diye new tanımlıyoruz
Kisi new_Kisi(char*, float, float); //isim, boy, kilo
//C'de struct içine yazamadığımızdan Kisi'yi parametre olarak gönderiyoruz
void yemekYe(const Kisi, float); 
void yaslan(const Kisi, int);
char* getIsim(const Kisi);
float getKilo(const Kisi);
void delete_Kisi(const Kisi); //Javada karşılığı yok ama biz heapteki ayrılmış belleği silmeliyiz.

#endif


