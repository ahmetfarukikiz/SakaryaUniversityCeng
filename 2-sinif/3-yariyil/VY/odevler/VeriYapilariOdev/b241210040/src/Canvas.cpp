/**
* @file Canvas.cpp
* @description Çizilen şekilleri birleştiren, ekranın şekil çizilen bölümünü tutan sınıf
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/Canvas.hpp"
#include "../include/SekilListe.hpp" //döngüsel bağımlılık hatası çözümü için

#

Canvas::Canvas() : Ekran(25, 95) {}
Canvas::~Canvas() {}

void Canvas::Guncelle(SekilListe *sekilListe)
{
    Temizle(' ');
    if(sekilListe == NULL) return;

    int uzunluk = sekilListe->Size();
    if (uzunluk == 0) return;
    
    Sekil** ZSiralamasi = new Sekil*[uzunluk];

    SekilDugum* itr = sekilListe->GetHead();
    //SekilListesindeki tüm düğümleri geçici diziye kopyala
    for(int i = 0; itr!=NULL; i++, itr= itr->next){
        ZSiralamasi[i] = itr->item;
    }

    //Bubble Sort algoritması ile Z değerine göre sıralıyorum
    for(int i=0; i < uzunluk-1; i++){
        for(int j=0; j < uzunluk-i-1; j++){
            //Z değeri bir sonrakinden büyükse kücük olanı (sonrakini) öne al.
            if(ZSiralamasi[j]->GetZ() > ZSiralamasi[j+1]->GetZ()){
                Sekil* tmp = ZSiralamasi[j];
                ZSiralamasi[j] = ZSiralamasi[j+1];
                ZSiralamasi[j+1] = tmp;
            }
        }
    }

    for(int k=0; k < uzunluk; k++) {
        Sekil* s = ZSiralamasi[k];
        
        // Şeklin kendi içindeki matrisi, canvasın ekran matrisine kopyalar
        for(int i=0; i < s->GetYuk(); i++) {
            for(int j=0; j < s->GetGen(); j++) {
                
                int hedefY = s->GetY() + i;
                int hedefX = s->GetX() + j;


                if (hedefY >= 0 && hedefY < satir && 
                    hedefX >= 0 && hedefX < sutun) 
                {
                    char c = s->GetMatris(i, j);
                    if (c != ' ') {  // Bosluk karakteriyse kopyalama
                        EkranDizisi[hedefY][hedefX] = c;
                    }
                }
            }
        }
    }

    delete[] ZSiralamasi; // Temizlik
}