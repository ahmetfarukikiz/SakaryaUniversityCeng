/**
* @file AnaEkran.cpp
* @description Diğer ekranları birleştirip ekrana basılmaya hazır hale getiren sınıf ve fonksiyonları
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 20.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/AnaEkran.hpp"

AnaEkran::AnaEkran() : Ekran(27, 110) {
}
AnaEkran::~AnaEkran() {}

void AnaEkran::Entegre(Canvas *canvas, SolMenu *solmenu, AltMenu *altmenu)
{
    // SOL MENU ENTEGRASYONU
    if (solmenu != NULL) {
        for (int i = 0; i < solmenu->satir && i < this->satir; i++) {
            for (int j = 0; j < solmenu->sutun && j < this->sutun; j++) {
                this->EkranDizisi[i][j] = solmenu->EkranDizisi[i][j];
            }
        }
    }

    // CANVAS ENTEGRASYONU
    if (canvas != NULL) {
        int baslangicSutunu = 15; 
        for (int i = 0; i < canvas->satir && i < this->satir; i++) {
            for (int j = 0; j < canvas->sutun; j++) {
                if (baslangicSutunu + j < this->sutun) {
                    this->EkranDizisi[i][baslangicSutunu + j] = canvas->EkranDizisi[i][j];
                }
            }
        }
    }

    //	ALTMENU ENTEGRASYONU
    if (altmenu != NULL) {
		for (int i = 0; i < altmenu->satir; i++) {
			for (int j = 0; j < altmenu->sutun && j < this->sutun; j++) {
				//EN ALTA YERLESTIRIR
				this->EkranDizisi[this->satir-altmenu->satir + i][j] = altmenu->EkranDizisi[i][j];
			}
    	}
    }
}

ostream &operator<<(ostream & screen, AnaEkran* right)
{

    if (right == NULL)  return screen;

    //Her karakteri coutla ekrana bastırma mantığı verimsiz çalıştığı için artık stringe alıyorum

	string EkranaBasilacakString = "";
    
    // String için kullanılacak yeri önceden ayır
    // (Satır * (Sütun + 1)) kadar yer lazım (+1 \n için)
    EkranaBasilacakString.reserve(right->satir * (right->sutun + 1));

    for(int i = 0; i < right->satir; i++){
        for(int j = 0; j < right->sutun; j++){
            EkranaBasilacakString += right->EkranDizisi[i][j];
        }
        EkranaBasilacakString += '\n';
    }
    screen << EkranaBasilacakString;  //her seferinde cout çağırmak yerine stringe alıp bir kez cout çağırmak yeterli
    return screen;
}