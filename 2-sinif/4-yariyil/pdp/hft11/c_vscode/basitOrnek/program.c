#include "stdio.h"
#include "setjmp.h"

typedef enum {false, true}boolean;

jmp_buf jumper;

int bolme(int x, int y){
	if(y == 0) longjmp(jumper, 1); //jumper'ın değerini 1 yap
	return x/y;
}

int main(){
	int a = 10, b=0;
	if(setjmp(jumper) == false){ // geri dönme noktası bırak ve değeri değiştiyse geri dön.
		printf("%d",bolme(a,b));
	}
	else{
		printf("Sifira Bölünme Hatası");
	}
	return 0;
}
