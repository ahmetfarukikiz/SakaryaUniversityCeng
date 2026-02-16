/**
* @file Ucgen.cpp
* @description Sekilden türeyen üçgen yıldız sınıfı ve çizim fonksiyonları
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 17.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/


#include "../include/Ucgen.hpp"


Ucgen::Ucgen(int gen, int yuk, int x, int y, int z, char k) 
    : Sekil((2 * yuk - 1), yuk, x, y, z, k) //genislik oto hesaplaniyor
{
    Cizdir();
}

Ucgen::~Ucgen() {}

void Ucgen::Cizdir() {

    //temizle
    for(int i=0; i<20; i++) {
        for(int j=0; j<20; j++) {
            matris[i][j] = ' ';
        }
    }

    int ortaNokta = genislik / 2;

    //Ucgen ciziliyor
    for(int i=0; i < yukseklik; i++){

        int yildizSayisi = (2 * i) + 1;
        int baslangic = ortaNokta - i;
        
        for(int j=0; j < yildizSayisi; j++){
            matris[i][baslangic + j] = karakter;
        }
    }
}

char Ucgen::GetType()
{
	return 'U';
}