/****************************************************************************
**                                SAKARYA ÜNÝVERSÝTESÝ
**                       BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                           BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                             PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**                       PROJE
**                       ÖÐRENCÝ ADI........:Ahmet Faruk Ýkiz
**                       ÖÐRENCÝ NUMARASI...:B241210040
**                       DERS GRUBU.........:A
****************************************************************************/

#include <iostream>
#include "TatilSitesi.h"

int main(int argc, char** argv) {
		
	setlocale(LC_ALL, "Turkish");	

	TatilSitesi* t = new TatilSitesi();

	t->baslat();
	
	delete t;
	
	return 0;
}