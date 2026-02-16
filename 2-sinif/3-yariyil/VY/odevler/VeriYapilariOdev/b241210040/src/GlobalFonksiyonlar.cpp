/**
* @file GlobalFonksiyonlar.cpp
* @description Daha onceden yazdigim, herhangi bir sinifa bagli olmayan verimlilik saglayan bazi fonksiyonlar
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 17.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/GlobalFonksiyonlar.hpp"

int rastgele(int min, int max) { // rastgele(min, max) min ile max arasında rastgele bir sayı oluşturur.
	return rand() % (max - min + 1) + min;
}