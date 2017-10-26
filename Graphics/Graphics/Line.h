#pragma once
#include <iostream>
#include <fstream>
#include <vector>
template <class T>
class Line
{
public:
	Line(T &p1, T &p2)
		: points{ p1,p2 } {};

	Line()
		: points{ T(), T()} {};

	std::vector<T> &getPoints() { return points; };

	~Line() {};
	friend auto operator+(const Line &p1, const T &p2) {};
	friend auto operator+(const Line &l1, const Line &l2) {};
	int operator==(const Line &p) { return ((points[0] == p.points[0]) + (points[1] == p.points[1])); };

	friend std::ostream& operator<<(std::ostream& os, const  Line&);
	//friend std::istream& operator>>(std::istream& is, Line &l);

private:
	std::vector<T> points;
};


