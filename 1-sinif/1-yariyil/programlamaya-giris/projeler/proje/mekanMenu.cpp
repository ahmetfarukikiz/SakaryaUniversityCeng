#include <iostream>
#include "mekanMenu.h"
#include <conio.h>
#include <iomanip>
#include "mekan.h"
#include <string>
#include "globalFonksiyonlar.h"
#include "anaMenu.h"
#include <fstream>
#include "kisiMenu.h"
	
using namespace std;


Daire* daireler[MAX_DAIRE] = { nullptr };
Fitness* fitnesslar[MAX_FITNESS] = { nullptr };
Havuz* havuzlar[MAX_HAVUZ] = { nullptr };


mekanMenu::mekanMenu() { //constructor
	ofstream data("Mekan.txt",ios::app); //Mekan.txt oluþtur 
	if (!data.is_open()) {
		cerr << "Mekan.txt dosyasi oluþturulamadi";
	}
	data.close();

	ofstream HavuzKul("HavuzKul.txt", ios::app); //HavuzKul.txt oluþtur
	if (!HavuzKul.is_open()) {
		cerr << "HavuzKul.txt dosyasi oluþturulamadi " << endl;
	}
	HavuzKul.close();

	ofstream fitness("Fitness.txt", ios::app);  //HavuzKul.txt oluþtur 
	if (!fitness.is_open()) {
		cerr << "Fitness.txt dosyasi oluþturulamadi " << endl;
	}
	fitness.close();

}


void mekanMenu::mekanArayuz() {
	system("cls");
	cout << endl << right << setw(28) << ">MEKAN ÝÞLEMLERÝ" << endl;
	cout << left << setw(20) << "ekle(1)" << right << setw(20)
		<< "sil(2)" << left << setw(20) << endl
		<< "düzelt(3)" << right << setw(20)
		<< "listele(4)" << endl << "geri (0)";					
}

int mekanMenu::islemSor() {
	
	int secim = 0;
	bool gecerli;

	do {

		secim = _getch();	
		secim = secim - 48; //niyeyse char olarak atama yapti 0=48 1=49 oldu ben de düzelmesi için 48 çýkardým

		gecerli = (secim == ekle || secim == sil || secim == duzenle || secim == listele || secim == geri);

	} while (!gecerli);

	return secim;
		
}

bool mekanMenu::mekanEkle(){
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>MEKAN EKLE" << endl;
	cout << left << setw(20) << "Daire(1)" << right << setw(20)
		<< "Fitness(2)" << left << setw(20) << endl
		<< "Havuz(3)" << right << setw(20) << "geri (0)";

	secim=mekanSor();

	if (secim == geri) {
		return true; //geri tusuna basildi
	}
	
	else if (secim == daire) {
		
		
		for (int i = 0; i < MAX_DAIRE; ++i) { //0 dan 1 e kadar daire adreslerine bakýlýyor ilk bos adrese bir daire atanýyor.
			int mekanNo;
			if (daireler[i] == nullptr ) {
				cout << endl << endl;
			
				bool ayniDaire;
			do{
				ayniDaire = false;
				cout << "Daire no girin: ";
				mekanNo = kullanicidanSayiAl(1, 3);
				for (int i = 0; i < MAX_DAIRE; i++) { //tüm dairelerin mekanNo su kontrol ediliyor
					if (daireler[i] != nullptr) {
						if (mekanNo == daireler[i]->getmekanNo()) { //girdiðimiz sayý ile ayný ise kontrol iþlemi sonlandýrýyor
							ayniDaire = true; 
							cout << endl << "Bu oda zaten mevcut!" << endl;
							break;
						}
					}
				}
			} while (ayniDaire == true); //girdiðimiz sayý ayný iste tekrar sayý istemek için baþa dön
				
				daireler[i] = new Daire(mekanNo,false,false); //her yeni oluþan dairenin izini false tur.
				cout << endl << "daire eklendi" << endl;
				dosyayaEkle(mekanNo, "Daire");
				system("pause");
				break;
			}
		}
	}

	else if (secim == fitness) {


		for (int i = 0; i < MAX_FITNESS; ++i) { //0 dan 1 e kadar fitness adreslerine bakýlýyor ilk bos adrese bir daire atanýyor.
			int mekanNo;
			if (fitnesslar[i] == nullptr) {
				cout << endl << endl;

				bool ayniFitness;
				do {
					ayniFitness = false;
					cout << "Fitness no girin: ";
					mekanNo = kullanicidanSayiAl(1, 3);
					for (int i = 0; i < MAX_FITNESS; i++) { //tüm fitnesslarýn mekanNo su kontrol ediliyor
						if (daireler[i] != nullptr) {
							if (mekanNo == fitnesslar[i]->getmekanNo()) { //girdiðimiz sayý ile ayný ise kontrol iþlemi sonlandýrýyor
								ayniFitness = true;
								cout << endl << "Bu fitness zaten mevcut!" << endl;
								break;
							}
						}
					}
				} while (ayniFitness == true); //girdiðimiz sayý ayný iste tekrar sayý istemek için baþa dön

				fitnesslar[i] = new Fitness(mekanNo); //her yeni oluþan dairenin izini false tur.
				cout << endl << "Fitness eklendi" << endl;
				dosyayaEkle(mekanNo, "Fitness");
				system("pause");
				break;
			}
		}
	}

	else if (secim == havuz) {


		for (int i = 0; i < MAX_HAVUZ; ++i) { //0 dan 1 e kadar havuz adreslerine bakýlýyor ilk bos adrese bir daire atanýyor.
			int mekanNo;
			if (havuzlar[i] == nullptr) {
				cout << endl << endl;

				bool ayniFitness;
				do {
					ayniFitness = false;
					cout << "Havuz no girin: ";
					mekanNo = kullanicidanSayiAl(1, 3);
					for (int i = 0; i < MAX_HAVUZ; i++) { //tüm havuzlarýn mekanNo su kontrol ediliyor
						if (daireler[i] != nullptr) {
							if (mekanNo == havuzlar[i]->getmekanNo()) { //girdiðimiz sayý ile ayný ise kontrol iþlemi sonlandýrýyor
								ayniFitness = true;
								cout << endl << "Bu Havuz zaten mevcut!" << endl;
								break;
							}
						}
					}
				} while (ayniFitness == true); //girdiðimiz sayý ayný iste tekrar sayý istemek için baþa dön

				havuzlar[i] = new Havuz(mekanNo); //her yeni oluþan dairenin izini false tur.
				cout << endl << "Havuz eklendi" << endl;
				dosyayaEkle(mekanNo, "Havuz");
				system("pause");
				break;
			}
		}
	}

	return false; //geri tusuna basilmadi
}

