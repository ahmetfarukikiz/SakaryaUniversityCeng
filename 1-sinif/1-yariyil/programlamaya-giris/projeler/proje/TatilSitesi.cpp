#include <iostream>
#include <fstream>
#include "globalFonksiyonlar.h"
#include "TatilSitesi.h"
#include "mekan.h"

//menuler
#include "anaMenu.h"
#include "mekanMenu.h"
#include "kisiMenu.h"
#include "odemeMenu.h"

void TatilSitesi::baslat() {

	int anaMenuSecim;
	while (1) {
		system("cls");


		anaMenu* a = new anaMenu();

		anaMenuSecim = a->calistir();


		if (anaMenuSecim == mekanMenusu) {
			bool geriGit;
			mekanMenu* m = new mekanMenu();
			geriGit = m->calistir();
			if (geriGit == true) delete m; continue;
		}

		else if (anaMenuSecim == odemeMenusu) {
			bool geriGit;
			odemeMenu* o = new odemeMenu();
			geriGit = o->calistir();
			if (geriGit == true) delete o;  continue;

		}

		else if (anaMenuSecim == kisiMenusu) {
			bool geriGit;
			KisiMenu* k = new KisiMenu();
			geriGit = k->calistir();
			if (geriGit == true) delete k; continue;
		}

		else if (anaMenuSecim == cikis) { //programý sonlandýr
			cout << endl << endl << "çýkýþ yapýlýyor.." << endl;

			break;

		}
		delete a;
	}
}