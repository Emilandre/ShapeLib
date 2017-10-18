#pragma once
#include "shape.h"
class Line : public Shape
{
public:
	Line(int x, int y, int z, int x2, int y2, int z2);
	
	void operator=(Shape &s);
	~Line();
};

