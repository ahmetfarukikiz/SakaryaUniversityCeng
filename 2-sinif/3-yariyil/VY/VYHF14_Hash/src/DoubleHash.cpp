#include "DoubleHash.hpp"

DoubleHash::DoubleHash()
{
	Table = new int[MAX];
	clear();
}

int DoubleHash::hashfunc1(int data)
{
	return data % MAX;
}

int DoubleHash::hashfunc2(int data)
{
	return R - (data % R);
}

void DoubleHash::add(int data)
{
	if(length == MAX) throw "Table is full";
	if(find(data)) return;
	int index = hashfunc1(data);
	//çarpışma varsa
	if(Table[index] !=-1){ 
		int step = hashfunc2(data);
		int i = 1;
		while(true){
			int newIndex = (index+i*step)%MAX; //buraya tekrar bak
			if(Table[newIndex] == -1){
				Table[newIndex] = data;
				if(i > maxStep) maxStep = i;
				break;
			}
			i++;
		}
	}
	else{
		Table[index] = data;
	}
	length++;
}

bool DoubleHash::find(int data)
{
	if(length == 0) return false;
	int index = hashfunc1(data);
	if(Table[index] == data) return true;
	int step = hashfunc2(data); //çarpışma olduysa
	int i = 0;
	while(i<=maxStep){
		int newIndex = (index+i*step)%MAX; //buraya tekrar bak
		if(Table[newIndex] == data) return true;
		i++; 
	}
	return false;
}

void DoubleHash::clear()
{
	//Varsayım yapıyoruz yoksa bir dizi daha kullanmamız gerekir
	//sadece pozitif sayı eklenebilir diyip -1 i ayraç olarak kabul ediyoruz.
	length = 0;
	maxStep = 0;
	for (int i = 0; i < MAX; i++)
	{
		Table[i] = -1;
	}
	
}

void DoubleHash::print()
{
	for(int i=0; i<MAX;i++){
		if(Table[i]!=-1) cout << "["<<Table[i] << "]" << endl;
		else cout << "[ ]" << endl;
	}
}

DoubleHash::~DoubleHash()
{
	delete [] Table;
}
