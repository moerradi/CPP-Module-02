#include "Point.hpp"

void isInside(Point a, Point b, Point c, Point p)
{
	std::cout << "p1: " << a.getX() << "," << a.getY() << std::endl;
	std::cout << "p2: " << b.getX() << "," << b.getY() << std::endl;
	std::cout << "p3: " << c.getX() << "," << c.getY() << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "Point (" << p.getX() << "," << p.getY() << ") is inside the triangle" << std::endl;
	else
		std::cout << "Point (" << p.getX() << "," << p.getY() << ") is outside the triangle" << std::endl;
}

int main( void ) {
	std::cout << "Example of point inside triangle" << std::endl;
	Point p1(0, 0);
	Point p2(0, 3);
	Point p3(3, 0);
	Point p4(1, 1);
	isInside(p1, p2, p3, p4);
	std::cout << "Example of point outside triangle" << std::endl;
	p1 = Point(0, 0);
	p2 = Point(0, 3);
	p3 = Point(3, 0);
	p4 = Point(4, 4);
	isInside(p1, p2, p3, p4);
	std::cout << "Example of point on edge" << std::endl;
	p1 = Point(0, 0);
	p2 = Point(0, 3);
	p3 = Point(3, 0);
	p4 = Point(1, 2);
	isInside(p1, p2, p3, p4);
	std::cout << "Example of point on vertex" << std::endl;
	p1 = Point(0, 0);
	p2 = Point(0, 3);
	p3 = Point(3, 0);
	p4 = Point(0, 0);
	isInside(p1, p2, p3, p4);
	return 0;
}