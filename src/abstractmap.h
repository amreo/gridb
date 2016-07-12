#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H
#include "abstractlocated.h"
#include "abstracttile.h"
#include "coord.h"
#include <QSize>
/**
 * @brief The AbstractMap class
 */
class AbstractMap
{
    public:
        /**
         * @brief GetMapTile
         * @param x
         * @param y
         * @return
         */
        virtual AbstractMapTile GetMapTile(int x, int y) const;
        /**
         * @brief GetMapTile
         * @param c
         * @return
         */
        virtual AbstractMapTile GetMapTile(AbstractLocated c) const;

        /**
         * @brief GetTile
         * @param x
         * @param y
         * @return
         */
        virtual AbstractTile GetTile(int x, int y) const;
        /**
         * @brief GetTile
         * @param c
         * @return
         */
        virtual AbstractTile GetTile(AbstractLocated c) const;

        /**
         * @brief GetDefaultTile
         * @return
         */
        virtual AbstractTile GetDefaultTile() const;

        /**
         * @brief GetSize
         * @return
         */
        virtual Qsize GetSize() const;
        /**
         * @brief GetLocation
         * @return
         */
        virtual Coord GetLocation() const;

        /**
         * @brief SetTile
         * @param x
         * @param y
         * @param tile
         */
        virtual void SetTile(int x, int y, AbstractTile* tile);
        /**
         * @brief SetTile
         * @param Tile
         */
        virtual void SetTile(AbstractLocated&, AbstractTile* Tile);

        /**
         * @brief SetDefaultTile
         * @param Tile
         */
        virtual void SetDefaultTile(AbstractTile* Tile);

        /**
         * @brief InitMap
         */
        virtual void InitMap();

        /**
         * @brief IsValid
         * @param c
         * @return
         */
        virtual bool IsValid(AbstractLocated c);
        /**
         * @brief IsValid
         * @param cX
         * @param cY
         * @return
         */
        virtual bool IsValid(int cX, int cY);

        /**
         * @brief NotifyChange
         * @param src
         * @param dest
         */
        virtual void NotifyChange(AbstractActor&, AbstractMapTile* src, AbstractMapTile* dest);

        /**
         * @brief SetActor
         */
        virtual void SetActor(AbstractActor&);
        /**
         * @brief GetActor
         * @param c
         * @return
         */
        virtual AbstractActor GetActor(AbstractLocated c) const;
        /**
         * @brief GetActor
         * @param x
         * @param y
         * @return
         */
        virtual AbstractActor GetActor(int x, int y) const;
        /**
         * @brief DespawnActor
         */
        virtual void DespawnActor (AbstractActor&);
)
#endif // ABSTRACTMAP_H
