#pragma once
#include <iostream>
#include <fstream>

class Point2D
{
public:
	Point2D(double inx, double iny) : x{ inx }, y{ iny } {};
	Point2D() : x{ 0 }, y{ 0 } {}

	void setCoordinates(double inx, double iny) { x = inx; y = iny; };

	double getX() const{ return x; };
	double getY() const { return y; };

	int operator==(const Point2D &p);

	friend std::ostream& operator<<(std::ostream& os, const Point2D&);
	friend std::istream& operator>>(std::istream& os, Point2D&);
	~Point2D() {};
private:
	double x;
	double y;

};
