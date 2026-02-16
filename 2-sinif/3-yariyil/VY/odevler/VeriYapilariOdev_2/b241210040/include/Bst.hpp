#ifndef BST_HPP
#define BST_HPP

#include "BstNode.hpp"
#include <iostream>

using namespace std;

class Bst {
private:
    BstNode* root;
    int length;

    void searchAndAdd(BstNode*& subNode, int item);
    void postordersil(BstNode*& subNode, int* gecdizi, int& index);
    int height(BstNode* subNode);
    void clearTree(BstNode*& subNode);

public:
    Bst();
    ~Bst();
    BstNode* getRoot();
    int count();
    bool isEmpty();
    void add(int item);
    void postordersil(int* gecdizi);
    int height();
    void clear();
};

#endif