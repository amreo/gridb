#ifndef LISTCOORDSELECTER_H
#define LISTCOORDSELECTER_H
#include "coordselecter.h"
#include <QLinkedList>
#include "coord.h"

/**
 * @brief This class rappresent a set of selected coord. It uses a list.
 * @version 0.1
 * @since 0.2
 */
class ListCoordSelecter : public CoordSelecter
{
	public:
		/**
		 * @brief ListCoordSelecter costructor
		 */
		ListCoordSelecter();

		/**
		 * @brief Select  loc
		 * @param loc
		 */
		void select(const Located& loc);
		/**
		 * @brief Select a coord in x and y
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		void select(int x, int y);

		/**
		 * @brief Deselect  loc
		 * @param loc
		 */
		void deSelect(const Located& loc);
		/**
		 * @brief Deselect a coord in x and y
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		void deSelect(int x, int y);

		/**
		 * @brief Check if the location is selected
		 * @param loc
		 */
		bool isSelected(const Located& loc);
		/**
		 * @brief Check if the location is selected
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		bool isSelected(int x, int y);

	protected:
		/**
		 * @brief A list that contains the selected coords
		 */
		QLinkedList<Located> list;
};

#endif // LISTCOORDSELECTER_H