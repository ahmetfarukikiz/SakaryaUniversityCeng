#include <stdio.h> 

int main(){
	const double g;
	printf("Yercekim:");
	/*g=9.8; //Derleyici hata verir çünkü rastgele bir değer atandı bile consta 
	ve sen değiştirmeye çalıştın */

	scanf("%lf",&g); //bu şekilde g'nin adresi olarak yapılırsa derleyici hata vermez
	//bellek yoluyla constlar değiştirilebilir //güvensiz programlama
	//bu sebeple javada pointera izin verilmez


	return 0;
}