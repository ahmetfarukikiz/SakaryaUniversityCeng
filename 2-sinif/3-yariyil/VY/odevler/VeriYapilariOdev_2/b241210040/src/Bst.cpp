/**
* @file Bst.cpp
* @description gelen verileri bst mantığına göre sıralayan ve postorder mantığına göre silip veri bilgisini döndüren ağaç sınıfı
* @course 1.Öğretim B Grubu
* @assignment 2.Ödev
* @date 4.12.2025
* @author Ahmet Faruk ikiz faruk.ikiz@ogr.sakarya.edu.tr
*/

#include "Bst.hpp"
#include <algorithm> // max fonksiyonu için gerekli

Bst::Bst() {
    root = NULL;
    length = 0;
}

Bst::~Bst() {
    clear();
}

BstNode *Bst::getRoot()
{
	return root;
}

int Bst::count()
{
	return length;
}

bool Bst::isEmpty() {
    return root == NULL;
}

void Bst::add(int item) {
    searchAndAdd(root, item);
}

void Bst::searchAndAdd(BstNode*& subNode, int item) {
    if (subNode == NULL) {
        subNode = new BstNode(item);
        length++;
    }
    else if (item <= subNode->data) {
        searchAndAdd(subNode->left, item);
    }
    else if (item > subNode->data) {
        searchAndAdd(subNode->right, item);
    }
    else return;
}


void Bst::postordersil(int* geciciDizi) {
    int index = 0; 
    postordersil(root, geciciDizi, index); 
}

//dizi mantığıyla yap //kontrol
void Bst::postordersil(BstNode*& subNode, int* geciciDizi, int& index) {
    if (subNode != NULL) {
        postordersil(subNode->left, geciciDizi, index);
        postordersil(subNode->right, geciciDizi, index);
        geciciDizi[index] = subNode->data;
        index++;
        
        delete subNode; // postordersil sil
        length--;
        subNode = NULL;
    }
}

int Bst::height() {
    return height(root);
}

int Bst::height(BstNode* subNode) {
    if (subNode == NULL) return -1;
    return 1 + max(height(subNode->left), height(subNode->right));
}

void Bst::clear() {
    clearTree(root);
}

void Bst::clearTree(BstNode*& subNode) {
    if (subNode != NULL) {
        clearTree(subNode->left);
        clearTree(subNode->right);
        delete subNode;
        subNode = NULL;
    }
}