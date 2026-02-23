#include "stdio.h"

//stackte oluşur ve fonk bitince silinceğinden olmayan adres döndürür derleme hatası verir
// char* isimDondurHatali(){ 
// 	char isimdondur[] =  {'A','L','I','\0'};
// 	return isimdondur;
// }

const char* isimDondur(){
	const char *isimdondur = "Yavuz";
	return isimdondur;
}

int main() {
	char* isim = "Yavuz"; //normalde tek char alan bir pointer olmalı fakat biz karakter dizisi gibi bir şey atadık

	//ilk charı yazdırır
	printf("%c",*isim); //Y

	//%s string yazmak istiyorum demektir. isim ise ilk char'ın adresidir \0 a gelince bittiğini anlar
	printf("\n%s",isim); //Yavuz

	char CharDizisi[] = {'A','L','I','\0'}; //\0 ı eklemeliyiz yoksa saçmalar
	printf("\n%s",CharDizisi); //ALI


	const char* isim2 = isimDondur();
	printf("\n%s",isim2);
	return 0;
}