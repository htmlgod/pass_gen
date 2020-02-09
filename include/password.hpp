#pragma once 

#include <iostream>
#include <vector>
#include <symbol.hpp>

class Password {
private:
	std::vector<Symbol> _password;
	u_int 				_length;
public:
	explicit Password(u_int length);
	void print();
};
