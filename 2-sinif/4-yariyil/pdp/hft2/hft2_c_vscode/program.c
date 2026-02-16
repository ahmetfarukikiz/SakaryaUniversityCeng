#include <stdio.h> //# ile başlayanlar ön işleme konutudur

int main(){
	char x = 'A';
	printf("%d",x); //A karakterinin ascii kodunu ekrana basar

	printf("%c",'\n');

	if(50) printf("50'yi true olarak kabul ediyor\n");
	//boolean türü yoktur. 0 false tur diğer sayılar true'dur
	

	char y = '\b';
	printf("Sakarya%c",y); //çıkış karakteri örneği

	printf("\n\n");

	//boolean benzetimi
	//javaya benzer olsun diye boolean dedik dogruyanlis da diyebilirdik
	typedef enum BOOL{false, true}boolean; //enum kelimeyi numaralandırır false=0 true=1
	boolean kontrol = true;
	if(kontrol) printf("bool turu varmis gibi yapiyoruz");
	return 0;
}