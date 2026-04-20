#include "Dosya.h"

int main(){
	Dosya d = new_Dosya("dene.txt");

	try{
		printf("%s",d->oku(d));
	}
	catch{
		printf("Dosya okumada hata var");
	}
	tryEnd; //try catch bloğunu kapat
	
	d->delete_dosya(d);


	return 0;
}


