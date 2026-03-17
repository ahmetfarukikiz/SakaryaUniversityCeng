/**
* @file Yildiz.cpp
* @description Sekilden türeyen yıldız yıldız sınıfı ve çizim fonksiyonları
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 17.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/Yildiz.hpp"

Yildiz::Yildiz(int gen, int yuk, int x, int y, int z, char k) : Sekil(yuk, yuk, x, y, z, k) //yuk ve gen ayni olacak.
{
    Cizdir();
}
Yildiz::~Yildiz() {}

void Yildiz::Cizdir() {
    
    //temizle
     for(int i=0; i<20; i++) {
        for(int j=0; j<20; j++) {
            matris[i][j] = ' ';
        }
    }

	int yariYukseklik = yukseklik / 2;
    int ortaSutun = genislik / 2;

    for (int i = 0; i < yukseklik; i++) {
        int yildizYaricap = 0;

        if (yukseklik % 2 != 0) { //TEK SAYI İÇİN
            // 
            if (i <= yariYukseklik) {
                yildizYaricap = i; // Genişliyor
            } else {
                yildizYaricap = (yukseklik - 1) - i; // Daralıyor
            }
        } 
        else { //ÇİFT SAYI İÇİN
    
            if (i < yariYukseklik) {
                yildizYaricap = i; // Genişliyor
            } else {
                yildizYaricap = (yukseklik - 1) - i; // Daralıyor
            }
        }

        // ÇİZİM
        int baslangic = ortaSutun - yildizYaricap;
        int bitis = ortaSutun + yildizYaricap;

        // Dizi sınır kontrolü
        if(baslangic < 0) baslangic = 0;
        if(bitis >= genislik) bitis = genislik - 1;

        for (int j = baslangic; j <= bitis; j++) {
            matris[i][j] = karakter;
        }
    }
}

char Yildiz::GetType()
{
	return 'Y';
}
