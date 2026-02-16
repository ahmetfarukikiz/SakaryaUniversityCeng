#ifndef DHASH_HPP
#define DHASH_HPP

#include <iostream>
using namespace std;
#define MAX 7 //capacity
#define R 5

class DoubleHash{
	private:
		int *Table;
		int maxStep;
		int length; //gerçek anlamda kaç eleman olduğu
	public:
		DoubleHash();
		int hashfunc1(int); //return sayi%tablo.u = index
		int hashfunc2(int); //return R - (sayi&R) = atlama uzunluğu
		void add(int);
		bool find(int);
		void clear();
		void print();
		~DoubleHash();

};

#endif