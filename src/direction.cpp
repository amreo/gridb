#include "direction.h"
#include <QDebug>


Direction::Direction(int coefficientX, int coefficientY)
{
	if (coefficientX > 1) coefficientX = 1;
	if (coefficientX < -1) coefficientX = -1;
	if (coefficientY > 1) coefficientY = 1;
	if (coefficientY < -1) coefficientY = -1;

	this->coefficientX = coefficientX;
	this->coefficientY = coefficientY;
}
