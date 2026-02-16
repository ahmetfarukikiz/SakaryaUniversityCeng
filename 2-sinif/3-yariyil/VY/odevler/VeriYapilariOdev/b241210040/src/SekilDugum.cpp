/**
* @file SekilDugum.cpp
* @description Icinde Sekil tutan tek yonlu bagli listenin dugumu
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 17.11.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "../include/SekilDugum.hpp"

SekilDugum::SekilDugum(Sekil* item, SekilDugum * next)
{
	this->item = item; 
	this->next = next;
}

SekilDugum::~SekilDugum() 
{
	if(item != NULL) delete item;
}