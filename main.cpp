// main.cpp

#include "circle.h"
#include <vector>

int main() {
    
    Circle circle1(2.5, 1.0, 2.0);
    Circle circle2 = circle1; 
    Circle circle3;
    circle3 = circle2;  

   
    std::vector<Circle> circles = {
        Circle(3.0, 0.0, 0.0),
        Circle(2.0, 1.0, 1.0),
        Circle(4.0, 2.0, 2.0),
    };

    
    double thresholdArea = 10.0;
    for (const auto& circle : circles) {
        if (circle.area() > thresholdArea) {
            std::cout << circle << std::endl;
        }
    }

    
    Circle maxTouchingCircle;
    int maxTouchCount = 0;

    for (const auto& currentCircle : circles) {
        int touchCount = 0;

        for (const auto& otherCircle : circles) {
            if (currentCircle != otherCircle && currentCircle.distanceTo(otherCircle) <= (currentCircle.getRadius() + otherCircle.getRadius())) {
                touchCount++;
            }
        }

        if (touchCount > maxTouchCount) {
            maxTouchCount = touchCount;
            maxTouchingCircle = currentCircle;
        }
    }

    std::cout << "Circle touching the maximum number of circles: " << maxTouchingCircle << std::endl;

   

    return 0;
}
