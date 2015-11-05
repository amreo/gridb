#include "gridcoordselecter.h"
#include <QDebug>
#include <QtGlobal>
#include "coord.h"

GridCoordSelecter::GridCoordSelecter(int offX, int offY, int width, int height)
{
	this->_offX = offX;
	this->_offY = offY;
	if (width <= 0)
	{
		qDebug() << "GridCoordSelecter is costructed with negative width ["
				 << offX << "; " << offY << "; " << width << "; " << height << "]";
		width = 0;
	}

	if (height <= 0)
	{
		qDebug() << "GridCoordSelecter is costructed with negative height ["
				 << offX << "; " << offY << "; " << width << "; " << height << "]";
		height = 0;
	}
	this->_width = width;
	this->_height = height;

	this->grid = new bool[width*height];
}

GridCoordSelecter::~GridCoordSelecter()
{
	delete this->grid;
}

int GridCoordSelecter::offsetX()
{
	return this->_offX;
}
int GridCoordSelecter::offsetY()
{
	return this->_offY;
}
int GridCoordSelecter::width()
{
	return this->_width;
}
int GridCoordSelecter::height()
{
	return this->_height;
}

void GridCoordSelecter::select(const Located& loc)
{
	this->select(loc.x(), loc.y());
}

void GridCoordSelecter::select(int x, int y)
{
	if (!checkBounds(x, y))
	{
		qDebug() << "loc [" << x << "; " << y << "] are out of bounds";
	}
	else
	{
		SetInternalState(x, y, SELECTED);
	}
}

void GridCoordSelecter::deSelect(const Located& loc)
{
	this->deSelect(loc.x(), loc.y());
}

void GridCoordSelecter::deSelect(int x, int y)
{
	if (!checkBounds(x, y))
	{
		qDebug() << "loc [" << x << "; " << y << "] are out of bounds";
	}
	else
	{
		SetInternalState(x, y, DESELECTED);
	}
}

bool GridCoordSelecter::isSelected(const Located& loc) const
{
	return isSelected(loc.x(),loc.y());
}

bool GridCoordSelecter::isSelected(int x, int y) const
{
	if (!checkBounds(x, y))
	{
		qDebug() << "loc [" << x << "; " << y << "] are out of bounds";
		return DESELECTED;
	}
	else
	{
		return this->InternalState(x,y);
	}
}

const QLinkedList<Located> GridCoordSelecter::getSelection() const
{
	QLinkedList<Located> list;

	FORXY(x, 0, this->_width-1, y, 0, this->_height -1)
		if (this->grid[x*this->_width+y] == SELECTED)
			list.append(Coord(x+this->_offX, y+this->_offY));

	return list;
}

bool GridCoordSelecter::checkBounds(int x, int y) const
{
	//check the x and y after sub offX/offY
	return ((x - this->_offX < 0 && x-this->_offX > _width-1) && (y - this->_offY < 0 && y-this->_offY > _height-1));
}

void GridCoordSelecter::SetInternalState(int x, int y, bool value)
{
	this->grid[(x-this->_offX)*this->_width+y-this->_offY] = value;
}

bool GridCoordSelecter::InternalState(int x, int y) const
{
	return this->grid[(x-this->_offX)*this->_width+y-this->_offY];
}
