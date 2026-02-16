/**
* @file Dikdortgen.cpp
* @description Sekilden türeyen üçgen dikdörtgen sınıfı ve çizim fonksiyonları
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 17.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/Dikdortgen.hpp"

Dikdortgen::Dikdortgen(int gen, int yuk, int x, int y, int z, char k) : Sekil(gen, yuk, x, y, z, k)
{
    Cizdir();
}
Dikdortgen::~Dikdortgen() {}

void Dikdortgen::Cizdir() {
    for(int i=0; i < yukseklik; i++){
        for(int j=0; j < genislik; j++){
            matris[i][j] = karakter; 
        }
    }
}

char Dikdortgen::GetType()
{
	return 'D';
}