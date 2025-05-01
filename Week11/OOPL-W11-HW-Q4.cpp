#include <iostream>

template <typename T1, typename T2>
class Base
{
public:
    Base(T1 a, T2 b) : x(a), y(b) {}
    T1 getX() const { return x; }
    T2 getY() const { return y; }

private:
    T1 x;
    T2 y;
};

template <typename T1, typename T2, typename T3, typename T4>
class Derived : public Base<T1, T2>
{
public:
    Derived(T1 a, T2 b, T3 c, T4 d)
        : Base<T1, T2>(a, b), u(c), v(d) {}
    auto multiplyBase() const
    {
        return this->getX() * this->getY();
    }
    auto multiplyDerived() const
    {
        return u * v;
    }

private:
    T3 u;
    T4 v;
};

int main()
{
    Derived<int, int, double, double> obj(3, 4, 1.5, 2.0);
    std::cout << "Base multiplication (3*4): " << obj.multiplyBase() << "\n";
    std::cout << "Derived multiplication (1.5*2.0): " << obj.multiplyDerived() << "\n";
    return 0;
}
