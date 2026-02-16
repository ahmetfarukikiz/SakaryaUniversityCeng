#include "OpenHash.hpp"
#include "DoubleHash.hpp"

int main(){
	OpenHash *h = new OpenHash();

	h->add(7);
	h->add(8);
	h->add(14);
	h->add(15);
	h->add(5);
	h->add(12);

	h->print();

	cout << endl << endl << endl;

	DoubleHash *dh = new DoubleHash();

	dh->add(7);
	dh->add(8);
	dh->add(14);
	dh->add(15);
	dh->add(5);
	dh->add(12);
	
	dh->print();

	
	delete dh;
	return 0;
}