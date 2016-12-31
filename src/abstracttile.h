#ifndef ABSTRACTTILE_H
#define ABSTRACTTILE_H

#include <QObject>
#include <QString>
#include "abstractmaptile.h"
#include "actormoveevent.h"

/**
 * @brief Base-class of any type of Tile
 */
class AbstractTile : public QObject
{
        Q_OBJECT
    public:
        AbstractTile(QObject* parent = 0) : QObject(parent) {}

        /**
         * @brief Return a copy of itself
         * @return A copy of itself
         */
        virtual AbstractTile* getCopy() const = 0;
        /**
         * @brief Return a copy of itself if static or itself if not static
         * @return A copy of itself if static or itself if not static
         */
        virtual AbstractTile* getInstance() const = 0;
        /**
         * @brief Return true if itself is shared between MapTile
         * @return True if itself is shared between MapTile
         */
        virtual bool isStatic() const = 0;

        /**
         * @brief Return the score of this Tile for Path Finding
         * @param Actor that could walk on this tile
         * @return The score of this Tile for Path Finding
         * @remarks The score depend by actor
         */
//        virtual float getPathFinderScore(const AbstractActor* actor, const AbstractMapTile* tile) const = 0;

        /**
         * @brief Return the name of this Tile
         * @return The name of this Tile
         */
        virtual QString getName() const = 0;

        /**
         * @brief Init this tile of mapTile
         * @param MapTile that contain this tile (if not static)
         */
        virtual void init(AbstractMapTile* ref) { Q_UNUSED(ref) }

        /**
         * @brief Update this tile of mapTile
         * @param MapTile that contain this tile (if not static)
         */
        virtual void update(AbstractMapTile* ref) { Q_UNUSED(ref) }

        /**
         * @brief Return true if this tile is equal to second tile
         * @param second tile
         * @return True if they are equal
         */
        virtual bool isEqual(const AbstractTile* tile2) const = 0;

        /**
         * @brief Emit the event Actor entering event
         * @param event
         */
        bool inline emitActorEnteringEvent( ActorMoveEvent& event)
        {
            actorEnteringEvent(event);
            if (!event.cancel())
                emit actorEntering(event);
            return event.cancel();
        }
        /**
         * @brief Emit the event Actor entered event
         * @param event
         */
        void inline emitActorEnteredEvent(ActorMoveEvent& event)
        {
            actorEnteredEvent(event);
            emit actorEntered(event);
        }
        /**
         * @brief Emit the event Actor leaving event
         * @param event
         */
        bool inline emitActorLeavingEvent(ActorMoveEvent& event)
        {
            actorLeavingEvent(event);
            if (!event.cancel())
                emit actorLeaving(event);
            return event.cancel();
        }
        /**
         * @brief Emit the event Actor leaved event
         * @param event
         */
        void inline emitActorLeavedEvent(ActorMoveEvent& event)
        {
            actorLeavedEvent(event);
            emit actorEntering(event);
        }

        /**
         * @brief
         * @param event
         */
        virtual void actorEnteringEvent(ActorMoveEvent& event) { Q_UNUSED(event) }
        /**
         * @brief actorEnteredEvent
         * @param event
         */
        virtual void actorEnteredEvent(ActorMoveEvent& event) { Q_UNUSED(event) }
        /**
         * @brief actorLeavingEvent
         * @param event
         */
        virtual void actorLeavingEvent(ActorMoveEvent& event) { Q_UNUSED(event) }
        /**
         * @brief actorLeavedEvent
         * @param event
         */
        virtual void actorLeavedEvent(ActorMoveEvent& event) { Q_UNUSED(event) }

    signals:
        /**
         * @brief This signal is emitted when a Actor is entering in this tile
         * @param event
         */
        void actorEntering(ActorMoveEvent& event);
        /**
         * @brief This signal is emitted when a Actor is entered in this tile
         * @param event
         */
        void actorEntered(ActorMoveEvent& event);
        /**
         * @brief This signal is emitted when a Actor is leaving this tile
         * @param event
         */
        void actorLeaving(ActorMoveEvent& event);
        /**
         * @brief This signal is emitted when a Actor is leaved this tile
         * @param event
         */
        void actorLeaved(ActorMoveEvent& event);

    public slots:

};

#endif // ABSTRACTTILE_H
