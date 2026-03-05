#include <conio.h>
#include <iomanip> 
#include <iostream>
#include "kisiMenu.h"
#include "anaMenu.h"
#include <fstream>
#include "oturan.h"
#include <string>
#include "mekanMenu.h"


using namespace std;

AileReisi* aileReisleri[MAX_AILEREISI] = { nullptr };
Misafir* misafirler[MAX_MISAFIR] = { nullptr };


KisiMenu::KisiMenu() { //constructor
	ofstream kisi("Data.txt",ios::app); //daire.txt oluþtur
	if (!kisi.is_open()) {
		cerr << "Data.txt dosyasi oluþturulamadi";
	}
	kisi.close();
}

void KisiMenu::kisiArayuz(){
	system("cls");
	cout << endl << right << setw(28) << ">KÝÞÝ ÝÞLEMLERÝ" << endl;
	cout << left << setw(20) << "ekle(1)" << right << setw(20)
		<< "sil(2)" << left << setw(20) << endl
		<< "düzenle(3)" << right << setw(20)
		<< "raporla(4)" << endl << "geri (0)";
}

int KisiMenu::islemSor(){	
	int secim = 0;
	bool gecerli;

	do {
		secim = _getch();
		secim = secim - 48; //niyeyse char olarak atama yapti 0=48 1=49 oldu ben de düzelmesi için 48 çýkardým

		gecerli = (secim == ekle || secim == sil || secim == duzenle || secim == listele || secim == geri);

	} while (!gecerli);

	return secim;
}

bool KisiMenu::kisiEkle() {
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>KÝÞÝ EKLE" << endl << endl;
	cout << left << setw(20) << "AileReisi(1)" << right << setw(20)
		<< "Misafir(2)" << endl << right << setw(40)
		<< "geri (0)";

	secim = kisiSor();
	if (secim == geri) {
		return true; //geri tusuna basildi
	}

	else if (secim == 1) {
		cout << endl << "Aile Reisi ekleniyor" << endl;
		for (int i = 0; i < MAX_AILEREISI; ++i) { //0 dan 1 e kadar daire adreslerine bakýlýyor ilk bos adrese bir daire atanýyor.
			
			string ad;
			string soyad;
			int yas;
			int mekanNo;
			Daire* dairesi = nullptr; 

			if (aileReisleri[i] == nullptr) {
				cout << endl << endl;

				cout << "Ad: ";
				getline(cin, ad);
				cout << endl;

				cout << "Soyad: ";
				getline(cin, soyad);
				cout << endl;

				cout << "Yaþ: ";
				yas = kullanicidanSayiAl(1, 3);
				cout << endl;

				bool bulundu;
				do{ 
					bulundu = false;
					cout << endl << "Kaldýðý daire: ";
					mekanNo = kullanicidanSayiAl(1, 3);
					for (int i = 0; i < MAX_DAIRE; i++) { //tüm dairelerin mekanNo su kontrol ediliyor
						if (daireler[i] != nullptr) {
							if (mekanNo == daireler[i]->getmekanNo()) { //girdiðimiz sayý ile ayný ise  kontrol iþlemi sonlandýrýyor
								dairesi = daireler[i];
								bulundu = true;
								if (daireler[i]->getaileReisiVar() == true) {
									cout << endl << "Dairede zaten bir Aile Reisi var" << endl;
									system("pause");
									return true;
								}
							}
						}
					}  

					if(bulundu==false) cout << endl << "Böyle bir daire yok." << endl;

					
					

				} while (bulundu == false);

				
				aileReisleri[i] = new AileReisi(ad, soyad, yas, dairesi);
				dosyayaEkle("AileReisi", ad, soyad, yas, dairesi);
				aileReisleri[i]->kaldigiDaire->setaileReisiVar(true);
				cout << endl << endl << "kisi " << aileReisleri[i]->getkaldigiDaireNo() << " numaralý daireye kaydedildi." << endl;
				system("pause");
				break;
			}
		}
	}

	else if (secim == 2) {
		cout << "misafir kiþisi ekleniyor";

		for (int i = 0; i < MAX_MISAFIR; ++i) { //0 dan 1 e kadar daire adreslerine bakýlýyor ilk bos adrese bir daire atanýyor.
			string ad;
			string soyad;
			int yas;
			int mekanNo;
			Daire* dairesi = nullptr;

			if (misafirler[i] == nullptr) {
				cout << endl << endl;

				cout << "Ad: ";
				getline(cin, ad);
				cout << endl;

				cout << "Soyad: ";
				getline(cin, soyad);
				cout << endl;

				cout << "Yaþ: ";
				yas = kullanicidanSayiAl(1, 3);
				cout << endl;

				bool bulundu;
				do {
					bulundu = false;
					cout << endl << "Kaldýðý daire: ";
					mekanNo = kullanicidanSayiAl(1, 3);
					for (int i = 0; i < MAX_DAIRE; i++) { //tüm dairelerin mekanNo su kontrol ediliyor
						if (daireler[i] != nullptr) {
							if (mekanNo == daireler[i]->getmekanNo()) { //girdiðimiz sayý ile ayný ise kontrol iþlemi sonlandýrýyor
								dairesi = daireler[i];
								bulundu = true;
							}
						}
					}

					if (bulundu == false) cout << endl << "Böyle bir daire yok." << endl;


				} while (bulundu == false);


				misafirler[i] = new Misafir(ad, soyad, yas, dairesi);
				dosyayaEkle("Misafir", ad, soyad, yas, dairesi);
				cout << endl << endl << "kisi " << mekanNo << " numaralý daireye kaydedildi." << endl;
				system("pause");
				break;
			}
		}
	}
}