void mekanMenu::dosyayaEkle(int mekanNo, string tip){
	ofstream mekan("Mekan.txt", ios::app);
	mekan << "Daire " << mekanNo << endl;
}

void mekanMenu::dosyayiGuncelle(string tip){
	ofstream dosya("Mekan.txt", ios::trunc);  // Dosyayý baþtan oluþtur her þey silinir
	if (dosya.is_open()) {
		for (int i = 0; i < MAX_DAIRE; i++) { //0 dan 100 e kadar daireler taranýr
			if(daireler[i]!=nullptr){ //eðer daire boþ deðilse yazýlýr
				dosya << tip << " " << daireler[i]->getmekanNo() << endl;
			}
		}
		dosya.close();
		cout << "Mekanlar dosyasina güncellenmiþ mekanlar kaydedildi.\n";
	}
	else {
		cout << "Dosya yazma hatasi.\n";
	}
}

bool mekanMenu::mekanSil() {
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>MEKAN SÝL" << endl;
	cout << left << setw(20) << "Daire(1)" << right << setw(20)
		<< "Fitness(2)" << left << setw(20) << endl
		<< "Havuz(3)" << right << setw(20) << "geri (0)";

	secim = mekanSor();

	if (secim == geri) {
		return true; //geri tusuna basildi
	}

	else if (secim == daire) {
		int mekanNo = 0;
		cout << endl << endl << "Silinecek daire numarasýný giriniz: " << endl;
		mekanNo = kullanicidanSayiAl(1,3);
		for (int i = 0; i < MAX_DAIRE; ++i) { //0 dan 100 e kadar daireler taranýyor
			        if (daireler[i] != nullptr && daireler[i]->getmekanNo() == mekanNo) { //eðer boþ deðilse ve istenen daire numarasýna sahipse bunu yapsýn
			            delete daireler[i];
						daireler[i] = nullptr;
						cout << endl << "daire ve içindeki kiþiler silindi" << endl;
						dosyayiGuncelle("Daire");
						system("pause");
						break;
			        }
					else {
						if (i == MAX_DAIRE - 1){ //eðer tüm diziyi tarar ve istenen numaraya sahip oda bulamazsa bunu yapsýn
							cout << endl << "Daire bulunamadý." << endl;
							system("pause");
							return true;
						}
					}
		}

	}

	return false;
}

