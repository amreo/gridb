#ifndef MOVABLE_H
#define MOVABLE_H

#include <QObject>
#include "located.h"
#include "direction.h"

/**
 * @brief This class is the base class of any movable objects in 2D space
 * @author amreo
 * @version 0.1
 * @since 0.1
 */
class Movable : public QObject, public Located
{
		Q_OBJECT

	public:

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

	signals:
		/**
		 * @brief This signal is emitted whenever the location is changed
		 * @param New location
		 */
		void locationChanged(const Located& newLocation);

	public slots:
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

		/**
		 * @brief Move the coordinate by offset
		 * @param offset x
		 * @param offset y
		 */
		void move(int offsetX, int offsetY);
		/**
		 * @brief Move the coordinate by direction and offset
		 * @param dir
		 * @param offset
		 */
		void move(const Direction& dir, int offset = 0);
		/**
		 * @brief Move the coordinate by the offset
		 * @param offset X and Y
		 */
		void move(const Located& offset);

	protected:
		/**
		 * @brief Create a new instance of movable position or object
		 * @param Coordinate x
		 * @param Coordinate y
		 */
		Movable(int x = 0, int y = 0, QObject *parent = 0);
};

#endif // MOVABLE_H
