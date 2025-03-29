#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInteger
{
private:
    std::vector<int> digits;
    bool is_positive;

    void trim_zeros()
    {
        while (digits.size() > 1 && digits.back() == 0)
        {
            digits.pop_back();
        }
        if (digits.empty())
        {
            digits.push_back(0);
            is_positive = true;
        }
    }

    static int compare_absolute(const std::vector<int> &a, const std::vector<int> &b)
    {
        if (a.size() != b.size())
            return a.size() > b.size() ? 1 : -1;
        for (int i = a.size() - 1; i >= 0; --i)
        {
            if (a[i] != b[i])
                return a[i] > b[i] ? 1 : -1;
        }
        return 0;
    }

    static std::vector<int> add_absolute(const std::vector<int> &a, const std::vector<int> &b)
    {
        std::vector<int> result;
        int carry = 0;
        size_t max_len = std::max(a.size(), b.size());
        for (size_t i = 0; i < max_len || carry; ++i)
        {
            int sum = carry;
            if (i < a.size())
                sum += a[i];
            if (i < b.size())
                sum += b[i];
            carry = sum / 10;
            result.push_back(sum % 10);
        }
        return result;
    }

    static std::vector<int> subtract_absolute(const std::vector<int> &a, const std::vector<int> &b)
    {
        std::vector<int> result;
        int borrow = 0;
        for (size_t i = 0; i < a.size(); ++i)
        {
            int sub = a[i] - borrow;
            borrow = 0;
            if (i < b.size())
                sub -= b[i];
            if (sub < 0)
            {
                sub += 10;
                borrow = 1;
            }
            result.push_back(sub);
        }
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();
        return result;
    }

    static std::vector<int> multiply_absolute(const std::vector<int> &a, const std::vector<int> &b)
    {
        std::vector<int> result(a.size() + b.size(), 0);
        for (size_t i = 0; i < a.size(); ++i)
        {
            int carry = 0;
            for (size_t j = 0; j < b.size() || carry; ++j)
            {
                long long mul = result[i + j] + a[i] * (j < b.size() ? b[j] : 0) + carry;
                result[i + j] = mul % 10;
                carry = mul / 10;
            }
        }
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();
        return result;
    }

public:
    BigInteger() : digits{0}, is_positive(true) {}

    BigInteger(const std::string &s)
    {
        if (s.empty())
        {
            digits.push_back(0);
            is_positive = true;
            return;
        }
        size_t start = 0;
        is_positive = true;
        if (s[0] == '-')
        {
            is_positive = false;
            start = 1;
        }
        digits.resize(s.size() - start);
        for (size_t i = start; i < s.size(); ++i)
        {
            digits[s.size() - 1 - i] = s[i] - '0';
        }
        trim_zeros();
        if (digits.size() == 1 && digits[0] == 0)
            is_positive = true;
    }

    BigInteger(const std::vector<int> &d, bool pos) : digits(d), is_positive(pos)
    {
        trim_zeros();
        if (digits.size() == 1 && digits[0] == 0)
            is_positive = true;
    }

    friend BigInteger operator+(const BigInteger &a, const BigInteger &b);
    friend BigInteger operator-(const BigInteger &a, const BigInteger &b);
    friend BigInteger operator*(const BigInteger &a, const BigInteger &b);

    friend bool operator==(const BigInteger &a, const BigInteger &b);
    friend bool operator!=(const BigInteger &a, const BigInteger &b);
    friend bool operator<(const BigInteger &a, const BigInteger &b);
    friend bool operator>(const BigInteger &a, const BigInteger &b);
    friend bool operator<=(const BigInteger &a, const BigInteger &b);
    friend bool operator>=(const BigInteger &a, const BigInteger &b);

    friend std::ostream &operator<<(std::ostream &os, const BigInteger &bi);
    friend std::istream &operator>>(std::istream &is, BigInteger &bi);
};

BigInteger operator+(const BigInteger &a, const BigInteger &b)
{
    if (a.is_positive == b.is_positive)
    {
        return BigInteger(BigInteger::add_absolute(a.digits, b.digits), a.is_positive);
    }
    else
    {
        int cmp = BigInteger::compare_absolute(a.digits, b.digits);
        if (cmp == 0)
            return BigInteger();
        if (cmp > 0)
        {
            return BigInteger(BigInteger::subtract_absolute(a.digits, b.digits), a.is_positive);
        }
        else
        {
            return BigInteger(BigInteger::subtract_absolute(b.digits, a.digits), b.is_positive);
        }
    }
}

BigInteger operator-(const BigInteger &a, const BigInteger &b)
{
    if (a.is_positive != b.is_positive)
    {
        return BigInteger(BigInteger::add_absolute(a.digits, b.digits), a.is_positive);
    }
    else
    {
        int cmp = BigInteger::compare_absolute(a.digits, b.digits);
        if (cmp == 0)
            return BigInteger();
        if (cmp > 0)
        {
            return BigInteger(BigInteger::subtract_absolute(a.digits, b.digits), a.is_positive);
        }
        else
        {
            return BigInteger(BigInteger::subtract_absolute(b.digits, a.digits), !a.is_positive);
        }
    }
}

BigInteger operator*(const BigInteger &a, const BigInteger &b)
{
    bool res_sign = (a.is_positive == b.is_positive);
    std::vector<int> res_digits = BigInteger::multiply_absolute(a.digits, b.digits);
    return BigInteger(res_digits, res_digits.back() == 0 ? true : res_sign);
}

bool operator==(const BigInteger &a, const BigInteger &b)
{
    return a.is_positive == b.is_positive && a.digits == b.digits;
}

bool operator!=(const BigInteger &a, const BigInteger &b)
{
    return !(a == b);
}

bool operator<(const BigInteger &a, const BigInteger &b)
{
    if (a.is_positive != b.is_positive)
        return !a.is_positive;
    int cmp = BigInteger::compare_absolute(a.digits, b.digits);
    return a.is_positive ? cmp < 0 : cmp > 0;
}

bool operator>(const BigInteger &a, const BigInteger &b)
{
    return b < a;
}

bool operator<=(const BigInteger &a, const BigInteger &b)
{
    return !(b < a);
}

bool operator>=(const BigInteger &a, const BigInteger &b)
{
    return !(a < b);
}

std::ostream &operator<<(std::ostream &os, const BigInteger &bi)
{
    if (!bi.is_positive && !(bi.digits.size() == 1 && bi.digits[0] == 0))
        os << '-';
    for (auto it = bi.digits.rbegin(); it != bi.digits.rend(); ++it)
    {
        os << *it;
    }
    return os;
}

std::istream &operator>>(std::istream &is, BigInteger &bi)
{
    std::string s;
    is >> s;
    bi = BigInteger(s);
    return is;
}