/**
* @file Ekran.cpp
* @description Canvas, SolMenu, AltMenu ve AnaEkran'a miras verir. Bu sınıfların EkranDizilerini oluşturur.
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/Ekran.hpp"
#include "../include/Sekil.hpp" //döngüsel bağımlılık hatası çözümü için
#include <conio.h>
#include "Ekran.hpp"


Ekran::Ekran(int satirSayisi, int sutunSayisi) {
    this->satir = satirSayisi;
    this->sutun = sutunSayisi;

    // satır için yer ayır
    EkranDizisi = new char*[satir];

    // her satırdaki sütünlar için yer ayır
    for(int i = 0; i < satir; i++) {
        EkranDizisi[i] = new char[sutun];
        
		//başlangıçta boş
        for(int j = 0; j < sutun; j++) {
            EkranDizisi[i][j] = ' ';
        }
    }
}
Ekran::~Ekran() {
	if (EkranDizisi != NULL) {
        // her bir satırdaki sütunları serbest bırak
        for(int i = 0; i < satir; i++) {
            delete[] EkranDizisi[i];
        }
        // Sonra satırları serbest bırak
        delete[] EkranDizisi;
    }
}

void Ekran::Temizle(char bosluk) {
    for(int i=0; i<satir; i++) {
        for(int j=0; j<sutun; j++) {
            EkranDizisi[i][j] = bosluk;
        }
    }
}



