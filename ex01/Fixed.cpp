#include "Fixed.hpp"
#include <iostream>
#include <bitset>
#include <cmath>

const int	Fixed::fractional_bits = 8;

int	Fixed::getRawBits( void ) const {
	#ifdef DEBUG
	std::cout << "getRawBits func called" << std::endl;
	#endif
	return (this->fix);
}

void	Fixed::setRawBits( int const raw ) {
	#ifdef DEBUG
	std::cout << "setRawBits func called" << std::endl;
	#endif
	this->fix = raw;
}

Fixed::Fixed(): fix(0){
	#ifdef DEBUG
	std::cout << "default constructor called" << std::endl;
	#endif
}

Fixed::Fixed(const Fixed &fixed){
	#ifdef DEBUG
	std::cout << "copy constructor called" << std::endl;
	#endif
	*this = fixed;
}

static int	int_to_fixed(const int integer, const int fractional_bits){
	return (integer << fractional_bits);
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
	#ifdef DEBUG
	std::cout << "[int]copy constructor called" << std::endl;
	#endif
	setRawBits(int_to_fixed(integer, fractional_bits));
}

double	get_abs(double a){
	if (a < 0.0)
		return (-a);
	return (a);
}


Fixed::Fixed(float floating){
	#ifdef DEBUG
	std::cout << "[float]copy constructor called" << std::endl;
	#endif
	this->fix = roundf(floating * power(2, fractional_bits));
}

float	Fixed::toFloat( void ) const{
	return ((static_cast<float>(fix) / power(2, fractional_bits)));
}

int	Fixed::toInt( void ) const{
	return (fix / power(2, fractional_bits));
}

Fixed	&Fixed::operator=(const Fixed &other){
	#ifdef DEBUG
	std::cout << "copy assinment operator called" << std::endl;
	#endif
	if (this != &other)
		this->fix = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	#ifdef DEBUG
	std::cout << "Destructor called" << std::endl;
	#endif
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return (os);
}


// Fixed::Fixed(float floating){
// 	std::cout << "[float]copy constructor called" << std::endl;

// 	int		time = fractional_bits;
// 	double	i = 1.0 / 2.0;
// 	int		integer_part = int_to_fixed(static_cast<int>(floating), fractional_bits);
// 	int		fractional = 0;
// 	floating = get_abs(floating - static_cast<int>(floating));

// 	while (time && floating > 0.0f){
// 		if (floating >= i)
// 		{
// 			floating -= i;
// 			fractional = fractional | get_stand_bit(time);
// 		}
// 		i /= 2.0;
// 		time--;
// 	}
// 	if (floating >= 1.0 / power(2,  (fractional_bits - time) + 1))
// 		fractional += 1;
// 	this->fix = integer_part | fractional;
// }

// float	Fixed::toFloat( void ) const{
// 	int		integer_part = toInt();
// 	int		fractional_part = this->fix - int_to_fixed(integer_part, fractional_bits);

// 	int		i = fractional_bits;
// 	float	ret = 0;
// 	float	fr = 1.0 / 2.0;
// 	int		getter;

// 	while (i && fractional_part){
// 		getter = get_stand_bit(i);
// 		if (fractional_part & getter)
// 		{
// 			ret += fr;
// 			fractional_part -= getter;
// 		}
// 		fr /= 2.0;
// 		i--;
// 	}
// 	if (fix & 0x80000000)
// 	{
// 		ret = -ret;
// 		ret = integer_part - ret;
// 	}
// 	else
// 	{
// 		ret = integer_part + ret;
// 	}
// 	return (ret);
// }

// int	Fixed::toInt( void ) const{

// 	int	ret = fix;
// 	bool	is_minus;
// 	if (ret < 0)
// 	{
// 		// ret = -ret;
// 		ret = ret & 0x7FFFFFFF;
// 		is_minus = true;
// 	}
// 	else
// 		is_minus = false;
// 	ret = ret >> fractional_bits;
// 	if (is_minus)
// 		ret = -ret;
// 	return (ret);
// }


// static int	get_stand_bit(size_t position){
// 	if (position == 0)
// 		return (0);
// 	return (power(2, position - 1));
// }