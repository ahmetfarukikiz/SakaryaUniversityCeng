/****************************************************************************
**					   	SAKARYA ÜNÝVERSÝTESÝ
**			   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**					ÖDEV NUMARASI…...:1
**					ÖÐRENCÝ ADI......:Ahmet Faruk ikiz
**					ÖÐRENCÝ NUMARASI.:B241210040
**					DERS GRUBU.......:A
****************************************************************************/


#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cstring>
#include <conio.h>

using namespace std;

string artisPeriyodu; //kullanicidan alinan bilgiye gore alisfiyatinin kac ayda bir artmasi gerektigini soyleyecek
int artisOrani;

string aytarihi[12] = { "ocak", "subat", "mart", "nisan", "mayis", "haziran", "temmuz", "agustos", "eylul", "ekim", "kasim", "aralik" };

int tabloay;

float f = 0.0F;

char ayirici = ',';           //stringKelime olduðunu anlamasý için kelimeler arasý bir iþaret
int i = 0;                    //firmaUrun stringindeki her bir char(karakter) indisi
int StringKelimeNumarasi = 1; // firmaUrun stringi içerisinden adi(1) alisFiyati(2), stokMiktari(3) ve kdvOrani(4) 3'lüsünün 1 2 3 4 1 2 3 4 þeklinde ayrýþtýrýlmasýný saðlayan deðiþken
int ay = 0;                   //ay sayisi (urun structýnýn urunler deðiþken dizisinin birinci indisi)
int un = 0;                   //urun numarasi (urun structýnýn urunler deðiþken dizisinin ikinci indisi) 1 2 3 4(0) 1 2 3 4(1) dongusunun her bitisini ifade eder mesela mouse 0.urun
string stringKelime;          //firmaUrun stringi içinde , ler arasý her bir kelime

struct Urun {
    string adi;
    float alisFiyati; //firmanin alis fiyati
    int stokMiktari;  //ay basi urunden kac tane oldugu.
    int kdvOrani;
    float satisFiyati; //alisFiyati+kar+kdvMiktari
    int satisMiktari;
    float kdvMiktari;   //alisFiyati*kdvOrani
    float aylikKar;
    int kalanStok; //onceki aydan kalan stok

};

struct giderler {
    float personel;
    float elektrik;
    float kira;
    float su;
    float diger;
    float aylikToplamKdvMiktari;
    float aylikToplamAlisFiyati;
    float aylikToplamGider;
};


float aylikToplamCiro[12]; //aylik tum urunlerin toplam satis fiyati
float aylikToplamKar[12]; //aylik tum urunlerin toplam karý
float yilsonuKar; //yýlsonu
float yilsonuGider; //yýlsonu
int yilsonuSatisMiktari[20]; //her bir urun icin yil sonu satis miktari





giderler gider[12] = {}; //indis[12] ay sayisini temsil ediyor.
Urun urunler[12][20] = {}; //ilk indis[12] ay sayisini; ikinci indis[20] ürün sayisini temsil eder örnek: [0][0] 1.ayýn 1.ürünü manasýna gelir 

string firmaUrun; //firmadaki urun alis fiyati ve stok miktarlarini belirten bir veri


//fonksiyon deklarasyonlari
void StringKelimeKontrolveAtama();
void uruntablosu(int); //tablonun anahatlarini yazdirmak için kullanacaðým fonksiyonun deklarasyonu (i: ay sayisi)
int rastgele(int min, int max); //min ile max arasýnda rasgele bir sayý döndürür
void firmaUrunStringKelimeCekici();
void kullanicidanArtisOraniIsteme();
void alisFiyatiAktarma();
float aylikToplamGiderHesaplayici();
float aylikToplamKarHesaplayici();
void firmaUrunStringSonrasiÝslemler();
string yenifirmaUrunOlusturucu();
void yilsonuIstatistikYazdirici();
string yillikEnAzSatilanHesaplayici();
string yillikEnCokSatilanHesaplayici();
string aylikEnAzSatilanHesaplayici();
string aylikEnCokSatilanHesaplayici();
string aylikEnAzKarEdenHesaplayici();
string aylikEnCokKarEdenHesaplayici();


