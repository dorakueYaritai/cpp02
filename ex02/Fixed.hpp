# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	fix;
	static const int	fractional_bits;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int integer);
	Fixed(float floating);
	~Fixed();
	Fixed	&operator=(const Fixed &other);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		getFractionalBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	float				getFractionalPart( void ) const;
	// void				setFractionalBits( int bits );
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
bool	operator<(const Fixed& fix1, const Fixed& fix2);
bool	operator>(const Fixed& fix1, const Fixed& fix2);
bool	operator!=(const Fixed& fix1, const Fixed& fix2);
bool	operator==(const Fixed& fix1, const Fixed& fix2);
bool	operator<=(const Fixed& fix1, const Fixed& fix2);
bool	operator>=(const Fixed& fix1, const Fixed& fix2);
Fixed	operator+(const Fixed& fix1, const Fixed& fix2);
Fixed	operator-(const Fixed& fix1, const Fixed& fix2);
Fixed	operator*(const Fixed& fix1, const Fixed& fix2);
Fixed	operator/(const Fixed& fix1, const Fixed& fix2);
Fixed	&operator++(Fixed& fix1);
Fixed	operator++(Fixed& fix1, int);
Fixed	&operator--(Fixed& fix1);
Fixed	operator--(Fixed& fix1, int);

#endif