#ifndef ANAEKRAN_HPP
#define ANAEKRAN_HPP

#include <iostream>
#include <string>
#include "Ekran.hpp"
#include "Canvas.hpp"
#include "Solmenu.hpp"
#include "AltMenu.hpp"
//27 110
class AnaEkran : public Ekran {
	public:
		AnaEkran();
        ~AnaEkran();
		void Entegre(Canvas*, SolMenu*, AltMenu*);
		friend ostream& operator<<(ostream&, AnaEkran*);
};

#endif