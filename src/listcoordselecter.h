#ifndef LISTCOORDSELECTER_H
#define LISTCOORDSELECTER_H
#include "coordselecter.h"
#include <QLinkedList>
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
		 * @brief Costructor
		 */
		ListCoordSelecter();
		/**
         * @brief Distructor
		 */
		virtual ~ListCoordSelecter() {}

		/**
		 * @brief Select  loc
		 * @param loc
		 */
        void select(const AbstractLocated& loc);
        /**
         * @brief Select  loc
         * @param loc
         */
        void select(const AbstractLocated* loc);
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
        void deSelect(const AbstractLocated& loc);
        /**
         * @brief Deselect  loc
         * @param loc
         */
        void deSelect(const AbstractLocated* loc);
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
        bool isSelected(const AbstractLocated& loc) const;
        /**
         * @brief Check if the location is selected
         * @param loc
         */
        bool isSelected(const AbstractLocated* loc) const;
        /**
		 * @brief Check if the location is selected
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		bool isSelected(int x, int y) const;

        /**
         * @brief Return the list of selected coords
         * @return The list of selected coords
         */
        const QLinkedList<Coord> getSelection() const;


	protected:
		/**
		 * @brief A list that contains the selected coords
		 */
        QLinkedList<Coord> list;
};

#endif // LISTCOORDSELECTER_H
