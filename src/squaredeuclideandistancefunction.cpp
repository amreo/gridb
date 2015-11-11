#include "squaredeuclideandistancefunction.h"

float SquaredEuclideanDistanceFunction::operator()(int x1, int y1, int x2, int y2) const
{
	//dX = |x1-x2|
	//dY = |y1-y2|
	//d = dX*dX+dY*dY
	int dX = x1-x2;
	int dY = y1-y2;
	return dX*dX+dY*dY;
}

