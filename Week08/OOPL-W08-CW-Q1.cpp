#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;

    static int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int num = 0, int den = 1)
    {
        if (den == 0)
            den = 1;
        int common = gcd(abs(num), abs(den));
        num /= common;
        den /= common;
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
        numerator = num;
        denominator = den;
    }

    friend Fraction operator+(const Fraction &a, const Fraction &b);
    friend Fraction operator-(const Fraction &a, const Fraction &b);
    friend Fraction operator*(const Fraction &a, const Fraction &b);
    friend Fraction operator/(const Fraction &a, const Fraction &b);

    friend bool operator==(const Fraction &a, const Fraction &b);
    friend bool operator!=(const Fraction &a, const Fraction &b);
    friend bool operator<(const Fraction &a, const Fraction &b);
    friend bool operator>(const Fraction &a, const Fraction &b);
    friend bool operator<=(const Fraction &a, const Fraction &b);
    friend bool operator>=(const Fraction &a, const Fraction &b);

    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
    friend std::istream &operator>>(std::istream &is, Fraction &f);
};

Fraction operator+(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}

Fraction operator-(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
}

Fraction operator*(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
}

Fraction operator/(const Fraction &a, const Fraction &b)
{
    return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
}

bool operator==(const Fraction &a, const Fraction &b)
{
    return a.numerator * b.denominator == b.numerator * a.denominator;
}

bool operator!=(const Fraction &a, const Fraction &b)
{
    return !(a == b);
}

bool operator<(const Fraction &a, const Fraction &b)
{
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

bool operator>(const Fraction &a, const Fraction &b)
{
    return b < a;
}

bool operator<=(const Fraction &a, const Fraction &b)
{
    return !(b < a);
}

bool operator>=(const Fraction &a, const Fraction &b)
{
    return !(a < b);
}

std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
    if (f.denominator == 1)
    {
        os << f.numerator;
    }
    else
    {
        os << f.numerator << "/" << f.denominator;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &f)
{
    int num, den = 1;
    char slash;
    is >> num;
    if (is.peek() == '/')
    {
        is >> slash >> den;
    }
    f = Fraction(num, den);
    return is;
}