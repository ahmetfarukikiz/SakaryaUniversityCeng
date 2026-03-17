#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
	
    BstNode(int value);
};

#endif