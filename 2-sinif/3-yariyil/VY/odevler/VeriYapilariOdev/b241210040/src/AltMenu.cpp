/**
* @file AltMenu.cpp
* @description Hangi menünün aktif olduğunu kontrol eden sınıf, ekranın alt bölümü
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/AltMenu.hpp"

AltMenu::AltMenu() : Ekran(2, 110) {
}

AltMenu::~AltMenu() {}

void AltMenu::Guncelle(char menuTuru)
{

	Temizle(' ');
            
    string menu = "";

    if(menuTuru == 'D') menu = "(ws) hareket (f) listeyi sec (c) sil  (x) cikis  (k) programi kaydet";
    else if(menuTuru == 'S') menu = "(wasd) hareket  (q) onceki sekil  (e) sonraki sekil  (c) sekil sil   (g) listeye don";

	int uzunluk = menu.length();

    for(int j = 0; j < sutun && j < uzunluk; j++){
			EkranDizisi[1][j] = menu[j];
		}
}