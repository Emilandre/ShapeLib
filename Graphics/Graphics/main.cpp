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

	std::cout << "Saving: " << p3 << std::endl;

	std::ifstream ifs("savePoint.txt");

	Point2D tmp;
	if (ifs >> tmp) {
		std::cout << "Reading: " << tmp;
		if (p3 == tmp) {
			std::cout << " Save success" << std::endl;
		}
		else {
			std::cout << " Save Error" << std::endl;
		}

	}
	else {
		std::cout << "Could not load Point";
	}
	ifs.close();
}
void testLines() {
	Point2D p;
	Point2D p2(4, 5);
	Line2D l(2, 1, 3, 4);
	Line2D l2 = p + p2;
	std::cout << l << std::endl << l2 << std::endl;

	std::ofstream ofs("saveLine.txt");
	std::cout << "Saving: " << l;
	ofs << l;
	ofs.close();

	std::ifstream ifs("saveLine.txt");

	Line2D tmp;
	if (ifs >> tmp) {
		std::cout << "Reading: " << tmp;
		if (l == tmp) {
			std::cout << "Save success" << std::endl;
		}
		else {
			std::cout << "Save Error" << std::endl;
		}
	}
	else {
		std::cout << "Could not load Polygon";
	}
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

	std::ofstream ofs("savePoly.txt");
	std::cout << "Saving: " << py << std::endl;
	ofs << py;
	ofs.close();

	std::ifstream ifs("savePoly.txt");

	Polygon2D tmp;
	if (ifs >> tmp) {
		std::cout << "Reading: " << tmp;
		if (py == tmp) {
			std::cout << " Save success" << std::endl;
		}
		else {
			std::cout << " Save Error" << std::endl;
		}

	}
	else {
		std::cout << "Could not load Polygon";
	}
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

