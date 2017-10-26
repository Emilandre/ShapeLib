#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "line3D.h"

class Polygon3D
{
public:
	Polygon3D(std::vector<Point3D> inPoints) :
		points{ inPoints } {};
	Polygon3D(std::vector<Point3D> inPoints, Point3D inPoint);
	Polygon3D(std::vector<Point3D> inPointsA, std::vector<Point3D> inPointsB);
	Polygon3D();

	std::vector<Point3D> getPoints() const { return points; };

	void setPoints(std::vector<Point3D> _points) { points = _points; };

	int operator==(const Polygon3D &p);
	Polygon3D operator=(const Polygon3D &py) {};
	friend Polygon3D operator+(const Line3D &p1, const Point3D &p2);
	friend Polygon3D operator+(const Point3D &p2, const Line3D &p1);
	friend Polygon3D operator+(const Line3D &l1, const Line3D &l2);
	friend Polygon3D operator+(Polygon3D &p1, Line3D &l);
	friend Polygon3D operator+(Polygon3D &p1, Point3D &l);
	friend Polygon3D operator+(Polygon3D &p1, Polygon3D &p2);

	friend std::ostream& operator<<(std::ostream& os, const  Polygon3D &p);
	friend std::istream& operator>>(std::istream& is, Polygon3D &p);

	~Polygon3D() {};

private:
	std::vector<Point3D> points;
};
