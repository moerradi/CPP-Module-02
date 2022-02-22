#ifndef __POINT_HPP__
# define __POINT_HPP__
#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float x, const float y);
		Point(Point const & src);
		~Point(void);

		Point &		operator=(Point const & rhs);
		Fixed		getX(void) const;
		Fixed		getY(void) const;
	private:
		Fixed		_x;
		Fixed		_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif