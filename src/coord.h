#ifndef COORD_H
#define COORD_H
#include "movable.h"
#include <QPoint>

/**
 * @brief This class rappresent a 2D coord
 * @author amreo
 * @version 0.2
 * @since 0.1
 */
class Coord : public Movable
{
        Q_OBJECT
    public:
        /**
         * @brief Costructor of coord
         * @param Coordinate X
         * @param Coordinate Y
         * @param Parent object
         */
        Coord(int x = 0, int y = 0) : Movable(x,y) {}
        /**
         * @brief Copy costructor of coord
         * @param location
         */
        Coord(const Coord& c) : Coord(c.x(), c.y()) {}
        /**
         * @brief Create a new coord from a AbstractLocated
         * @param location
         */
        Coord(const AbstractLocated& c) : Coord(c.x(), c.y()) {}
        /**
         * @brief Costructor of coord
         * @param point
         */
        explicit Coord(const QPoint& point) : Coord(point.x(), point.y()) {}

        /**
         * @brief Sum the left and the right
         * @param left
         * @param right
         * @return the sum of left and right
         */
        inline static Coord sum(const AbstractLocated& left, const AbstractLocated& right)
        { return Coord(left.x()+right.x(), left.y() + right.y()); }
        /**
         * @brief Add the direction to left
         * @param left coord
         * @param Direction to added
         * @param Distance of the movement
         * @return The sum of the left and Direction
         */
        inline static Coord sum(const AbstractLocated& left, const Direction& dir, int distance = 1)
        { return Coord(left.x()+dir.coefficientX()*distance, left.y() + dir.coefficientY()*distance); }

        /*
         * @brief Sub to left the right
         * @param left
         * @param right
         * @return the sum of left and -right
         */
        inline static Coord sub(const AbstractLocated& left, const AbstractLocated& right)
        { return Coord(left.x() - right.x(), left.y() - right.y()); }
        /*
         * @brief Sub to left the direction*offset
         * @param left
         * @param Direction of the movement
         * @return the sum of left and -dir*offset
         */
        inline static Coord sub(const AbstractLocated& left, const Direction& dir, int offset = 1)
        { return Coord(left.x() - dir.coefficientX()*offset, left.y() - dir.coefficientY()*offset); }

        /**
         * @brief Move the coord by offset right
         * @param Offset X and Y
         * @return the coord moved
         */
        inline Coord operator+(const AbstractLocated& loc2) const
        { return Coord(this->x()+loc2.x(), this->y()+loc2.y()); }
        /**
         * @brief Move the coord by direction(1)
         * @param Direction of the movement
         * @return the coord moved
         */
        inline Coord operator+(const Direction& dir) const
        { return Coord(this->x()+dir.coefficientX(), this->y()+dir.coefficientY()); }

        /**
         * @brief Move the coord by -offset right
         * @param Offset X and Y
         * @return the coord moved
         */
        inline Coord operator-(const AbstractLocated& loc2) const
        { return Coord(this->x()-loc2.x(), this->y()-loc2.y()); }
        /**
         * @brief Move the coord by -dir(1)
         * @param Direction of the movement
         * @return the coord moved
         */
        inline Coord operator-(const Direction& dir) const
        { return Coord(this->x()-dir.coefficientX(), this->y()-dir.coefficientY()); }


        /**
         * Stub destructor
         */
        ~Coord() {}

    signals:

    public slots:

};

#endif // COORD_H
