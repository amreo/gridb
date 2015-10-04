#ifndef LOCATED_H
#define LOCATED_H

#include "src_global.h"

/**
 * @brief This class is the base $class class of any non-movable objects
 *		  and it can rappresent a fixed position in 2D space
 * @author amreo
 * @version 1.0
 * @since 1.0
 */
class SRCSHARED_EXPORT Located
{

	public:
		/**
		 * @brief Create a new instance of fixed position
		 *		X = 0 and Y = 0
		 */
		Located();
		/**
		 * @brief Create a new instance of fixed position
		 * @param Coordinate x
		 * @param Coordinate y
		 */
		Located(int x, int y);

		/**
		 * @brief Return the X coordinate
		 * @return X coordinate
		 */
		int getX();
		/**
		 * @brief Return the Y coordinate
		 * @return Y coordinate
		 */
		int getY();

	protected:
		/**
		 * @brief Coordinate x
		 */
		int x;
		/**
		 * @brief Coordinate y
		 */
		int y;
};

#endif // LOCATED_H