int main() {

    srand(time(0));
    cout.precision(2); //float double ',' den sonra 2 basamak alsýn 
    cout << fixed;

    kullanicidanArtisOraniIsteme();



    for (ay = 0; ay < 12; ay++) {
        if (ay == 0) { //ay== 0 için ilk firmaurunu kullan
            firmaUrun = "mouse,700.00,70,20,bilgisayar,30500.00,75,20,kulaklik,2550.00,120.00,20,buzdolabi,30700.00,50,20,supurge,5000.00,60,20,utu,3500.00,110,20,bulasik makinesi,16000.00,75,20,camasir makinesi,18000.00,75,20,blender,1200.00,80,20,kettle,1000.00,80,20,telefon,27000.00,60,20,power bank,1200.00,70,20,tablet,6000.00,100,20,televizyon,35000.00,50,20,akilli saat,4300.00,85,20,monitor,3500.00,60,20,yazici,3100.00,70,20,termos,1300.00,80,20,klavye,1400.00,95,20,derin dondurucu,19300,50,20,";
        }
        else if (ay != 0) { //diðer aylar için yeni oluþturacaðýn firmaurun stringi kullan
            firmaUrun = yenifirmaUrunOlusturucu();
        }
        cout << ay + 1 << ".ayin firmaurun stringi: " << firmaUrun << endl << endl;

        firmaUrunStringKelimeCekici();
        firmaUrunStringSonrasiÝslemler();

        gider[ay].aylikToplamGider = aylikToplamGiderHesaplayici();
        aylikToplamKar[ay] = aylikToplamKarHesaplayici();



        uruntablosu(ay);



        firmaUrun.clear();

    }

    yilsonuIstatistikYazdirici();





    cout << endl << endl << endl;
    return 0;
}

//altfonksiyon
void StringKelimeKontrolveAtama() { //firmaUrun stringinden deðer atama yaparken hangi deðiþkene atayacaðýmý kontrol ettiðim fonksiyon.
    if (StringKelimeNumarasi == 1) {
        urunler[ay][un].adi = stringKelime;
        StringKelimeNumarasi++;
    }

    else if (StringKelimeNumarasi == 2) {

        urunler[ay][un].alisFiyati = stof(stringKelime);
        StringKelimeNumarasi++;
    }

    else if (StringKelimeNumarasi == 3) {
        urunler[ay][un].stokMiktari = stoi(stringKelime);
        StringKelimeNumarasi++;
    }

    else {
        urunler[ay][un].kdvOrani = stoi(stringKelime);
        un++;
        StringKelimeNumarasi = 1;
    }

}

//asilfonksiyon
void firmaUrunStringKelimeCekici() { //firmaurunden aldigi kelimeleri teker teker ayristirir ve stringKelime stringine atama yapar, her kelime sonunda stringKelime yi sýfýrlar.


    while (i != firmaUrun.length()) { //karakter numarasi, dizi numarasina esit olana dek dönsün.

        if (firmaUrun[i] != ayirici) { // , gelmediði sürece oluþturduðumuz geçiçi StringKelime stringine Firmaurun stringinden harf ekler.
            stringKelime += firmaUrun[i];
        }
        else {

            StringKelimeKontrolveAtama(); //kelimeyi kontrol eder ve ait olduðu indisteki ait olduðu struct deðiþkenine atama yapar. 
            stringKelime.clear(); //yeni kelime için stringi temizler
        }
        i++;
    };

}



