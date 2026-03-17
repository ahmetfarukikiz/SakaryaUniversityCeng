#ifndef ANALISTE_HPP
#define ANALISTE_HPP

#include "AnaDugum.hpp"

class AnaListe{
	private:
		AnaDugum* head;
		AnaDugum* _current;
		int length;

		AnaDugum* FindPrevByPosition(int);
	public:

	class Iterator{
		private:
			AnaDugum* ptr;

		public:
			Iterator(AnaDugum* start);
			bool hasNext() const;
			bool hasPrev() const;
			void next();
			void prev();
			AnaDugum* getCurrent() const;
    };

		Iterator GetIterator();

		AnaListe();

		~AnaListe();


		int Size()const;

		bool IsEmpty()const;

		void Add(SekilListe*);

		void Insert(int, SekilListe*);

		SekilListe* First();

		SekilListe* Last();

		int IndexOf(SekilListe*);

		void Remove(SekilListe*);

		void RemoveAt(int);

		bool Find(SekilListe*);

		void Clear();
		

};

#endif