#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include  "Stack.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>

class Postfix{
	private:
		string ifade;

		bool oncelikKontrolu(char,char);
		void postfixeAktar(Stack<char>,string&);
		string infixtoPostFix(string);
		double stringtoDouble(string);
	public:
		Postfix(string);
		double hesapla();
		string getIfade();
		friend ostream& operator<<(ostream&, Postfix&);
		
};

#endif
