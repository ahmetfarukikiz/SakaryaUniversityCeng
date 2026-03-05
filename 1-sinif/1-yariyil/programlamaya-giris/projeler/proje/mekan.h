#ifndef MEKAN_H
#define MEKAN_H

#include <iostream>
#include "globalFonksiyonlar.h"

using namespace std;


class Mekan { //abstract class ~base class
protected:
	int mekanNo;
public:
	Mekan(int mn) : mekanNo(mn) {}
};

class Daire:public Mekan { 
		bool aileReisiVar;
	string oturanBilgisi;
	bool izinli; //aidat ödenmiþ havuz ve fitness kullanýlabilir
public:
	Daire(int mn, bool i, bool a) : Mekan{ mn }, izinli(i) , aileReisiVar(a) {} //her yeni oluþan dairenin izini false olarak atanýr ödeme yapýldýktan sonra true olur
	void setmekanNo(int m);
	int getmekanNo();
	void setaileReisiVar(bool a);
	bool getaileReisiVar();
	void setizinli(bool a);
	bool getizinli();

};

class Fitness :public Mekan { 
public:
	Fitness(int mn) : Mekan{ mn } {}
	int getmekanNo();
};

class Havuz :public Mekan { 
public:
	Havuz(int mn) : Mekan{ mn } {}
	int getmekanNo();
};

#endif
