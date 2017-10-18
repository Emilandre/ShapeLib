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

std::ostream& operator<<(std::ostream& os, const  Line2D l) {
	return os << '[' <<*l.start << '|' << *l.end << ']'<< std::endl;
}
std::istream& operator>>(std::istream& is, Line2D &l) {
	char c = is.peek();
		
	if (c == '[') {
		is >> c;
		is >> l.getStart();
	}
	c = is.peek();
	if (c == '|') {
		is >> c;
		is >> l.getEnd();
	}
	return is;
}


std::ostream& operator<<(std::ostream& os, const  Polygon2D p) {
	os << "{";
	for (int i = 0; i < p.numPoints; i++) {
		os << p.points[i];
		if (i < p.numPoints - 1) {
			os << '|';
		}
	}
	return os << "}";
}
std::istream& operator>>(std::istream& is, Polygon2D &py) {
	std::vector<Point2D> points;
	int numCount = 0;
	char next = is.peek();
	Point2D p;

	if(next == '{') {
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
			else if( next == '('){
				is >> p;
				points.push_back(p);
				numCount++;
			}
		}
	}
	Point2D *rPoints = new Point2D[numCount];
	int i = 0;
	for (Point2D &p : points) {
		rPoints[i] = p;
		i++;
	}
	py = Polygon2D(rPoints, numCount);
	return is;
}

auto operator+(Point2D &p1, Point2D &p2) {
	return Line2D(p1, p2);
}
auto operator+( Line2D &l1,  Point2D &p2) {
	Point2D a = Point2D(l1.getStart());
	Point2D b = Point2D(l1.getEnd());
	Point2D c = Point2D(p2);
	return Polygon2D(a, b, c);
}
auto operator+( Point2D &p1, Line2D &l1 ) {
	return l1+p1;
}
auto operator+(Line2D &l1, Line2D &l2) {
	Point2D *points = new Point2D[4];
	points[0] = l1.getStart();
	points[1] = l1.getEnd();
	points[2] = l2.getStart();
	points[3] = l2.getEnd();
	return  Polygon2D(points,4);
}

Polygon2D operator+(Polygon2D &p1, Polygon2D &p2) {
	Point2D *newPoints = new Point2D[p1.numPoints + p2.numPoints];
	for (int i = 0; i < p1.numPoints; i++) {
		newPoints[i] = p1.points[i];
	}
	for (int i = 0; i < p2.numPoints; i++) {
		newPoints[i + p1.numPoints] = p2.points[i];
	}
	return Polygon2D(newPoints, p1.numPoints + p2.numPoints);

}
