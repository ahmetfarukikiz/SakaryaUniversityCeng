#ifndef HEAPTREE_HPP
#define HEAPTREE_HPP

#include <iostream>
using namespace std;

class HeapTree
{
private:
	int *items;
	int length;
	int capacity;

	int LeftChildIndex(int);
	int RightChildIndex(int);
	int ParentIndex(int);
	void HeapfyUp(int);
	void HeapfyDown(int);
	void Swap(int &, int &);

public:
	HeapTree(int);
	bool isEmpty();
	void add(int);
	int getMinValue();
	~HeapTree();
};

#endif