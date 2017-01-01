#include "gridlistcoordselecter.h"
#include "listcoordselecter.h"
#include <QDebug>
#include <QtGlobal>
#include "coord.h"

GridListCoordSelecter::GridListCoordSelecter(int offX, int offY, int width, int height) : ListCoordSelecter()
{
    this->_offX = offX;
    this->_offY = offY;
    if (width <= 0)
    {
        qWarning() << "GridListCoordSelecter is costructed with negative width ["
                 << offX << "; " << offY << "; " << width << "; " << height << "]";
        width = 0;
    }

    if (height <= 0)
    {
        qWarning() << "GridListCoordSelecter is costructed with negative height ["
                 << offX << "; " << offY << "; " << width << "; " << height << "]";
        height = 0;
    }
    this->_width = width;
    this->_height = height;

    this->grid = new ptr_QLinkedListNode [width* height];
    this->gridBool = new bool [width* height];

    for (int x = 0; x < _width; x++)
        for (int y = 0; y < _height; y++)
        {
             grid[x*_width+y] = NULL;
             gridBool[x*_width+y] = false;
        }

}

GridListCoordSelecter::~GridListCoordSelecter()
{
    delete[] this->grid;
    delete[] this->gridBool;
}

int GridListCoordSelecter::offsetX()
{
    return this->_offX;
}
int GridListCoordSelecter::offsetY()
{
    return this->_offY;
}
int GridListCoordSelecter::width()
{
    return this->_width;
}
int GridListCoordSelecter::height()
{
    return this->_height;
}


void GridListCoordSelecter::select(const AbstractLocated &loc)
{
    if (!this->isSelected(loc)) {
        this->list.append(Coord(loc));
        this->SetInternalState(loc.x(), loc.y(), this->list.end()-1);
        this->SetInternalStateBool(loc.x(), loc.y(), true);
    }
}

void GridListCoordSelecter::select(const AbstractLocated *loc)
{
    if (!this->isSelected(loc)) {
        this->list.append(Coord(*loc));
        this->SetInternalState(loc->x(), loc->y(), this->list.end()-1);
        this->SetInternalStateBool(loc->x(), loc->y(), true);
    }
}

void GridListCoordSelecter::select(int x, int y)
{
    if (!this->isSelected(x,y)) {
        this->list.append(Coord(x,y));
        this->SetInternalState(x, y, this->list.end()-1);
        this->SetInternalStateBool(x, y, true);
    }
}

void GridListCoordSelecter::deSelect(const AbstractLocated &loc)
{
    if (this->isSelected(loc)) {
        this->list.erase(InternalState(loc.x(),loc.y()));
        this->SetInternalState(loc.x(), loc.y(), NULL);
        this->SetInternalStateBool(loc.x(), loc.y(), false);
    }
}

void GridListCoordSelecter::deSelect(const AbstractLocated *loc)
{
    if (this->isSelected(loc)) {
        this->list.erase(InternalState(loc->x(),loc->y()));
        this->SetInternalState(loc->x(), loc->y(), NULL);
        this->SetInternalStateBool(loc->x(), loc->y(), false);
    }
}

void GridListCoordSelecter::deSelect(int x, int y)
{
    if (this->isSelected(x,y)) {
        this->list.erase(InternalState(x, y));
        this->SetInternalState(x, y, NULL);
        this->SetInternalStateBool(x, y, false);
    }
}

bool GridListCoordSelecter::isSelected(const AbstractLocated &loc) const
{

    return InternalStateBool(loc.x(), loc.y());
}

bool GridListCoordSelecter::isSelected(const AbstractLocated *loc) const
{
    return InternalStateBool(loc->x(), loc->y());
}

bool GridListCoordSelecter::isSelected(int x, int y) const
{
    return InternalStateBool(x, y);
}

void GridListCoordSelecter::SetInternalState(int x, int y, GridListCoordSelecter::ptr_QLinkedListNode value)
{
    x -= _offX;
    y -= _offY;
    this->grid[x*_width + y] = value;
}

GridListCoordSelecter::ptr_QLinkedListNode GridListCoordSelecter::InternalState(int x, int y) const
{
    x -= _offX;
    y -= _offY;
    return this->grid[x*_width + y];
}

void GridListCoordSelecter::SetInternalStateBool(int x, int y, bool value)
{
    x -= _offX;
    y -= _offY;
    this->gridBool[x*_width + y] = value;
}

bool GridListCoordSelecter::InternalStateBool(int x, int y) const
{
    x -= _offX;
    y -= _offY;
    return this->gridBool[x*_width + y];
}

