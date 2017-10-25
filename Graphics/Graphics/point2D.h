#pragma once
#include <iostream>
#include <fstream>

class Point2D
{
public:
	Point2D(double inx, double iny) : x{ inx }, y{ iny } {};
	Point2D() : x{ 0 }, y{ 0 } {}

	~Point2D() {};
	void setCoordinates(double inx, double iny) { x = inx; y = iny; };
	const double &getX() { return x; };
	const double &getY() { return y; };

	friend std::ostream& operator<<(std::ostream& os, const Point2D&);
	friend std::istream& operator>>(std::istream& os, Point2D&);

	int operator==(const Point2D &p);
	friend auto operator+(Point2D &p1, Point2D &p2);
private:
	double x;
	double y;

};

