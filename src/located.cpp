#include "located.h"


Located::Located()
{
	this->x = 0;
	this->y = 0;
}

Located::Located(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Located::getX()
{
	return this->x;
}


int Located::getY()
{
	return this->y;
}
