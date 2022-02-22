#include "Point.hpp"

Fixed surface(Point p1, Point p2, Point p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool PointInTriangle (Point v1, Point v2, Point v3, Point pt)
{
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = surface(pt, v1, v2);
    d2 = surface(pt, v2, v3);
    d3 = surface(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}