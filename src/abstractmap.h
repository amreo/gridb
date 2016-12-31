#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H
#include "abstractlocated.h"
#include "abstractmaptile.h"
#include "coord.h"
#include <QSize>

class AbstractMapTile;
class AbstractTile;

/**
 * @brief This class is the base class of any kind of grid map
 * @author amreo, amdev10
 * @version 0.1
 * @since 0.4
 */
class AbstractMap : public QObject
{
    Q_OBJECT
    public:
        /**
         * @brief Return the map tile at the specified coord
         * @param Coord x
         * @param Coord y
         * @return The map tile at the specified coord
         */
        virtual AbstractMapTile* mapTile(int x, int y) const = 0;
        /**
         * @brief Return the map tile at the specified coord
         * @return The map tile at the specified coord
         */
        virtual AbstractMapTile* mapTile(const AbstractLocated& c) const = 0;

        /**
         * @brief Return the default tile of the map where there is no a mapTile setted
         * @return The default tile of the map
         */
        virtual AbstractTile* defaultTile() const = 0;

        /**
         * @brief Return the size of the map where there is no a mapTile setted
         * @return The size of the map
         */
        virtual QSize size() const = 0;

        /**
         * @brief Set the default tile of the map where there is no a mapTile setted
         * @param Default tile
         */
        virtual void setDefaultTile(AbstractTile* Tile) = 0;

        /**
         * @brief Initialize the status of the map and relatives tile
         */
        virtual void initMap() = 0;

        /**
         * @brief Check if the specified coord is valid for the map
         * @param Coord
         * @return True if the coord c is valid, otherwise false
         */
        virtual bool isValid(const AbstractLocated& c) const = 0;

        /**
         * @brief Check if the specified coord is valid for the map
         * @param Coord X
         * @param Coord Y
         * @return True if the coord c is valid, otherwise false
         */
        virtual bool isValid(int cX, int cY) const = 0;


        signals:
//        /**
//         * @brief NotifyChange
//         * @param src
//         * @param dest
//         */
//        virtual void notifyChange(const AbstractActor* act, const AbstractMapTile* src, const AbstractMapTile* dest);

};
#endif // ABSTRACTMAP_H
