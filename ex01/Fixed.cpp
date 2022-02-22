#include "Fixed.hpp"

Fixed::Fixed() {
	_n = 0; 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int n) {
	_n = n << _fbits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	_n = roundf(f * (1 << _fbits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	_n = f.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return _n;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "getRawBits member function called" << std::endl;
	_n = raw;
}
std::ostream &operator << (std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return out;
}

int Fixed::toInt(void) const {
	return _n >> _fbits;
}

float Fixed::toFloat(void) const {
	    return ((float)_n / (float)(1 << _fbits));
}

