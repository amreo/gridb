#ifndef LOCATED_H
#define LOCATED_H
#include "abstractlocated.h"

class Located : public virtual AbstractLocated
{
    public:
        inline int x() const { return _x; }
        inline int y() const { return _y; }

        virtual ~Located() {}

    protected:
        int _x;
        int _y;

        Located(int x = 0, int y = 0) : _x(x), _y(y) {}
};

#endif // LOCATED_H
