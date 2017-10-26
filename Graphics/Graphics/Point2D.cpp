#include "stdafx.h"
#include "point2D.h"

int Point2D::operator==(const Point2D &p) { 
	double dx = x - p.x;
	double dy = y - p.y;

	if (dy == 0 && dx == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

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




