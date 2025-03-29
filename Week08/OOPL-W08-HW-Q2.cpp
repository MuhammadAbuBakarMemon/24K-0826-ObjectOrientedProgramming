#include <iostream>
using namespace std;

class shape
{
private:
    double area;

public:
    shape(double a = 0) : area(a) {}
    double Area() const
    {
        return area;
    }
};

double operator+(const shape &s1, const shape &s2)
{
    return s1.Area() + s2.Area();
}

int main()
{
    shape shape1(5.5);
    shape shape2(4.5);
    double total = shape1 + shape2;
    cout << "Sum of areas: " << total << endl;
    return 0;
}