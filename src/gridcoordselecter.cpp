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
        qWarning() << "GridCoordSelecter is costructed with negative width ["
                   << offX << "; " << offY << "; " << width << "; " << height << "]";
        width = 0;
    }

    if (height <= 0)
    {
        qWarning() << "GridCoordSelecter is costructed with negative height ["
                   << offX << "; " << offY << "; " << width << "; " << height << "]";
        height = 0;
    }
    this->_width = width;
    this->_height = height;

    this->grid = new bool[width*height];

    for (int x = 0; x < _width; x++)
        for (int y = 0; y < _height; y++)
            grid[x*_width+y] = DESELECTED;
}

GridCoordSelecter::~GridCoordSelecter()
{
    delete[] this->grid;
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

void GridCoordSelecter::select(const AbstractLocated& loc)
{
    this->select(loc.x(), loc.y());
}
void GridCoordSelecter::select(const AbstractLocated* loc)
{
    this->select(loc->x(), loc->y());
}

void GridCoordSelecter::select(int x, int y)
{
    if (!checkBounds(x, y))
    {
        qWarning() << "loc [" << x << "; " << y << "] are out of bounds";
    }
    else
    {
        SetInternalState(x, y, SELECTED);
    }
}

void GridCoordSelecter::deSelect(const AbstractLocated& loc)
{
    this->deSelect(loc.x(), loc.y());
}
void GridCoordSelecter::deSelect(const AbstractLocated* loc)
{
    this->deSelect(loc->x(), loc->y());
}


void GridCoordSelecter::deSelect(int x, int y)
{
    if (!checkBounds(x, y))
    {
        qWarning() << "loc [" << x << "; " << y << "] are out of bounds";
    }
    else
    {
        SetInternalState(x, y, DESELECTED);
    }
}

bool GridCoordSelecter::isSelected(const AbstractLocated& loc) const
{
    return isSelected(loc.x(),loc.y());
}
bool GridCoordSelecter::isSelected(const AbstractLocated* loc) const
{
    return isSelected(loc->x(),loc->y());
}

bool GridCoordSelecter::isSelected(int x, int y) const
{
    if (!checkBounds(x, y))
    {
        qWarning() << "loc [" << x << "; " << y << "] are out of bounds";
        return DESELECTED;
    }
    else
    {
        return this->InternalState(x,y);
    }
}

const QLinkedList<Coord> GridCoordSelecter::getSelection() const
{
    QLinkedList<Coord> list;
    for (int x = 0; x < _width; x++)
        for (int y = 0; y < _height; y++)
            if (grid[x*_width+y] == SELECTED)
                list.append(Coord(x+_offX,y+_offY));
    return list;
}

bool GridCoordSelecter::checkBounds(int x, int y) const
{
    x -= _offX;
    y -= _offY;
    return (x > 0 && x < _width && y > 0 && y < _height);
}

void GridCoordSelecter::SetInternalState(int x, int y, bool value)
{
    x -= _offX;
    y -= _offY;
    this->grid[x*_width + y] = value;
}

bool GridCoordSelecter::InternalState(int x, int y) const
{
    x -= _offX;
    y -= _offY;
    return this->grid[x*_width + y];
}
