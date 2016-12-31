#ifndef ABSTRACTMAPTILE_H
#define ABSTRACTMAPTILE_H
#include <QObject>
#include "abstractlocated.h"
#include "abstractmap.h"


class AbstractTile;
class AbstractMap;

/**
 * @brief This class is a base class of any MapTile contained in a Map
 */
class AbstractMapTile : public QObject, public virtual AbstractLocated
{
    Q_OBJECT

    public:

        virtual ~AbstractMapTile() = 0;

        /**
         * @brief Return the map of this MapTile
         * @return The map of this MapTile
         */
        virtual AbstractMap* map() const = 0;
        /**
         * @brief Return the tile of this MapTile
         * @return Tile of this MapTile
         */
        virtual AbstractTile* tile() const = 0;
        /**
         * @brief Set the tile of this MapTile
         * @param The tile to set
         * @remarks When the tile is setted, It raises the signal of changing tile
         */
        virtual void setTile(AbstractTile* tile) = 0;
        /**
         * @brief Set the tile of this MapTile
         * @param The tile to set
         * @remarks When the tile is setted, It doesn't raise the signal of changing tile
         */
        virtual void setUnsecureTile(AbstractTile* tile) = 0;

        /**
         * @brief Remove the tile of this MapTile
         * @remarks The signal of changing tile is activated
         */
        virtual void removeTile() = 0;
        /**
         * @brief Remove the tile of this MapTile
         * @remarks The signal of changing tile is not activated
         */
        virtual void removeUnsecureTile() = 0;

        /**
         * @brief Return true if this MapTile has got a tile
         * @return True if this MapTile has got a tile
         */
        virtual bool hasTile() const = 0;

        /**
         * @brief Initialize the MapTile and the actor
         */
        virtual void init() = 0;
        /**
         * @brief Update the tile
         */
        virtual void updateTile() = 0;

    signals:
        /**
         * @brief This signal is emitted whenever the tile is changed
         */
        /*void changedTile();*/

//        /**
//         * @brief Set the actor on this MapTile
//         * @param The actor to set
//         */
//        virtual void setActor(AbstractActor* actor) = 0;
//        /**
//         * @brief Return the actor on this MapTile
//         * @return The actor on this MapTile
//         */
//        virtual AbstractActor* actor() const = 0;
//        /**
//         * @brief Return true if there is a actor on this MapTile
//         * @return True if there is a actor on this MapTile
//         */
//        virtual bool hasActor() const = 0;
//        /**
//         * @brief Return true if the actor can enter in this MapTile
//         * @param The actor
//         * @return True if the actor can enter in this MapTile
//         */
//        virtual bool canActorEnterIn(AbstractActor* actor) const = 0;
};

#endif // ABSTRACTMAPTILE_H
