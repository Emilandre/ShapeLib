#pragma once
#include <vector>

std::ostream& operator<<(std::ostream& os, const Point2D &p) {
	return os << '(' << p.x << ',' << p.y << ')';
}
std::istream& operator>>(std::istream& is, Point2D &p) {
		char c = is.peek();
		double x = 0;
		double y = 0;
		if (c == '(') {
			is >> c;
			is >> x;
		}
		c = is.peek();
		if (c == ',') {
			is >> c;
			is >> y;
		}
		is >> c;
		p.setCoordinates(x, y);
	return is;
}
std::ostream& operator<<(std::ostream& os, const Line<Point2D> &l) {
	return os << '[' << l.points[0] << '|' << l.points[1] << ']';
}
std::ostream& operator<<(std::ostream& os, const Line<Point3D> &l) {
	return os << '[' << l.points[0] << '|' << l.points[1] << ']';
}

std::ostream& operator<<(std::ostream& os, const Polygon<Point2D> &py) {
	os << "{";
	for (const Point2D &p : py.points) {
		os << p;
	}
	return os << "}";
}
std::ostream& operator<<(std::ostream& os, const Polygon<Point3D> &py) {
	os << "{";
	for (const Point3D &p : py.points) {
		os << p;
	}
	return os << "}";
}
std::istream& operator>>(std::istream& is, Polygon<Point2D> &py) {
	std::vector<Point2D> points;
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
			}
			else if (next == '(') {
				is >> p;
				points.push_back(p);
			}
		}
	}
	py.setPoints(points);
	return is;
}

std::istream& operator>>(std::istream& is, Polygon<Point3D> &py) {
	std::vector<Point3D> points;
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
			}
			else if (next == '(') {
				is >> p;
				points.push_back(p);
			}
		}
	}
	py.setPoints(points);
	return is;
}

auto operator+(Point2D &p1, Point2D &p2) {
	return Line2D(p1, p2);
}
auto operator+( const Line2D &l1,  const Point2D &p2) {
	std::vector<Point2D> p = l1.points;
	p.push_back(p2);
	return Polygon2D(p);
}
auto operator+( const Point2D &p1, const Line2D &l1 ) {
	return l1+p1;
}
auto operator+(const Line2D &l1, const Line2D &l2) {
	std::vector<Point2D> p = l1.points;
	p.push_back(l2.points[0]);
	p.push_back(l2.points[1]);

	return  Polygon2D(p);
}

Polygon2D operator+(Polygon2D &p1, Line2D &l) {
	return Polygon2D(p1.points, l.getPoints());
}
Polygon2D operator+(Polygon2D &p1, Point2D &p) {

	return Polygon2D(p1.points, p);
}
Polygon2D operator+(Polygon2D &p1, Polygon2D &p2) {
	return Polygon2D(p1.points,p2.points);
}
