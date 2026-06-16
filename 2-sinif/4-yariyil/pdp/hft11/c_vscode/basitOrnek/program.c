#include "stdio.h"
#include "setjmp.h"

jmp_buf jumper; //içinde cpu bilgilerini tutan bir buffer

int bolme(int x, int y){
	// y 0'a eşit ise jumper'ın içinde tutulan adrese git. (setjmp satırına döner)
	if(y == 0) longjmp(jumper, 1); //setjmp'ın yeni döndüreceği değer 1 olacak
	return x/y;
}

int main(){
	int a = 10, b=0;
	if(setjmp(jumper) == 0){ //jumper'ın içine şuanki satırı kaydeder ve ilk kez 0 döndürür
		printf("%d",bolme(a,b));
	}
	else{
		printf("Sifira Bölünme Hatası");
	}
	return 0;
}

