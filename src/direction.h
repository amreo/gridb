#ifndef DIRECTION_H
#define DIRECTION_H
#include "src_global.h"

/**
 * @brief This class rappresent a one direction (up, down, ...)
 * @version 1.0
 * @since 1.0
 */
class SRCSHARED_EXPORT Direction
{
	public:
		/**
		 * @brief Create a new instance of direction
		 * @param coefficient X
		 * @param coefficient Y
		 */
		Direction(int coefficientX = 0, int coefficientY = 0);

	//protected:
		/**
		 * @brief Coefficient X of direction.
		 * * -1 to left
		 * * +1 to right
		 * * 0 no move
		 */
		short int coefficientX;
		/**
		 * @brief Coefficient Y of direction.
		 * * -1 to up
		 * * +1 to down
		 * * 0 no move
		 */
		short int coefficientY;

};

#endif // DIRECTION_H
