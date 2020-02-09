#include <symbol.hpp>

u_int Symbol::generateCode() {
	std::random_device rd;
	std::mt19937 mersenne(rd());

	u_int code = (mersenne() % 127) + 33;
	if (code > 126) 
		code -= 33;

	return code;
}

Symbol::Symbol() {
	this->_code = generateCode();
	this->_symbol = static_cast<char>(_code);
}
char Symbol::getChar() {
	return this->_symbol;
}
