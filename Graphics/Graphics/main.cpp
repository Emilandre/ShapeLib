
#include "stdafx.h"
#include "Test2D.h"
#include "Test3D.h"
int main()
{
	Test2D t;
	t.testPoints();
	t.testLines();
	t.testPoly();
	std::cout << "\n";
	Test3D t3;
	t3.testPoints();
	t3.testLines();
	t3.testPoly();

	std::cin.get();

    return 0;
}

