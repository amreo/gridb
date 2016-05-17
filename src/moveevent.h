#ifndef MOVEEVENT_H
#define MOVEEVENT_H
#include "abstractlocated.h"

/**
 * @brief Event class that contains source location and destination location
 * @version 0.1
 * @since 0.3
 */
class MoveEvent
{
    protected:
        /**
         * @brief Source location of the event
         */
        AbstractLocated& source;
        /**
         * @brief Destination location of th event
         */
        AbstractLocated& destination;

    public:
        /**
         * @brief Create a new event object
         * @param source location
         * @param destination location
         */
        inline MoveEvent(const AbstractLocated& source, const AbstractLocated& destination) { this->source = source; this->destination = destination; }

        /**
         * @brief Set the source of the moveEvent
         * @param source
         */
        inline void setSource(const AbstractLocated& source) { this->source = source; }
        /**
         * @brief Set the destination of the moveEvent
         * @param destination
         */
        inline void setDestination(const AbstractLocated& destination) { this->destination = destination; }
        /**
         * @brief Get the source of the movement
         * @return the source of the movement
         */
        inline const AbstractLocated& source() const { return source; }
        /**
         * @brief Get the destination of the movement
         * @return the destination of the movement
         */
        inline const AbstractLocated& destination() const { return destination; }

};

#endif // MOVEEVENT_H
