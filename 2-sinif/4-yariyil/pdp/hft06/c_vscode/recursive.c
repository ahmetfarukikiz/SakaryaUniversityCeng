#include <stdio.h>
#include "stdarg.h"

typedef enum { false, true } boolean; //bool tipini tanımlıyoruz.

boolean asalmi(int parametreAdedi, ...){  //parametreAdedi, sayi, bolen
	va_list valist; //parametre tutan liste
	va_start(valist, parametreAdedi); //bu kadar parametre adedi valiste gönderildi
	int sayi = va_arg(valist, int); //sırada int türünden bir parametre gelicek onu al
	if(parametreAdedi == 1) { //ilk parametre harici 1 ise
		va_end(valist);
		return asalmi(2,sayi,2);
	}
	int bolen = va_arg(valist, int);
	va_end(valist);
	if(sayi == bolen) return true;
	if(sayi % bolen == 0) return false;
	return asalmi(2,sayi,bolen+1);
}

int main() {
	if(asalmi(1,13)) printf("Asal Sayi");
	else printf("Asal sayi değil");

	return 0;
}
