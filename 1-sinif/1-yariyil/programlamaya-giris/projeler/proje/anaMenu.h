#ifndef ANAMENU_H
#define ANAMENU_H

#include <iostream>

using namespace std;



class anaMenu {
	void anaMenuArayuz();
	int islemSor();
public:
	int calistir();


};

enum islem {
	geri = 0, ekle, sil, duzenle, listele
};

enum menuler{
	cikis, mekanMenusu, odemeMenusu, kisiMenusu
};


#endif