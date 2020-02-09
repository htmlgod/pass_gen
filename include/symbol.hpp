#pragma once 
#include <string>
#include <random>

using u_int = unsigned int;

class Symbol {
private:
	u_int _code;
	char  _symbol;
	u_int generateCode();
public:
	Symbol();
	Symbol generateSymbol();
	char getChar();
};


