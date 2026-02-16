/**
* @file AnaDugum.cpp
* @description Iki yonlu ana listenin dugum sinifi. Icinde SekilListesi tutar.
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 16.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/AnaDugum.hpp"

AnaDugum::AnaDugum(SekilListe* item, AnaDugum* next=NULL, AnaDugum*prev=NULL){
	this->item = item;
	this->next = next;
	this->prev = prev;
}
AnaDugum::~AnaDugum() 
{
	if (item != NULL) {
        delete item; 
    }
}