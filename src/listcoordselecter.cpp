#include "listcoordselecter.h"
#include <QLinkedList>
#include <located.h>
#include "src_global.h"

ListCoordSelecter::ListCoordSelecter()
{
    this->list = QLinkedList<Coord>();
}

void ListCoordSelecter::select(const AbstractLocated& loc)
{
	if (!this->isSelected(loc)) {
        this->list.append(Coord(loc));
	}
}
void ListCoordSelecter::select(const AbstractLocated* loc)
{
    if (!this->isSelected(loc)) {
        this->list.append(Coord(loc->x(), loc->y()));
    }
}
void ListCoordSelecter::select(int x, int y)
{
	if (!this->isSelected(x,y)) {
		this->list.append(Coord(x,y));
	}
}

void ListCoordSelecter::deSelect(const AbstractLocated& loc)
{
	for (auto iter = this->list.begin(); iter != list.end(); ++iter)
	{
		if(iter->x() == loc.x() && iter->y() == loc.y())
		{
			this->list.erase(iter);
			break; //end of loop
		}
	}
}
void ListCoordSelecter::deSelect(const AbstractLocated* loc)
{
    for (auto iter = this->list.begin(); iter != list.end(); ++iter)
    {
        if(iter->x() == loc->x() && iter->y() == loc->y())
        {
            this->list.erase(iter);
            break; //end of loop
        }
    }
}

void ListCoordSelecter::deSelect(int x, int y)
{
	for (auto iter = this->list.begin(); iter != list.end(); ++iter)
	{
		if(iter->x() == x && iter->y() == y)
		{
			this->list.erase(iter);
			break; //end of loop
		}
	}
}

bool ListCoordSelecter::isSelected(const AbstractLocated& loc) const
{
	foreach (Located item, this->list) {
		if (item.x()==loc.x() && item.y()==loc.y())
			return true;
	}
	return false;
}
bool ListCoordSelecter::isSelected(const AbstractLocated* loc) const
{
    foreach (Located item, this->list) {
        if (item.x()==loc->x() && item.y()==loc->y())
            return true;
    }
    return false;
}


bool ListCoordSelecter::isSelected(int x, int y) const
{
	foreach (Located item, this->list) {
		if (item.x()==x && item.y()==y)
			return true;
	}
	return false;
}

const QLinkedList<Coord> ListCoordSelecter::getSelection() const
{
	return this->list;
}
