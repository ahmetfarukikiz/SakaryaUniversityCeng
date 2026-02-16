#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename T>
class Stack{
private:
	T* items;
	int capacity;
	int topOfStack; //çıkmak üzere olan elemanın indexi
	void reverse (int newCapacity){
		T *tmp = new T[newCapacity];
		for(int i = 0; i< capacity; i++){
			tmp[i] = items[i];
		}
		delete [] items;
		items = tmp;
	}
public:
	Stack(){
		capacity = 100;
		items = new T[capacity];
		topOfStack = -1;
	}

	bool isEmpty(){
		return topOfStack == -1;
	}

	void push(const T& item){
		if (topOfStack+1 == capacity) reverse(2*capacity);
		topOfStack++;
		items[topOfStack] = item;
	}

	const T& top(){
		if(isEmpty()) throw "Stack is empty";
		return items[topOfStack];
	}

	void pop(){
		if(isEmpty()) throw "Stack is empty";
		topOfStack--; //silmemize gerek yok zaten artık erişilemez.
	}

	void clear(){
		topOfStack = -1;
	}
	~Stack(){
		delete[] items;
	}
};

#endif