/****************************************************************************
**                                SAKARYA ÜNİVERSİTESİ
**                       BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                           BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                             PROGRAMLAMAYA GİRİŞİ DERSİ
**
**                       ÖDEV NUMARASI......:2
**                       ÖĞRENCİ ADI........:Ahmet Faruk İkiz
**                       ÖĞRENCİ NUMARASI...:B241210040
**                       DERS GRUBU.........:A
****************************************************************************/

#include <iostream>
#include <conio.h>
#include <string> 
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;


//gecici baslangic değişkenleri nesnedeki degerlerlerle bi alakalari yok tek olaylari kurucu fonksiyona deger atamak //global olma sebepleri fonksiyon içinde kullanabilmek
float sermaye;
int tavukSayisi;
float yemKgFiyati;
float yumurtaFiyati;
float tavukAlimFiyati;

int gunSayisi;

struct gungun { //belli istatistiki bilgileri ekrana basmak icin gecici olarak saklama amaciyla olusturulmus degiskenler //her gun sonunda sifirlanirlar
	int yemTuketimi;
	int yumurta;
	int kesilenTavuk;
	float Gelir;
	float Gider;
}gunluk;

//fonksiyon declaration
float kullanicidanSayiAl(bool tamSayi);
void kullanicidanBaslangicVeriIsteme();
int rastgele(int min, int max);
void gunlukSifirlama(); //gunluk structının degelerini her gun sonunda ekrana basıldıktan sonra sıfırlanmasını saglar

class Tavuk {
private:
	int toplamYumurta;	//"tek bir" tavugun toplam verdigi yumurta 
	int kacGunluk;		//ciftlige geleli kac gun oldugu
	int yumurtlamiyor;  //kac gundur yumurtlamadigi
public:
	Tavuk() : toplamYumurta(0), kacGunluk(0), yumurtlamiyor(0) {}
	int yemYe();
	int yumurtla();
	bool kesilsinMi();
	void resetTavuk();
	void yaslandir();
};


class Ciftlik {
private:
	float kalanPara;
	int tavukSayisi;
	float yemKgFiyati;
	float yumurtaFiyati;
	float tavukAlimFiyati;
	int yemAmbari; //çiftlikte kaç gram yem kaldığını tutan değişken

public:
	Ciftlik(float a, int b, float c, float d, float e) : kalanPara(a), tavukSayisi(b), yemKgFiyati(c), yumurtaFiyati(d), tavukAlimFiyati(e), yemAmbari(0) { //parameter constructor 
		yemSatinAl();
		tavukAl(tavukSayisi); //tavuk sayisi kadar tavuk al
	}

	Tavuk tavuklar[500]; //500 elemanli bir dizi olusturuyorum fakat tavukSayisi kadarlik kismini kullanicam

	//method declaration

	void tavukAl(int alimMiktari); //ne kadar tavuk alicaksan icine yaz
	void yemSatinAl();
	void simulasyonYap(int gunSayisi); //method declaration
	void tabloYap(int gunSayisi);
	void gunlukIsler();
};


int main(int argc, char* argv[]) {

	srand(time(0));
	cout.precision(2); //float double ',' den sonra 2 basamak alsın 
	cout << fixed;

	kullanicidanBaslangicVeriIsteme();

	Ciftlik ciftlik(sermaye, tavukSayisi, yemKgFiyati, yumurtaFiyati, tavukAlimFiyati);
	ciftlik.simulasyonYap(gunSayisi);

	return 0;
}


//method definiton

void Ciftlik::yemSatinAl() {

	kalanPara -= (700 * yemKgFiyati); //700 kg yem al ve kalan paradan düş
	gunluk.Gider += (700 * yemKgFiyati); //gidere ekleniyor

	yemAmbari += 700000; //g cinsinden 

}

void Ciftlik::tabloYap(int gunSayisi) {

	system("cls");
	cout << endl;
	cout << "Simule edilecek gun sayisi: " << gunSayisi << endl;
	cout << "Baslangic sermayesi: " << sermaye << endl;
	cout << "Tavuk Sayisi: " << tavukSayisi << endl;
	cout << "Yem fiyati(kg): " << yemKgFiyati << endl;
	cout << "Yumurta fiyati: " << yumurtaFiyati << endl;
	cout << "tavuk Alim Fiyati: " << tavukAlimFiyati << endl << endl;

	cout << right
		<< "Gun" << setw(17)
		<< "Yem Tuketimi" << setw(17)
		<< "Yumurta" << setw(17)
		<< "Kesilen Tavuk" << setw(17)
		<< "Gunluk Gelir" << setw(17)
		<< "Gunluk Gider" << setw(17)
		<< "Kalan Yem" << setw(13)
		<< "Kalan Para" << endl;

	for (int i = 0; i < 3; i++) { //tablonun üstündeki başlıkların altındaki çizgiler yapılıyor
		cout << '-';
	}
	cout << setw(6);
	for (int i = 0; i < 12; i++) {
		cout << '-';
	}
	cout << setw(11);
	for (int i = 0; i < 7; i++) {
		cout << '-';
	}
	cout << setw(5);
	for (int i = 0; i < 13; i++) {
		cout << '-';
	}
	cout << setw(6);
	for (int i = 0; i < 12; i++) {
		cout << '-';
	}
	cout << setw(6);
	for (int i = 0; i < 12; i++) {
		cout << '-';
	}
	cout << setw(9);
	for (int i = 0; i < 9; i++) {
		cout << '-';
	}
	cout << setw(4);
	for (int i = 0; i < 10; i++) {
		cout << '-';
	}
	cout << endl;


}

