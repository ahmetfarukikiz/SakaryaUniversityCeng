#include <stdio.h> //# ile başlayanlar ön işleme konutudur

int main(){
	int sayi; //int kadar yer ayır
	printf("Sayi:"); //bir fonksiyondur
	scanf("%d",&sayi); //%d tam sayı demektir (ilk parametre sayı tipi, ikincisi atanacak degiskenin adresi)
	short binler,yuzler,onlar,birler;
	binler = sayi/1000;
	yuzler = (sayi%1000)/100; //tam sayı bölmesi 5848'den 848 ordan da 8
	onlar = (sayi%100)/10;
	birler = sayi%10;

	printf("Birler: %d\nYuzler: %d\nOnlar: %d\nBirler: %d\n",binler,yuzler,onlar,birler);
	//%d yazdığımız yerler için parametre bekler

	return 0;
}