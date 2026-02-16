/**
* @file SolMenu.cpp
* @description Düğümlerin ve seçili düğümün gösterildiği ekranın sol bölümünü tutan ve yöneten sınıf
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/SolMenu.hpp"
#include "../include/AnaListe.hpp" //döngüsel bağımlılık hatası çözümü için
#include "../include/AnaDugum.hpp" //döngüsel bağımlılık hatası çözümü için

// 	SOLMENU

SolMenu::SolMenu() : Ekran(25, 15) {
}
SolMenu::~SolMenu() {}

void SolMenu::Guncelle(AnaListe* analiste, AnaDugum* current)
{
    
    Temizle(' ');
    if(current == NULL || analiste == NULL) return;

    int index = analiste->IndexOf(current->item); 
    int dugumKumesi = (int)(index / 6); //her kumede 6 dugum var  //0 1 2 3 diye index mmantigiyla gidiyor
    int baslangicIndex = (dugumKumesi * 6); //0.indexten, 6.indexten (7.dugum) ... mantigiyla gidiyor
    if(!(index == baslangicIndex || index != 0 || index == baslangicIndex + 5)) return; //liste degismemesine ragmen bastan hesaplamasin

    AnaListe::Iterator* itr = new AnaListe::Iterator(analiste->GetIterator());
    for(int i = 0; i < baslangicIndex && itr->hasNext(); i++) {
        itr->next();
    }

    int bas = 0; int son = 3;
    for(; son < satir && itr->getCurrent() != NULL; bas += 4, son += 4) {

  
            for(int i = bas; i < son; i++) {
                for(int j = 0; j < sutun-5; j++) {
                    if(i == bas || i == son-1) EkranDizisi[i][j] = '*';
                    else {
                        if(j == 0 || j == sutun-6) EkranDizisi[i][j] = '*';
                    }
                    if(i == bas + 1) EkranDizisi[i][((sutun-5)/2)-1] = itr->getCurrent()->item->Size() + '0'; //char'a çevirme
                    
                }
                //ATKIF DUGUM CIZILIYORSA
                if(itr->getCurrent() == current) { 
                    EkranDizisi[i][sutun-5]   = '<';
                    EkranDizisi[i][sutun-4]   = '-';
                    EkranDizisi[i][sutun-3]   = '-';
                }
            }
            
       
        if (itr->hasNext()) {
            itr->next();
        } else {
            break; 
        }
    }
    delete itr;
}
