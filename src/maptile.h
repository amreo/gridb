#ifndef MAPTILE_H
#define MAPTILE_H
#include "abstractmaptile.h"
#include "located.h"

/**
 * @brief A base-class of any generic MapTile
 */
class MapTile : public AbstractMapTile, public Located
{

    public:
        /**
         * @brief Create a new instance of MapTile
         * @param x
         * @param y
         * @param map
         */
        MapTile(int x, int y, AbstractMap* map) : Located(x,y)
        { _map = map; }
        MapTile(const AbstractLocated& loc, AbstractMap* map) : Located(loc.x(), loc.y())
        { _map = map; }
        MapTile(const AbstractLocated* loc, AbstractMap* map) : Located(loc->x(), loc->y())
        { _map = map; }

        ~MapTile() {}

        // AbstractMapTile interface
    public:

        /**
         * @brief Return the map of this MapTile
         * @return The map of this MapTile
         */
        virtual inline AbstractMap* map() const { return _map; }

        /**
         * @brief Return the tile of this MapTile
         * @return Tile of this MapTile
         */
        virtual inline AbstractTile* tile() const { return _tile; }
        /**
         * @brief Set the tile of this MapTile
         * @param The tile to set
         * @remarks When the tile is setted, It raises the signal of changing tile
         */
        virtual void setTile(AbstractTile* tile)
        { _tile = tile; /*emit changedTile();*/ }
        /**
         * @brief Set the tile of this MapTile
         * @param The tile to set
         * @remarks When the tile is setted, It doesn't raise the signal of changing tile
         */
        virtual void setUnsecureTile(AbstractTile* tile) { _tile = tile; }
        /**
         * @brief Remove the tile of this MapTile
         * @remarks The signal of changing tile is activated
         */
        virtual void removeTile()
        { _tile = nullptr; /*TODO: activate signal*/ }
        /**
         * @brief Remove the tile of this MapTile
         * @remarks The signal of changing tile is not activated
         */
        virtual void removeUnsecureTile() { _tile = nullptr; /*emit changedTile();*/ }
        /**
         * @brief Return true if this MapTile has got a tile
         * @return True if this MapTile has got a tile
         */
        virtual inline bool hasTile() const {return _tile != nullptr; }

        /**
         * @brief Initialize the MapTile and the actor
         */
        virtual void init() { _tile->init(this); }
        /**
         * @brief Update the tile
         */
        virtual void updateTile() { _tile->update(this); }

//        /**
//         * @brief Set the actor on this MapTile
//         * @param The actor to set
//         */
//        virtual void setActor(AbstractActor* actor) { _actor = &actor; }
//        /**
//         * @brief Return the actor on this MapTile
//         * @return The actor on this MapTile
//         */
//        virtual AbstractActor* actor() const { return *_actor; }
//        /**
//         * @brief Return true if there is a actor on this MapTile
//         * @return True if there is a actor on this MapTile
//         */
//        virtual inline bool hasActor() const { return _actor != nullptr; }
//        /**
//         * @brief Return true if the actor can enter in this MapTile
//         * @param The actor
//         * @return True if the actor can enter in this MapTile
//         */
//        virtual bool canActorEnterIn(AbstractActor* actor) const
//        {
//            if (!hasActor() && hasTile())
//                return _tile.canActorEnterIn(this, actor);
//            else
//                return false;
//        }

    protected:
        /**
         * @brief The map
         */
        AbstractMap* _map;
        /**
         * @brief The tile
         */
        AbstractTile* _tile;
//        /**
//         * @brief The actor
//         */
//        AbstractActor* _actor;
};

#endif // MAPTILE_H
