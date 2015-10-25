#include "coord.h"
#include "movable.h"
#include <QDebug>

Coord::Coord(int x, int y, QObject* parent) : Movable(x,y,parent) {}

Coord Coord::sum(const Located& left, const Located& right)
{
	return Coord(left.x()+right.x(), left.y()+right.y());
}

Coord Coord::sum(const Located& left, const Direction& dir, int offset)
{
	return Coord(left.x()+dir.coefficientX()*offset, left.y()+dir.coefficientY()*offset);
}

Coord Coord::sub(const Located& left, const Located& right)
{
	return Coord(left.x()-right.x(), left.y()-right.y());
}

Coord Coord::sub(const Located& left, const Direction& dir, int offset)
{
	return Coord(left.x()-dir.coefficientX()*offset, left.y()-dir.coefficientY()*offset);
}

Coord Coord::operator+(const Located& right)
{
	return Coord(this->x()+right.x(), this->y()+right.y());
}

Coord Coord::operator+(const Direction& right)
{
	return Coord(this->x()+right.coefficientX(), this->y()+right.coefficientY());
}

Coord Coord::operator-(const Located& right)
{
	return Coord(this->x()-right.x(), this->y()-right.y());
}

Coord Coord::operator-(const Direction& right)
{
	return Coord(this->x()-right.coefficientX(), this->y()-right.coefficientY());
}