void Ciftlik::simulasyonYap(int gunSayisi) {  //ciktiyi burdan alicam

	tabloYap(gunSayisi);

	for (int i = 1; i <= gunSayisi; i++) {

		gunlukIsler(); //gunluk structı bilgileri ve diğer bilgiler hesaplanıyor.
		cout << fixed;
		cout << right << setw(3) << i << setw(15) << gunluk.yemTuketimi << setw(19) << gunluk.yumurta << setw(15)
			<< gunluk.kesilenTavuk << setw(18) << gunluk.Gelir << setw(18) << gunluk.Gider << setw(17)
			<< yemAmbari << setw(13) << kalanPara << endl;

		if (kalanPara < 0) {
			cout << "Iflas Ettiniz...";
			break;
		}
		gunlukSifirlama(); //bazi istatistiki bilgileri yazdirdiktan sonra, sonraki gun icin sifirliyorum
	}
}

void Ciftlik::gunlukIsler() {

	for (int i = 0; i < tavukSayisi; i++) { //0 dan tavuksayisina kadar tavuklara islemler yapiliyor.
		gunluk.yemTuketimi += tavuklar[i].yemYe(); //tuketilen yemler toplaniyor


		gunluk.yumurta += tavuklar[i].yumurtla();  //yumurtalar toplaniyor

		tavuklar[i].yaslandir();	//tavugun ciftlikte durdugu gun sayisini 1 arttirir. 
		if (tavuklar[i].kesilsinMi()) { //kesilsinMi fonk'u 1 dondururse tavuk kesiliyor

			gunluk.kesilenTavuk++; //gunluk kesilen tavuk sayisini 1 artirir

			kalanPara += (tavukAlimFiyati / 2); //kesilen tavuk satiliyor
			gunluk.Gelir += (tavukAlimFiyati / 2); //gelire ekleniyor

			tavukAl(1); //tavuk satin alma fiyatini kalanparadan düser
			tavuklar[i].resetTavuk(); //gelen yeni tavuk icin ozellikleri sifirlar
		}
	}

	yemAmbari -= gunluk.yemTuketimi; //her bir tavuk icin 100 ila 120g yem eksiltir.
	kalanPara += (gunluk.yumurta * yumurtaFiyati);  //yumurtalar satiliyor
	gunluk.Gelir += (gunluk.yumurta * yumurtaFiyati); //gelire ekleniyor


	if (yemAmbari < 70000) { //70kg dan az yem kalmissa yemsatin al
		yemSatinAl();
	}


}

void Ciftlik::tavukAl(int alimMiktari) { //parametre yazilan sayi kadar tavuk satin al
	kalanPara -= tavukAlimFiyati * alimMiktari; //tavuklar aliniyor
	gunluk.Gider += tavukAlimFiyati * alimMiktari; //gidere ekleniyor
}

int Tavuk::yemYe() { //bir tavuk icin ne kadar yem yedigini dondurur
	return rastgele(100, 120);
}

int Tavuk::yumurtla() {
	if (kacGunluk < 3) return 0;

	else {
		int yumurtlamaSayisi = 0; //her bir tavuk icin o gun yumurtladigi sayi local değişken
		yumurtlamaSayisi = rastgele(0, 2);

		if (yumurtlamaSayisi == 0) {
			yumurtlamiyor++;
			return 0;
		}

		else {  //yumurtladi ise toplam yumurtaya ekle ve yumurta miktarini dondur
			yumurtlamiyor = 0;
			toplamYumurta += yumurtlamaSayisi;
			return yumurtlamaSayisi;
		}
	}
}

bool Tavuk::kesilsinMi() { //kesilmesi gerekliyse 1 döndürür
	return (yumurtlamiyor == 3 || toplamYumurta >= 100); //3 gundur yumurtlamadıysa veya verdigi toplam yumurta 100 u aşdıysa 1 döndür
}

void Tavuk::resetTavuk() { //tavuk[i] nesnesinin özelliklerini sıfırlar
	kacGunluk = 0;
	yumurtlamiyor = 0;
	toplamYumurta = 0;
}

