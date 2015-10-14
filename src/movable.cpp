#include "movable.h"


Movable::Movable(int x, int y, QObject* parent) : QObject(parent), Located(x,y)
{

}

Movable::Movable(const Movable& loc) :  QObject(NULL), Located(loc)
{
	this->x = loc.getX();
	this->y = loc.getY();
}

Movable::Movable(const Located& loc)
{
	this->x = loc.getX();
	this->y = loc.getY();
}
