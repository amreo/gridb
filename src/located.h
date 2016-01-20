#ifndef LOCATED_H
#define LOCATED_H
#include "abstractlocated.h"

/**
 * @brief This class is the base class of any non-movable objects in 2D space
 * @author amreo
 * @version 0.2
 * @since 0.1
 */
class Located : public virtual AbstractLocated
{
    public:
        /**
         * @brief Return the X coordinate
         * @return X coordinate
         */
        inline int x() const { return _x; }
        /**
         * @brief Return the Y coordinate
         * @return Y coordinate
         */
        inline int y() const { return _y; }

        /**
         * @brief Stub destructor
         */
        virtual ~Located() {}

    protected:
        /**
         * @brief Coordinate x
         */
        int _x;
        /**
         * @brief Coordinate y
         */
        int _y;

        /**
         * @brief Create a new instance of fixed position
         * @param Coordinate x
         * @param Coordinate y
         */
        Located(int x = 0, int y = 0) : _x(x), _y(y) {}
};

#endif // LOCATED_H
