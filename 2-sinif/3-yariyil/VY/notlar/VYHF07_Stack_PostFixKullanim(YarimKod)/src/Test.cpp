#include "Stack.hpp"

int main(){
	Stack<int> *yigit = new Stack<int>();

	yigit->push(100);
	yigit->push(2020);
	yigit->push(400);
	yigit->pop();
	cout << yigit->top();
}