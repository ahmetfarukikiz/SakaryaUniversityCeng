#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
using namespace std;
#define MAX 7

struct Node{
	int data;
	Node* next;
	Node(int data, Node* next = NULL){
		this->data = data;
		this->next = next;
	}
};

class OpenHash{
	private:
		Node* Table[MAX];
	public:
		OpenHash();
		int hashfunc(int);
		void add(int);
		void deleteData(int);
		void clear();
		bool find(int);
		bool isEmpty();
		void print(); //normalde gerekmez test amacıyla
		~OpenHash();
};

#endif