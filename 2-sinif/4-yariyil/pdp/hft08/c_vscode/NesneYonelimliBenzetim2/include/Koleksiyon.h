#ifndef KOLEKSIYON_H
#define KOLEKSIYON_H

#include "Topluluk.h"

struct KOLEKSIYON
{
	Topluluk super;
	double (*ortalama)(struct KOLEKSIYON*);
	void (*yazdir)(struct KOLEKSIYON*);
	void (*delete_Koleksiyon)(struct KOLEKSIYON*);

};
typedef struct KOLEKSIYON* Koleksiyon;

Koleksiyon new_Koleksiyon(int*, int);
double ortalama(const Koleksiyon);
void yazdir_(const Koleksiyon);
void delete_Koleksiyon(const Koleksiyon);



#endif