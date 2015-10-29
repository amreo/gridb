#ifndef COORDSELECTER_H
#define COORDSELECTER_H
#include "located.h"

/**
 * @brief This class rappresent a set of selected coord
 * @version 0.1
 * @since 0.2
 */
class CoordSelecter
{
	public:

		/**
		 * @brief Select  loc
		 * @param loc
		 */
		virtual void select(const Located& loc) = 0;
		/**
		 * @brief Select a coord in x and y
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		virtual void select(int x, int y) = 0;
		/**
		 * @brief Select a list of coord
		 * @param list of coord
		 * @param n of elemenent
		 */
		void select(const Located list[], int n);

		/**
		 * @brief Deselect  loc
		 * @param loc
		 */
		virtual void deSelect(const Located& loc) = 0;
		/**
		 * @brief Deselect a coord in x and y
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		virtual void deSelect(int x, int y) = 0;
		/**
		 * @brief Deselect a list of coord
		 * @param list of coord
		 * @param n of elemenent
		 */
		void deSelect(const Located list[], int n);



		/**
		 * @brief Check if the location is selected
		 * @param loc
		 */
		virtual bool isSelected(const Located& loc) = 0;
		/**
		 * @brief Check if the location is selected
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		virtual bool isSelected(int x, int y) = 0;
		/**
		 * @brief Check if the all coords in the list are selected
		 * @param list of coord
		 * @param n of elemenent
		 */
		bool isSelected(const Located list[], int n);

};

#endif // COORDSELECTER_H
