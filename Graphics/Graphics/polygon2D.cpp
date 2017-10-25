#include "stdafx.h"
#include "polygon2D.h"

Polygon2D::Polygon2D(Point2D *inpoints, int innumPoints) {
	points = inpoints;
	numPoints = innumPoints;
}

Polygon2D::Polygon2D() {
	points = new Point2D[3];
	numPoints = 3;
	points[0] = Point2D();
	points[1] = Point2D();
	points[2] = Point2D();
}

Polygon2D::Polygon2D(Point2D p1, Point2D p2, Point2D p3) {
	points = new Point2D[3];
	numPoints = 3;
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	
}

int Polygon2D::operator==(const Polygon2D &p) {
	if (numPoints == p.numPoints) {
		for (int i = 0; i < numPoints; i++) {
			if (!(points[i] == p.points[i])) {
				return 0;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

Polygon2D::~Polygon2D()
{
	delete[] points;
}

Polygon2D::Polygon2D(Polygon2D &py) {
	points = new Point2D[py.numPoints];
	numPoints = py.numPoints;
	for (int i = 0; i < numPoints; i++) {
		points[i] = py.points[i];
	}
}

Polygon2D Polygon2D::operator=(const Polygon2D &py) {
	points = new Point2D[py.numPoints];
	numPoints = py.numPoints;
	for (int i = 0; i < numPoints; i++) {
		points[i] = py.points[i];
	}
	return *this;
}