void KisiMenu::dosyayaEkle(string tip, string ad, string soyad, int yas, Daire* daire) {
	ofstream kisi;
	kisi.open("Data.txt", ios::app); 
	if (kisi.is_open()) {
		kisi << "Adi: " << ad << endl
			<< "Soyadi: " << soyad << endl
			<< "Yasi: " << yas << endl
			<< "tip: " << tip << endl
			<< "Kaldigi Daire: " << daire->getmekanNo() << endl << "-" << endl;
		kisi.close(); 
	}
	else cerr << "bir sorun var";
}

void KisiMenu::dosyayiGuncelle(){

	ofstream reis("Data.txt", ios::trunc);  // Dosyayý baþtan oluþtur her þey silinir
	if (reis.is_open()) {
		for (int i = 0; i < MAX_AILEREISI; i++) { //0 dan 100 e kadar kiþiler taranýr
			if (aileReisleri[i] != nullptr) { //eðer kiþi varsa yazýlýr
				reis << "Adi: " << aileReisleri[i]->getad() << endl
					<< "Soyadi: " << aileReisleri[i]->getsoyad() << endl
					<< "Yasi: " << aileReisleri[i]->getyas() << endl
					<< "tip: " << "Aile Reisi" << endl
					<< "Kaldigi Daire: " << aileReisleri[i]->kaldigiDaire->getmekanNo() << endl << "-" << endl;
			}
		}
		reis.close();
	}
	else {
		cout << "Dosya yazma hatasi.\n";
	}

	ofstream misafir("Data.txt", ios::app);  
	if (misafir.is_open()) {
		for (int i = 0; i < MAX_MISAFIR; i++) { //0 dan 100 e kadar kiþiler taranýr
			if (misafirler[i] != nullptr) { //eðer kiþi varsa yazýlýr
				misafir << "Adi: " << misafirler[i]->getad() << endl
					<< "Soyadi: " << misafirler[i]->getsoyad() << endl
					<< "Yasi: " << misafirler[i]->getyas() << endl
					<< "tip: " << "Misafir" << endl
					<< "Kaldigi Daire: " << misafirler[i]->kaldigiDaire->getmekanNo() << endl << "-" << endl;
			}
		}
		misafir.close();
		cout << "Mekanlar dosyasina güncellenmiþ mekanlar kaydedildi.\n";
	}
	else {
		cout << "Dosya yazma hatasi.\n";
	}
}



