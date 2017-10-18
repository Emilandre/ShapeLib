#pragma once
#include <iostream>
#include <fstream>
#include "point2D.h"
class Line2D
{
public:
	Line2D(Point2D &p1, Point2D &p2) 
		: start{ &p1 }, end{ &p2 } {};

	Line2D(double x, double y, double x2, double y2) 
		: start{ new Point2D(x,y) }, end{ new Point2D(x2,y2) } {};

	Line2D() 
		: start{ new Point2D}, end{ new Point2D } {};

	 Point2D &getStart() { return *start; };
	 Point2D &getEnd() { return *end; };

	~Line2D();
	friend auto operator+( Line2D &p1,  Point2D &p2);
	friend auto operator+(Line2D &l1, Line2D &l2);
	int operator==(const Line2D &p) { return ((*start == *p.start) + (*end == *p.end)); };

	friend std::ostream& operator<<(std::ostream& os, const  Line2D);
	friend std::istream& operator>>(std::istream& is, Line2D &l);

private:
	Point2D *start;
	Point2D *end;
};


