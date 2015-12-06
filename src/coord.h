#ifndef COORD_H
#define COORD_H
#include "movable.h"

class Coord : public Movable
{
    Q_OBJECT
public:
    Coord(int x = 0, int y = 0) : Movable(x,y) {}
    Coord(const Coord& c) : Coord(c.x(), c.y()) {}
    Coord(const AbstractLocated& c) : Coord(c.x(), c.y()) {}

    static Coord sum(const AbstractLocated& loc1, const AbstractLocated& loc2)
    { return Coord(loc1.x()+loc2.x(), loc1.y() + loc2.y()); }

    static Coord sub(const AbstractLocated& loc1, const AbstractLocated& loc2)
    { return Coord(loc1.x() - loc2.x(), loc1.y() - loc2.y()); }

    Coord operator+(const AbstractLocated& loc2) const
    { return Coord(this->x()+loc2.x(), this->y()+loc2.y()); }
    Coord operator-(const AbstractLocated& loc2) const
    { return Coord(this->x()-loc2.x(), this->y()-loc2.y()); }

    ~Coord() {}

signals:

public slots:

};

#endif // COORD_H
