#include <cmath>

class Circle {
private:
    double radius;
    const double PI = 3.14159265358979323846;

public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * PI * radius;
    }
};