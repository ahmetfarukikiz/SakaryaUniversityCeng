#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Queue.hpp"
#include <fstream>
#include <sstream>
#include "GlobalFonksiyonlar.hpp"


class Program {
private:
	int kuyrukSayisi;
	Queue **kuyruklar;
	int turSayisi;

	int kuyrukSayisiHesapla();
	void tekTur();
	void ciftTur();
	void ekraniCiz(int aktifTur);
	void dosyadanOlustur();

public:
	Program();
	~Program();
	void baslat();

};

#endif