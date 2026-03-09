#include <stdio.h>
//c'de durum etiketleri yoktur goto ile aynı etki oluşturulabilir
int main(){
	for(int i=1;i<=9;i++){
		inner:
		for(int j=1;j<=9;j++){
			if(i*j >= 10) goto outer;
			printf(" %d",i*j);
		}
	}
	outer:

	printf("\n");

	return 0;
}