bool mekanMenu::mekanDuzenle() {
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>MEKAN DÜZENLE" << endl;
	cout << left << setw(20) << "Daire(1)" << right << setw(20) << "geri (0)";

	secim = mekanSor();

	if (secim == geri) {
		return true; //geri tusuna basildi
	}
	else if (secim == daire) {
		int mekanNo = 0;
		int yeniNo = 0;
		cout << endl << endl << "Düzenlenecek daire numarasýný giriniz: ";
		mekanNo = kullanicidanSayiAl(1, 3);
		for (int i = 0; i < MAX_DAIRE; ++i) { //0 dan 100 e kadar daireler taranýyor
			if (daireler[i] != nullptr && daireler[i]->getmekanNo() == mekanNo) { //eðer boþ deðilse ve istenen daire numarasýna sahipse bunu yapsýn
				cout << endl << "Daire bulundu.." << endl;
				bool ayniDaire;
				do{
					ayniDaire = false;
					cout << "Yeni Daire numarasýný giriniz: ";
					yeniNo = kullanicidanSayiAl(1, 3);
					for (int i = 0; i < MAX_DAIRE; i++) { //tüm dairelerin mekanNo su kontrol ediliyor
						if (daireler[i] != nullptr) {
							if (yeniNo == daireler[i]->getmekanNo()) { //girdiðimiz sayý ile ayný ise kontrol iþlemi sonlandýrýyor
								ayniDaire = true;
								cout << endl << "Bu oda zaten mevcut!" << endl;
								break;
							}
						}
					}
				} while (ayniDaire == true); //girdiðimiz sayý ayný iste tekrar sayý istemek için baþa dön

				daireler[i]->setmekanNo(yeniNo);
				cout << endl << "Yeni No: " << yeniNo << " olarak güncellendi!" << endl;
				dosyayiGuncelle("Daire");
				KisiMenu* k = new KisiMenu();
				k->dosyayiGuncelle();
				delete k;
				k = nullptr;
				dosyayiGuncelle("Aile Reisi");
				system("pause");
				break;
			}
			else {
				if (i == MAX_DAIRE - 1) { //eðer tüm diziyi tarar ve istenen numaraya sahip oda bulamazsa bunu yapsýn
					cout << endl << "Daire bulunamadý." << endl;
					system("pause");
					return true;
				}
			}
		}
	}

}

bool mekanMenu::mekanListele(){
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>MEKAN LÝSTELE" << endl;
	cout << left << setw(20) << "Daire(1)" << right << setw(20)
		<< "Fitness Kullaným(2)" << left << setw(20) << endl
		<< "Havuz Kullaným(3)" << right << setw(20) << "geri (0)";

	secim = mekanSor();

	if (secim == geri) {
		return true; //geri tusuna basildi
	}

	else if (secim == daire) {

		cout << endl << endl;
		cout << "Kayýtlý Daireler:" << endl << endl;
		    for (int i = 0; i < MAX_DAIRE; ++i) {
		        if (daireler[i] != nullptr) {
					cout << "Daire No: " << daireler[i]->getmekanNo() << endl;
		        }
		    }
			system("pause");
			return true; //çýk
	}

	else if (secim == havuz) {

		cout << endl << endl;
		cout << "Dairelerin Havuz Kullaným Durumu:" << endl << endl;
		for (int i = 0; i < MAX_DAIRE; ++i) {
			if (daireler[i] != nullptr) {
				cout << "Daire No: " << daireler[i]->getmekanNo() << " - "; 
				if (daireler[i]->getizinli()) {
					cout << "havuzu kullanabilir" << endl;
				}
				else cout << "havuzu kullanamaz" << endl;
			}
		}

		system("pause");
		return true;
	}

	else if (secim == fitness) {

		cout << endl << endl;
		cout << "Dairelerin Fitness Kullaným Durumu:" << endl << endl;
		for (int i = 0; i < MAX_DAIRE; ++i) {
			if (daireler[i] != nullptr) {
				cout << "Daire No: " << daireler[i]->getmekanNo() << " - ";
				if (daireler[i]->getizinli()) {
					cout << "fitness'ý kullanabilir" << endl;
				}
				else cout << "fitness'ý kullanamaz" << endl;
			}
		}

		system("pause");
		return true;
	}


	return false; //geri tusuna basilmadi
}


int mekanMenu::mekanSor(){
	int secim = 0;
	bool gecerli;

	do {

		secim = _getch();
		secim = secim - 48; //niyeyse char olarak atama yapti 0=48 1=49 oldu ben de düzelmesi için 48 çýkardým

		gecerli = (secim == daire || secim == fitness || secim == havuz || secim == geri);

	} while (!gecerli);

	return secim;
}



bool mekanMenu::calistir() {
	while(1){
		int secim;
		mekanArayuz();
		secim=islemSor();
		cout << "secim: " << secim;

		if (secim == geri) { 
			return true; 
		}

		else if (secim == ekle) {
			bool geriGit;
			geriGit=mekanEkle();
			if (geriGit == true) continue;
			
		}

		else if (secim == sil) {
			bool geriGit;
			geriGit = mekanSil();
			if (geriGit == true) continue;
		}

		else if (secim == duzenle) {
			bool geriGit;
			geriGit = mekanDuzenle();
			if (geriGit == true) continue;
		}

		else if (secim == listele) {
			bool geriGit;
			geriGit = mekanListele();
			if (geriGit == true) continue;
		}
	}
	return false; //geri tusuna basilmadi
}


