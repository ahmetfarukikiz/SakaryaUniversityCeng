#include "Postfix.hpp"

		bool Postfix::oncelikKontrolu(char op1,char op2){
			if(op1 == '(') return false;
			else if(op2 == '(') return false;
			else if(op2 == '(') return true;

			else if(op1 == '*' || op1 == '/') return true;
			else if(op2 == '*' || op2 == '/') return false;

		}
		void Postfix::postfixeAktar(Stack<char> stack,string& postfixIfade){}
		string Postfix::infixtoPostFix(string infix){
			int uzunluk = infix.length();
			Stack<char> *stack = new Stack<char>();
			string postfixIfade = "";
			for(int i = 0; i< uzunluk; i++){
				if(isdigit(infix[i])){
					while(isdigit(infix[i])){
						postfixIfade += " ";
					}
					i--;
				}
				else if(infix[i] == '(') {

				}
				else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*') {

				}
				else if(infix[i] == ')'){

				}
			}
		}
		double Postfix::stringtoDouble(string){}

		Postfix::Postfix(string){}
		double Postfix::hesapla(){}
		string Postfix::getIfade(){}
		friend ostream& operator<<(ostream&, Postfix&){}