#include "HeapTree.hpp"

int HeapTree::LeftChildIndex(int index)
{
	return index * 2 + 1;
}

int HeapTree::RightChildIndex(int index)
{
	return index* 2 + 2;
}

int HeapTree::ParentIndex(int index)
{
	return (index - 1) / 2;
}

void HeapTree::HeapfyUp(int index)
{
	int parentIndex;
	if(index != 0){
		parentIndex	= ParentIndex(index);
		if(items[parentIndex] > items[index]) {
			swap(items[parentIndex],items[index]);
			HeapfyUp(parentIndex);
		}
	}

}

void HeapTree::HeapfyDown(int index)
{
	int rightIndex, leftIndex, minIndex;
	leftIndex = LeftChildIndex(index);
	rightIndex = RightChildIndex(index);
	//sadece uzunluktan büyük mü diye bakarken doğrudan index karşılaştırılır
	if(rightIndex >= length){
		if(leftIndex > length) return;
		else minIndex = leftIndex;
	}
	else{
		//dikkat doğrudan indeexleri değil indexteki değerleri karşılaştır
		if(items[leftIndex] <= items[rightIndex]) 
			minIndex = leftIndex;
		else minIndex = rightIndex;
	}

	if(items[index] > items[minIndex]){
		swap(items[index], items[minIndex]);
		HeapfyDown(minIndex);
	}
}





void HeapTree::Swap(int & item1, int & item2)
{
	int tmp;
	tmp = item1;
	item1 = item2;
	item2 = tmp;	
}

HeapTree::HeapTree(int size)
{
	items = new int[capacity];
	capacity = size;
	length = 0;
}

bool HeapTree::isEmpty()
{
	return length == 0;
}

void HeapTree::add(int item)
{
	if (capacity == length) throw "agac dolu";
	items[length] = item;
	length++;
	HeapfyUp(length-1);
}

int HeapTree::getMinValue()
{
	if(isEmpty()) throw "Tree is empty";
	int minValue = items[0];
	items[0] = items[length-1];
	length--;
	if (length > 0) HeapfyDown(0); // null erişim olmaması için length > 0 kontrolu
	return minValue;
}

HeapTree::~HeapTree()
{
	delete [] items;
}
