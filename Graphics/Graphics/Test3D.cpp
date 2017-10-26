#include "stdafx.h"
#include "Test3D.h"

void Test3D::testPoints() {
	std::cout << "\nTesting 3DPoints: \n";

	Point3D p;
	Point3D p2(2, 6, 1);
	Point3D p3(1, 2, 9);
	std::cout << p << std::endl << p2 << std::endl;

	glib::Save<Point3D>("savePoint", p3);

	Point3D test = glib::Load<Point3D>("savePoint");
}
void Test3D::testLines() {
	std::cout << "\n\nTesting 3DLines \n";

	Point3D p;
	Point3D p2(4, 5, 7);
	Line3D l(2, 1, 3, 4, 6, 7);
	Line3D l2 = p + p2;
	std::cout << l << std::endl << l2 << std::endl;


	glib::Save<Line3D>("saveLine", l);

	glib::Load<Line3D>("saveLine");
}
void Test3D::testPoly() {

	std::cout << "\n\nTesting 3DPolygons: \n";
	Point3D p2(4, 5, 1);
	Point3D p3(8, 9, 11);
	Point3D p4(1, 9, 2);
	Line3D l(2, 1, 3, 4, 1, 2);
	Polygon3D py = p2 + p3 + p4;
	Polygon3D py2 = p2 + l;
	Polygon3D py5 = py2 + l;
	Polygon3D py6 = py + Point3D(10, 10, 9);
	Polygon3D py3 = py2 + py2;

	std::vector<Polygon3D> prints = { py, py2, py3, py5, py6 };


	for (Polygon3D p : prints) {
		std::cout << p << std::endl;
	}

	glib::Save<Polygon3D>("savePoly", py3);

	Polygon3D py4 = glib::Load<Polygon3D>("savePoly");

}


