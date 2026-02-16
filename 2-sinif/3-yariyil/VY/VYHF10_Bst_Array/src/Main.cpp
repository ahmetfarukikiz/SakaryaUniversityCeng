#include "../include/Bst.hpp"

int main(){
	int sayilar[] = {80,12,77,48,10,121,110,60};
	Bst<int> *bst = new Bst<int>();
	for(int i =0; i< 9; i++){ bst->add(sayilar[i]);}
	if(bst->search(77)) cout << " var" <<endl;
	else cout << " yok";

	return 0;
}