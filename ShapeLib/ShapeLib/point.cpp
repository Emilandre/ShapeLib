#include "stdafx.h"
#include "point.h"


Point::Point(int x, int y, int z)
{
	Shape::addCoords(x, y, z);
	Shape::define(1, 'P');
}


Point::~Point()
{
}
