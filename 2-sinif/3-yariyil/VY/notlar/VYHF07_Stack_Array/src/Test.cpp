#include "Stack.hpp"

int main(){
	Stack<int> *yigit = new Stack<int>();

	yigit->push(100);
	yigit->push(200);
	yigit->push(300);
	yigit->pop();
	cout << yigit->top();
}