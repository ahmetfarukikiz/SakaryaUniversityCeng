/**
* @file main.cpp
* @description program classından nesne oluşturup baslat metodunu çağırır
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 3.12.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "Program.hpp"

using namespace std;

int main(){
	
	Program *p = new Program();

	try {
        p->baslat();
    }
    catch (const char* hata) {
        cout << "Programda bir hata meydana geldi: " << hata << endl;
    }

	delete p;

	return 0;
}