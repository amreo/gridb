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

		/**
		 * @brief Sum the left and the right
		 * @param left
		 * @param right
		 * @return the sum of left and right
		 */
		static Coord sum(const Located& left, const Located& right);
		/**
		 * @brief Sub the left and the right
		 * @param left
		 * @param right
		 * @return the sum of left and -right
		 */
		static Coord sub(const Located& left, const Located& right);


		/**
		 * @brief Move the coord by offset right
		 * @param Offset X and Y
		 * @return the coord moved
		 */
		Coord operator+(const Located& right);
		/**
		 * @brief Move the coord by -offset right
		 * @param Offset X and Y
		 * @return the coord moved
		 */
		Coord operator-(const Located& right);
	signals:

	public slots:
};

#endif // COORD_H
