#include "Line.h"
#include "Point.h"

Line::Line(Point *point1, Point *point2)
{
	A = point2->getY() - point1->getY();
	B = point1->getX() - point2->getX();
	const double tmp = point2->getX() * point1->getY();
	C = tmp - point1->getX() * point2->getY();
}

bool Line::isParallel(Line *line)
{
	return A * line->B == B * line->A;
}

Point *Line::intersect(Line *line)
{
	//((b1*c2-b2*c1)/(a1*b2-a2*b1)，(a2*c1-a1*c2)/(a1*b2-a2*b1))
	double x = (B * line->C - line->B * C) / (A * line->B - line->A * B);
	double y = (line->A * C- A * line->C)/(A * line->B- line->A * B);
	Point *point = new Point(x, y);
	return point;
}
