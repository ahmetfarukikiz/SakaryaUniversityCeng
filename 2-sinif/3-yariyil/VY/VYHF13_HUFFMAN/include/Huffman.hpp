#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <fstream>
#include <cstring>
#include "Node.hpp"

class Huffman{ //ASCII'ye göre
	private:
		int chars; //256
		string content; //dosya içeriği
		Node *root;
		Node* createTree(int freq[]);
		void createCodes(Node*, string);
		int minNodeIndex(Node* trees[]);
		void readFile(string);
		void inorder(Node* ,ostream&); //birini seçiyoruz
		void removeTree(Node*&); //çöp kalmaması için
	public:
		Huffman(string);
		void encode();
		friend ostream& operator<<(ostream&, Huffman&);
		~Huffman();


};

#endif