#include "stdafx.h"
#include "Line2D.h"



Line2D::~Line2D()
{
	std::cout << "Deleting";
	delete start;
	delete end;
}
