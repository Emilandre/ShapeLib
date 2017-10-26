#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "line2D.h"

class Polygon2D
{
public:
	Polygon2D(std::vector<Point2D> inPoints) :
		points{ inPoints } {};
	Polygon2D(std::vector<Point2D> inPoints, Point2D inPoint);
	Polygon2D(std::vector<Point2D> inPointsA, std::vector<Point2D> inPointsB);
	Polygon2D();

	std::vector<Point2D> getPoints() const{ return points; };

	void setPoints( std::vector<Point2D> _points) { points = _points; };

	int operator==(const Polygon2D &p);
	Polygon2D operator=(const Polygon2D &py) {};
	friend Polygon2D operator+(const Line2D &p1, const Point2D &p2);
	friend Polygon2D operator+(const Point2D &p2, const Line2D &p1);
	friend Polygon2D operator+(const Line2D &l1, const Line2D &l2);
	friend Polygon2D operator+(Polygon2D &p1, Line2D &l);
	friend Polygon2D operator+(Polygon2D &p1, Point2D &l);
	friend Polygon2D operator+(Polygon2D &p1, Polygon2D &p2);

	friend std::ostream& operator<<(std::ostream& os, const  Polygon2D &p);
	friend std::istream& operator>>(std::istream& is, Polygon2D &p);

	~Polygon2D() {};

private:
	std::vector<Point2D> points;
};
