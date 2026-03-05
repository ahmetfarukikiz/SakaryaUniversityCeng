#ifndef MEKANMENU_H
#define MEKANMENU_H

#include <iostream>
#include "anaMenu.h"
#include "mekan.h"

constexpr auto MAX_DAIRE = 100;
constexpr auto MAX_FITNESS = 1;
constexpr auto MAX_HAVUZ = 1;

//extern ediyorum ki diðer dosyalarda da kullanýlabilsin
extern Daire* daireler[MAX_DAIRE];
extern Fitness* fitnesslar[MAX_FITNESS];
extern Havuz* havuzlar[MAX_HAVUZ];

using namespace std;

class mekanMenu {
	void mekanArayuz();
	int islemSor();
	bool mekanEkle();
	bool mekanSil();
	bool mekanDuzenle();
	bool mekanListele();
	int mekanSor();
	void dosyayaEkle(int mekanNo, string tip);
	void dosyayiGuncelle(string tip);
	
public:
	mekanMenu(); //Mekan.txt oluþturur
	bool calistir();

	
	friend float kullanicidanSayiAl(bool tamSayiMi, int sinir);

};



enum mekan {
	daire = 1, fitness, havuz
};
#endif