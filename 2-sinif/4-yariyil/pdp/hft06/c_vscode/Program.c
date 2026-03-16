#include <stdio.h>

//burada prototip tanımlanırsa hata vermez. //func'ın imzası
//direkt fonksiyon tanımı yukarıda da yapılabilir.
double f(double a, double b); 

int main() {
	// printf("%lf\n", f(10.5,21.8));

	int x = 10.5, y = 21.8;
	printf("%lf\n", f(x, y)); //değer ile çağırma. 

	return 0;
}

//fonksiyon tanımı altta olduğundan hata verir.
double f(double a, double b) {
	return a / b;
}