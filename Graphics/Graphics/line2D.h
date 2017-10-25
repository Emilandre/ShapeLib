#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "point2D.h"
class Line2D
{
public:
	Line2D(Point2D &p1, Point2D &p2) 
		: points{ p1,p2 } {};

	Line2D(double x, double y, double x2, double y2) 
		: points{ Point2D(x,y), Point2D(x2,y2) } {};

	Line2D() 
		: points{ Point2D(), Point2D() } {};
	 	
	std::vector<Point2D> &getPoints() { return points; };

	~Line2D();
	friend auto operator+( const Line2D &p1,  const Point2D &p2);
	friend auto operator+(const Line2D &l1, const Line2D &l2);
	int operator==(const Line2D &p) { return ((points[0] == p.points[0]) + (points[1] == p.points[1])); };
	
	friend std::ostream& operator<<(std::ostream& os, const  Line2D&);
	friend std::istream& operator>>(std::istream& is, Line2D &l);

private:
	std::vector<Point2D> points;
};


