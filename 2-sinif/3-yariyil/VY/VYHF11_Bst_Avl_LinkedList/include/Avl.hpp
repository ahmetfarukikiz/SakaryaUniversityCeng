#ifndef Avl_HPP
#define Avl_HPP

#include "Node.hpp"

template <typename T>
class Avl {
   private:
   	Node<T>* root;	
	Node<T>* searchAndAdd(Node<T>* subNode, const T& item){ //referanssız alınırsa nasıl olacağı
		if(subNode == NULL) subNode = new Node<T>(item);
		else if(item < subNode->data){
			subNode->left = searchAndAdd(subNode->left,item);
			//sola eklenmişse solda denge bozulmuş olabilir //2 fazlaysa denge bozulur
			if(height(subNode->left) == height(subNode->right)+2)
				if(item < subNode->left->data)
					subNode = swapWithLeftChild(subNode);
				else{
					subNode->left = swapWithRightChild(subNode->left);
					subNode = swapWithLeftChild(subNode);

				}
		}
		else if(item > subNode->data){	
			subNode->right = searchAndAdd(subNode->right,item);

			if(height(subNode->right) == height(subNode->left)+2)
				if(item < subNode->right->data)
					subNode = swapWithRightChild(subNode);
				else{
					subNode->right = swapWithLeftChild(subNode->right);
					subNode = swapWithRightChild(subNode);

				}
		}
		subNode->height = height(subNode);
		return subNode;

	}

	Node<T>* swapWithLeftChild(Node<T>* subNode){
		Node<T>* tmp = subNode->left;
		subNode->left = tmp->right;
		tmp->right = subNode;
		//yukseklik guncelle
		subNode->height = height(subNode);
		tmp->height = 1 + max(height(tmp->left), subNode->height);

		return tmp; //yeni subNode yeni yukarda olan şey
	}

	Node<T>* swapWithRightChild(Node<T>* subNode){
		Node<T>* tmp = subNode->right;
		subNode->right = tmp->left;
		tmp->left = subNode;
		//yukseklik guncelle	
		subNode->height = height(subNode);
		tmp->height = 1 + max(height(tmp->right), subNode->height);

		return tmp; //yeni subNode yeni yukarda olan şey
	}

	int height(Node<T> *subNode){
		if(subNode == NULL) return -1;
		return 1 + max(height(subNode->left), height(subNode->right));

	}

	void postorder(Node<T> *subnode){
		if(subnode != NULL){
			postorder(subnode->left);
			postorder(subnode->right);
			cout << subnode->data << " ";
		}
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
		Avl(){
			root = NULL;
		}
		void add(const T& item){
			root = searchAndAdd(root, item); 
		}
		int height(){
			return height(root);
		}

		void postorder(){
			postorder(root);
		}
		void clear(){
			clearTree(root);
		}
		~Avl(){
			clear();
		}
};

#endif

int hashfunc(const string &kelime) {
    int toplam = 0;

    for (int i = 0; i < kelime.length(); i++) {
        toplam += (int)kelime[i];
    }

    return toplam % 257;
}

