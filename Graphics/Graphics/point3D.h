#pragma once
#include <iostream>
#include <fstream>

class Point3D
{
public:

	Point3D(double inx, double iny, double inz) : x{ inx }, y{ iny }, z{ inz } {};
	Point3D() : x{ 0 }, y{ 0 }, z{ 0} {}

	~Point3D() {};
	void setCoordinates(double inx, double iny, double inz) { x = inx; y = iny; z = inz; };

	double getX() const { return x; };
	double getY() const { return y; };
	double getZ() const { return z; };

	friend std::ostream& operator<<(std::ostream& os, const Point3D&);
	friend std::istream& operator>>(std::istream& os, Point3D&);

	int operator==(const Point3D &p);

private:

	double x;
	double y;
	double z;

};


