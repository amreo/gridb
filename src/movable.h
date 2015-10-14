#ifndef MOVABLE_H
#define MOVABLE_H

#include <QObject>
#include "located.h"

/**
 * @brief This class is the base class of any movable objects
 *		  and it can rappresent a movable position in 2D space
 * @author amreo
 * @version 0.1
 * @since 0.1
 */
class Movable : public QObject, public Located
{
		Q_OBJECT

	public:
		/**
		 * @brief Create a new instance of movable position or object
		 * @param Coordinate x
		 * @param Coordinate y
		 */
		Movable(int x = 0, int y = 0, QObject *parent = 0);

		/**
		 * @brief Create a new instance of movable position from movable object
		 * @param Movable object
		 */
		Movable(const Movable& loc);
		/**
		 * @brief Create a new instance of movable position from located object
		 * @param Located object
		 */
		Movable(const Located& loc);

		/**
		 * @brief Set the coordinate X
		 * @param New coordinte X
		 */
		void setX(int x);
		/**
		 * @brief Set the coordinate Y
		 * @param New coordinte Y
		 */
		void setY(int y);

		/**
		 * @brief Set the coordinate x and y
		 * @param New coordinate x
		 * @param New coordinate y
		 */
		void setMovable(int x, int y);
		/**
		 * @brief Set the coordinate x and y from loc
		 * @param Located object
		 */
		void setMovable(const Located& loc);


	signals:

	public slots:

};

#endif // MOVABLE_H
