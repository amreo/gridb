#include "euclideandistancefunction.h"
#include <QtMath>

float EuclideanDistanceFunction::operator()(int x1, int y1, int x2, int y2) const
{
	//dX = |x1-x2|
	//dY = |y1-y2|
	//d = sqrt(dX*dX+dY*dY)
	int dX = x1-x2;
	int dY = y1-y2;
	return qSqrt(dX*dX+dY*dY);
}
