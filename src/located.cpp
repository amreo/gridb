#include "located.h"

Located::Located(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

Located::Located(const Located& loc)
{
	this->_x = loc._x;
	this->_y = loc._y;
}

 int Located::x() const
{
	return this->_x;
}
int Located::y() const
{
	return this->_y;
}

Located Located::getLocation()
{
	return Located(this->_x, this->_y);
}
