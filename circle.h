// circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

class Circle {
private:
    double radius;
    double x;
    double y;

public:
    Circle(double r = 1.0, double x = 0.0, double y = 0.0);
    Circle(const Circle& other);
    ~Circle();

    double getRadius() const;
    std::pair<double, double> getCenter() const;

    void setRadius(double r);
    void moveX(double distance);
    void moveY(double distance);
    void scale(double factor);

    bool operator==(const Circle& other) const;
    bool operator!=(const Circle& other) const;
    bool operator>(const Circle& other) const;
    bool operator<(const Circle& other) const;

    bool containsPoint(double px, double py) const;
    int intersectionPoints(const Circle& other) const;
    void printTangentEquation(double px, double py) const;

    double circumference() const;
    double area() const;
    double distanceTo(const Circle& other) const;

    // Add any other necessary functions

    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
    friend std::istream& operator>>(std::istream& is, Circle& circle);
};

#endif // CIRCLE_H
