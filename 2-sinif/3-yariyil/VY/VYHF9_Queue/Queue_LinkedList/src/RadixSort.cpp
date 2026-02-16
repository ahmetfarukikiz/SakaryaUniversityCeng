#include "../include/Queue.hpp"
#include <cmath>

int BasamakSayisi(int sayi) {
	sayi = abs(sayi);
	int basamak = 0;
	while(sayi > 0) {
		basamak++;
		sayi/=10;
	}
	return basamak;
}

int EnYuksekBasamakSayisi(int* items, int length) {
	int max = 0;
	for(int i = 0; i < length; i++){
		if(BasamakSayisi(items[i])> max) max = BasamakSayisi(items[i]);
	}
	return max;
}

int* RadixSort(int* items, int length){
    Queue<int>* queues[10];
    for(int i = 0; i < 10; i++) queues[i] = new Queue<int>();

    int maks = EnYuksekBasamakSayisi(items, length);

    for(int pass = 0; pass < maks; pass++) {

        // 1) KUYRUKLARA DAĞIT
        for(int i = 0; i < length; i++){
            int basamak = (items[i] / (int)pow(10, pass)) % 10;
            queues[basamak]->enqueue(items[i]);
        }

        // 2) KUYRUKLARDAN GERİ TOPLA
        int index = 0;
        for(int k = 0; k < 10; k++){
            while(!queues[k]->isEmpty()){
                items[index++] = queues[k]->peek();
                queues[k]->dequeue();
            }
        }
    }

    for(int i = 0; i < 10; i++) delete queues[i];

    int* sirali = new int[length];
    for(int i = 0; i < length; i++) sirali[i] = items[i];
    return sirali;
}


int main(){
	int sayilar[] = {142,231,211,2441,1,212,22,55,23,11};
	int* sirali = RadixSort(sayilar,10);

	for(int i = 0; i < 10; i++){
		cout << sirali[i] << " ";
	}
	//yazdırılabilir

	delete [] sirali;
	return 0;
}