#ifndef ANADUGUM_HPP
#define ANADUGUM_HPP

#include "SekilListe.hpp"
#include <iostream>

using namespace std;

class AnaDugum{
 public:
	SekilListe* item;
	AnaDugum* next;
	AnaDugum* prev;

	AnaDugum(SekilListe*, AnaDugum*, AnaDugum*);
	~AnaDugum(); //eger SekilListeyi pointer yaparsan burda net delete yap.
};

#endif