#ifndef COORDSELECTER_H
#define COORDSELECTER_H
#include "coord.h"
#include <QLinkedList>

/**
 * @brief This class rappresent a set of selected coord
 * @version 0.1
 * @since 0.2
 */
class CoordSelecter
{
	public:

        /**
         * @brief Virtual destructor
         */
        virtual ~CoordSelecter() {}

		/**
		 * @brief Select  loc
		 * @param loc
		 */
        virtual void select(const AbstractLocated& loc) = 0;
        /**
         * @brief Select  loc
         * @param loc
         */
        virtual void select(const AbstractLocated* loc) = 0;
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
        void select(const AbstractLocated* list[], int n);

		/**
		 * @brief Deselect  loc
		 * @param loc
		 */
        virtual void deSelect(const AbstractLocated& loc) = 0;
        /**
         * @brief Deselect  loc
         * @param loc
         */
        virtual void deSelect(const AbstractLocated* loc) = 0;
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
        void deSelect(const AbstractLocated* list[], int n);

		/**
		 * @brief Check if the location is selected
		 * @param loc
		 */
        virtual bool isSelected(const AbstractLocated& loc) const = 0;
        /**
         * @brief Check if the location is selected
         * @param loc
         */
        virtual bool isSelected(const AbstractLocated* loc) const = 0;
		/**
		 * @brief Check if the location is selected
		 * @param x coordinate x
		 * @param y coordinate y
		 */
		virtual bool isSelected(int x, int y) const = 0;
		/**
		 * @brief Check if the all coords in the list are selected
		 * @param list of coord
		 * @param n of elemenent
		 */
        bool isSelected(const AbstractLocated* list[], int n) const;


		/**
		 * @brief Return the list of selected coords
		 * @return The list of selected coords
		 */
        virtual const QLinkedList<Coord> getSelection() const = 0;
};

#endif // COORDSELECTER_H
