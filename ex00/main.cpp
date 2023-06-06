#include "Fixed.hpp"
#include <iostream>
int main( void ) {
	Fixed a;
	std::cout << "======" << std::endl;
	Fixed b( a );
	std::cout << "======" << std::endl;
	Fixed c;
	std::cout << "======" << std::endl;
	c = b;
	std::cout << "======" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}