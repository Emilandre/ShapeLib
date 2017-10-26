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

	const double &getX() { return x; };
	const double &getY() { return y; };
	const double &getZ() { return z; };

	friend std::ostream& operator<<(std::ostream& os, const Point3D &p);
	friend std::istream& operator>>(std::istream& os, Point3D&) {};

	int operator==(const Point3D &p);
	friend auto operator+(Point3D &p1, Point3D &p2) {};

private:

	double x;
	double y;
	double z;

};

