#include "Huffman.hpp"

Node *Huffman::createTree(int freq[])
{
	Node *trees[chars];
	for (int i = 0; i < chars; i++)
	{
		if (freq[i] > 0)
		{
			trees[i] = new Node((char)i, freq[i]);
		}
		else
		{
			trees[i] = NULL;
		}
	}
	while (true)
	{
		int minIndex1 = minNodeIndex(trees); // küçüklerin ilkini bulduk
		Node *min1 = trees[minIndex1];
		trees[minIndex1] = NULL;
		int minIndex2 = minNodeIndex(trees);
		if (minIndex2 == -1)
			return min1;
		Node *min2 = trees[minIndex2];
		trees[minIndex2] = new Node(' ', min1->freq + min2->freq, min1, min2); // min1 miin2 den daha küçük
	}
}

void Huffman::createCodes(Node *subNode, string code)
{
	if (subNode == NULL)
		return; // durma noktası
	if (subNode->isLeaf())
	{
		subNode->code = code;
	}
	else
	{
		createCodes(subNode->left, code + '0');
		createCodes(subNode->right, code + '1');
	}
}

int Huffman::minNodeIndex(Node *trees[])
{
	Node *min;
	int minIndex = -1;
	for (int i = 0; i < chars; i++)
	{ // ilk gelen değeri küçük kabule et;
		if (trees[i] != NULL)
		{
			min = trees[i];
			minIndex = i;
			break;
		}
	}
	for (int i = 0; i < chars; i++)
	{
		if (trees[i] == NULL)
			continue;
		if (*min > *(trees[i]))
		{
			min = trees[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void Huffman::readFile(string fileName)
{
	string row;
	ifstream fl(fileName);

	if (fl.is_open())
	{
		while (getline(fl, row))
		{
			content += row;
			content += "\n";
		}
	}
	fl.close();
}

void Huffman::inorder(Node *subNode, ostream &screen)
{
	if (subNode != NULL)
	{
		inorder(subNode->left, screen);
		if (subNode->isLeaf())
			screen << subNode->character << ":" << subNode->code << endl;
		inorder(subNode->right, screen);
	}
}

void Huffman::removeTree(Node *&subNode)
{
	if (subNode != NULL)
	{
		removeTree(subNode->left);
		removeTree(subNode->right);
		delete subNode;
		subNode = NULL;
	}
}

Huffman::Huffman(string fileName)
{
	chars = 256;
	content = "";
	readFile(fileName);
	root = NULL;
}

void Huffman::encode()
{
	char charsArray[content.size() - 1];
	strcpy(charsArray, content.c_str()); // char pointer olarak istediği için c_str ile char pointera dönüştürür
	int freq[chars];
	for (int i = 0; i < chars; i++)
		freq[i] = 0;
	for (int i = 0; i < content.size() - 1; i++)
	{
		freq[charsArray[i]]++;
	}
	root = createTree(freq);

	createCodes(root, "");
}

Huffman::~Huffman()
{
	removeTree(root);
}

ostream &operator<<(ostream &screen, Huffman &rhs)
{
	screen << "Huffman Codelari:" << endl;
	rhs.inorder(rhs.root, screen);

	return screen;
}
