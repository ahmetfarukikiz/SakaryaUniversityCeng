#include "anaMenu.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#include "mekan.h"


using namespace std;


void anaMenu::anaMenuArayuz(){
	cout << endl << right << setw(28) << "TATİL SİTESİ YÖNETİMİi" << endl << endl;
	cout << left << setw(20) << "Mekan İşlemleri(1)" << right << setw(20)
		<< "Ödeme İşlemleri(2)" << setw(20) << endl
		<< left << "Kişi İşlemleri(3)" << right << setw(20)
		<< "Çıkış(0)";
}

int anaMenu::islemSor(){
	int secim = 0;
	bool gecerli;

	

		secim = _getch();
		secim = secim - 48; //niyeyse char olarak atama yapti 0=48 1=49 oldu ben de düzelmesi için 48 çıkardım

		gecerli = (secim == cikis || secim == mekanMenusu || secim == odemeMenusu || secim == kisiMenusu );

	

		return static_cast<int>(secim);

}

int anaMenu::calistir() {
	
		int secim;
		anaMenuArayuz();
		secim = islemSor();

		if (secim == cikis) return 0;

		else if (secim == mekanMenusu) return mekanMenusu;

		else if (secim == odemeMenusu) return odemeMenusu;

		else if (secim == kisiMenusu) return kisiMenusu;
	
}
