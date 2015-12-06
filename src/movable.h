#ifndef MOVABLE_H
#define MOVABLE_H
#include "abstractmovable.h"
#include "located.h"


class Movable : public AbstractMovable, public Located
{
    Q_OBJECT
    public:

        AbstractMovable& operator>>(const AbstractLocated& loc) {move(loc); return *this; }
        AbstractMovable& operator<<(const AbstractLocated& loc) {move(-loc.x(), -loc.y()); return *this; }

        virtual ~Movable() {}

    signals:

    public slots:
        void setX(int x) { _x = x; emit locationChanged(*this);}
        void setY(int y) { _y = y; emit locationChanged(*this);}
        void setMovable(int x, int y) {_x = x; _y = y; emit locationChanged(*this); }
        void setMovable(const AbstractLocated& loc) {_x = loc.x(); _y = loc.y(); emit locationChanged(loc); }

    protected:
        Movable(int x=0, int y=0) : Located(x,y) {}
};

#endif // MOVABLE_H
