#include <stdio.h> 

int main(){
	//boolean benzetimi
	//javaya benzer olsun diye boolean dedik dogruyanlis da diyebilirdik
	typedef enum BOOL{false, true}boolean; //enum kelimeyi numaralandırır false=0 true=1
	boolean kontrol = true;
	if(kontrol) printf("bool turu varmis gibi yapiyoruz\n\n");


	int a = 100;
	int b = 100000;
	//a'nın türünün yani int in kapladığı alan
	printf("a uzunluk: %d\n",sizeof a); 
	//sizeof(a) olarak da kullanılabiir
	printf("a uzunluk: %d\n",sizeof(b));  


	double sonuc = (100/12)-5*3; //sonucu sağ taraf belirler
	double gercekdoublesonuc = (100.0/12)-5*3; //artık ondalıklı gelicek
	printf("sonuc: %lf\nsonucdouble=%lf",sonuc, gercekdoublesonuc);

	return 0;
}