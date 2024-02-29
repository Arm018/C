#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    double x, y;

public:
    Point();
    Point(double x, double y);
    Point(const Point &other);
    ~Point();

    double getX() const;
    double getY() const;
    void setCoordinates(double x, double y);

    friend std::ostream &operator<<(std::ostream &out, const Point &point);
    friend std::istream &operator>>(std::istream &in, Point &point);

    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

    double distanceTo(const Point &other) const;
    double distanceToOrigin() const;

    Point moveParallelX(double distance) const;
    Point moveParallelY(double distance) const;

    Point pointInQuadrant(int quadrant) const;
};

#endif // POINT_H
