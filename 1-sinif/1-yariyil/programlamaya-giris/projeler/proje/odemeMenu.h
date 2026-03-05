#ifndef ODEMEMENU_H
#define ODEMEMENU_H

class odemeMenu {
	void odemeArayuz();
	int islemSor();
	bool reisVarMi();
	bool odemeEkle();
	void odemeDosyaGuncelle();
	bool odemeSil();
	bool odemeDuzenle();
	bool odemeListele();
public:
	odemeMenu();
	bool calistir();
};

#endif