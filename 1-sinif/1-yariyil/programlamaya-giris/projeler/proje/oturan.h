#ifndef OTURAN_H
#define OTURAN_H

#include <iostream>
#include "mekan.h"
#include <string>
using namespace std;

class Oturan { //~base class
protected:
	string ad;
	string soyad;
	int yas;
public:
	Daire* kaldigiDaire;
	Oturan(string a, string s, int y, Daire* d) : ad(a), soyad(s), yas(y) ,kaldigiDaire(d) {}  // Base constructor

};

class AileReisi : public Oturan {
	bool aidatOdendi; //eger 1 ise fitness ve havuz kullandýrýlsýn
	float toplamYaptigiOdeme;
public:
	AileReisi(string a, string s, int y, Daire* d) : Oturan{a,s,y,d } {}
	bool getaidatOdendi();
	string getad();
	string getsoyad();
	int getyas();
	int getkaldigiDaireNo();
	void kaldigiDaireyiGuncelle(Daire* yeniDaire);
	friend class odemeMenu;
};

class Misafir : public Oturan {
public:
	Misafir(string a, string s, int y, Daire* d) : Oturan{ a,s,y,d } {}
	string getad();
	string getsoyad();
	int getyas();
	int getkaldigiDaireNo();

};

#endif
