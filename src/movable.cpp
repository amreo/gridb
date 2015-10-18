#include "movable.h"


Movable::Movable(int x, int y, QObject* parent) : QObject(parent), Located(x,y)
{

}

Movable::Movable(const Movable& loc) :  QObject(NULL), Located(loc)
{
	this->_x = loc.x();
	this->_y = loc.y();
}

Movable::Movable(const Located& loc)
{
	this->_x = loc.x();
	this->_y = loc.y();
}

void Movable::setX(int x)
{
	this->_x = x;
	emit locationChanged(*this);
}

void Movable::setY(int y)
{
	this->_y = y;
	emit locationChanged(*this);
}

void Movable::setMovable(int x, int y)
{
	this->_x = x;
	this->_y = y;
	emit locationChanged(*this);
}

void Movable::setMovable(const Located& loc)
{
	this->_x = loc.x();
	this->_y = loc.y();
	emit locationChanged(*this);
}

void Movable::move(int offsetX, int offsetY)
{
	this->_x += offsetX;
	this->_y += offsetY;
	emit locationChanged(*this);
}

void Movable::move(const Direction& dir, int offset)
{
	this->_x += offset * dir.coefficientX();
	this->_y += offset * dir.coefficientY();
	emit locationChanged(*this);
}
