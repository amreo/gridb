#ifndef GRIDCOORDSELECTER_H
#define GRIDCOORDSELECTER_H
#include "coordselecter.h"
#define SELECTED true
#define DESELECTED false

class GridCoordSelecter : public CoordSelecter
{
	public:
		/**
		 * @brief Costructor of GridCoordSelecter
		 * @param offX offsetX
		 * @param offY offsetY
		 * @param width
		 * @param height
		 */
		GridCoordSelecter(int offX = -10, int offY = -10, int width = 20, int height = 20);
		/**
		 * @brief Destructor of GridCoordSelecter
		 */
		~GridCoordSelecter();


		/**
		 * @brief Return the offset X of GridCoordSelecter
		 * @return The offset X
		 */
		int offsetX();
		/**
		 * @brief Return the offset Y of GridCoordSelecter
		 * @return The offset Y
		 */
		int offsetY();
		/**
		 * @brief Return the limit of width
		 * @return The limit of width
		 */
		int width();
		/**
		 * @brief Return the limit of height
		 * @return The limit of height
		 */
		int height();

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
		bool isSelected(const Located& loc) const;
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
		const QLinkedList<Located> getSelection() const;


	protected:
		int _offX;
		int _offY;
		int _width;
		int _height;
		bool* grid;

		/**
		 * @brief Check if the X and Y are in the bounds
		 * @param Coordinate X
		 * @param Coordinate Y
		 * @return True if are in the bound, else false
		 */
		bool checkBounds(int x, int y) const;
		/**
		 * @brief Set the cell of grid to value
		 * @param x
		 * @param y
		 * @param value
		 */
		void SetInternalState(int x, int y, bool value = SELECTED );
		/**
		 * @brief Get the value of the cell
		 * @param x
		 * @param y
		 */
		bool InternalState(int x, int y) const;
};

#endif // GRIDCOORDSELECTER_H
