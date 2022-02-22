#include "Point.hpp"

Point::Point() {
	this->_x = Fixed(0);
	this->_y = Fixed(0);
	// std::cout << "Point: Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) {
	this->_x = Fixed(x);
	this->_y = Fixed(y);
	// std::cout << "Point: Parametric constructor called" << std::endl;
}

Point::Point(Point const & src) {
	*this = src;
	// std::cout << "Point: Copy constructor called" << std::endl;
}

Point &Point::operator=(Point const & rhs) {
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	// std::cout << "Point : Copy assignation operator called" << std::endl;
	return (*this);
}

Point::~Point(void) {
	// std::cout << "Point: destructor called" << std::endl;
	return ;
}

Fixed Point::getX(void) const {
	return this->_x;
}

Fixed Point::getY(void) const {
	return this->_y;
}

