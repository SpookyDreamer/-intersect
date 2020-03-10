#include "Point.h"

Point::Point(double xAxis, double yAxis)
{
	x = xAxis;
	y = yAxis;
}

double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

bool Point::equals(Point *point)
{
	return x == point->x && y == point->y;
}
