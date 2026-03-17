/**
* @file Main.cpp
* @description CizimProgrami nesnesi olusturur ve baslat() methodunu cagirir.
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/CizimProgrami.hpp"
#include <ctime> 
using namespace std;


int main(int argc, char** argv) {
	
	srand(time(NULL));

	setlocale(LC_ALL, "Turkish");	

	CizimProgrami* c = new CizimProgrami();

	try {
        c->baslat();
    }
    catch (const char* hata) {
        cout << "Programda bir hata meydana geldi: " << hata << endl;
    }

	delete c;
	
	return 0;
}