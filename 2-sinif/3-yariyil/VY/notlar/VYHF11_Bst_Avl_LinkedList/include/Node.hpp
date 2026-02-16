#ifndef Node_HPP
#define Node_HPP

#include <iostream>

using namespace std;
template <typename T>
struct Node {
	T data;
	Node<T>* left;
	Node<T>* right;
	int height;

	Node(const T& d, Node<T>* l = nullptr, Node<T>* r = nullptr)
	{
		data = d;
		left = l;
		right = r;
		height = 0;
	}
};

#endif	