#include <iostream>
#include <conio.h>
#include <string>
#include "globalFonksiyonlar.h"
#include "mekan.h"

using namespace std;


float kullanicidanSayiAl(bool tamSayiMi,int sinir) { //kullanýcýdan sayý isterken istenmeyen giriþleri kontrol ediyorum. 

	char x; //getch'ye atanacak her bir karakter
	string dizi = ""; //atanan karakterleri uc uca ekleyerek sayi mi degil mi kontrolu yapýyorum
	bool nokta = false; //hic noktaya basilmis mi diye kontrol eder
	do {
		int uzunluk = 0;
		do {
			x = _getch();

			if(uzunluk<sinir){

				if (tamSayiMi == true) { nokta = true; } //tamsayýysa nokta giriþmiþ gibi say tekrar nokta girmesine izin verme

				if (nokta == false) { //henüz hic nokta yazmadiysa bunu yap
					if (isdigit(x) || (x == '.')) {
						dizi += x;
						cout << x;
						if (x == '.') nokta = true; //ilk nokta yazdiktan sonra nokta=true yap
						uzunluk++;
					}
				}

				else if (nokta == true) { //en az bir nokta yazildiysa veya tamsayiysa bunu yap
					if (isdigit(x)) {
						dizi += x;
						cout << x;
						uzunluk++;
					}
				}
				
				
			}

			if (x == '\b' && dizi != "") { //eðer backspace e basýldýysa ve dizi boþ deðilse yap
				cout << "\b \b"; //son karakteri ekrandan siler
				if (dizi.back() == '.') nokta = false; //dizinin son karakteri . ise ve silinirse nokta hiç koyulmamýþ gibi davran
				dizi.pop_back(); //son karakteri diziden siler

				if (uzunluk >= 0) uzunluk--;
				
			}

		} while ((x != '\r')); //entera basýlana kadar karakterler, stringe atanmaya devam edecek

		if (dizi == "") {
			cout << "Bu veri bos birakilamaz!" << endl;
		}



	} while (dizi == ""); //dizi bos ise donguye giricek devam etmesine izin vermeyecek


	if (tamSayiMi == 1)  return stoi(dizi);

	else return stof(dizi);

}

				