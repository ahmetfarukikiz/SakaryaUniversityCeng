#include "mekan.h"
#include <iostream>
#include <fstream>
#include "globalFonksiyonlar.h"

using namespace std;

void Daire::setmekanNo(int m){
	mekanNo = m;
}

int Daire::getmekanNo(){
	return mekanNo;
}

void Daire::setaileReisiVar(bool a){
	aileReisiVar = a;
}

bool Daire::getaileReisiVar(){
	return aileReisiVar;
}

void Daire::setizinli(bool a){
	izinli = a;
}

bool Daire::getizinli()
{
	return izinli;
}

int Fitness::getmekanNo(){
	return mekanNo;
}

int Havuz::getmekanNo() {
	return mekanNo;
}
