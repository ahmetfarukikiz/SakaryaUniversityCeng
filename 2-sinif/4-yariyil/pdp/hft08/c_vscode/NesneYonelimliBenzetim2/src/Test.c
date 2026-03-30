#include "Koleksiyon.h"

int main(){
	int s[] = {100, 20, 300, 40, 50};
	Koleksiyon k = new_Koleksiyon(s,5);
	k->yazdir(k);
	k->delete_Koleksiyon(k);

	return 0;
}