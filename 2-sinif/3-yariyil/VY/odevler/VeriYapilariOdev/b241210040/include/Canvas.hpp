#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "Ekran.hpp"
class SekilListe; //ileri bildirim

class Canvas : public Ekran {
	public:
		Canvas();  
        ~Canvas();
		void Guncelle(SekilListe* sekilListe);
};

#endif