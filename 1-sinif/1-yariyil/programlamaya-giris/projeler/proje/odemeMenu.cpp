#include "odemeMenu.h"
#include <fstream>
#include <iostream>
#include "mekanMenu.h"
#include <iomanip>
#include <conio.h>
#include "kisiMenu.h"


using namespace std;

constexpr auto AIDAT = 13000;

odemeMenu::odemeMenu() {
	ofstream odeme("Odeme.txt", ios::app); //daire.txt oluþtur
	if (!odeme.is_open()) {
		cerr << "Odeme.txt dosyasi oluþturulamadi";
	}
	odeme.close();
}

void odemeMenu::odemeArayuz(){
	system("cls");
	cout << endl << right << setw(28) << ">ÖDEME ÝÞLEMLERÝ" << endl;
	cout << left << setw(20) << "ekle(1)" << right << setw(20)
		<< "sil(2)" << left << setw(20) << endl
		<< "düzelt(3)" << right << setw(20)
		<< "raporla(4)" << endl << "geri (0)";
}

int odemeMenu::islemSor(){
	int secim = 0;
	bool gecerli;

	do {
		secim = _getch();
		secim = secim - 48; //niyeyse char olarak atama yapti 0=48 1=49 oldu ben de düzelmesi için 48 çýkardým

		gecerli = (secim == ekle || secim == sil || secim == duzenle || secim == listele || secim == geri);

	} while (!gecerli);

	return secim;
}

bool odemeMenu::reisVarMi() {
	for (int i = 0; i < MAX_AILEREISI; ++i) {
		if (aileReisleri[i] != nullptr) {
			return true;
		}
	}
	cout << endl << endl << "Hiç AileReisiniz olmadan ödeme iþlemi yapamazsýnýz!" << endl;
	system("pause");
	return false;
}

