#ifndef SQUAREDEUCLIDEANDISTANCEFUNCTION_H
#define SQUAREDEUCLIDEANDISTANCEFUNCTION_H
#include "abstractdistancefunction.h"

/**
 * @brief Rappresent a functor that return the squared euclidean distance between p1 and p2
 * @version 0.1
 * @since 0.3
 */
class SquaredEuclideanDistanceFunction : public AbstractDistanceFunction
{
	public:
		/**
		 * @brief Calculate the distance between x1/y1 and x2/y2
		 * @param Coordinate X of first point
		 * @param Coordinate Y of first point
		 * @param Coordinate X of second point
		 * @param Coordinate Y of second point
		 * @return the distance between first and second point
		 */
		virtual float operator() (int x1, int y1, int x2, int y2) const;

};

#endif // SQUAREDEUCLIDEANDISTANCEFUNCTION_H