// ShapeLib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "shape.h"
#include "point.h"
#include "line.h"
void testPoint() {
	
}

int main()
{
	int status = 100;
	Shape s;
	Shape s1;
	Shape s3;

	Point p(1, 2, 3);
	Point p2(4,5,6);
	Line l1(1, 2, 3, 4, 2, 1);
	while (status != -1) {

		if (status == 1) {
			Line l = p + p2;
		}
		

		std::cin >> status;
	}
    return 0;
}