bool odemeMenu::odemeEkle(){
	string ad;
	string soyad;
	float anlikOdeme;
	cout << endl << endl << "Ödeme yapýcak Aile Reisinin, \nAdi: ";
	getline(cin, ad);
	cout << endl;
	cout << "Soyadi: ";
	getline(cin, soyad);
	for (int i = 0; i < MAX_AILEREISI; ++i) { //0 dan 100 e kadar kiþiler taranýyor
		if (aileReisleri[i] != nullptr && aileReisleri[i]->getad() == ad && aileReisleri[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen ad soyad uyuyorsa bunu yapsýn
			cout << endl << "Aylýk aidat 13000TL dir." << endl;
			cout << endl << "Yapýlacak Ödeme Tutarýný yazýnýz (TL) : ";
			anlikOdeme = kullanicidanSayiAl(0, 7);;
			aileReisleri[i]->toplamYaptigiOdeme += anlikOdeme;
			if (aileReisleri[i]->toplamYaptigiOdeme >= AIDAT) {
				aileReisleri[i]->aidatOdendi = true; //aidat ödedi diye iþaretle
				aileReisleri[i]->kaldigiDaire->setizinli(true); //havuz kullanmasýna izin ver
				cout << "Artýk Havuz ve Fitness'ý Kullanabilirsiniz!";
				ofstream havuzkul("HavuzKul.txt", ios::app);
				havuzkul << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Havuz Kullandirildi" << endl;
				havuzkul.close();
				ofstream fitnesskul("Fitness.txt", ios::app);
				fitnesskul << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Fitness Kullandirildi" << endl;
				fitnesskul.close();

			}
			else {
				cout << endl << "havuzu kullanabilmek için " << AIDAT - aileReisleri[i]->toplamYaptigiOdeme << "TL kadar daha para ödemeniz gerekmektedir." << endl; 
				ofstream havuz("HavuzKul.txt", ios::app);
				havuz << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Havuz Kullandirilmadi" << endl;
				havuz.close();
				ofstream fitness("Fitness.txt", ios::app);
				fitness << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Fitness Kullandirilmadi" << endl;
				fitness.close();
			}

			//		
			odemeDosyaGuncelle();

			cout << endl << "Ödeme iþlemi tamamlandý" << endl << endl;
			system("pause");
			break;
		}
		else {
			if (i == MAX_AILEREISI - 1) { //eðer tüm diziyi tarar ve istenen ada ve soyada sahip kiþi bulamazsa bunu yapsýn
				cout << endl << "kiþi bulunamadý." << endl;
				system("pause");
				return true;
			}
		}
	}

	return false;
}

void odemeMenu::odemeDosyaGuncelle() {
	for(int i = 0; i < MAX_AILEREISI; ++i){
		if(aileReisleri[i]!=nullptr){
			ofstream odeme("Odeme.txt", ios::trunc);
			if (!odeme.is_open()) {
				cerr << "Odeme.txt dosyasi oluþturulamadi";
			}
			odeme << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Yaptigi odeme: " << aileReisleri[i]->toplamYaptigiOdeme << endl;
			odeme.close();
		}
	}
}

bool odemeMenu::odemeSil(){
	string ad;
	string soyad;
	float anlikOdeme;
	cout << endl << endl << "Ödemesi silinecek Aile Reisinin, \nAdi: ";
	getline(cin, ad);
	cout << endl;
	cout << "Soyadi: ";
	getline(cin, soyad);
	for (int i = 0; i < MAX_AILEREISI; ++i) { //0 dan 100 e kadar kiþiler taranýyor
		if (aileReisleri[i] != nullptr && aileReisleri[i]->getad() == ad && aileReisleri[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen ad soyad uyuyorsa bunu yapsýn
			aileReisleri[i]->aidatOdendi = false;
			aileReisleri[i]->toplamYaptigiOdeme = 0;
			aileReisleri[i]->kaldigiDaire->setizinli(false);
			cout << endl << ad << " " << soyad << " kiþisinin ödemesi silindi." << endl;
			odemeDosyaGuncelle();
			system("pause");
			break;
		}
		else { cout << endl << "kiþi bulunamadi" << endl; system("pause"); break; }
	}
	return false;
}

bool odemeMenu::odemeDuzenle(){
	string ad;
	string soyad;
	float yeniOdeme;
	cout << endl << endl << "Ödemesi düzenlenecek Aile Reisinin, \nAdi: ";
	getline(cin, ad);
	cout << endl;
	cout << "Soyadi: ";
	getline(cin, soyad);
	for (int i = 0; i < MAX_AILEREISI; ++i) { //0 dan 100 e kadar kiþiler taranýyor
		if (aileReisleri[i] != nullptr && aileReisleri[i]->getad() == ad && aileReisleri[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen ad soyad uyuyorsa bunu yapsýn
			aileReisleri[i]->aidatOdendi = false;
			aileReisleri[i]->toplamYaptigiOdeme = 0;
			aileReisleri[i]->kaldigiDaire->setizinli(false);
			cout << endl << "Yapýlacak Ödeme Tutarýný yazýnýz (TL) : ";
			yeniOdeme = kullanicidanSayiAl(0, 7);;
			aileReisleri[i]->toplamYaptigiOdeme += yeniOdeme;
			if (aileReisleri[i]->toplamYaptigiOdeme >= AIDAT) {
				aileReisleri[i]->aidatOdendi = true; //aidat ödedi diye iþaretle
				aileReisleri[i]->kaldigiDaire->setizinli(true); //havuz kullanmasýna izin ver
				cout << "Artýk Havuz ve Fitness'ý Kullanabilirsiniz!";
				ofstream havuzkul("HavuzKul.txt", ios::app);
				havuzkul << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Havuz Kullandirildi" << endl;
				havuzkul.close();
				ofstream fitnesskul("Fitness.txt", ios::app);
				fitnesskul << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Fitness Kullandirildi" << endl;
				fitnesskul.close();

			}
			else {
				cout << endl << "havuzu kullanabilmek için " << AIDAT - aileReisleri[i]->toplamYaptigiOdeme << "TL kadar daha para ödemeniz gerekmektedir." << endl;
				ofstream havuz("HavuzKul.txt", ios::app);
				havuz << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Havuz Kullandirilmadi" << endl;
				havuz.close();
				ofstream fitness("Fitness.txt", ios::app);
				fitness << aileReisleri[i]->ad << " " << aileReisleri[i]->soyad << " - " << "Fitness Kullandirilmadi" << endl;
				fitness.close();
			}
			cout << "kiþi ödemesi güncellendi";
			odemeDosyaGuncelle();
			system("pause");
			break;
		}
	}
	return false;
}

bool odemeMenu::odemeListele(){
	cout << endl << endl;
	cout << "Ödeme Raporu:" << endl << endl;
	for (int i = 0; i < MAX_AILEREISI; ++i) { //aileReisleri taranýyor ve boþ deðilse bilgileri konsola yazdýrýlýyor
		if (aileReisleri[i] != nullptr) {
			cout << aileReisleri[i]->ad << aileReisleri[i]->soyad << " - " << aileReisleri[i]->toplamYaptigiOdeme;
			if (aileReisleri[i]->aidatOdendi) cout << " Aidat Ödendi";
			cout << endl;
		}
	}
	system("pause");
	return true; //çýk
}

bool odemeMenu::calistir(){
	while (1) {
		int secim;
		odemeArayuz();
		secim = islemSor();

		if (reisVarMi() == false) { //burdaki false dan kasýt henüz hiç Aile Reisinin olmadýðý
			return true; //burdaki true dan kasýt geri gidilmek istendiði
		}


		if (secim == geri) {
			return true; 
		}

		else if (secim == ekle) {
			bool geriGit;
			geriGit = odemeEkle();
			if (geriGit == true) continue;
		}

		else if (secim == sil) {
			bool geriGit;
			geriGit = odemeSil();
			if (geriGit == true) continue;
		}

		else if (secim == duzenle) {
			bool geriGit;
			geriGit = odemeDuzenle();
			if (geriGit == true) continue;
		}

		else if (secim == listele) {
			bool geriGit;
			geriGit = odemeListele();
			if (geriGit == true) continue;
		}

	}
	return false; //geri tuþuna basýlmadý
}
