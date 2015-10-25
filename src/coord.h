#ifndef COORD_H
#define COORD_H
#include "movable.h"

/**
 * @brief This class rappresent a position in 2D space
 * @author amreo
 * @version 0.1
 * @since 0.1
 */
class Coord : public Movable
{
		Q_OBJECT
	public:
		/**
		 * @brief Create a new instance of coord
		 * @param Coordinate x
		 * @param Coordinate y
		 */
		Coord(int x = 0, int y = 0, QObject *parent = 0);

	signals:

	public slots:

};

#endif // COORD_H
