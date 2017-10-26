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
	 	
	 std::vector<Point2D> getPoints() const { return points; };

	int operator==(const Line2D &p) { return ((points[0] == p.points[0]) + (points[1] == p.points[1])); };
	friend Line2D operator+(Point2D &p1, Point2D &p2);

	friend std::ostream& operator<<(std::ostream& os, const  Line2D&);
	friend std::istream& operator>>(std::istream& is, Line2D &l);
	
	~Line2D() {};
private:
	std::vector<Point2D> points;
};


