/**
* @file AnaListe.cpp
* @description Iki yonlu ana liste icinde SekillerListesi tutar. Icinde gomulu iterator sinifi bulunur.
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/AnaListe.hpp"



AnaListe::AnaListe()
{

	head = NULL;
	_current = head;
	length = 0;
}

AnaListe::~AnaListe(){
	Clear();
}



AnaDugum *AnaListe::FindPrevByPosition(int index)
{
    if (index < 0 || index > length) throw "Index out of Range";
    
    if (head == NULL) return NULL;

    AnaDugum* itr = head;
    int i = 1;

    while (itr->next != NULL && i != index) {
        itr = itr->next;
        i++;
    }
    
    return itr;
}


int AnaListe::Size() const
{
	return length;
}

bool AnaListe::IsEmpty() const
{
	return length == 0;
}

void AnaListe::Add(SekilListe* item)
{
	Insert(length, item);
}

//indexi verirken sıfırdan baslatmak gerek
void AnaListe::Insert(int index,SekilListe* item) 
{
	if (index < 0 || index > length) throw "Index out of Range";
	if (index == 0) {
		head = new AnaDugum(item,head,NULL);
		if (head->next != NULL) head->next->prev = head;
	}
	else {
		AnaDugum* prv = FindPrevByPosition(index);
		prv->next = new AnaDugum(item, prv->next, prv);
		if (prv->next->next != NULL)
			prv->next->next->prev = prv->next;
	}

	if (length == 0) {
        _current = head; 
    }

	length++;
}

SekilListe* AnaListe::First()
{
	if (IsEmpty()) throw "No Such Element";
	return head->item;
}

SekilListe* AnaListe::Last()
{
	if (IsEmpty()) throw "No Such Element";
	return FindPrevByPosition(length)->item;
}

int AnaListe::IndexOf(SekilListe *eleman)
{
	int index = 0;
	for (AnaDugum* itr = head; itr != NULL; itr = itr->next) {
	if (itr->item == eleman) return index; 
	index++;
	}
	throw "No Such Element";
}

void AnaListe::Remove(SekilListe* eleman)
{
	int index = IndexOf(eleman);
	RemoveAt(index);
}

void AnaListe::RemoveAt(int index)
{
	if(index < 0 || index >= length) throw "Index out of Range";
			AnaDugum *del;
			if(index == 0){
				del = head;
				head = head->next;
				if(head != NULL) head->prev = NULL;
			}
			else{
				AnaDugum *prv = FindPrevByPosition(index);
				del = prv->next;
				prv->next = del->next;
				if(del->next != NULL)
					del->next->prev = prv;
			}
			length--;
			delete del;
}

bool AnaListe::Find(SekilListe* eleman)
{
	for (AnaDugum* itr = head; itr != NULL; itr = itr->next) {
		if (itr->item == eleman) return true;
	}
	return false;
}

void AnaListe::Clear()
{
	while(!IsEmpty())
	RemoveAt(0);
}


AnaListe::Iterator::Iterator(AnaDugum *start)
{
	ptr = start;

}

bool AnaListe::Iterator::hasNext() const
{
    return ptr && ptr->next;
}

bool AnaListe::Iterator::hasPrev() const
{
    return ptr && ptr->prev;
}

void AnaListe::Iterator::next()
{
	if (hasNext()) ptr = ptr->next;  
}

void AnaListe::Iterator::prev()
{
	if (hasPrev()) ptr = ptr->prev;
}

AnaDugum *AnaListe::Iterator::getCurrent() const
{
	return ptr;
}

//starti head'e esitlenmis bir iterator dondurur
AnaListe::Iterator AnaListe::GetIterator()
{
	return Iterator(head);
}
