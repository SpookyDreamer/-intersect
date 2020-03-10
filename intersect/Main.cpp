#pragma once

#include <vector>
#include <iostream>
#include "Line.h"
#include "Point.h"

int main()
{
	unsigned int count;
	std::cin >> count;
	std::vector<Line*> lines;
	std::vector<Point*> intersects;
	unsigned int i;
	for (i = 0; i < count; i++)
	{
		char type;
		double x1, y1, x2, y2;
		std::cin >> type;
		std::cin >> x1 >> y1 >> x2 >> y2;
		Point *point1 = new Point(x1, y1);
		Point *point2 = new Point(x2, y2);
		Line *line = new Line(point1, point2);
		unsigned int j;
		for (j = 0; j < lines.size(); j++)
		{
			if (line->isParallel(lines[j]))
			{
				continue;
			}
			Point *p = line->intersect(lines[j]);
			unsigned int k;
			bool flag = false;
			for (k = 0; k < intersects.size(); k++)
			{
				if (p->equals(intersects[k]))
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				intersects.push_back(p);
			}
		}
		lines.push_back(line);
	}
	std::wcout << intersects.size() << std::endl;
	return 0;
}
