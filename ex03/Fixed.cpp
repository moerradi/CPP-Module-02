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
	if (this != &f)
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

Fixed & Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}

bool Fixed::operator==(const Fixed &f) const {
	return (_n == f.getRawBits());
}

bool Fixed::operator!=(const Fixed &f) const {
	return _n != f.getRawBits();
}

bool Fixed::operator>(const Fixed &f) const {
	return _n > f.getRawBits();
}

bool Fixed::operator<(const Fixed &f) const {
	return _n < f.getRawBits();
}

bool Fixed::operator>=(const Fixed &f) const {
	return _n >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed &f) const {
	return _n <= f.getRawBits();
}

Fixed Fixed::operator+(const Fixed &f) {
	Fixed res;
	res._n = _n + f.getRawBits();
	return res;
}

Fixed Fixed::operator-(const Fixed &f) {
	Fixed res;
	res._n = _n - f.getRawBits();
	return res;
}

Fixed Fixed::operator*(const Fixed &f) {
	Fixed res;
	res.setRawBits((_n * f.getRawBits()) >> _fbits);
	return res;   
}

Fixed Fixed::operator/(const Fixed &f) {
	Fixed res;
	res.setRawBits((_n << _fbits) / f.getRawBits());
	return res;
}

Fixed Fixed::operator++(void) {
	++_n;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed res = *this;
	_n++;
	return res;
}

Fixed Fixed::operator--(void) {
	--_n;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed res = *this;
	_n--;
	return res;
}

