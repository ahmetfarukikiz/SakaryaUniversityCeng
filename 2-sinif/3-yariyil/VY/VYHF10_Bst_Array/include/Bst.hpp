#ifndef BST_HPP

#include <iostream>
#define SIZE 1000
using namespace std;

template <typename T>
class Bst{
	private:
		T*items;
		int itemStatus[SIZE]; //itemlerin varlık durumlarını bildiren dizi
	public:
	Bst(){
		items = new T[SIZE];
		clear();
	}
	void clear(){
		for(int i = 0; i< SIZE; i++) {
			itemStatus[i] = 0;
		}
	}
	void add(const T& item){
		int suankiIndex = 0;
		while(true){ 
			if(itemStatus[suankiIndex] == 0){
				items[suankiIndex] = item;    
    			itemStatus[suankiIndex] = 1;  
				break;
			}
			else if(item < items[suankiIndex])
				suankiIndex = 2*suankiIndex+1;
			else if(item > items[suankiIndex])
				suankiIndex = 2*suankiIndex+2;
			else break;
		}
	}

	bool search(const T& item) {
		int suankiIndex = 0;
		while(true){ 
			if(itemStatus[suankiIndex] == 0) return false;
			else if(item < items[suankiIndex])
				suankiIndex = 2*suankiIndex+1;
			else if(item > items[suankiIndex])
				suankiIndex = 2*suankiIndex+2;
			else return true;
		}
	}

	void inorder(int index = 0){
		if(itemStatus[index] == 0) return;
		inorder(2*index+1); //sol çocuğu inorder dolaş
		cout << items[index] << ""; //kendini yaz
		inorder(2*index+2); //sağ çocuğu inorder dolaş
	}

	
	void preorder(int index = 0){
		if(itemStatus[index] == 0) return;
		cout << items[index] << ""; //kendini yaz
		preorder(2*index+1); //sol çocuğu inorder dolaş
		preorder(2*index+2); //sağ çocuğu inorder dolaş
	}

	void postorder(int index = 0){
		if(itemStatus[index] == 0) return;
		postorder(2*index+1); //sol çocuğu inorder dolaş
		postorder(2*index+2); //sağ çocuğu inorder dolaş
		cout << items[index] << ""; //kendini yaz
	}

	void levelorder(){ //diziye ilk eklenirken preorder olarak eklendiği için direkt boşlar atlanır ve veri okunur
		for(int i = 0; i < SIZE < i; i++){
			if(itemStatus[i] != 0) cout << items[i] << " ";
		}	
	}

	int height(int index = 0){ //parametre gönderilmezse ağacın yüksekliği parametre gönderilirse düğümün yüksekliği
		if(itemStatus[index] == 0) return -1;
		return 1 + max(height(2*index+1),height(2*index+2)); //sağ ve sol çocuktan yüksekliği büyük olan düğümü getir.
	}

	~Bst(){
		delete[] items;
	}
};

#endif