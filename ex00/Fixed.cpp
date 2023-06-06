#include "Fixed.hpp"
#include <iostream>

const int	Fixed::fractional_bits = 8;

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits func called" << std::endl;
	return (this->fix);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits func called" << std::endl;
	this->fix = raw;
}

Fixed::Fixed(): fix(0){
	std::cout << "default constructor called" << std::endl;
}


Fixed	&Fixed::operator=(const Fixed &other){
	std::cout << "copy assinment operator called" << std::endl;
	if (this != &other)
		this->fix = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << "copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
