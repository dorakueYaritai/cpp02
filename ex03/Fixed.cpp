#include "Fixed.hpp"
#include <iostream>
#include <bitset>
#include <cmath>

const int	Fixed::fractional_bits = 8;

int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits func called" << std::endl;
	return (this->fix);
}

int	Fixed::getFractionalBits( void ) const {
	return (this->fractional_bits);
}

void	Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits func called" << std::endl;
	this->fix = raw;
}

Fixed::Fixed(): fix(0){
	// std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
	// std::cout << "copy constructor called" << std::endl;
	*this = fixed;
}

static int	power_sub(int base, size_t times, int product){
	if (times == 0)
		return (1);
	else if (times == 1)
		return (product);
	else
		return (power_sub(base, times - 1, product * base));
}

static int	power(int base, size_t times){
	return (power_sub(base, times, base));
}

Fixed::Fixed(const int integer){
	// std::cout << "[int]copy constructor called" << std::endl;
	this->fix = integer * power(2, fractional_bits);
}

double	get_abs(double a){
	if (a < 0.0)
		return (-a);
	return (a);
}

Fixed::Fixed(float floating){
	// std::cout << "[float]copy constructor called" << std::endl;
	this->fix = roundf(floating * power(2, fractional_bits));
}

float	Fixed::toFloat( void ) const{
	return ((static_cast<float>(fix) / power(2, fractional_bits)));
}

int	Fixed::toInt( void ) const{
	return (fix / power(2, fractional_bits));
}

Fixed	&Fixed::operator=(const Fixed &other){
	// std::cout << "copy assinment operator called" << std::endl;
	if (this != &other)
		this->fix = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return (os);
}

bool	operator<(const Fixed& fix1, const Fixed& fix2){
	int	differ = fix1.getFractionalBits() - fix2.getFractionalBits();
	if (differ == 0)
		return (fix1.getRawBits() < fix2.getRawBits());

	int	fix1_int = fix1.toInt();
	int	fix2_int = fix2.toInt();
	if (fix1_int != fix2_int)
		return (fix1_int < fix2_int);

	int	fract1 = fix1.getRawBits() & (power(2, fix1.getFractionalBits()) - 1);
	int	fract2 = fix2.getRawBits() & (power(2, fix2.getFractionalBits()) - 1);
	if (differ < 0)
		fract1 = fract1 << -differ;
	else if (differ > 0)
		fract2 = fract2 << differ;
	return (fract1 < fract2);
}

bool	operator>(const Fixed& fix1, const Fixed& fix2){
	int	differ = fix1.getFractionalBits() - fix2.getFractionalBits();
	if (differ == 0)
		return (fix1.getRawBits() > fix2.getRawBits());

	int	fix1_int = fix1.toInt();
	int	fix2_int = fix2.toInt();

	if (fix1_int != fix2_int)
		return (fix1_int > fix2_int);

	int	fract1 = fix1.getRawBits() & (power(2, fix1.getFractionalBits()) - 1);
	int	fract2 = fix2.getRawBits() & (power(2, fix2.getFractionalBits()) - 1);
	if (differ > 0)
		fract1 = fract1 << -differ;
	else if (differ > 0)
		fract2 = fract2 << differ;
	return (fract1 > fract2);
}

bool	operator==(const Fixed& fix1, const Fixed& fix2){
	int	differ = fix1.getFractionalBits() - fix2.getFractionalBits();
	if (differ == 0)
		return (fix1.getRawBits() == fix2.getRawBits());

	int	fix1_int = fix1.toInt();
	int	fix2_int = fix2.toInt();

	if (fix1_int != fix2_int)
		return (false);

	int	fract1 = fix1.getRawBits() & (power(2, fix1.getFractionalBits()) - 1);
	int	fract2 = fix2.getRawBits() & (power(2, fix2.getFractionalBits()) - 1);
	if (differ > 0)
		fract1 = fract1 << -differ;
	else if (differ > 0)
		fract2 = fract2 << differ;
	return (fract1 == fract2);
}

bool	operator<=(const Fixed& fix1, const Fixed& fix2){
	return (fix1 < fix2 || fix1 == fix2);
}

bool	operator>=(const Fixed& fix1, const Fixed& fix2){
	return (fix1 > fix2 || fix1 == fix2);
}

bool	operator!=(const Fixed& fix1, const Fixed& fix2){
	return (!(fix1 == fix2));
}

// fractional bits が異なってた場合、小さい方に合わせる
Fixed	operator+(const Fixed& fix1, const Fixed& fix2){
	// std::cout << "operator+ called" << std::endl;
	Fixed	result;
	result.setRawBits(fix1.getRawBits() + fix2.getRawBits());
	return (result);
	// Fixed	result;
	// int		differ = fix1.getFractionalBits() - fix2.getFractionalBits();
	// if (differ > 0) // fix1のfractional bitsの方が大きい
	// {
	// 	result.setFractionalBits(fix2.getFractionalBits());
	// 	return (fix2.getrawbits() + (fix1.getrawbits() >> differ));
	// }
	// else
	// {
	// 	result.setFractionalBits(fix1.getFractionalBits());
	// 	return (fix1.getrawbits() + (fix2.getrawbits() >> -differ));
	// }
}

Fixed	operator-(const Fixed& fix1, const Fixed& fix2){
	// std::cout << "operator+ called" << std::endl;
	Fixed	result;
	result.setRawBits(fix1.getRawBits() - fix2.getRawBits());
	return (result);
	// Fixed	result;
	// int		differ = fix1.getFractionalBits() - fix2.getFractionalBits();
	// if (differ > 0) // fix1のfractional bitsの方が大きい
	// {
	// 	result.setFractionalBits(fix2.getFractionalBits());
	// 	return ((fix1.getrawbits() >> differ) - fix2.getrawbits());
	// }
	// else
	// {
	// 	result.setFractionalBits(fix1.getFractionalBits());
	// 	return (fix1.getrawbits() - (fix2.getrawbits() >> -differ));
	// }
}

Fixed	operator*(const Fixed& fix1, const Fixed& fix2){
	// std::cout << "operator* called" << std::endl;
	long	fix1_long = fix1.getRawBits();
	long	fix2_long = fix2.getRawBits();
	long	result_long = fix1_long * fix2_long / power(2, fix2.getFractionalBits());
	Fixed	result;
	int		result_int = result_long;
	result.setRawBits(result_int);
	// result = Fixed(result_int);

	return (result);
}

Fixed	operator/(const Fixed& fix1, const Fixed& fix2){
	// std::cout << "operator/ called" << std::endl;
	Fixed	result;
	result = Fixed(fix1.getRawBits() / fix2.getRawBits());
	return (result);
}

Fixed	&operator++(Fixed& fix1){
	fix1.setRawBits(fix1.getRawBits() + 1);
	return (fix1);
}

Fixed	operator++(Fixed& fix1, int){
	Fixed	temp = fix1;
	fix1.setRawBits(fix1.getRawBits() + 1);
	return (temp);
}

Fixed	&operator--(Fixed& fix1){
	fix1.setRawBits(fix1.getRawBits() - 1);
	return (fix1);
}

Fixed	operator--(Fixed& fix1, int){
	Fixed	temp = fix1;
	fix1.setRawBits(fix1.getRawBits() - 1);
	return (temp);
}
