#include <iostream>
#include <string>
#include <cmath>

struct Point
{
    double x;
    double y;
};

class Shape
{
protected:
    Point position;
    std::string color;
    float borderThickness;

public:
    Shape(double x, double y, const std::string &col, float thickness = 1.0f)
        : position{x, y}, color(col), borderThickness(thickness) {}

    virtual ~Shape() = default;

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual void move(double dx, double dy)
    {
        position.x += dx;
        position.y += dy;
    }

    virtual void setColor(const std::string &newColor)
    {
        color = newColor;
    }

    virtual void printDetails() const
    {
        std::cout << "Position: (" << position.x << ", " << position.y << ")\n"
                  << "Color: " << color << "\n"
                  << "Border Thickness: " << borderThickness << "\n";
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double x, double y, double r, const std::string &col, float thickness = 1.0f)
        : Shape(x, y, col, thickness), radius(r) {}

    void draw() const override
    {
        std::cout << "Drawing Circle:\n";
        Shape::printDetails();
        std::cout << "Radius: " << radius << "\n";
    }

    double calculateArea() const override
    {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override
    {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double x, double y, double w, double h, const std::string &col, float thickness = 1.0f)
        : Shape(x, y, col, thickness), width(w), height(h) {}

    void draw() const override
    {
        std::cout << "Drawing Rectangle:\n";
        Shape::printDetails();
        std::cout << "Width: " << width << "\n"
                  << "Height: " << height << "\n";
    }

    double calculateArea() const override
    {
        return width * height;
    }

    double calculatePerimeter() const override
    {
        return 2 * (width + height);
    }
};

class Triangle : public Shape
{
private:
    Point points[2];

public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3,
             const std::string &col, float thickness = 1.0f)
        : Shape(x1, y1, col, thickness)
    {
        points[0] = {x2, y2};
        points[1] = {x3, y3};
    }

    void draw() const override
    {
        std::cout << "Drawing Triangle:\n";
        Shape::printDetails();
        std::cout << "Point 2: (" << points[0].x << ", " << points[0].y << ")\n"
                  << "Point 3: (" << points[1].x << ", " << points[1].y << ")\n";
    }

    double calculateArea() const override
    {
        return 0.5 * std::abs(
                         (position.x * (points[0].y - points[1].y) +
                          (points[0].x * (points[1].y - position.y)) +
                          (points[1].x * (position.y - points[0].y))));
    }

    double calculatePerimeter() const override
    {
        double side1 = std::sqrt(std::pow(points[0].x - position.x, 2) + std::pow(points[0].y - position.y, 2));
        double side2 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
        double side3 = std::sqrt(std::pow(position.x - points[1].x, 2) + std::pow(position.y - points[1].y, 2));
        return side1 + side2 + side3;
    }
};

class Polygon : public Shape
{
private:
    static const int MAX_POINTS = 10;
    Point points[MAX_POINTS];
    int numPoints;

public:
    Polygon(double x, double y, Point *pts, int n, const std::string &col, float thickness = 1.0f)
        : Shape(x, y, col, thickness), numPoints(n)
    {
        for (int i = 0; i < n && i < MAX_POINTS; i++)
        {
            points[i] = pts[i];
        }
    }

    void draw() const override
    {
        std::cout << "Drawing Polygon with " << numPoints << " points:\n";
        Shape::printDetails();
        for (int i = 0; i < numPoints; i++)
        {
            std::cout << "Point " << i + 1 << ": (" << points[i].x << ", " << points[i].y << ")\n";
        }
    }

    double calculateArea() const override
    {
        if (numPoints < 3)
            return 0.0;

        double area = 0.0;
        int j = numPoints - 1;

        for (int i = 0; i < numPoints; i++)
        {
            area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
            j = i;
        }

        return std::abs(area / 2.0);
    }

    double calculatePerimeter() const override
    {
        double perimeter = 0.0;
        for (int i = 0; i < numPoints; i++)
        {
            int next = (i + 1) % numPoints;
            perimeter += std::sqrt(
                std::pow(points[next].x - points[i].x, 2) +
                std::pow(points[next].y - points[i].y, 2));
        }
        return perimeter;
    }
};

int main()
{
    Circle circle(5.0, 5.0, 3.0, "Red");
    Rectangle rectangle(10.0, 10.0, 4.0, 6.0, "Blue");

    Point triPoints[2] = {{3.0, 0.0}, {0.0, 4.0}};
    Triangle triangle(0.0, 0.0, triPoints[0].x, triPoints[0].y,
                      triPoints[1].x, triPoints[1].y, "Green");

    Point polyPoints[5] = {{0.0, 0.0}, {2.0, 0.0}, {3.0, 2.0}, {1.0, 3.0}, {-1.0, 2.0}};
    Polygon pentagon(20.0, 20.0, polyPoints, 5, "Purple");

    circle.draw();
    std::cout << "Area: " << circle.calculateArea() << "\n";
    std::cout << "Perimeter: " << circle.calculatePerimeter() << "\n\n";

    rectangle.draw();
    std::cout << "Area: " << rectangle.calculateArea() << "\n";
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << "\n\n";

    triangle.draw();
    std::cout << "Area: " << triangle.calculateArea() << "\n";
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << "\n\n";

    pentagon.draw();
    std::cout << "Area: " << pentagon.calculateArea() << "\n";
    std::cout << "Perimeter: " << pentagon.calculatePerimeter() << "\n";

    return 0;
}