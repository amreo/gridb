#ifndef ABSTRACTMOVABLE_H
#define ABSTRACTMOVABLE_H

#include <QObject>
#include "abstractlocated.h"

class AbstractMovable : public QObject, public virtual AbstractLocated
{
    Q_OBJECT
public:

   virtual AbstractMovable& operator>>(const AbstractLocated& loc) = 0;
   virtual AbstractMovable& operator<<(const AbstractLocated& loc) = 0;

signals:
    void locationChanged(const AbstractLocated& newLocation);

public slots:
    virtual void setX(int x) = 0;
    virtual void setY(int y) = 0;
    virtual void setMovable(int x, int y) = 0;

    virtual void setMovable(const AbstractLocated& loc) = 0;

    inline void move(int offsetX, int offsetY) {setMovable(x()+offsetX, y()+offsetY);}
    inline void move(const AbstractLocated& offset) {setMovable(x()+offset.x(), y()+offset.y());}

};

#endif // ABSTRACTMOVABLE_H
