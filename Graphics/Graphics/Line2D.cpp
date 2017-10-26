#include "stdafx.h"
#include "Line2D.h"


Line2D operator+(Point2D &p1, Point2D &p2) {
	return Line2D(p1, p2);
}

std::ostream& operator<<(std::ostream& os, const Line2D &l) {
	return os << '[' << l.points[0] << '|' << l.points[1] << ']';
}
std::istream& operator>>(std::istream& is, Line2D &l) {
	char c = is.peek();

	if (c == '[') {
		is >> c;
		is >> l.points[0];
	}
	c = is.peek();
	if (c == '|') {
		is >> c;
		is >> l.points[1];
	}
	return is;
}