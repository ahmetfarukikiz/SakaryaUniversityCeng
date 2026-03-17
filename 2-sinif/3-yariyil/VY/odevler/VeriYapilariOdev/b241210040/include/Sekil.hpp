#ifndef SEKIL_HPP
#define SEKIL_HPP

#include <iostream>
#include "Ekran.hpp"
#include "Canvas.hpp"

using namespace std;

class Sekil{
    protected: 
	    char matris[20][20]; //sekil icin yeterli bir alan 
		int x, y;       
        int genislik;   
        int yukseklik;  
        int z;          
        char karakter; 
    public:
        //hareket
        void Yukari();
        void Asagi(int); //sınırları alırlar
        void Sag(int); //sınırları alırlar
        void Sol();

        //get methodları
		int GetX();
		int GetY();
        int GetZ();
        int GetGen();
        int GetYuk();
        int GetKar();
        int GetMatris(int, int);

        Sekil();
        Sekil(int gen, int yuk, int x, int y, int z, char k);
        virtual ~Sekil() = 0;
        
        // sekli kendi ic matrisine cizen fonksiyon
        virtual void Cizdir() = 0; 
        //Şeklin tipini döndürür (üçgen, dikdörtgen vb)
        virtual char GetType() = 0;
        
};


#endif