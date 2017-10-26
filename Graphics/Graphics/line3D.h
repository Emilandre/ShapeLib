#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "point3D.h"
class Line3D
{
public:
	Line3D(Point3D &p1, Point3D &p2)
		: points{ p1,p2 } {};

	Line3D(double x, double y, double z, double x2, double y2, double z2)
		: points{ Point3D(x,y,z), Point3D(x2,y2,z2) } {};

	Line3D()
		: points{ Point3D(), Point3D() } {};

	std::vector<Point3D> getPoints() const { return points; };

	int operator==(const Line3D &p) { return ((points[0] == p.points[0]) + (points[1] == p.points[1])); };
	friend Line3D operator+(Point3D &p1, Point3D &p2);

	friend std::ostream& operator<<(std::ostream& os, const  Line3D&);
	friend std::istream& operator>>(std::istream& is, Line3D &l);

	~Line3D() {};
private:
	std::vector<Point3D> points;
};


