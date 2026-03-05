#ifndef KISIMENU_H
#define KISIMENU_H

#include <iostream>
#include "mekan.h"
#include "oturan.h"

constexpr auto MAX_AILEREISI = 100;
constexpr auto MAX_MISAFIR = 300;

using namespace std;

extern AileReisi* aileReisleri[MAX_AILEREISI];
extern Misafir* misafirler[MAX_MISAFIR];


class KisiMenu {
	void kisiArayuz();
	int islemSor();
	bool kisiEkle();
	bool kisiSil();
	bool kisiListele();
	bool kisiDuzenle();
	int kisiSor();
	bool daireVarMi();
	void dosyayaEkle(string tip, string ad, string soyad, int yas, Daire* daire);


public:
	KisiMenu();
	bool calistir();
	void dosyayiGuncelle();


	friend float kullanicidanSayiAl(bool tamSayiMi, int sinir);

};

enum kisi {
	aileReisi= 1, misafir 
};

#endif
