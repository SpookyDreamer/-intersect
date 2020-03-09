#include<stdio.h>
#include "Line.h"
#include "Point.h"

Line::Line(Point *point1, Point *point2)
{
	A = point2->getY() - point1->getY();
	B = point1->getX() - point2->getX();
	double tmp = point2->getX() * point1->getY();
	C = tmp - point1->getX() * point2->getY();
}

bool Line::isParallel(Line *line)
{
	//printf("%lf %lf,%lf %lf\n", A, B, line->A, line->B);
	return A * line->B == B * line->A;
}

Point *Line::intersect(Line *line)
{
	//((b1*c2-b2*c1)/(a1*b2-a2*b1)，(a2*c1-a1*c2)/(a1*b2-a2*b1))
	double tmp1 = B * line->C;
	double tmp2 = line->B * C;
	double tmp = tmp1 - tmp2;
	double x = tmp;
	tmp1 = A * line->B;
	tmp2 = line->A * B;
	tmp = tmp1 - tmp2;
	x = x / tmp;
	tmp1 = line->A * C;
	tmp2 = A * line->C;
	tmp = tmp1 - tmp2;
	double y = tmp;
	tmp1 = A * line->B;
	tmp2 = line->A * B;
	tmp = tmp1 - tmp2;
	y = y / tmp;
	Point *point = new Point(x, y);
	return point;
}
