#include <iostream>
#include "Fixed.hpp"

void	test1(void);
void	test2(void);
void	test3(void);
void	test4(void);
void	test5(void);

int main( void ) {
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}

void	test1(void){
// // マイナスでの挙動
	std::cout << "======= test1 =======" << std::endl;
	{
		Fixed a;
		// Fixed c( -0.1f );
		// a = Fixed( -0.2f );
		a = Fixed( -2.0f );
		Fixed c( -1.0f );
		std::cout << "a is " << a << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "a is " << (++a)-- << std::endl;
		std::cout << "c is " << (++c)-- << std::endl;
		std::cout << "a + c is " << (a + c) << std::endl;
		std::cout << "a + c - c is " << (a + c - c) << std::endl;
		std::cout << "a + c - c - a is " << (a + c - c - a) << std::endl;
		std::cout << "a / a is " << (a / a) << std::endl;
		std::cout << "a * a is " << (a * a) << std::endl;
		std::cout << "a * a * a is " << (a * a * a) << std::endl;
	}
}

void	test2(void){
	std::cout << "======= test2 (subject) =======" << std::endl;
	{
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
}

void	test3(void){
	std::cout << "======= test3 =======" << std::endl;
// // 浮動小数点の挙動 四捨五入など
	{
		Fixed a;
		Fixed c( 42.42f );
		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "a is " << ++a << std::endl;
		std::cout << "c is " << ++c << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	}
}

void	test4(void){
	std::cout << "======= test4 =======" << std::endl;
// 内部表現から見てみる
	{
		Fixed a;
		//             |       |        |
		a.setRawBits(0b10000000000000000000000000000000);
		std::cout << a << std::endl;
		std::cout << a.toInt() << std::endl;

		                                //  fractional
		            // |      ||      ||      ||      |
		a.setRawBits(0b10000000000000000000000010000000);
		std::cout << a << std::endl;
		std::cout << a.toInt() << std::endl;
	}
}

void	test5(void){
	std::cout << "---------- test5 -----------" << std::endl;
	Fixed a;
	a.setRawBits(0b10000000000000000000000000000000);
	std::cout << "a is " << a << std::endl;
	a.setRawBits(0xffffffff);
	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
}