#include "Point.hpp"


//determine on which side of the line p2,p2 the point (p1) is
Fixed sign (Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

	// position of point in half plane created by ab
    d1 = sign(point, a, b);
	// position of point in half plane created by bc
    d2 = sign(point, b, c);
	// position of point in half plane created by ac
    d3 = sign(point, c, a);
    has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
    has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);
	// if point is in the same side of all half planes, it is inside the triangle
    return !(has_neg && has_pos);
}