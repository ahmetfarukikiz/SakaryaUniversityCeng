/**
* @file Queue.cpp
* @description  arraylist ile gerçekleştirilmiş sabit uzunluklu altıgen bir kuyruk yapısıdır içinde bst ağacı tutar 
gelen ağaç verisini dağıtır.  
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 4.12.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/


#include "Queue.hpp"
#include <stdexcept>

Queue::Queue()
{
	front = 0;
	back = -1;	
	length = 0;
	items = new Bst*[capacity];
}

void Queue::enqueue(Bst *item)
{
	back = (back+1)%capacity;
	items[back] = item;
	length++;
	
}

void Queue::dequeue()
{
	if(isEmpty()) throw std::runtime_error("Kuyruk Bos");

	if(items[front] !=  nullptr) {
        delete items[front]; //pointer dizisi olduğu için delete ediyorum
        items[front] = nullptr; 
    }

	front = (front+1)%capacity;
	length--;
}

//peekMax ile bulunan ağacı parametre alır
void Queue::dequeueMax(Bst* silinecekAgac)
{
    if (isEmpty() || silinecekAgac == nullptr) throw std::runtime_error("Hata");

    int silinecekIndex = -1;
    
    for (int i = 0; i < length; i++) {
        int index = (front + i) % capacity;
        if (items[index] == silinecekAgac) {
            silinecekIndex = index;
            break;
        }
    }

    if (silinecekIndex == -1) return; 
    
    if (silinecekIndex == front) {
        dequeue();
        return;
    }

    if(items[silinecekIndex] != nullptr){
        delete items[silinecekIndex];
    }

    int curr = silinecekIndex;
    while (curr != back) {
        int next = (curr + 1) % capacity; 
        items[curr] = items[next];        
        curr = next;                      
    }

    items[back] = nullptr;
    back = (back - 1 + capacity) % capacity;
    length--;
}


int* Queue::postOrderDequeue()
{
	int* geciciDizi = new int[peek()->count()];
	peek()->postordersil(geciciDizi); //agacı postordersil bir şekilde gecdiziye kaydeder
	dequeue(); //agacı siler
	enqueue(new Bst()); //altıgen yapının bozulmaması için yeni ağaç
	return geciciDizi;
}

int *Queue::postOrderDequeueMax(int& boyut)
{
	Bst* silinecekAgac = peekMax();
    boyut = silinecekAgac->count();
    int* geciciDizi = new int[boyut];
    silinecekAgac->postordersil(geciciDizi); 
    dequeueMax(silinecekAgac); 
    enqueue(new Bst()); 
    return geciciDizi;
}

void Queue::clear()
{
	while(!isEmpty()){
        dequeue();
    }

	front = 0;
	back = -1;	
	length = 0;
}



//kuyruğun frontundan başlayarak dağıtım yapar
void Queue::verilenAgaciDagit(int *alinanAgac, int alinanAgacUzunlugu)
{
    if (isEmpty() || alinanAgac == nullptr || alinanAgacUzunlugu <= 0) return;

    int verilenAgacSirasi = 0;

    for (int i = 0; i < alinanAgacUzunlugu; i++) {
        //kuyruğun frontundan başlayarak sıradaki indexi hesaplar
        int index = (front + verilenAgacSirasi) % capacity;

        items[index]->add(alinanAgac[i]);

        // modüler, döngüsel dağıtım
        verilenAgacSirasi = (verilenAgacSirasi + 1) % length;
    }
}

int Queue::count() const
{
	return length;
}

bool Queue::isEmpty()const{
	return length == 0;
}


Bst* Queue::peek(){
	if(isEmpty()) throw std::runtime_error("Kuyruk Bos");
	return items[front];
}

Bst *Queue::peekMax()
{
    if (isEmpty()) return nullptr;

    Bst* bstMax = items[front];
    int heightMax = bstMax->height(); 

    for (int i = 1; i < length; i++) {
        int index = (front + i) % capacity;
        Bst* currentBst = items[index];
        int currentHeight = currentBst->height();
        
        if (currentHeight > heightMax) {
            heightMax = currentHeight;
            bstMax = currentBst;
        }
    }

    return bstMax;
}

Queue::~Queue(){
	if (items != nullptr) {
        clear();
        delete [] items;
    }
}

int Queue::getEkranDegeri()
{

	if (isEmpty()) return 0;
	
	if (peek() == nullptr || peekMax() == nullptr) {
        return 0; 
    }
	if (peek()->isEmpty() || peekMax()->isEmpty()) {
        return 0; 
    }
	if(peekMax()->getRoot()->data == 0) return 0; //sıfıra bölme hatası kontrolü
	return peek()->getRoot()->data / peekMax()->getRoot()->data;
}
