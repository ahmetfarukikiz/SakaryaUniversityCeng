#ifndef TOPLULUK_H
#define TOPLULUK_H

#include <stdio.h>
#include <stdlib.h>

struct TOPLULUK{
	int* sayilar;
	int uzunluk;

	int* (*sirala)(struct TOPLULUK*);
	void (*yazdir)(struct TOPLULUK*);
	void (*delete_Topluluk)(struct TOPLULUK*);
};

typedef struct TOPLULUK* Topluluk;
Topluluk new_Topluluk(int*, int); //kurucu fonksiyon görevi
int* sirala(const Topluluk);
void yazdir(const Topluluk);
void delete_Topluluk(const Topluluk);

#endif
