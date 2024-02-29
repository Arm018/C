#include "point.h"
#include <cmath>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {
    std::cout << "Copying point: (" << x << ", " << y << ")" << std::endl;
}

Point::~Point() {
    std::cout << "Destroying point: (" << x << ", " << y << ")" << std::endl;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setCoordinates(double x, double y) {
    this->x = x;
    this->y = y;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

std::istream &operator>>(std::istream &in, Point &point) {
    in >> point.x >> point.y;
    return in;
}

bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point &other) const {
    return !(*this == other);
}

double Point::distanceTo(const Point &other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

double Point::distanceToOrigin() const {
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

Point Point::moveParallelX(double distance) const {
    return Point(x + distance, y);
}

Point Point::moveParallelY(double distance) const {
    return Point(x, y + distance);
}

Point Point::pointInQuadrant(int quadrant) const {
    double newX, newY;

    switch (quadrant) {
        case 1:
            newX = std::abs(x);
            newY = std::abs(y);
            break;
        case 2:
            newX = -std::abs(x);
            newY = std::abs(y);
            break;
        case 3:
            newX = -std::abs(x);
            newY = -std::abs(y);
            break;
        case 4:
            newX = std::abs(x);
            newY = -std::abs(y);
            break;
        default:
            newX = x;
            newY = y;
            break;
    }

    return Point(newX, newY);
}