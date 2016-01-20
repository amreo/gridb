#ifndef MOVEEVENT_H
#define MOVEEVENT_H
#include "coord.h"

/**
 * @brief Event class that contains source location and destination location
 * @version 0.1
 * @since 0.3
 */
class moveEvent
{
    protected:
        /**
         * @brief Source location of the event
         */
        Coord& source;
        /**
         * @brief Destination location of th event
         */
        Coord& destination;

    public:
        /**
         * @brief Create a new event object
         * @param source location
         * @param destination location
         */
        inline moveEvent(const Coord& source, const Coord& destination) { this->source = source; this->destination = destination; }

        /**
         * @brief Set the source of the moveEvent
         * @param source
         */
        inline void setSource(const Coord& source) { this->source = source; }
        /**
         * @brief Set the destination of the moveEvent
         * @param destination
         */
        inline void setDestination(const Coord& destination) { this->destination = destination; }
        /**
         * @brief Get the source of the movement
         * @return the source of the movement
         */
        inline const Coord& source() const { return source; }
        /**
         * @brief Get the destination of the movement
         * @return the destination of the movement
         */
        inline const Coord& destination() const { return destination; }

};

#endif // MOVEEVENT_H
