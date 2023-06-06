class Fixed
{
private:
	int	fix;
	static const int	fractional_bits;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed	&operator=(const Fixed &other);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
