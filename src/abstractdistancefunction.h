#ifndef ABSTRACTDISTANCEFUNCTION_H
#define ABSTRACTDISTANCEFUNCTION_H
#include "abstractlocated.h"
/**
 * @brief Rappresent a generic functor that return the distance between p1 and p2
 * @version 0.1
 * @since 0.3
 */
class AbstractDistanceFunction
{
	public:
		/**
		 * @brief Calculate the distance between loc1 and loc2
		 * @param First point
		 * @param Second point
		 * @return the distance between first and second point
		 */
        virtual float inline operator() (const AbstractLocated& loc1, const AbstractLocated& loc2) const
		{ return this->operator ()(loc1.x(), loc1.y(), loc2.x(), loc2.y()); }
		/**
		 * @brief Calculate the distance between x1/y1 and x2/y2
		 * @param Coordinate X of first point
		 * @param Coordinate Y of first point
		 * @param Coordinate X of second point
		 * @param Coordinate Y of second point
		 * @return the distance between first and second point
		 */
        virtual float operator() (int x1, int y1, int x2, int y2) const = 0;
};

#endif // ABSTRACTDISTANCEFUNCTION_H
