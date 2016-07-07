#ifndef ABSTRACTMAPTILE_H
#define ABSTRACTMAPTILE_H
#include "abstractlocated.h"
#include "abstracttile.h"
/**
 * @brief This class is a base class of any MapTile contained in a Map
 */
class AbstractMapTile : public virtual AbstractLocated
{
    public:
        /**
         * @brief Return the map of this MapTile
         * @return The map of this MapTile
         */
        virtual AbstractMap* map() const;
        /**
         * @brief Return the tile of this MapTile
         * @return Tile of this MapTile
         */
        virtual AbstractTile* tile() const;
        /**
         * @brief Set the tile of this MapTile
         * @param The tile to set
         * @remarks When the tile is setted, It raises the signal of changing tile
         */
        virtual void setTile(AbstractTile* tile);
        /**
         * @brief Set the tile of this MapTile
         * @param The tile to set
         * @remarks When the tile is setted, It doesn't raise the signal of changing tile
         */
        virtual void setUnsecureTile(AbstractTile* tile);

        /**
         * @brief Remove the tile of this MapTile
         * @remarks The signal of changing tile is activated
         */
        virtual void removeTile();
        /**
         * @brief Remove the tile of this MapTile
         * @remarks The signal of changing tile is not activated
         */
        virtual void removeUnsecureTile();

        /**
         * @brief Return true if this MapTile has got a tile
         * @return True if this MapTile has got a tile
         */
        virtual bool hasTile() const;

        /**
         * @brief Initialize the MapTile and the actor
         */
        virtual void init();
        /**
         * @brief Update the tile
         */
        virtual void updateTile();

        /**
         * @brief Set the actor on this MapTile
         * @param The actor to set
         */
        virtual void setActor(AbstractActor* actor);
        /**
         * @brief Return the actor on this MapTile
         * @return The actor on this MapTile
         */
        virtual AbstractActor* actor() const;
        /**
         * @brief Return true if there is a actor on this MapTile
         * @return True if there is a actor on this MapTile
         */
        virtual bool hasActor() const;
        /**
         * @brief Return true if the actor can enter in this MapTile
         * @param The actor
         * @return True if the actor can enter in this MapTile
         */
        virtual bool canActorEnterIn(AbstractActor* actor) const;
};

#endif // ABSTRACTMAPTILE_H
