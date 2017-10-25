#include "stdafx.h"
#include "polygon2D.h"

Polygon2D::Polygon2D(std::vector<Point2D> inPoints) {
	points = inPoints;
}

Polygon2D::Polygon2D(std::vector<Point2D> inPoints, Point2D inPoint) {
	points = inPoints;
	points.push_back(inPoint);
}

Polygon2D::Polygon2D(std::vector<Point2D> inPointsA, std::vector<Point2D> inPointsB) {
	for (Point2D &p : inPointsA) {
		points.push_back(p);
	}
	for (Point2D &p : inPointsB) {
		points.push_back(p);
	}
}

Polygon2D::Polygon2D() {
	for (int i = 0; i < 3; i++) {
		points.push_back(Point2D());
	}
}

int Polygon2D::operator==(const Polygon2D &py) {
	if (points.size() == py.points.size()) {
		for (int i = 0; i < points.size(); i++) {
			if (!(points[i] == py.points[i])) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

Polygon2D::~Polygon2D()
{
}


