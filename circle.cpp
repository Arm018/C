// circle.cpp

#include "circle.h"
#include <cmath>

Circle::Circle(double r, double x, double y) : radius(r), x(x), y(y) {}

Circle::Circle(const Circle& other) : radius(other.radius), x(other.x), y(other.y) {}

Circle::~Circle() {
    std::cout << "Circle destroyed." << std::endl;
}

double Circle::getRadius() const {
    return radius;
}

std::pair<double, double> Circle::getCenter() const {
    return std::make_pair(x, y);
}

void Circle::setRadius(double r) {
    radius = r;
}

void Circle::moveX(double distance) {
    x += distance;
}

void Circle::moveY(double distance) {
    y += distance;
}

void Circle::scale(double factor) {
    radius *= factor;
}

bool Circle::operator==(const Circle& other) const {
    return (radius == other.radius) && (x == other.x) && (y == other.y);
}

bool Circle::operator!=(const Circle& other) const {
    return !(*this == other);
}

bool Circle::operator>(const Circle& other) const {
    return radius > other.radius;
}

bool Circle::operator<(const Circle& other) const {
    return radius < other.radius;
}

bool Circle::containsPoint(double px, double py) const {
    return std::pow(px - x, 2) + std::pow(py - y, 2) <= std::pow(radius, 2);
}

int Circle::intersectionPoints(const Circle& other) const {
    // Implement the intersection points calculation
    // This is just a placeholder, replace with the actual calculation
    return 0;
}

void Circle::printTangentEquation(double px, double py) const {
    // Implement the tangent equation printing
}

double Circle::circumference() const {
    return 2 * M_PI * radius;
}

double Circle::area() const {
    return M_PI * std::pow(radius, 2);
}

double Circle::distanceTo(const Circle& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "Circle [Radius: " << circle.radius << ", Center: (" << circle.x << ", " << circle.y << ")]";
    return os;
}

std::istream& operator>>(std::istream& is, Circle& circle) {
    is >> circle.radius >> circle.x >> circle.y;
    return is;
}
