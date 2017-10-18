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

bool Point2D::Save(const std::string &fileName) {	
	std::ofstream ofs(fileName + ".txt", std::ofstream::app);
	
	if (ofs << *this) {
		ofs.close();
		return true;
	}
	else {
		ofs.close();
		return false;
	}
}


Point2D::~Point2D()
{
}
