#include "Node.hpp"

Node::Node(char character, int freq, Node* left, Node* right){
	this->character=character;
	this->freq = freq;
	this->left = left;
	this->right = right;
	this->code = "";
}

bool Node::isLeaf()
{
	return left == NULL && right == NULL;
}

bool Node::operator==(Node& rhs){
	return this->character == rhs.character;
}

bool Node::operator!=(Node& rhs){
	return this->character != rhs.character;
}

bool Node::operator>(Node& rhs){ //frequence'a göre
	return this->freq > rhs.freq;
}
