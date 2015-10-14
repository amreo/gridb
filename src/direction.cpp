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

int Direction::getCoefficientX() const
{
	return this->coefficientX;
}

int Direction::getCoefficientY() const
{
	return this->coefficientY;
}

int Direction::getDirectionAngle() const
{
	if (Direction::equal(*this, Direction::UP))
		return 0;
	else if (Direction::equal(*this, Direction::UP_RIGHT))
		return 1;
	else if (Direction::equal(*this, Direction::RIGHT))
		return 2;
	else if (Direction::equal(*this, Direction::DOWN_RIGHT))
		return 3;
	else if (Direction::equal(*this, Direction::DOWN))
		return 4;
	else if (Direction::equal(*this, Direction::DOWN_LEFT))
		return 5;
	else if (Direction::equal(*this, Direction::LEFT))
		return 6;
	else if (Direction::equal(*this, Direction::UP_LEFT))
		return 7;
	return 0;
}

Direction Direction::getDirectionOpposite() const
{
	return Direction(-this->coefficientX, -this->coefficientY);
}

Direction Direction::getDirectionRotated(int angle) const
{
	if (Direction::equal(Direction::NONE, *this)) return Direction::NONE;
	Direction dir = Direction::NONE;
	dir.setDirection(this->getDirectionAngle() + angle);
	return dir;
}

void Direction::setDirection(const Direction& dir)
{
	this->coefficientX = dir.coefficientX;
	this->coefficientY = dir.coefficientY;
}

void Direction::setDirection(const int coefficientX, const int coefficientY)
{
	setCoefficientX(coefficientX);
	setCoefficientY(coefficientY);
}

void Direction::setDirection(int angle)
{
	//simply and positivity angle
	angle %= 8;
	if (angle < 0) angle = 8+angle;
	switch (angle) {
		case 0:
			this->setDirection(Direction::UP);
			return;
		case 1:
			this->setDirection(Direction::UP_RIGHT);
			return;
		case 2:
			this->setDirection(Direction::RIGHT);
			return;
		case 3:
			this->setDirection(Direction::DOWN_RIGHT);
			return;
		case 4:
			this->setDirection(Direction::DOWN);
			return;
		case 5:
			this->setDirection(Direction::DOWN_LEFT);
			return;
		case 6:
			this->setDirection(Direction::LEFT);
			return;
		case 7:
			this->setDirection(Direction::UP_LEFT);
			return;
	}
}

void Direction::setCoefficientX(const int coefficientX)
{
	this->coefficientX = coefficientX;
	if (this->coefficientX > 1) this->coefficientX = 1;
	if (this->coefficientX < -1) this->coefficientX = -1;
}

void Direction::setCoefficientY(const int coefficientY)
{
	this->coefficientY = coefficientY;
	if (this->coefficientY > 1) this->coefficientY = 1;
	if (this->coefficientY < -1) this->coefficientY = -1;
}

Direction Direction::sum(const Direction& dir1, const Direction& dir2)
{
	return Direction(dir1.coefficientX + dir2.coefficientX, dir1.coefficientY + dir2.coefficientY);
}

Direction Direction::sum(const int coeX1, const int coeY1, const int coeX2, const int coeY2)
{
	return Direction(coeX1+coeX2, coeY1+coeY2);
}

Direction Direction::sub(const Direction& dir1, const Direction& dir2)
{
	return Direction(dir1.coefficientX - dir2.coefficientX, dir1.coefficientY - dir2.coefficientY);
}

Direction Direction::sub(const int coeX1, const int coeY1, const int coeX2, const int coeY2)
{
	return Direction(coeX1-coeX2, coeY1-coeY2);
}

bool Direction::equal(const Direction& dir1, const Direction& dir2)
{
	return dir1.coefficientX == dir2.coefficientX && dir1.coefficientY == dir2.coefficientY;
}

Direction Direction::operator+(const Direction& dir2)
{
	return Direction(this->coefficientX + dir2.coefficientX, this->coefficientY + dir2.coefficientY);
}

Direction Direction::operator-(const Direction& dir2)
{
	return Direction(this->coefficientX - dir2.coefficientX, this->coefficientY - dir2.coefficientY);
}

bool Direction::operator==(const Direction& dir2)
{
	return this->coefficientX == dir2.coefficientX && this->coefficientY == dir2.coefficientY;
}

bool Direction::operator!=(const Direction& dir2)
{
	return this->coefficientX != dir2.coefficientX || this->coefficientY != dir2.coefficientY;
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
