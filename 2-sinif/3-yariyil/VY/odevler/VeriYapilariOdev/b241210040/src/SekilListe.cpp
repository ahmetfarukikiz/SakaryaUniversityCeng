/**
* @file SekilListe.cpp
* @description Tek yonlu bagli liste. Icinde ekrana cizdirilecek Sekil sinifindan nesneler tutar
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 17.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/SekilListe.hpp"
#include "SekilListe.hpp"

SekilDugum *SekilListe::FindPrevByPosition(int position)
{
	if(position < 0 || position > length) throw "Index out of range";
	int index = 1;

	for(SekilDugum* itr = head; itr!=NULL; itr= itr->next , index++){ 
		if(position == index) return itr;  
	}						

	return NULL;
}

SekilListe::SekilListe()
{
	length = 0;
	head = NULL;
}


SekilListe::~SekilListe()
{
    Clear();
}

SekilDugum *SekilListe::GetHead()
{
	return head;
}

void SekilListe::Add(Sekil* eleman)
{
    Insert(length, eleman);
}

void SekilListe::Insert(int index, Sekil * eleman)
{
	if(index == 0) head = new SekilDugum(eleman,head); //başa eklemek isterse
			else{
				SekilDugum* prev = FindPrevByPosition(index);
				prev->next = new SekilDugum(eleman,prev->next);
			}
			length++;
}



//2'den 7'ye kadar sayi gelicek ve o kadar sekil olusturacak
void SekilListe::RastgeleSekilOlustur(int sekilSayisi, int canvasSatir, int canvasSutun){ 

	for(int i = 0; i < sekilSayisi; i++){
		int olusacakSekil = rastgele(1,3);
		Sekil* yeniSekil;
		
		int w = rastgele(3, 7);  // Genişlik 
        int h = rastgele(3, 7);  // Yükseklik

        int x;
		if(olusacakSekil == 1) x = rastgele(0, canvasSutun-(2*h-1)); //ucgen icin ekstra genislik ayrilir cunku w = 2*h-1
		else if (olusacakSekil == 3) x = rastgele(0, canvasSutun-h); // yildiz için w = h
		else {		  		   x = rastgele(0, canvasSutun-w);	  }	//max x degerinden genisligi kadar uzak olmali

        int y = rastgele(0, canvasSatir-h); //max y degerinden yuksekligi kadar uzak olmalı
        int z = rastgele(0, 100);  // Çizim sırası //özellikle büyük aralık ki çakışma ihtimali azalsın
		char charElemanlari[] = {'#','o','@','*','+'};
        char c = charElemanlari[(rastgele(0, sizeof(charElemanlari) - 1))];

		switch (olusacakSekil) //sekil turunu rastgele belirliyor
		{
			case 1: yeniSekil = new Ucgen(w, h, x, y, z, c); break;
			case 2: yeniSekil = new Dikdortgen(w, h, x, y, z, c); break;  
			case 3: yeniSekil = new Yildiz(w, h, x, y, z, c); break;
		}
		
		this->Add(yeniSekil);
	}
}

void SekilListe::DosyadanSekilOlustur(ifstream& dosya, int sekilSayisi)
{
	int w, h, x, y, z, intc;
	char tur, c;
	Sekil* yeniSekil;

	for(int i = 0; i < sekilSayisi; i++) {
		dosya >> tur >> w >> h >> x >> y >> z >> intc;

		c= (char)intc; //direkt char olarak okutsaydım ilk basamağını okur bırakırdı

		switch (tur)
		{
		case 'U': yeniSekil = new Ucgen(w, h, x, y, z, c);  break;
		case 'D': yeniSekil = new Dikdortgen(w, h, x, y, z, c);  break;	
		case 'Y': yeniSekil = new Yildiz(w, h, x, y, z, c); break;	
		
		default:
			break;
		}
		this->Add(yeniSekil);
	}
}

int SekilListe::Size() const
{
	return length;
}

bool SekilListe::IsEmpty() const
{
	return length == 0;
}

int SekilListe::IndexOf(Sekil *eleman)
{
	int index = 0;
	for (SekilDugum* itr = head; itr != NULL; itr = itr->next) {
		if (itr->item == eleman) return index;
		index++;
	}
	throw "No Such Element";
}

void SekilListe::Remove(Sekil* eleman)
{
	int index = IndexOf(eleman);
	RemoveAt(index);
}

void SekilListe::RemoveAt(int index)
{
	if(length == 0) throw "Empty List";
	SekilDugum* del;
	if(index == 0) { //headi siliyor
		del = head;
		head = head->next;
				
	}
	else{
		SekilDugum *prev = FindPrevByPosition(index);
		del= prev->next;
		prev->next = prev->next->next;
	}			

	delete del;
	length--;
}

bool SekilListe::Find(Sekil *)
{
	return false;
}

void SekilListe::Clear()
{
	while(!IsEmpty())
	RemoveAt(0);
}


SekilListe::Iterator::Iterator(SekilDugum *start, SekilListe* bagliOlduguListe)
{
	ptr = start;
	liste = bagliOlduguListe;
}

bool SekilListe::Iterator::hasNext() const
{
    return ptr && ptr->next;
}


void SekilListe::Iterator::next()
{
	if (hasNext()) ptr = ptr->next;  
}


SekilDugum *SekilListe::Iterator::getCurrent() const
{
	return ptr;
}

//bastan dolasir bi oncesine gelir
void SekilListe::Iterator::prev()
{
	if(!hasPrev()) return;

	//geri gelme işleminde eğer eski head silimiş ve yenisi atanmış ise bozulmaması için
	SekilDugum* guncelHead = liste->head;
	if (ptr == guncelHead || guncelHead == NULL) return;

    SekilDugum* temp = guncelHead; 

    while (temp->next != NULL && temp->next != ptr) { //bi öncesine kadar git
        temp = temp->next;
    }

    if (temp->next == ptr) { //gercekten bi oncesindeyse yeni dugumu o olarak isaratle
        ptr = temp;
    }
}

bool SekilListe::Iterator::hasPrev() const
{
    // Eğer şu anki düğüm head değilse gerisine gidilebilir.
	SekilDugum* guncelHead = liste->head;
    return ptr != guncelHead && ptr != NULL;
}


//starti ve kendi head'i listenin head'ine esitlenmis bir iterator dondurur
SekilListe::Iterator SekilListe::GetIterator()
{
	return Iterator(head, this);
}

