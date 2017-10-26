#include "stdafx.h"
#include "polygon2D.h"



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

Polygon2D operator+(const Line2D &l1, const Point2D &p2) {
	std::vector<Point2D> p = l1.getPoints();
	p.push_back(p2);
	return Polygon2D(p);
}
Polygon2D operator+(const Point2D &p1, const Line2D &l1) {
	return l1 + p1;
}

Polygon2D operator+(const Line2D &l1, const Line2D &l2) {
	std::vector<Point2D> p = l1.getPoints();
	p.push_back(l2.getPoints()[0]);
	p.push_back(l2.getPoints()[1]);
	return  Polygon2D(p);
}

Polygon2D operator+(Polygon2D &p1, Line2D &l) {
	return Polygon2D(p1.points, l.getPoints());
}
Polygon2D operator+(Polygon2D &p1, Point2D &p) {

	return Polygon2D(p1.points, p);
}
Polygon2D operator+(Polygon2D &p1, Polygon2D &p2) {
	return Polygon2D(p1.points, p2.points);
}

std::ostream& operator<<(std::ostream& os, const Polygon2D &py) {
	os << "{";
	for (const Point2D &p : py.points) {
		os << p;
	}
	return os << "}";
}
std::istream& operator>>(std::istream& is, Polygon2D &py) {
	std::vector<Point2D> points;
	int numCount = 0;
	char next = is.peek();
	Point2D p;

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