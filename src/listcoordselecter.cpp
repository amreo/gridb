#include "listcoordselecter.h"
#include <QLinkedList>
#include <located.h>
#include "src_global.h"

ListCoordSelecter::ListCoordSelecter()
{
	this->list = QLinkedList<Located>();
}

void ListCoordSelecter::select(const Located& loc)
{
	if (!this->isSelected(loc)) {
		this->list.append(loc);
	}
}

void ListCoordSelecter::select(int x, int y)
{
	if (!this->isSelected(x,y)) {
		this->list.append(Coord(x,y));
	}
}

void ListCoordSelecter::deSelect(const Located& loc)
{

}

void ListCoordSelecter::deSelect(int x, int y)
{

}

bool ListCoordSelecter::isSelected(const Located& loc)
{
	foreach (Located item, this->list) {
		if (item.x()==loc.x() && item.y()==loc.y())
			return true;
	}
	return false;
}

bool ListCoordSelecter::isSelected(int x, int y)
{
	foreach (Located item, this->list) {
		if (item.x()==x && item.y()==y)
			return true;
	}
	return false;
}