bool KisiMenu::kisiSil(){
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>KÝÞÝ SÝL" << endl << endl;
	cout << left << setw(20) << "AileReisi(1)" << right << setw(20)
		<< "Misafir(2)" << endl << right << setw(40)
		<< "geri (0)";

	secim = kisiSor();

	if (secim == geri) {
		return true; //geri tusuna basildi
	}

	else if (secim == aileReisi) {
		string ad;
		string soyad;
		cout << endl << endl << "Silmek istediðiniz kiþinin, \nadi: ";
		getline(cin, ad);
		cout << endl;
		cout << "Soyadi: ";
		getline(cin, soyad);
		for (int i = 0; i < MAX_AILEREISI; ++i) { //0 dan 100 e kadar kiþiler taranýyor
			if (aileReisleri[i] != nullptr && aileReisleri[i]->getad() == ad && aileReisleri[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen ad soyad uyuyorsa bunu yapsýn
				aileReisleri[i]->kaldigiDaire->setaileReisiVar(false);
				delete aileReisleri[i];
				aileReisleri[i] = nullptr;
				cout << endl << "kiþi silindi" << endl;
				dosyayiGuncelle();
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
	}

	else if (secim == misafir) { 
		string ad;
		string soyad;
		cout << endl << endl << "Silmek istediðiniz kiþinin, \nadi: ";
		getline(cin, ad);
		cout << endl;
		cout << "Soyadi: ";
		getline(cin, soyad);
		for (int i = 0; i < MAX_MISAFIR; ++i) { //0 dan 100 e kadar kiþiler taranýyor
	 		if (misafirler[i] != nullptr && misafirler[i]->getad() == ad && misafirler[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen ad soyad uyuyorsa bunu yapsýn
				delete misafirler[i];
				misafirler[i] = nullptr;
				cout << endl << "kiþi silindi" << endl;
				dosyayiGuncelle();
				system("pause");
				break;
			}
			else {
				if (i == MAX_MISAFIR - 1) { //eðer tüm diziyi tarar ve istenen ada ve soyada sahip kiþi bulamazsa bunu yapsýn
					cout << endl << "kiþi bulunamadý." << endl;
					system("pause");
					return true;
				}
			}
		}
	}

	return false;
}

bool KisiMenu::kisiListele(){
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>KÝÞÝ LÝSTELE" << endl << endl;
	cout << left << setw(20) << "AileReisi(1)" << right << setw(20)
		<< "Misafir(2)" << endl << right << setw(40)						
		<< "geri (0)";

	secim = kisiSor();

	if (secim == geri) {
		return true; //geri tusuna basildi
	}

	else if (secim == aileReisi) {

		cout << endl << endl;
		cout << "Kayýtlý AileReisleri:" << endl << endl;
		for (int i = 0; i < MAX_AILEREISI; ++i) { //aileReisleri taranýyor ve boþ deðilse bilgileri konsola yazdýrýlýyor
			if (aileReisleri[i] != nullptr) {
				cout << "Adi: " << aileReisleri[i]->getad() << endl;
				cout << "Soyadi: " << aileReisleri[i]->getsoyad() << endl;
				cout << "Yasi: " << aileReisleri[i]->getyas() << endl;
				cout << "Kaldigi Daire: " << aileReisleri[i]->kaldigiDaire->getmekanNo() << endl;
				cout << "Borcu: "; if (aileReisleri[i]->getaidatOdendi() == true) cout << "yok";
				else cout << "var";
				cout << endl << endl;
			}
		}
		system("pause");
		return true; //çýk
	}

	else if (secim == misafir) {

		cout << endl << endl;
		cout << "Kayýtlý Misafirler:" << endl << endl;
		for (int i = 0; i < MAX_MISAFIR; ++i) { //aileReisleri taranýyor ve boþ deðilse bilgileri konsola yazdýrýlýyor
			if (misafirler[i] != nullptr) {
				cout << "Adi: " << misafirler[i]->getad() << endl;
				cout << "Soyadi: " << misafirler[i]->getsoyad() << endl;
				cout << "Yasi: " << misafirler[i]->getyas() << endl;
				cout << "Kaldigi Daire: " << misafirler[i]->kaldigiDaire->getmekanNo() << endl;
				cout << "H/F Kullanabilir: ";
				if (misafirler[i]->kaldigiDaire->getizinli()) cout << "evet";
				else cout << "hayir";
				cout << endl << endl;
			}
		}
		system("pause");
		return true; //çýk
	}


	return false; //geri tusuna basilmadi
}

bool KisiMenu::kisiDuzenle(){
	int secim = 0;
	system("cls");
	cout << endl << right << setw(25) << ">>KÝÞÝ LÝSTELE" << endl << endl;
	cout << left << setw(20) << "AileReisi(1)" << right << setw(20)
		<< "Misafir(2)" << endl << right << setw(40)
		<< "geri (0)";

	secim = kisiSor();

	if (secim == geri) {
		return true; //geri tusuna basildi
	}
	else if (secim == aileReisi) {
		string ad;
		string soyad;
		int yeniNo;
		int yas;
		Daire* yeniDairesi = nullptr;
		cout << endl << endl << "Düzenlemek istediðiniz kiþinin, \nadi: ";
		getline(cin, ad);
		cout << endl;
		cout << "Soyadi: ";
		getline(cin, soyad);
		for (int i = 0; i < MAX_AILEREISI; ++i) { //0 dan 100 e kadar daireler taranýyor
			if (aileReisleri[i] != nullptr && aileReisleri[i]->getad() == ad && aileReisleri[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen daire numarasýna sahipse bunu yapsýn
				cout << endl << "Kiþi bulundu.." << endl;
				yas = aileReisleri[i]->getyas();
				aileReisleri[i]->kaldigiDaire->setaileReisiVar(false);
				bool doluDaire;
				do {
					doluDaire = false;
					cout << "Kiþinin yeni kaydedileceði dairenin numarasýný giriniz: ";
					yeniNo = kullanicidanSayiAl(1, 3);
					for (int i = 0; i < MAX_DAIRE; i++) { //tüm dairelerin mekanNo su kontrol ediliyor
						if (daireler[i] != nullptr) { //daire varsa
							if (yeniNo == daireler[i]->getmekanNo()) { //girdiðimiz numaraya sahip daire ise

								if (daireler[i]->getaileReisiVar() == true) {
									cout << endl << "Bu Daire zaten bir Aile Reisine sahip." << endl;
									system("pause");
									doluDaire = true;
									break;
								}

								else { // ve o dairede aile reisi yoksa

									yeniDairesi = daireler[i];
									for (int i = 0; i < MAX_AILEREISI; ++i) { //0 dan 100 e kadar kiþiler taranýyor
										if (aileReisleri[i] != nullptr && aileReisleri[i]->getad() == ad && aileReisleri[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen ad soyad uyuyorsa bunu yapsýn
											aileReisleri[i]->kaldigiDaire->setaileReisiVar(false);
											delete aileReisleri[i];
											aileReisleri[i] = nullptr;
											break;
										}
									}
									aileReisleri[i] = new AileReisi(ad, soyad, yas, yeniDairesi);
									break;
								}
								
							}
							
						}
						if (i == MAX_DAIRE - 1) { //eðer tüm diziyi tarar ve istenen ada ve soyada sahip kiþi bulamazsa bunu yapsýn
							cout << endl << "daire bulunamadý." << endl;
							system("pause");
							return true;
						}
					}
				} while (doluDaire == true); //girdiðimiz sayý ayný iste tekrar sayý istemek için baþa dön

				cout << endl << "Yeni No: " << yeniNo << " olarak güncellendi!" << endl;
				dosyayiGuncelle();
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
	}
	else if (secim == misafir) {
		string ad;
		string soyad;
		int yeniNo;
		int yas;
		Daire* yeniDairesi = nullptr;
		cout << endl << endl << "Düzenlemek istediðiniz kiþinin, \nadi: ";
		getline(cin, ad);
		cout << endl;
		cout << "Soyadi: ";
		getline(cin, soyad);
		for (int i = 0; i < MAX_MISAFIR; ++i) { //0 dan 100 e kadar daireler taranýyor
			if (misafirler[i] != nullptr && misafirler[i]->getad() == ad && misafirler[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen daire numarasýna sahipse bunu yapsýn
				cout << endl << "Kiþi bulundu.." << endl;
				yas = misafirler[i]->getyas();
				bool doluDaire;
				do {
					doluDaire = false;
					cout << "Kiþinin yeni kaydedileceði dairenin numarasýný giriniz: ";
					yeniNo = kullanicidanSayiAl(1, 3);
					for (int i = 0; i < MAX_DAIRE; i++) { //tüm dairelerin mekanNo su kontrol ediliyor
						if (daireler[i] != nullptr) { //daire varsa
							if (yeniNo == daireler[i]->getmekanNo()) { //girdiðimiz numaraya sahip daire ise



								
								yeniDairesi = daireler[i];
								for (int i = 0; i < MAX_MISAFIR; ++i) { //0 dan 100 e kadar kiþiler taranýyor
									if (misafirler[i] != nullptr && misafirler[i]->getad() == ad && misafirler[i]->getsoyad() == soyad) { //eðer boþ deðilse ve istenen ad soyad uyuyorsa bunu yapsýn
										delete misafirler[i];
										misafirler[i] = nullptr;
										break;
									}
								}
								misafirler[i] = new Misafir(ad, soyad, yas, yeniDairesi);
								break;
				

							}

						}
						if (i == MAX_DAIRE - 1) { //eðer tüm diziyi tarar ve istenen ada ve soyada sahip kiþi bulamazsa bunu yapsýn
							cout << endl << "daire bulunamadý." << endl;
							system("pause");
							return true;
						}
					}
				} while (doluDaire == true); //girdiðimiz sayý ayný iste tekrar sayý istemek için baþa dön

				cout << endl << "Yeni No: " << yeniNo << " olarak güncellendi!" << endl;
				dosyayiGuncelle();
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
	}
} 

int KisiMenu::kisiSor(){
	int secim = 0;
	bool gecerli;

	do {

		secim = _getch();
		secim = secim - 48; //niyeyse char olarak atama yapti 0=48 1=49 oldu ben de düzelmesi için 48 çýkardým
		gecerli = (secim == aileReisi || secim == misafir || secim == geri);

	} while (!gecerli);

	return secim;
}

bool KisiMenu::daireVarMi() {
	for (int i = 0; i < MAX_DAIRE; ++i) {
		if (daireler[i] != nullptr) {
			return true;
		}
	}
	cout << endl << endl << "Daireniz olmadan kiþi üzerinde iþlem yapamazsýnýz!" << endl;
	system("pause");
	return false;
}



bool KisiMenu::calistir(){
	while (1) {
		int secim;
		kisiArayuz();
		secim = islemSor();
		
		if (daireVarMi() == false) { //burdaki false dan kasýt henüz hiç mekanýn olmadýðý
			return true; //burdaki true dan kasýt geri gidilmek istendiði
		}

		if (secim == geri) {
			return true;
		}

		else if (secim == ekle) {
			bool geriGit;
			geriGit = kisiEkle();
			if (geriGit == true) continue;

		}

		else if (secim == sil) {
			bool geriGit;
			geriGit = kisiSil();
			if (geriGit == true) continue;
		}

		else if (secim == duzenle) {
			bool geriGit;
			geriGit = kisiDuzenle();
			if (geriGit == true) continue;
		}

		else if (secim == listele) {
			bool geriGit;
			geriGit = kisiListele();
			if (geriGit == true) continue;
		}
	}
	return false; //geri tuþuna basýlmadý
}
