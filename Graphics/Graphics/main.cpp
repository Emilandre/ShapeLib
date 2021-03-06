#include "stdafx.h"
#include "point2D.h"
#include "line2D.h"
#include "polygon2D.h"
#include "OperatorOverloads.h"

void testPoints() {
	Point2D p;
	Point2D p2(2, 6);
	Point2D p3(1, 2);
	std::cout << p << std::endl << p2 << std::endl;


	Save<Point2D>("savePoint", p3);

	Point2D test = Load<Point2D>("savePoint");
}
void testLines() {
	Point2D p;
	Point2D p2(4, 5);
	Line2D l(2, 1, 3, 4);
	Line2D l2 = p + p2;
	std::cout << l << std::endl << l2 << std::endl;

	Save<Line2D>("saveLine", l);

	Load<Line2D>("saveLine");
}
void testPoly() {
	Point2D p2(4, 5);
	Point2D p3(8, 9);
	Point2D p4(1, 9);
	Line2D l(2, 1, 3, 4);
	Polygon2D py = p2 + p3 + p4;
	Polygon2D py2 = p2 + l;
	Polygon2D py3 = py + py2;

	std::cout << py << std::endl << py2 << std::endl << py3 << std::endl;

	Save<Polygon2D>("savePoly", py);

	Load<Polygon2D>("savePoly");
	
}
int main()
{
	char input = ' ';
	while (input != 'x') {
		switch (input) { 
		case 'p':
			testPoints(); break;
		case 'l':
			testLines(); break;
		case 's':
			testPoly(); break;
		}
		std::cin >> input;

	}
	
	
    return 0;
}

