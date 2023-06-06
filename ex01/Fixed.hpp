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
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif