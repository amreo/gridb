#ifndef TILE_H
#define TILE_H
#include "abstracttile.h"

class tile : public AbstractTile
{
    public:
        tile();

        // AbstractTile interface
    public:

        /**
         * @brief Return a copy of itself
         * @return A copy of itself
         */
        virtual AbstractTile *getCopy() const;
        /**
         * @brief Return a copy of itself if static or itself if not static
         * @return A copy of itself if static or itself if not static
         */
        virtual AbstractTile *getInstance() const
        {
            if (isStatic())
                return this;
            else
                return getCopy();
        }

};

#endif // TILE_H
