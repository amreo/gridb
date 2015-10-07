#ifndef LOCATED_H
#define LOCATED_H

#include "src_global.h"

/**
 * @brief This class is the base class of any non-movable objects
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
		 * @param Coordinate x
		 * @param Coordinate y
		 */
		Located(int x = 0, int y = 0);

		/**
		 * @brief Create a new instance of fixed position from located object
		 * @param Located object
		 */
		Located(const Located& loc);

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
		/**
		 * @brief Return the location of this object
		 * @return Location of this object
		 */
		Located getLocation();

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
