#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial
{
private:
    std::vector<int> coefficients;

    void trim_trailing_zeros()
    {
        while (!coefficients.empty() && coefficients.back() == 0)
        {
            coefficients.pop_back();
        }
        if (coefficients.empty())
        {
            coefficients.push_back(0);
        }
    }

public:
    Polynomial() : Polynomial(std::vector<int>()) {}

    Polynomial(const std::vector<int> &coeffs) : coefficients(coeffs)
    {
        trim_trailing_zeros();
    }

    friend class PolynomialUtils;

    friend Polynomial operator+(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator-(const Polynomial &a, const Polynomial &b);
    friend Polynomial operator*(const Polynomial &a, const Polynomial &b);

    friend std::ostream &operator<<(std::ostream &os, const Polynomial &p);
};

class PolynomialUtils
{
public:
    static int evaluate(const Polynomial &p, int x)
    {
        int result = 0;
        int power = 1;
        for (size_t i = 0; i < p.coefficients.size(); ++i)
        {
            result += p.coefficients[i] * power;
            power *= x;
        }
        return result;
    }

    static Polynomial derivative(const Polynomial &p)
    {
        std::vector<int> coeffs;
        for (size_t i = 1; i < p.coefficients.size(); ++i)
        {
            coeffs.push_back(p.coefficients[i] * i);
        }
        return Polynomial(coeffs);
    }
};

Polynomial operator+(const Polynomial &a, const Polynomial &b)
{
    std::vector<int> result_coeffs(std::max(a.coefficients.size(), b.coefficients.size()), 0);
    for (size_t i = 0; i < result_coeffs.size(); ++i)
    {
        int a_val = (i < a.coefficients.size()) ? a.coefficients[i] : 0;
        int b_val = (i < b.coefficients.size()) ? b.coefficients[i] : 0;
        result_coeffs[i] = a_val + b_val;
    }
    return Polynomial(result_coeffs);
}

Polynomial operator-(const Polynomial &a, const Polynomial &b)
{
    std::vector<int> result_coeffs(std::max(a.coefficients.size(), b.coefficients.size()), 0);
    for (size_t i = 0; i < result_coeffs.size(); ++i)
    {
        int a_val = (i < a.coefficients.size()) ? a.coefficients[i] : 0;
        int b_val = (i < b.coefficients.size()) ? b.coefficients[i] : 0;
        result_coeffs[i] = a_val - b_val;
    }
    return Polynomial(result_coeffs);
}

Polynomial operator*(const Polynomial &a, const Polynomial &b)
{
    std::vector<int> result_coeffs(a.coefficients.size() + b.coefficients.size() - 1, 0);
    for (size_t i = 0; i < a.coefficients.size(); ++i)
    {
        for (size_t j = 0; j < b.coefficients.size(); ++j)
        {
            result_coeffs[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }
    return Polynomial(result_coeffs);
}

std::ostream &operator<<(std::ostream &os, const Polynomial &p)
{
    bool firstTerm = true;
    for (size_t i = 0; i < p.coefficients.size(); ++i)
    {
        int coeff = p.coefficients[i];
        if (coeff == 0)
            continue;

        if (!firstTerm)
        {
            os << (coeff > 0 ? " + " : " - ");
        }
        else
        {
            if (coeff < 0)
            {
                os << "-";
            }
            firstTerm = false;
        }

        int abs_coeff = abs(coeff);
        if (i == 0)
        {
            os << abs_coeff;
        }
        else
        {
            if (abs_coeff != 1)
            {
                os << abs_coeff;
            }
            if (i == 1)
            {
                os << "x";
            }
            else
            {
                os << "x^" << i;
            }
        }
        firstTerm = false;
    }

    if (firstTerm)
    {
        os << "0";
    }

    return os;
}