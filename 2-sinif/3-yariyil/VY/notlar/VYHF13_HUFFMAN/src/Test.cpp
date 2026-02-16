#include "Huffman.hpp"

int main(){
	Huffman * huffman = new Huffman("Data.txt");
	huffman->encode();
	cout << *huffman;
	return 0;
}