#include "stdafx.h"
#include "Line3D.h"


Line3D operator+(Point3D &p1, Point3D &p2) {
	return Line3D(p1, p2);
}

std::ostream& operator<<(std::ostream& os, const Line3D &l) {
	return os << '[' << l.points[0] << '|' << l.points[1] << ']';
}
std::istream& operator>>(std::istream& is, Line3D &l) {
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