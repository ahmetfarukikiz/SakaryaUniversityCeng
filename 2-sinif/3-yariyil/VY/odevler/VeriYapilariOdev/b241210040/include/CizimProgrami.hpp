#ifndef CIZIMPROGRAMI_HPP
#define CIZIMPROGRAMI_HPP

#include "AnaListe.hpp"
#include "Ekran.hpp"
#include "AnaEkran.hpp"
#include "GlobalFonksiyonlar.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>


using namespace std;

class CizimProgrami {
			
	private:
		AnaListe* _analiste;

		AnaEkran* _anaekran;
		SolMenu* _solmenu;
		AltMenu* _altmenu;
		Canvas* _canvas;
		char aktifMenu;
		AnaListe::Iterator* _anaListItr;
		SekilListe::Iterator* _sekilListItr;
		bool degisiklik;

		AnaDugum* aktifDugum;
		int AnaDugumSayisi;

		
		void dosyayaYaz();
		bool dosyadanOku();
		bool rastgeleOlustur();
		void _SekilListItrGuncelle();
		void BaslangicSorusu();
		void AnaDugumSil();
		void SekilDugumSil(SekilListe* suankiSklList);

		void AnaEkraniCiz();
		bool DugumMenu();
		void SekilMenu();
		
		
	public:
	
		CizimProgrami();
		~CizimProgrami();
		void baslat();
		
};


#endif

