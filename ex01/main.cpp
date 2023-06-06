#include "Fixed.hpp"
#include <iostream>
#include <bitset>
#include <iostream>

void	test1(void);
void	test2(void);
void	test3(void);

int main( void ) {
	test1();
	test2();
	// test3();
	return 0;
}

void	test1(void){
	std::cout << "---------- test1 -----------" << std::endl;
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	test2(void){
	std::cout << "---------- test2 -----------" << std::endl;
		Fixed a;
		Fixed const b( -10 );
		Fixed const c( -42.42f );
		Fixed const d( b );
		a = Fixed( -1234.4321f );
		std::cout << "a is " << a.toFloat() << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	test3(void){
	std::cout << "---------- test3 -----------" << std::endl;
	Fixed a;
	a.setRawBits(0xffffffff);
	std::cout << "a is " << a.toFloat() << std::endl;
	a.setRawBits(0b11100000000000000000000000000000);
	std::cout << "a is " << a.toFloat() << std::endl;
}