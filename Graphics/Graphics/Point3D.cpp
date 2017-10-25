#include "stdafx.h"
#include "point3D.h"

int Point3D::operator==(const Point3D &p) {
	double dx = x - p.x;
	double dy = y - p.y;
	double dz = z - p.z;

	if (dy == 0 && dx == 0 && dz == 0) {
		return 1;
	}
	else {
		return 0;
	}
}