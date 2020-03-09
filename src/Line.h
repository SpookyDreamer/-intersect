#pragma once

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
class Point;

class Line
{
private:
	double A = 0;
	double B = 0;
	double C = 0;

public:
	Line(Point *point1, Point *point2);

	virtual bool isParallel(Line *line);

	virtual Point *intersect(Line *line);
};
