#ifndef SEKILDUGUM_HPP
#define SEKILDUGUM_HPP

#include "Sekil.hpp"
#include "Ucgen.hpp"
#include "Yildiz.hpp"
#include "Dikdortgen.hpp"
#include <iostream>

using namespace std;

class SekilDugum{ 
 public:
	Sekil* item;
	SekilDugum* next;

	SekilDugum(Sekil*, SekilDugum*);
	~SekilDugum();
};

#endif
