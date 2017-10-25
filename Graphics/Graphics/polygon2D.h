#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "line2D.h"

class Polygon2D
{
public:
	Polygon2D(std::vector<Point2D> inPoints);
	Polygon2D(std::vector<Point2D> inPoints, Point2D inPoint);
	Polygon2D(std::vector<Point2D> inPointsA, std::vector<Point2D> inPointsB);
	Polygon2D();

	std::vector<Point2D> getPoints() { return points; };

	void setPoints( std::vector<Point2D> _points) { points = _points; };


	~Polygon2D();
	friend std::ostream& operator<<(std::ostream& os, const  Polygon2D &p);
	friend std::istream& operator>>(std::istream& is, Polygon2D &p);

	int operator==(const Polygon2D &p);
	Polygon2D operator=(const Polygon2D &py) {};

	friend Polygon2D operator+(Polygon2D &p1, Line2D &l);
	friend Polygon2D operator+(Polygon2D &p1, Point2D &l);
	friend Polygon2D operator+(Polygon2D &p1, Polygon2D &p2);

private:
	std::vector<Point2D> points;
};

