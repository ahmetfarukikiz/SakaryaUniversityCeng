#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"

template <typename T>
class Bst {
   private:
   	Node<T>* root;
	//ayrı bir pointer oluşturmuyoruz *& yapıyoruz ve diğer düğümün referansını alıyoruz subNode bir takma isim oluyor
	void searchAndAdd(Node<T> *&subNode, const T& item){ 
		if(subNode==NULL) subNode = new Node<T>(item);
		else if(item < subNode->data){
			searchAndAdd(subNode->left,item);
		}
		else if(item > subNode->data){
			searchAndAdd(subNode->right,item);
		}
		//aynı düğümse
		else return;
	}

	//nerden başlanacağı, neyi arayacağı
	bool search(Node<T> *subNode, const T& item){ 
		if(subNode==NULL) return false;
		else if(item == subNode->data) return true;
		else if(item < subNode->data){
			return search(subNode->left,item);
		}
		else
			return search(subNode->right,item);
	}

	void inorder(Node<T> *subNode){
		if(subNode != NULL){		
			inorder(subNode->left);
			cout << subNode->data << " ";
			inorder(subNode->right);
		}
	}

	void preorder(Node<T> *subNode){
		if(subNode != NULL){		
			cout << subNode->data << " ";
			preorder(subNode->left);
			preorder(subNode->right);
		}
	}

	
	void postorder(Node<T> *subNode){
		if(subNode != NULL){		
			postorder(subNode->left);
			postorder(subNode->right);
			cout << subNode->data << " ";
		}
	}

	int height(Node<T> *subNode){
		if(subNode == NULL) return -1;
		return 1 + max(height(subNode->left), height(subNode->right));

	}
	void printlevel(Node<T> *subNode, int counter){
		if(subNode == NULL) return;
		if(counter == 0) cout << subNode->data << " ";
		else{
			printlevel(subNode->left, counter-1);
			printlevel(subNode->right, counter-1);
		}
	}

	bool searchAndDelete(Node<T> *&subNode, const T& item){
		if(subNode == NULL) return false;
		if(subNode->data == item) return deleteNode(subNode);
		else if(item < subNode->data)
			return searchAndDelete(subNode->left,item);
		else 
			return searchAndDelete(subNode->right,item);
	}

	bool deleteNode(Node<T> *&subNode){
		Node<T> *p = subNode;
		if(subNode->right == NULL) subNode = subNode->left;
		if(subNode->left == NULL) subNode = subNode->right;
		//iki çocuğu varsa
		else{
			p = subNode->left;
			Node<T> *parent = subNode;
			while(p->right != NULL){
				parent = p;
				p = p->right;
			}
			subNode->data = p->data;
			if(parent == subNode) subNode->left = p->left;
			else parent->right = p->left;
		}
		delete p;
		return true;
	}

	void clearTree(Node<T> *&subNode){
		if(subNode != NULL){
			clearTree(subNode->left);
			clearTree(subNode->right);
			delete subNode;
			subNode = NULL;
		}
	}

   public:
		Bst(){
			root = NULL;
		}
		~Bst(){
			clear();
		}
		bool isEmpty() {
			return root == NULL;
		}
		void add(const T& item){
			searchAndAdd(root,item);
		}
		bool search(const T& item){
			//kökten başla itemı ara
			return search(root,item);
		}

		void inorder(){
			inorder(root);
		}

		void preorder(){
			preorder(root);
		}

		void postorder(){
			postorder(root);
		}

		int height(){
			return height(root);
		}

		void levelOrder(){
			int maxLevel = height();
			for(int level=0; level<=maxLevel; level++){
				printlevel(root,level);
			}
		}

		void deleteData(const T& item){
			if(searchAndDelete(root,item)==false) throw "item not found";

		}

		void clear(){
			clearTree(root);
		}
};

#endif