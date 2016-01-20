#ifndef MOVABLE_H
#define MOVABLE_H
#include "abstractmovable.h"
#include "located.h"

/**
 * @brief This class is the base class of any movable objects in 2D space
 * @author amreo
 * @version 0.2
 * @since 0.1
 */
class Movable : public AbstractMovable, public Located
{
    Q_OBJECT
    public:

        /**
        * @brief Move the coordinte by the offset loc
        * @param offset x and y
        */
        AbstractMovable& operator>>(const AbstractLocated& loc) {move(loc); return *this; }
        /**
         * @brief Move the coordinte by the offset -loc
         * @param offset x and y
         */
        AbstractMovable& operator<<(const AbstractLocated& loc) {move(-loc.x(), -loc.y()); return *this; }

        /**
         * @brief Stub destructor
         */
        virtual ~Movable() {}

    signals:

    public slots:
        /**
         * @brief Set the coordinate X
         * @param New coordinte X
         */
        void setX(int x) { _x = x; emit locationChanged(*this);}
        /**
         * @brief Set the coordinate Y
         * @param New coordinte Y
         */
        void setY(int y) { _y = y; emit locationChanged(*this);}
        /**
         * @brief Set the coordinate x and y
         * @param New coordinate x
         * @param New coordinate y
         */
        void setMovable(int x, int y) {_x = x; _y = y; emit locationChanged(*this); }
        /**
         * @brief Set the coordinate loc
         * @param New coordinate
         */
        void setMovable(const AbstractLocated& loc) {_x = loc.x(); _y = loc.y(); emit locationChanged(loc); }

    protected:
        /**
         * @brief Create a new instance of movable position
         * @param Coordinate x
         * @param Coordinate y
         */
        Movable(int x=0, int y=0) : Located(x,y) {}
};

#endif // MOVABLE_H
