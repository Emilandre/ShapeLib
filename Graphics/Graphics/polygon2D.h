#pragma once
#include <iostream>
#include <fstream>
#include "point2D.h"

class Polygon2D
{
public:
	Polygon2D(Point2D *inpoints, int innumPoints);
	Polygon2D();
	Polygon2D(Point2D, Point2D, Point2D);
	Polygon2D(Polygon2D &py);

	Point2D* getPoints() { return points; };
	const int& getNumPoints() { return numPoints; };
	void setPoints(Point2D* _points) { delete[] points; points = _points; };
	void setNumPoints(int newNum) { numPoints = newNum; };


	~Polygon2D();
	friend std::ostream& operator<<(std::ostream& os, const  Polygon2D &p);
	friend std::istream& operator>>(std::istream& is, Polygon2D &p);

	int operator==(const Polygon2D &p);
	Polygon2D operator=(const Polygon2D &py);
	friend Polygon2D operator+(Polygon2D &p1, Polygon2D &p2);

private:
	Point2D *points;
	int numPoints;
};

