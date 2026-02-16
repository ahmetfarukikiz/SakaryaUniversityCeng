#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template<typename Object>
class Queue{
	private:
		int front;
		int back;
		int capacity;
		int length;
		Object *items;
		void reserve(int newCapacity){
			Object *tmp = new Object[newCapacity];
			for(int j = 0, i = front; j <length; j++ ) {
				tmp[j] = items[i];
				i = (i+1)%capacity;
			}
			capacity = newCapacity;
			delete [] items;
			items = tmp;
			front = 0;
			back = length - 1;
		}
	public:
		Queue(){
			capacity = 100;
			front = 0;
			back = -1;	
			length = 0;
			items = new Object[capacity];
		}

		void clear(){
			front = 0;
			back = -1;
			length = 0;
		}
		int count()const{
			return length;
		}
		bool isEmpty(){
			return length == 0;
		}

		const Object& peek(){
			if(isEmpty()) throw "Kuyruk Bos";
			return items[front];
		}

		void dequeue(){
			if(isEmpty()) throw "Kuyruk Bos";
			front = (front+1)%capacity;
			length--;
		}
		void enqueue(Object& item){
			if(length == capacity) reserve(2*capacity);
			back = (back+1)%capacity;
			items[back] = item;
			length++;
		}
		
		~Queue(){
			delete [] items;  
		}

		

};

#endif