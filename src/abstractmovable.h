#ifndef ABSTRACTMOVABLE_H
#define ABSTRACTMOVABLE_H

#include <QObject>
#include "abstractlocated.h"
#include "direction.h"


/**
 * @brief This class is the base class of any movable objects in 2D space (without full implementation)
 * @author amreo
 * @version 0.1
 * @since 0.4
 */
class AbstractMovable : public QObject, public virtual AbstractLocated
{
        Q_OBJECT
    public:

        /**
        * @brief Move the coordinte by the offset loc
        * @param offset x and y
        */
        virtual AbstractMovable& operator>>(const AbstractLocated& loc) = 0;
        /**
         * @brief Move the coordinte by the offset -loc
         * @param offset x and y
         */
        virtual AbstractMovable& operator<<(const AbstractLocated& loc) = 0;

    signals:
        /**
         * @brief This signal is emitted whenever the location is changed
         * @param New location
         */
        void locationChanged(const AbstractLocated& newLocation); //TODO: use MoveEvent instead AbstractLocated

    public slots:
        /**
         * @brief Set the coordinate X
         * @param New coordinte X
         */
        virtual void setX(int x) = 0;
        /**
         * @brief Set the coordinate Y
         * @param New coordinte Y
         */
        virtual void setY(int y) = 0;
        /**
         * @brief Set the coordinate x and y
         * @param New coordinate x
         * @param New coordinate y
         */
        virtual void setMovable(int x, int y) = 0;
        /**
         * @brief Set the coordinate x and y from loc
         * @param Located object
         */
        virtual void setMovable(const AbstractLocated& loc) = 0;

        /**
         * @brief Move the coordinate by offset
         * @param offset x
         * @param offset y
         */
        inline void move(int offsetX, int offsetY) {setMovable(x()+offsetX, y()+offsetY);}
        /**
         * @brief Move the coordinate by the offset
         * @param offset X and Y
         */
        inline void move(const AbstractLocated& offset) {setMovable(x()+offset.x(), y()+offset.y());}
        /**
         * @brief Move the coordinate in the dir by offset
         * @param Direction of the movement
         * @param Distance of the movement;
         */
        inline void move(const Direction& dir, int distance) {
            setMovable(x()+distance*dir.coefficientX(), y()+distance*dir.coefficientY());
        }

};

#endif // ABSTRACTMOVABLE_H