void Tavuk::yaslandir() { //tavuk un icindeki private haldeki kacGunluk degiskenine direk erisemedigimden kapsülleme yaptım
	kacGunluk++; //tavuk çiftlikte kaldıgı sureyi 1 arttır
}

//function definition

void kullanicidanBaslangicVeriIsteme() { //baslangic verilerini kullanıcıdan istiyorum
	
	do {
		cout << "Baslangic sermayesi: ";
		sermaye = kullanicidanSayiAl(false); cout << endl << endl;
		if (sermaye <= 0) cout << "Baslangic sermayeniz 0 olamaz!" << endl;
	} while (sermaye <= 0); //0 girilirse döngüye gir

	do {
		cout << "Tavuk Sayisi: ";
		tavukSayisi = kullanicidanSayiAl(true); cout << endl << endl;
		if (tavukSayisi > 500) cout << "Tavuk sayisi en fazla 500 olabilir!" << endl;
		if (tavukSayisi <= 0) cout << "Dogru bir simulasyon icin en az 1 tavuk almalisiniz." << endl;
	} while (tavukSayisi > 500 || (tavukSayisi == 0)); //tavuk sayisinin 500 den büyük olmasını önler

	do {
		cout << "Yem Fiyati(kg): ";
		yemKgFiyati = kullanicidanSayiAl(false); cout << endl << endl;
		if (yemKgFiyati <= 0) cout << "Yem kg fiyati 0'dan buyuk olmalidir." << endl;
	} while (yemKgFiyati <= 0);

	do {
		cout << "Yumurta Fiyati: ";
		yumurtaFiyati = kullanicidanSayiAl(false); cout << endl << endl;
		if (yumurtaFiyati <= 0) cout << "Yumurta fiyati 0'dan buyuk olmalidir." << endl;
	} while (yumurtaFiyati <= 0);

	do {
		cout << "tavuk Alim Fiyati: ";
		tavukAlimFiyati = kullanicidanSayiAl(false); cout << endl << endl;
		if (tavukAlimFiyati <= 0) cout << "Tavuk Alim fiyati 0'dan buyuk olmalidir." << endl;
	} while (tavukAlimFiyati <= 0);

	do {
		cout << "Simule edilecek gun sayisi: ";
		gunSayisi = kullanicidanSayiAl(true); cout << endl << endl;
		if (gunSayisi == 0) cout << "Simulasyonun dogru calismasi icin gun sayisini en az 1 girin." << endl; //0 girilirse bu mesaji göster
	} while (gunSayisi == 0); 
}

float kullanicidanSayiAl(bool tamSayiMi) { //kullanıcıdan sayı isterken istenmeyen girişleri kontrol ediyorum. 

	char x; //getch'ye atanacak her bir karakter
	string dizi = ""; //atanan karakterleri uc uca ekleyerek sayi mi degil mi kontrolu yapıyorum
	bool nokta = false; //hic noktaya basilmis mi diye kontrol eder
	do {
		do {

			x = _getch();

			if (tamSayiMi == true) { nokta = true; } //tamsayıysa nokta girişmiş gibi say tekrar nokta girmesine izin verme

			if (nokta == false) { //henüz hic nokta yazmadiysa bunu yap
				if (isdigit(x) || (x == '.')) {
					dizi += x;
					cout << x;
					if (x == '.') nokta = true; //ilk nokta yazdiktan sonra nokta=true yap
				}
			}

			else if (nokta == true) { //en az bir nokta yazildiysa veya tamsayiysa bunu yap
				if (isdigit(x)) {
					dizi += x;
					cout << x;
				}
			}

			if (x == '\b' && dizi != "") { //eğer backspace e basıldıysa ve dizi boş değilse yap
				cout << "\b \b"; //son karakteri ekrandan siler
				if (dizi.back() == '.') nokta = false; //dizinin son karakteri . ise ve silinirse nokta hiç koyulmamış gibi davran
				dizi.pop_back(); //son karakteri diziden siler
			}

		} while ((x != '\r')); //entera basılana kadar karakterler, stringe atanmaya devam edecek

		if (dizi == "") {
			cout << "Bu veri bos birakilamaz!" << endl;
		}



	} while (dizi == ""); //dizi bos ise donguye giricek devam etmesine izin vermeyecek

	return stof(dizi); //string olan diziyi floata cevir

}

int rastgele(int min, int max) { // rastgele(min, max) min ile max arasında rastgele bir sayı oluşturur.
	return rand() % (max - min + 1) + min;
}

void gunlukSifirlama() { //gunluk structını dizi şeklinde yapmadığım için her gün çıktısını alıp resetliyorum
	gunluk.Gelir = 0;
	gunluk.Gider = 0;
	gunluk.kesilenTavuk = 0;
	gunluk.yemTuketimi = 0;
	gunluk.yumurta = 0;
}
