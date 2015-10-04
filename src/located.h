#ifndef LOCATED_H
#define LOCATED_H

#include "src_global.h"

/**
 * @brief The Located class
 *        This class is the base class of any non-movable objects
 *		  and it can rappresent a fixed position in 2D space
 * @author amreo
 * @version 1.0
 * @since 1.0
 */
class SRCSHARED_EXPORT Located
{

	public:
		Located();
		Located(int x, int y);

	//protected:
		int x;
		int y;
};

#endif // LOCATED_H
