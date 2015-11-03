#include "coordselecter.h"

void CoordSelecter::select(const Located list[], int n)
{
	for (int i=0; i<n; i++)
	{
		select(list[i]);
	}
}

void CoordSelecter::deSelect(const Located list[], int n)
{
	for (int i=0; i<n; i++)
	{
		deSelect(list[i]);
	}
}

bool CoordSelecter::isSelected(const Located list[], int n) const
{
	for (int i=0; i<n; i++)
		if (!isSelected(list[i]))
			return false;
	return true;
}
