/**
* @file Sekil.cpp
* @description Abstract base Sekil sınıfı ve virtual fonksiyonları, hareket fonksiyonlarını yönetir
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 17.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/Sekil.hpp"

Sekil::Sekil() {
	for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            matris[i][j] = ' ';
        }
    }      
}

Sekil::Sekil(int gen, int yuk, int x, int y, int z, char k) 
{
    this->genislik = gen;
    this->yukseklik = yuk;
    this->x = x;
    this->y = y;
    this->z = z;
    this->karakter = k;

    // matrisi boslukla doldurur
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            matris[i][j] = ' ';
        }
    }
}

Sekil::~Sekil() {}

//GET METOTLARI
int Sekil::GetX() {
	return x;
}
int Sekil::GetY(){
	return y;
}
int Sekil::GetZ(){
	return z;
}
int Sekil::GetGen(){
	return genislik;
}
int Sekil::GetYuk(){
	return yukseklik;
}
int Sekil::GetKar(){
	return karakter;
}
int Sekil::GetMatris(int i, int j){
	return matris[i][j];
}

//HAREKET
void Sekil::Yukari(){
    if(y > 0)  y--;
}

void Sekil::Asagi(int canvasSatirSiniri){
    if(y < canvasSatirSiniri-yukseklik) y++; 
}

void Sekil::Sag(int canvasSutunSiniri){
    if(x < canvasSutunSiniri-genislik) x++;
}

void Sekil::Sol(){
    if(x > 0) x--;
}







