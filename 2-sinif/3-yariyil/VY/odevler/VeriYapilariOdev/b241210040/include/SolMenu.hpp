#ifndef SOLMENU_HPP
#define SOLMENU_HPP

#include "Ekran.hpp"

class SolMenu : public Ekran {
	public:
		SolMenu();
        ~SolMenu(); 

		void Guncelle(AnaListe*, AnaDugum*);
};

#endif