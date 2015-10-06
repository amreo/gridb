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

Direction::Direction(const Direction& dir)
{
	this->coefficientX = dir.coefficientX;
	this->coefficientY = dir.coefficientY;
}

int Direction::getCoefficientX()
{
	return this->coefficientX;
}

int Direction::getCoefficientY()
{
	return this->coefficientY;
}

Direction Direction::NONE = Direction(0, 0);
Direction Direction::UP = Direction(0, -1);
Direction Direction::UP_RIGHT = Direction(1, -1);
Direction Direction::RIGHT = Direction(1, 0);
Direction Direction::DOWN_RIGHT = Direction(1, 1);
Direction Direction::DOWN = Direction(0, 1);
Direction Direction::DOWN_LEFT = Direction(-1, 1);
Direction Direction::LEFT  = Direction(-1, 0);
Direction Direction::UP_LEFT = Direction(-1, -1);
