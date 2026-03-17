#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Bst.hpp"
#include <iostream>

//bir düğüm dequeue edildiğinde otomatik olarak kuyruğun sonuna yeni düğüm enqueue edilecek.

class Queue{
private:
	int front;
	int back;
	const int capacity = 6; //sabit altıgen yapı
	int length;
	Bst **items;


public:
	Queue();
	~Queue();
	int getEkranDegeri();
	void enqueue(Bst* item);
	void dequeue();
	int* postOrderDequeue();
	int* postOrderDequeueMax(int &boyut);
	void clear();
	void verilenAgaciDagit(int* agacVerisi,int agacUzunlugu);
	int count()const;
	bool isEmpty()const;
	void dequeueMax(Bst* silinecekAgac);
	Bst* peek() const;
	Bst* peekMax() const;

};


#endif