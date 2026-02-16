#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename T> 
struct Node {
	T data;
	Node<T> *next;

	Node(const T& data, Node<T> *next = NULL) {
		this->data = data;
		this->next = next;
	}

};

template <typename T>
class Stack{
private:
	Node<T> *topOfStack;
public:
	Stack(){
		topOfStack = NULL;
	}

	bool isEmpty(){
		return topOfStack == NULL;
	}

	void push(const T& item){	
		topOfStack = new Node<T>(item, topOfStack);
	}

	const T& top(){
		if(isEmpty()) throw "Stack is empty";
		return topOfStack->data;
	}

	void pop(){
		if(isEmpty()) throw "Stack is empty";
		Node<T> *p = topOfStack;
		topOfStack = topOfStack->next;
		delete p;
	}

	void clear(){
		while(!isEmpty()){
			pop();
		}
	}
	~Stack(){
		while(!isEmpty()){
		pop();
		}
	}
};

#endif