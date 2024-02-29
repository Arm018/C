#include "point.h"
#include <vector>

int main() {
    // Тестирование объектов Point и их методов
    Point p1; // Конструктор без параметров
    std::cout << "p1: " << p1 << std::endl;

    Point p2(3.0, 4.0); // Конструктор с параметрами
    std::cout << "p2: " << p2 << std::endl;

    Point p3 = p2; // Конструктор копирования
    std::cout << "p3: " << p3 << std::endl;

    p1.setCoordinates(1.0, 2.0); // Установка новых координат
    std::cout << "p1 after setCoordinates: " << p1 << std::endl;

    std::cout << "Distance between p1 and p2: " << p1.distanceTo(p2) << std::endl;
    std::cout << "Distance from p1 to origin: " << p1.distanceToOrigin() << std::endl;

    Point p4 = p1.moveParallelX(5.0); // Перемещение по оси X
    std::cout << "p4 after moveParallelX: " << p4 << std::endl;

    Point p5 = p2.moveParallelY(-3.0); // Перемещение по оси Y
    std::cout << "p5 after moveParallelY: " << p5 << std::endl;

    // Тестирование массива объектов Point
    std::vector<Point> points = {p1, p2, p3, p4, p5};

    // Вывод точек, расстояние от которых до начальной точки координат больше 4.0
    double thresholdDistance = 4.0;
    std::cout << "Points with distance greater than " << thresholdDistance << " from origin:" << std::endl;
    for (const Point &point : points) {
        if (point.distanceToOrigin() > thresholdDistance) {
            std::cout << point << std::endl;
        }
    }

    // Поиск двух самых дальних точек
    double maxDistance = 0.0;
    Point farthestPoints[2];

    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double distance = points[i].distanceTo(points[j]);

            if (distance > maxDistance) {
                maxDistance = distance;
                farthestPoints[0] = points[i];
                farthestPoints[1] = points[j];
            }
        }
    }

    std::cout << "Two farthest points: " << farthestPoints[0] << " and " << farthestPoints[1] << std::endl;

    return 0;
}
