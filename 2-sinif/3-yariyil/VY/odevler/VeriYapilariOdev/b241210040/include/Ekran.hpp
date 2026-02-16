#ifndef EKRAN_HPP
#define EKRAN_HPP

#include <iostream>
#include <string>

using namespace std;

class Sekil;

class AnaListe; // İleri bildirim
class AnaDugum; // İleri bildirim


using namespace std;
class Ekran { //abstract //Canvas, SolMenu, AltMenu ve AnaEkrana miras verir.
	protected:
		
	public:
		int satir;
    	int sutun;
		char** EkranDizisi; //satırlar için ayrı her satırda da sütun için ayrı yer ayrılacağından çift pointer
		Ekran(int satirSayisi, int sutunSayisi);
        virtual ~Ekran();
		void Temizle(char d);
};

#endif
