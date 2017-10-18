#pragma once
#include <string>

struct Coord {
	int x, y, z;
};

class Shape
{
protected:
	Coord *m_coords;
	int m_numCoords;
	char m_identifier = ' ';
public:
	Shape();
	void define(int numCoords, char identifier);
	void print();

	void addCoords(int x, int y, int z);
	void addCoords(Coord c);

	void operator=(Shape &s);
	Shape operator+(Shape &s);
	int &getNumCoords() { return m_numCoords; };
	Coord *getCoords() { return m_coords; };
	~Shape();
};

