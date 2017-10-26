#include "stdafx.h"
#include "Polygon3D.h"



Polygon3D::Polygon3D(std::vector<Point3D> inPoints, Point3D inPoint) {
	points = inPoints;
	points.push_back(inPoint);
}

Polygon3D::Polygon3D(std::vector<Point3D> inPointsA, std::vector<Point3D> inPointsB) {
	for (Point3D &p : inPointsA) {
		points.push_back(p);
	}
	for (Point3D &p : inPointsB) {
		points.push_back(p);
	}
}

Polygon3D::Polygon3D() {
	for (int i = 0; i < 3; i++) {
		points.push_back(Point3D());
	}
}

int Polygon3D::operator==(const Polygon3D &py) {
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

Polygon3D operator+(const Line3D &l1, const Point3D &p2) {
	std::vector<Point3D> p = l1.getPoints();
	p.push_back(p2);
	return Polygon3D(p);
}
Polygon3D operator+(const Point3D &p1, const Line3D &l1) {
	return l1 + p1;
}

Polygon3D operator+(const Line3D &l1, const Line3D &l2) {
	std::vector<Point3D> p = l1.getPoints();
	p.push_back(l2.getPoints()[0]);
	p.push_back(l2.getPoints()[1]);
	return  Polygon3D(p);
}

Polygon3D operator+(Polygon3D &p1, Line3D &l) {
	return Polygon3D(p1.points, l.getPoints());
}
Polygon3D operator+(Polygon3D &p1, Point3D &p) {

	return Polygon3D(p1.points, p);
}
Polygon3D operator+(Polygon3D &p1, Polygon3D &p2) {
	return Polygon3D(p1.points, p2.points);
}

std::ostream& operator<<(std::ostream& os, const Polygon3D &py) {
	os << "{";
	for (const Point3D &p : py.points) {
		os << p;
	}
	return os << "}";
}
std::istream& operator>>(std::istream& is, Polygon3D &py) {
	std::vector<Point3D> points;
	int numCount = 0;
	char next = is.peek();
	Point3D p;

	if (next == '{') {
		is >> next;
		next = is.peek();
		while (!is.eof() && next != '}') {
			next = is.peek();
			if (next == '|') {
				is >> next;
				is >> p;
				points.push_back(p);
				numCount++;
			}
			else if (next == '(') {
				is >> p;
				points.push_back(p);
				numCount++;
			}
		}
	}
	py.setPoints(points);
	return is;
}