#ifndef ABSTRACTLOCATED_H
#define ABSTRACTLOCATED_H

/**
 * @brief This class is the base class of any non-movable objects in 2D space (without full implementation)
 * @author amreo
 * @version 0.1
 * @since 0.4
 */
class AbstractLocated
{
public:

    /**
     * @brief Return the X coordinate
     * @return X coordinate
     */
    virtual int x() const = 0;
    /**
     * @brief Return the Y coordinate
     * @return Y coordinate
     */
    virtual int y() const = 0;


    /**
     * @brief Check if the location are equal
     * @param Second location
     * @return True if are in the same location (x and y), else false
     */
    bool operator== (const AbstractLocated& second) const
    { return (this->x() == second.x()) && (this->y() == second.y()); }
    /**
     * @brief Check if the location are inequal
     * @param Second location
     * @return True if are in the same location (x and y), else false
     */
    bool operator!= (const AbstractLocated& second) const
    { return (this->x() != second.x()) || (this->y() != second.y()); }

    /**
     * @brief Check if the location are equal
     * @param First location
     * @param Second location
     * @return True if are in the same location (x and y), else false
     */
    static bool isLocationEqual(const AbstractLocated& loc1, const AbstractLocated& loc2)
    { return (loc1.x() == loc2.x()) && (loc1.y() == loc2.y()); }

    /**
     * @brief Stub decostructor
     */
    virtual ~AbstractLocated() {}
};

#endif // ABSTRACTLOCATED_H
