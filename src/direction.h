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
		/**
		 * @brief Copy costructor of Direction
		 * @param dir
		 */
		Direction(const Direction& dir);

		/**
		 * @brief Return the coefficient of x
		 * @return The coefficient of x
		 */
		int getCoefficientX();
		/**
		 * @brief Return the coefficient of y
		 * @return The coefficient of y
		 */
		int getCoefficientY();

		/**
		 * @brief Return the angle(time) of direction, 0=UP, 1=UP_RIGHT, 2=RIGHT, ...
		 * @return The angle(time) of direction
		 */
		int getDirectionAngle();

		/**
		 * @brief Return the direction opposite of this
		 * @return The direction opposite of this
		 */
		Direction getDirectionOpposite();
		/**
		 * @brief Return the direction rotated clockwise of 45° degrees for times time.
		 * @param angle number of rotation. if it's negative then it mean counterclockwise
		 * @return The direction rotated clockwise of 45° degrees for times time
		 */
		Direction getDirectionRotated(int angle);

		/**
		 * @brief Set the direction of this
		 * @param new direction
		 */
		void setDirection(const Direction& dir);
		/**
		 * @brief Set the direction of this
		 * @param New coefficient X
		 * @param New coefficient Y
		 */
		void setDirection(const int coefficientX, const int coefficientY);
		/**
		 * @brief Set the direction of this from angle(time)
		 * @param angle
		 */
		void setDirection(int angle);

		/**
		 * @brief Set the coefficient X
		 * @param New coefficient X
		 */
		void setCoefficientX(const int coefficientX);
		/**
		 * @brief Set the coefficient Y
		 * @param New coefficient Y
		 */
		void setCoefficientY(const int coefficientY);

		/**
		 * @brief Sum the direction left and right
		 * @param dir1 Direction 1
		 * @param dir2 Direction 2
		 * @return the direction summed
		 */
		static Direction sum(const Direction& dir1, const Direction& dir2);
		/**
		 * @brief Sum the direction left and right
		 * @param dir1 Direction 1
		 * @param dir2 Direction 2
		 * @return the direction summed
		 */
		static Direction sum(const int coeX1, const int coeY1, const int coeX2, const int coeY2);
		/**
		 * @brief Sub the direction left and right
		 * @param dir1 Direction 1
		 * @param dir2 Direction 2
		 * @return the direction 1 - direction 2
		 */
		static Direction sub(const Direction& dir1, const Direction& dir2);
		/**
		 * @brief Sub the direction left and right
		 * @param dir1 Direction 1
		 * @param dir2 Direction 2
		 * @return the direction 1 - direction 2
		 */
		static Direction sub(const int coeX1, const int coeY1, const int coeX2, const int coeY2);

		/**
		 * @brief Check if the dir1 and dir2 are equal
		 * @param dir1 first direction
		 * @param dir2 second direction
		 * @return true if are equal, else false
		 */
		static bool equal(const Direction& dir1, const Direction& dir2);

		/**
		 * @brief Sum the directions
		 * @param dir2 second Direction
		 * @return dir1 + dir2
		 */
		Direction operator+ (const Direction& dir2);
		/**
		 * @brief Sub the directions
		 * @param dir2 second Direction
		 * @return dir1 - dir2
		 */
		Direction operator- (const Direction& dir2);

		/**
		 * @brief Check if the directions are equal
		 * @param dir2 second direction
		 * @return true if ar equal, else false
		 */
		bool operator== (const Direction& dir2);
		/**
		 * @brief Check if the directions aren't equal
		 * @param dir2 second direction
		 * @return false if ar equal, else true
		 */
		bool operator!= (const Direction& dir2);

		/**
		 * @brief Direction NONE (0; 0)
		 */
		static Direction NONE;
		/**
		 * @brief Direction UP (0; -1)
		 */
		static Direction UP;
		/**
		 * @brief Direction UP_RIGHT (1; -1)
		 */
		static Direction UP_RIGHT;
		/**
		 * @brief Direction RIGHT (1; 0)
		 */
		static Direction RIGHT;
		/**
		 * @brief Direction DOWN_RIGHT (1; 1)
		 */
		static Direction DOWN_RIGHT;
		/**
		 * @brief Direction DOWN (0; 1)
		 */
		static Direction DOWN;
		/**
		 * @brief Direction DOWN_LEFT (-1; 1)
		 */
		static Direction DOWN_LEFT;
		/**
		 * @brief Direction LEFT (-1; 0)
		 */
		static Direction LEFT;
		/**
		 * @brief Direction UP_LEFT (-1; -1)
		 */
		static Direction UP_LEFT;

	protected:
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
