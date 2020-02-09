#include <password.hpp>

Password::Password(u_int length) {
	this->_length = length;
	for (u_int i = 0; i < this->_length; i++) 
		this->_password.emplace_back();
}
void Password::print() {
	for(auto& x : this->_password) {
		std::cout << x.getChar();
	}
	std::cout << std::endl;
}
