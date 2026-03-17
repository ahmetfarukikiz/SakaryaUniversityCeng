#ifndef SEKILLISTE_HPP
#define SEKILLISTE_HPP


#include "Ekran.hpp"
#include "SekilDugum.hpp"
#include "GlobalFonksiyonlar.hpp"
#include <fstream>
class SekilListe
{
private:
	SekilDugum* head;
	int length;
	SekilDugum* FindPrevByPosition(int);
public:
	SekilListe();
	~SekilListe();

		SekilDugum* GetHead();

		void RastgeleSekilOlustur(int sekilSayisi, int cSatir, int cSutun); //sınırları da gönder

		void DosyadanSekilOlustur(ifstream&, int);

		int Size()const;

		bool IsEmpty()const;

		void Add(Sekil*);

		void Insert(int,Sekil*);

		int IndexOf(Sekil*);

		void Remove(Sekil*);

		void RemoveAt(int);

		bool Find(Sekil*);

		void Clear();

		class Iterator{
			private:
				SekilDugum* ptr;
				SekilListe* liste;

			public:
				Iterator(SekilDugum* start,SekilListe* bagliOlduguListe);
				bool hasNext() const;
				void next();
				SekilDugum* getCurrent() const;
				void prev();
				bool hasPrev() const;
    	};

		Iterator GetIterator();

		
};

#endif