void uruntablosu(int i) {

    cout << left << "Ay: " << setw(8) << aytarihi[i]; if (artisPeriyodu != "sabit") { cout << "alis fiyati " << artisPeriyodu << " %" << artisOrani << " artsin"; } //i dediðim þey sol üstte yazan ayýn deðiþmesini saðlayacak argümanýn atanacaðý deðiþken
    cout << endl << endl;

    cout << right << setw(30) << "Alis Fiyati" << setw(20) << "Satis fiyati" << setw(20) << "stok miktari"
        << setw(20) << "Satis miktari" << setw(10) << "Kar" << endl << endl;
    for (un = 0; un < 20; un++) { //bütün ürünler verilen aya göre tablo halinde yazdýrýlýyor
        cout << left << setw(18) << urunler[ay][un].adi << right << urunler[ay][un].alisFiyati << setw(20) << urunler[ay][un].satisFiyati << right << setw(20) << urunler[ay][un].stokMiktari << setw(20) << urunler[ay][un].satisMiktari << setw(20) << urunler[ay][un].aylikKar << endl;
    }



    cout << endl << endl;

    cout << aytarihi[i] << " ayi en cok kar edilen : " << aylikEnCokKarEdenHesaplayici() << endl;
    cout << aytarihi[i] << " ayi en az kar edilen : " << aylikEnAzKarEdenHesaplayici() << endl;
    cout << aytarihi[i] << " ayi en cok satilan : " << aylikEnAzSatilanHesaplayici() << endl;
    cout << aytarihi[i] << " ayi en az satilan : " << aylikEnCokSatilanHesaplayici() << endl;
    cout << aytarihi[i] << " ayi toplam ciro : " << aylikToplamCiro[ay] << endl;
    cout << aytarihi[i] << " ayi toplam gider : " << gider[ay].aylikToplamGider << endl;
    cout << aytarihi[i] << " ayi toplam kar : " << aylikToplamKar[ay] << endl << endl;

    for (int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << endl << endl;
};

int rastgele(int min, int max) { // rastgele(min, max) min ile max arasýnda rastgele bir sayý oluþturur.
    return rand() % (max - min + 1) + min;

}



void kullanicidanArtisOraniIsteme() {
    bool basadon;
    do {
        int i;
        basadon = 0;
        cout << " alisfiyati kac ayda bir artsin?" << endl << endl;
        cout << left << setw(20) << "(a)ayda bir" << right << setw(20)
            << "iki ayda bir(b)" << left << setw(20) << endl
            << "(c)uc ayda bir" << right << setw(20)
            << "dort ayda bir(d)" << endl << "(e)sabit kalsin";

        i = _getch();

        if (i == 'a') artisPeriyodu = "aydabir";
        else if (i == 'b') artisPeriyodu = "ikiaydabir";
        else if (i == 'c') artisPeriyodu = "ucaydabir";
        else if (i == 'd') artisPeriyodu = "dortaydabir";
        else if (i == 'e') artisPeriyodu = "sabit";
        else {
            basadon = 1;    
            system("cls");
            cout << "lutfen dogru bir karakter tuslayiniz" << endl << endl;
        }

    } while (basadon == 1);

    system("cls");

    if (artisPeriyodu != "sabit") {

        char karakter;
        char karakter_dizisi[10];
        bool hatali_giris = 1;//hatali girisi engellemeye calistim fakat basaramadim suanlik bu degisken bi ise yaramiyor
        int sira_no = 0;
        while (1) {
            if (hatali_giris == 1) cout << " \n\nBir artis orani giriniz (yuzde cinsinden)" << endl << endl; 
            hatali_giris = 0;
            karakter = _getch();

            if (isdigit(karakter)) {   //sayi mi diye bakiyorum sayiysa diziye ekleyip ekrana yazdiriyorum
                cout << karakter;
                karakter_dizisi[sira_no++] = karakter;
            }

            else if (karakter == '\r') { //entera basinca diziye sayi eklemeyi bitir
                break;
            }
        }
        artisOrani = atoi(karakter_dizisi); //char dizisini tam sayiya çevir

        system("cls");
    }
}

void alisFiyatiAktarma() { //alýþfiyati fonksiyonu //her ayýn sonuna koy 

    if (ay != 11) {
        if (artisPeriyodu == "aydabir") {
            urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati + urunler[ay][un].alisFiyati * (float)artisOrani / (float)100; //ayda bir ise oran kadar aydabir arttýr
        }

        else if (artisPeriyodu == "ikiaydabir") {
            if (ay % 2 == 0) { //1. ay yapmak üzere +2 sonraki aylar için alis fiyatini arttir
                urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati + urunler[ay][un].alisFiyati * (float)artisOrani / (float)100;
            }
            else urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati;
        }

        else if (artisPeriyodu == "ucaydabir") {
            if (ay % 3 == 0) { //1. ay yapmak üzere +3 sonraki aylar için alis fiyatini arttir
                urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati + urunler[ay][un].alisFiyati * (float)artisOrani / (float)100;
            }
            else urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati;
        }
        else if (artisPeriyodu == "dortaydabir") {
            if (ay % 4 == 0) { //1. ay yapmak üzere +4 sonraki aylar için alis fiyatini arttir
                urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati + urunler[ay][un].alisFiyati * (float)artisOrani / (float)100;
            }
            else urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati;
        }

        else { urunler[ay + 1][un].alisFiyati = urunler[ay][un].alisFiyati; }
    }
}

void firmaUrunStringSonrasiIslemler() { //firmaurunden en gerekli verileri çektikten sonra bu veriler üzerinden diðer verilerin hesaplanmasýný saðlayan fonksiyon

    for (un = 0; un < 20; un++) {

        //þuanki ay için
        urunler[ay][un].kdvMiktari = urunler[ay][un].alisFiyati * (urunler[ay][un].kdvOrani / (float)(100)); // her ürün için ayrý ayrý kdv miktari (alis fiyatina eklenecek vergi) hesapladim
        urunler[ay][un].satisFiyati = urunler[ay][un].alisFiyati + (urunler[ay][un].alisFiyati * (float)(rastgele(30, 50) / (float)100)) + urunler[ay][un].kdvMiktari; //odev dosyasinda verilen kurala göre kar payi ve kdv ekleyerek satis fiyatini buluyorum
        urunler[ay][un].satisMiktari = (int)((float)urunler[ay][un].stokMiktari * (float)rastgele(60, 80) / (float)100); //önce her þeyi floata çevirip hesaplayýp sonra en yakýn basamaða yuvarladým //satismiktari

        if (ay == 0) {
            urunler[ay][un].aylikKar = (urunler[ay][un].satisFiyati * urunler[ay][un].satisMiktari) - (urunler[ay][un].stokMiktari * urunler[ay][un].alisFiyati) - urunler[ay][un].kdvMiktari; //kar= satýþ*satýþmiktar) - (stok*alýþ) - kdvmiktarý
        }
        else if (ay != 0) {
            urunler[ay][un].kalanStok = urunler[ay - 1][un].stokMiktari - urunler[ay - 1][un].satisMiktari;
            urunler[ay][un].aylikKar = (urunler[ay][un].satisFiyati * urunler[ay][un].satisMiktari) - ((urunler[ay][un].stokMiktari - urunler[ay][un].kalanStok) * urunler[ay][un].alisFiyati) - urunler[ay][un].kdvMiktari; //(satýþf * satýþmik) - ((stokmik - kalanstok) * alýþfiyatý) - kdvmiktarý //not:kalanstok onceki aydan kalaný ifade eder.
        }

        if (ay != 11) {
            //sonraki ay için
            urunler[ay + 1][un].stokMiktari = (2 * (urunler[ay][un].stokMiktari - urunler[ay][un].satisMiktari)) + ((int)((float)urunler[ay][un].satisMiktari * (float)rastgele(70, 100) / (float)100));
            alisFiyatiAktarma();
            urunler[ay + 1][un].kdvOrani = urunler[ay][un].kdvOrani;
            urunler[ay + 1][un].adi = urunler[ay][un].adi;
        }
    }
}


float aylikToplamGiderHesaplayici() { //toplamGidere eþitleyerek kullanýcam

    gider[ay].aylikToplamKdvMiktari = 0;
    for (un = 0; un < 20; un++) { //o ay için tum urunlerin kdv miktarlarini topla
        gider[ay].aylikToplamKdvMiktari += urunler[ay][un].kdvMiktari;
    }

    gider[ay].aylikToplamAlisFiyati = 0;
    for (un = 0; un < 20; un++) { //eðer 0.ay ise (stok miktari*alis fiyatlarini) topla farklý bir ayda isen yeni alinan urunler ile alis fiyatini çarp ve onlarý topla
        if (ay == 0) gider[ay].aylikToplamAlisFiyati = gider[ay].aylikToplamAlisFiyati + (urunler[ay][un].alisFiyati * urunler[ay][un].stokMiktari);
        else if (ay != 0) gider[ay].aylikToplamAlisFiyati = gider[ay].aylikToplamAlisFiyati + ((urunler[ay][un].stokMiktari - urunler[ay][un].kalanStok) * urunler[ay][un].alisFiyati);
    }


    //giderler hesaplanýyor
    gider[ay].elektrik = (float)rastgele(9000, 12000); 
    gider[ay].kira = (float)33090;
    gider[ay].personel = (float)90000;
    gider[ay].su = (float)rastgele(3000, 7000);
    gider[ay].diger = (float)rastgele(2000, 4000);
    return gider[ay].elektrik + gider[ay].kira + gider[ay].personel + gider[ay].su + gider[ay].diger + gider[ay].aylikToplamKdvMiktari + gider[ay].aylikToplamAlisFiyati; //kdvmiktari da bir gider sonucta ciro hesaplarken onu da katmýþtým
}

float aylikToplamKarHesaplayici() { // kullanirken aylikToplamKar = diye yazilmali
    aylikToplamCiro[ay] = 0;
    for (un = 0; un < 20; un++) {
        aylikToplamCiro[ay] += urunler[ay][un].satisFiyati * urunler[ay][un].satisMiktari;
    }
    return aylikToplamCiro[ay] - gider[ay].aylikToplamGider;

}

string yenifirmaUrunOlusturucu() { //firmaUrun = diye kullanilmali


    string s = "";

    for (un = 0; un < 20; un++) {
        if (un == 0) {
            cout.precision(2); //float double ',' den sonra 2 basamak alsýn 
            cout << fixed;
            s = urunler[ay][un].adi + ',' + to_string(urunler[ay][un].alisFiyati) + ',' + to_string(urunler[ay][un].stokMiktari) + ',' + to_string(urunler[ay][un].kdvOrani);
        }

        else s += ',' + urunler[ay][un].adi + ',' + to_string(urunler[ay][un].alisFiyati) + ',' + to_string(urunler[ay][un].stokMiktari) + ',' + to_string(urunler[ay][un].kdvOrani);

    }

    return s;
}

void yilsonuIstatistikYazdirici() {

    for (ay = 0; ay < 12; ay++) {   //tum aylýk toplam karlarý toplayýp yýlsonu toplam karý buldum
        yilsonuKar += aylikToplamKar[ay];
    }


    cout << endl << right << setw(70) << "YIL SONU ISTATISTIKLER:";

    cout << endl << endl << "YIL SONU TOPLAM KAR: " << yilsonuKar;

    cout << endl << endl;
    for (int i = 0; i < 120; i++) { //satýr çizgisi için 
        cout << '-';
    }
    cout << endl;
    cout << "YIL SONU TOPLAM SATIS MIKTARLARI:" << endl;


    cout << endl;


    cout << "EN AZ SATILAN URUN: " << yillikEnAzSatilanHesaplayici() << endl;
    cout << "EN COK SATILAN URUN: " << yillikEnCokSatilanHesaplayici();

    cout << endl;
    for (int i = 0; i < 120; i++) { //satýr çizgisi için
        cout << '-';
    }

}

string yillikEnAzSatilanHesaplayici() { // en az satilan en cok satilan urunu hesaplar

    for (un = 0; un < 20; un++) {

        for (ay = 0; ay < 12; ay++) {    //tum urunlerin satýs miktarlarýný topla
            yilsonuSatisMiktari[un] += urunler[ay][un].satisMiktari;
        }
    } 
    int a = 0;  //min deðeri bul ve o deðere sahip olan urunun ismini bul
    int min = yilsonuSatisMiktari[0];
    for (un = 0; un < 20; un++) {

        if (yilsonuSatisMiktari[un] < min) {
            min = yilsonuSatisMiktari[un];
            a = un;
        }
    }

    for (un = 0; un < 20; un++) {
        cout << urunler[1][un].adi << ": " << yilsonuSatisMiktari[un] << endl;
    }

    cout << endl;


    return urunler[1][a].adi;

}

string yillikEnCokSatilanHesaplayici() {

    int a = 0;
    int max = yilsonuSatisMiktari[0];
    for (un = 0; un < 20; un++) {

        if (yilsonuSatisMiktari[un] > max) {
            max = yilsonuSatisMiktari[un];
            a = un;
        }
    }
    return urunler[1][a].adi;
}

string aylikEnAzSatilanHesaplayici() {
    int a = 0;
    int min = urunler[ay][0].satisMiktari;
    for (un = 0; un < 20; un++) {

        if (urunler[ay][un].satisMiktari < min) {
            min = urunler[ay][un].satisMiktari;
            a = un;
        }
    }
    return urunler[1][a].adi;

}

string aylikEnCokSatilanHesaplayici() {
    int a = 0;
    int max = urunler[ay][0].satisMiktari;
    for (un = 0; un < 20; un++) {

        if (urunler[ay][un].satisMiktari > max) {
            max = urunler[ay][un].satisMiktari;
            a = un;
        }
    }
    return urunler[1][a].adi;

}

string aylikEnAzKarEdenHesaplayici() {
    int a = 0;//deðeri min yapan un deðerini hafýzada geçiçi olarak tutabilmek için oluþturduðum geçici deðiþken
    float min = urunler[ay][0].aylikKar;
    for (un = 0; un < 20; un++) {

        if (urunler[ay][un].aylikKar < min) {
            min = urunler[ay][un].aylikKar;
            a = un;
        }
    }
    return urunler[1][a].adi;

}

string aylikEnCokKarEdenHesaplayici() {
    int a = 0; //deðeri max yapan un deðerini hafýzada geçiçi olarak tutabilmek için oluþturduðum geçici deðiþken
    float max = urunler[ay][0].aylikKar;
    for (un = 0; un < 20; un++) {

        if (urunler[ay][un].aylikKar > max) {
            max = urunler[ay][un].aylikKar;
            a = un;
        }
    }
    return urunler[1][a].adi;

}
