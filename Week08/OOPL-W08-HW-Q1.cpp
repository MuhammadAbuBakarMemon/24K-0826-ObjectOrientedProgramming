#include <iostream>
using namespace std;

class Number
{
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    Number &operator--()
    {
        value *= 4;
        return *this;
    }

    Number operator--(int)
    {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    friend ostream &operator<<(ostream &os, const Number &n);
};

ostream &operator<<(ostream &os, const Number &n)
{
    os << n.value;
    return os;
}

int main()
{
    Number n(8);
    cout << "Original: " << n << endl;

    --n;
    cout << "After prefix --: " << n << endl;

    n--;
    cout << "After postfix --: " << n << endl;

    Number m(5);
    cout << "Postfix test: " << m-- << ", now m is " << m << endl;

    return 0;
}