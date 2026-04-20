#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "setjmp.h"
#include <stdlib.h>

typedef enum{false, true}boolean;

jmp_buf jumper;

#define try do{ if(setjmp(jumper) == false){
#define catch } else {
#define tryEnd }}while(0)
#define throw longjmp(jumper,1)

/*
do {
	if(setjmp(jumper)){
	}
	else{
	}
}while(0)
*/

struct DOSYA
{
	char* yol;
	char* icerik;
	char* (*oku)(struct  DOSYA*);
	void (*delete_dosya)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya new_Dosya(char*);
char* oku(const Dosya);
void delete_Dosya(Dosya);



#endif
