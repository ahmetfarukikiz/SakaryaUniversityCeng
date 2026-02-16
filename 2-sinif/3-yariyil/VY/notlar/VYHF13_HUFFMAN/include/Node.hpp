#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

struct Node{
	char character;
	int freq; //sıklığı
	string code;
	Node* left;
	Node* right;

	Node(char, int, Node* left = NULL, Node* right = NULL);

	bool isLeaf();
	bool operator==(Node&); //n1 == n2 şeklinde karşılaştırma
	bool operator!=(Node&);
	bool operator>(Node&); //frequence'a göre
};

#endif