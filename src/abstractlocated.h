#ifndef ABSTRACTLOCATED_H
#define ABSTRACTLOCATED_H


class AbstractLocated
{
public:
    virtual int x() const = 0;
    virtual int y() const = 0;

    bool operator== (const AbstractLocated& second) const
    { return (this->x() == second.x()) && (this->y() == second.y()); }
    bool operator!= (const AbstractLocated& second) const
    { return (this->x() != second.x()) || (this->y() != second.y()); }

    static bool isLocationEqual(const AbstractLocated& loc1, const AbstractLocated& loc2)
    { return (loc1.x() == loc2.x()) && (loc1.y() == loc2.y()); }

    virtual ~AbstractLocated() {}
};

#endif // ABSTRACTLOCATED_H
