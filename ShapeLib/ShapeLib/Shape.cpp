#include "stdafx.h"
#include "shape.h"


Shape::Shape()
{
}
void Shape::define(int numCoords, char identifier) {
	m_numCoords = numCoords;
	m_identifier = identifier;
}

void Shape::print() {
	Coord *c = m_coords;
	printf("%c: ", m_identifier);
	for(int i = 0; i < m_numCoords; i++) {
		printf("(%i,%i,%i)", c->x, c->y, c->z);
		c++;
	}
	printf("\n");
}

void Shape::addCoords(int x, int y, int z) {
	Coord *m = new Coord[m_numCoords + 1];

	Coord *iterator = m_coords;
	for (int i = 0; i < m_numCoords; i++) {
		m[i] = m_coords[i];
	}
	m[m_numCoords] = Coord{ x, y, z };
	m_numCoords++;
	delete[] m_coords;
	m_coords = m;
}

void Shape::addCoords(Coord c) {
	addCoords(c.x, c.y, c.z);
}

Shape Shape::operator+(Shape &s) {
	Shape tmp;
	for (int i = 0; i < m_numCoords; i++) {
		tmp.addCoords(m_coords[i]);
	}
	for (int i = 0; i < s.getNumCoords(); i++) {
		tmp.addCoords(s.getCoords()[i]);
	}
	return tmp;
}

void Shape::operator=(Shape &s) {
	
	delete[] m_coords;

	m_coords = s.getCoords();
	m_numCoords = s.getNumCoords();
}


Shape::~Shape()
{
	//delete[] m_coords;
}
