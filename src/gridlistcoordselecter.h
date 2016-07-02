#ifndef GRIDLISTCOORDSELECTER_H
#define GRIDLISTCOORDSELECTER_H
#include "listcoordselecter.h"
#include <QLinkedListNode>


class GridListCoordSelecter : public ListCoordSelecter
{
    public:
        /**
         * @brief Costructor
         */
        GridListCoordSelecter(int offX = -10, int offY = -10, int width = 20, int height = 20);
        /**
         * @brief Distructor
         */
        virtual ~GridListCoordSelecter();


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
         * @brief Check if the X and Y are in the bounds
         * @param Coordinate X
         * @param Coordinate Y
         * @return True if are in the bound, else false
         */
        bool checkBounds(int x, int y) const;

    protected:
        int _offX;
        int _offY;
        int _width;
        int _height;

        typedef QLinkedList<Coord>::iterator ptr_QLinkedListNode;
        ptr_QLinkedListNode* grid;
        bool* gridBool; //TODO: remove bool grid

        /**
         * @brief Set the cell of grid to value
         * @param x
         * @param y
         * @param value
         */
        void SetInternalState(int x, int y, ptr_QLinkedListNode value);
        /**
         * @brief Get the value of the cell
         * @param x
         * @param y
         */
        ptr_QLinkedListNode InternalState(int x, int y) const;

        /**
         * @brief Set the cell of grid (bool) to value
         * @param x
         * @param y
         * @param value
         */
        void SetInternalStateBool(int x, int y, bool value);
        /**
         * @brief Get the value of the cell (bool)
         * @param x
         * @param y
         */
        bool InternalStateBool(int x, int y) const;

};

#endif // GRIDLISTCOORDSELECTER_H
