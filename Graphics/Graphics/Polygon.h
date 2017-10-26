#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "line.h"

template <class T>
class Polygon
{
public:
	Polygon(std::vector<T> inPoints) : 
		points{ inPoints } {};

	Polygon(std::vector<T> inPoints, T inPoint) : 
		points{ inPoints } { points.push_back(inPoint); };

	Polygon(std::vector<T> inPointsA, std::vector<T> inPointsB) : points{ inPointsA }
	{
		for (T p : inPointsB) {
			points.push_back(p);
		}
	};

	Polygon() {};

	std::vector<T> getPoints() { return points; };

	void setPoints(std::vector<T> _points) { points = _points; };


	~Polygon() {};
	friend std::ostream& operator<<(std::ostream& os, const  Polygon &p);
	friend std::istream& operator>>(std::istream& is, Polygon &p);

	int operator==(const Polygon &p);
	Polygon operator=(const Polygon &py) {};

	friend Polygon operator+(Polygon &p1, Line &l);
	friend Polygon operator+(Polygon &p1, T &l);
	friend Polygon operator+(Polygon &p1, Polygon &p2);

private:
	std::vector<T> points;
};

