#include "Fixed.hpp"

Fixed::Fixed() {
	_n = 0; 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
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
	std::cout << "getRawBits member function called" << std::endl;
	return _n;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "getRawBits member function called" << std::endl;
	_n = raw;
}