#ifndef ACTORMOVEEVENT_H
#define ACTORMOVEEVENT_H
#include "abstractmaptile.h"

/**
 * @brief This class contains information about a move event
 */
class ActorMoveEvent
{
    public:
//        /**
//         * @brief Create a new instance of ActorMoveEvent
//         * @param From of the moveement
//         * @param Destination of the moveement
//         * @param Actor that is moving
//         */
//        ActorMoveEvent(AbstractMapTile& src, AbstractMapTile& dest, AbstractActor& actor);

        /**
         * @brief Return the source of the moveement
         * @return The source of the moveement
         */
        inline AbstractMapTile& src();
        /**
         * @brief Return the destination of the moveement
         * @return The destination of the moveement
         */
        inline AbstractMapTile& dest();

        /**
         * @brief Set the cancel value
         */
        inline void setCancel(bool value) { _cancel = value; }
        /**
         * @brief Return true if cancel the event, otherwise false
         * @return The cancel value
         */
        inline bool cancel() { return _cancel; }

    protected:
        /**
         * @brief Source of the moveement
         */
        AbstractMapTile* _src;
        /**
         * @brief Destination of the moveement
         */
        AbstractMapTile* _dest;
        /**
         * @brief The actot that is moving
         */
//        AbstactActor& _actor;
        /**
         * @brief True if is cancelling the moveement, otherwise false
         */
        bool _cancel;
};

#endif // ACTORMOVEEVENT_H
