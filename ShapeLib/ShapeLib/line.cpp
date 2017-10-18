#include "stdafx.h"
#include "line.h"


Line::Line(int x, int y, int z, int x2, int y2, int z2)
{
	Shape::addCoords(x, y, z);
	Shape::addCoords(x2, y2, z2);
	Shape::define(2, 'L');
}



Line::~Line()
{
}
