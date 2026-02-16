#include "OpenHash.hpp"

OpenHash::OpenHash(){
	for(int i = 0; i <MAX;i++){
		Table[i] = NULL;
	}
}

int OpenHash::hashfunc(int data)
{
	return data % MAX;
}

void OpenHash::add(int data)
{
	if(find(data)) return;
	int index = hashfunc(data);
	//veriyi başa ekle kalan listeyi sonuna ekle
	Table[index] = new Node(data,Table[index]);

}

void OpenHash::deleteData(int data)
{
	int index = hashfunc(data);
	if(Table[index] == NULL) throw "Item not found";
	//ilk item siliniyorsa
	if(Table[index]->data == data){
		Node* tmp = Table[index];
		Table[index] = Table[index]->next;
		delete tmp;
		return;
	}
	//aradan siliniyorsa
	Node *p = Table[index];
	while(p->next != NULL){
		if(p->next->data == data){
			Node* tmp = p->next;
			p->next = tmp->next;
			delete tmp;
			return;
		}
		p = p->next;
	}
	throw "Item not found";
}

void OpenHash::clear()
{
	for(int i = 0; i<MAX; i++){
		Node*tmp = Table[i];
		while(tmp!=NULL){
			Node *p = tmp;
			tmp=tmp->next;
			delete p;
		}
		Table[i] = NULL;
	}
}

bool OpenHash::find(int data)
{
	int index = hashfunc(data);
	Node* tmp = Table[index];
	while(tmp != NULL){
		if(tmp->data == data) return true;
		tmp=tmp->next;
	}
	return false;
}

bool OpenHash::isEmpty()
{
	for(int i = 0; i< MAX; i++){
		if(Table[i] != NULL) return false;
	}
	return true;
}

void OpenHash::print()
{
	for(int index = 0; index < MAX; index++){ //bir sonraki index
		Node *tmp = Table[index];
		cout << "["<<index<<"]->";
		while(tmp != NULL){ //tabloyu yaz
			cout << tmp->data<< "->";
			tmp= tmp->next;
		}
		cout << "NULL" << endl;
	}
}

OpenHash::~OpenHash()
{
	clear();
}
