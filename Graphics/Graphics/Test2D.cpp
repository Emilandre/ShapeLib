#include "stdafx.h"
#include "Test2D.h"


void Test2D::testPoints() {
	std::cout << "\nTesting 2DPoints: \n";

	Point2D p;
	Point2D p2(2, 6);
	Point2D p3(1, 2);
	std::cout << p << std::endl << p2 << std::endl;

	glib::Save<Point2D>("savePoint", p3);

	Point2D test = glib::Load<Point2D>("savePoint");
}
void Test2D::testLines() {
	std::cout << "\n\nTesting 2DLines \n";

	Point2D p;
	Point2D p2(4, 5);
	Line2D l(2, 1, 3, 4);
	Line2D l2 = p + p2;
	std::cout << l << std::endl << l2 << std::endl;


	glib::Save<Line2D>("saveLine", l);

	glib::Load<Line2D>("saveLine");
}
void Test2D::testPoly() {

	std::cout << "\n\nTesting 2DPolygons: \n";
	Point2D p2(4, 5);
	Point2D p3(8, 9);
	Point2D p4(1, 9);
	Line2D l(2, 1, 3, 4);
	Polygon2D py = p2 + p3 + p4;
	Polygon2D py2 = p2 + l;
	Polygon2D py5 = py2 + l;
	Polygon2D py6 = py + Point2D(10, 10);
	Polygon2D py3 = py2 + py2;

	std::vector<Polygon2D> prints = { py, py2, py3, py5, py6 };


	for (Polygon2D p : prints) {
		std::cout << p << std::endl;
	}

	glib::Save<Polygon2D>("savePoly", py3);

	Polygon2D py4 = glib::Load<Polygon2D>("savePoly");

}

