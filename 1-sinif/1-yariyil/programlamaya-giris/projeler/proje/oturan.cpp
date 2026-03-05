#include "oturan.h"

bool AileReisi::getaidatOdendi()
{
    return aidatOdendi;
}

string AileReisi::getad()
{
    return ad;
}

string AileReisi::getsoyad()
{
    return soyad;
}

int AileReisi::getyas(){
    return yas;
}

int AileReisi::getkaldigiDaireNo(){
   return kaldigiDaire->getmekanNo();
}

void AileReisi::kaldigiDaireyiGuncelle(Daire* yeniDaire) {
    if (yeniDaire == nullptr) {
        cerr << "hata var nullptr";
    }
    
    else  kaldigiDaire = yeniDaire;
}

string Misafir::getad()
{
    return ad;
}

string Misafir::getsoyad()
{
    return soyad;
}

int Misafir::getyas(){
    return yas;
}

int Misafir::getkaldigiDaireNo(){
    return kaldigiDaire->getmekanNo();
}
